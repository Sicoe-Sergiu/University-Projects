use Record_Label

create or alter proc addToTables(@tableName varchar(50)) as
    if @tableName in (select Name from Tables) begin
        print 'Table already present in tables'
        return
    end;
    if @tableName not in (select TABLE_NAME from INFORMATION_SCHEMA.TABLES) begin
        print 'Table not present in database'
        return
    end;
     insert into Tables (Name) values (@tableName)
go

create or alter procedure addToViews (@viewName varchar(50)) as
    if @viewName in (select Name from Views) begin
        print 'View already present in views'
        return
    end
    if @viewName not in (select TABLE_NAME from INFORMATION_SCHEMA.TABLES) begin
        print 'View not present in database'
        return
    end
    insert into Views (Name) values (@viewName)
go

create or alter procedure addToTests(@testName varchar(50)) as
    if @testName in (select Name from Tests) begin
        print 'Test already present in tests'
        return
    end
    insert into Tests(Name) values (@testName)
go

create or alter procedure connectTableToTest(@tableName varchar(50), @testName varchar(50), @rows int, @pos int) as
    if @tableName not in (select Name from Tables) begin
        print 'Table not present in tables'
        return
    end
    if @testName not in (select Name from Tests) begin
        print 'Test not present in tests'
        return
    end
    if exists(select *
              from TestTables T1
              join Tests T2
              on T1.testID = T2.testID
              where T2.Name = @testName and position = @pos ) begin

                  print 'Position provided conflicts with previous positions'
                  return
    end;

    insert into TestTables
        (testID, tableID, noRows, position)
    values (
            (select Tests.testID from Tests where Name = @testName),
            (select Tables.tableID from Tables where Name = @tableName),
            @rows,
            @pos
           )
go


create or alter procedure connectViewToTest (@viewName varchar(50), @testName varchar(50)) as
    if @viewName not in (select Name from Views) begin
        print 'View not present in views'
        return
    end
    if @testName not in (select Name from Tests) begin
        print 'Test not present in tests'
        return
    end
    insert into TestViews
        (testID, viewID)
    values (
        (select Tests.testID from Tests where Name = @testName),
        (select Views.viewID from Views where Name = @viewName)
    )
go


create or alter procedure runTest (@testName varchar(50)) as
begin
    if @testName not in (select Name from Tests ) begin
        print 'Test not present in tests'
        return
    end;

    declare @command varchar(50)
    declare @testStartTime datetime2
    declare @startTime datetime2
    declare @endTime datetime2
    declare @table varchar(50)
    declare @rows int
    declare @pos int
    declare @view varchar(50)
    declare @testId int
    declare @testRunId int

    select @testId = testId
    from Tests
    where Name = @testName

    set @testRunId = (select max(runID)+1 from TestRuns)

    if @testRunId is null
        set @testRunId = 0



    DECLARE tableCursor cursor scroll for
        select T1.name, T2.noRows, T2.Position
        from Tables T1
        join TestTables T2 on T1.tableID = T2.tableID
        where T2.testID = @testId
        order by T2.position

    DECLARE viewCursor cursor for
        select V.name
        from Views V
        join TestViews TV on V.viewID = TV.viewID
        where TV.testID = @testId

    set @testStartTime = sysdatetime()

    open tableCursor
    fetch last from tableCursor into @table, @rows, @pos

    while @@FETCH_STATUS = 0 begin
        exec ('delete from '+ @table)
        fetch prior from tableCursor into @table, @rows, @pos
    end;
    close tableCursor

    open tableCursor
    SET IDENTITY_INSERT TestRuns ON
    insert into
        TestRuns (runID, description, startAt)
    values
        (@testRunId, 'Tests results for: '+ @testName, @testStartTime)
    SET IDENTITY_INSERT TestRuns off

    fetch tableCursor into @table, @rows, @pos
    while @@fetch_status = 0 begin
        set @command = 'populateTable' + @table
        if @command not in ( select ROUTINE_NAME
                             from INFORMATION_SCHEMA.ROUTINES) begin
            print @command + 'does not exist'
            return
        end;

        set @startTime = sysdatetime()
        exec @command @rows
        set @endTime = sysdatetime()

        insert into TestRunTables
            (testRunID, tableID, startAt, endAt)
        values
            (@testRunId, (select tableID
                          from Tables
                          where Name = @table), @startTime, @endTime)
        fetch tableCursor into @table, @rows, @pos

    end
    close tableCursor
    deallocate tableCursor

    open viewCursor
    fetch viewCursor into @view
    while @@fetch_status = 0 begin
        SET @command = 'select * from '+ @view
        set @startTime = sysdatetime()
        exec (@command)
        set @endTime = sysdatetime()

        insert into TestRunViews
            (testRunID, viewID, startAt, endAt)
        values
            (@testRunId, (select viewID
                          from Views
                          where Name = @view), @startTime, @endTime)
        fetch viewCursor into @view

    end
    close viewCursor
    deallocate viewCursor

    update TestRuns
    set endAt = sysdatetime()
    where runID = @testRunId

end

go
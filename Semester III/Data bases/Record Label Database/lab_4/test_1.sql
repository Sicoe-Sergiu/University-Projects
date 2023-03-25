use Record_Label

exec addToTables @tableName = 'EventFounder'

create or alter view getEventFounderNameAndPhone as
    select first_name, last_name, phone
    from EventFounder
go

exec addToViews @viewName = 'getEventFounderNameAndPhone'
exec addToTests @testName = 'test1'
exec connectTableToTest @tableName = 'EventFounder', @testName = 'test1', @rows = 1000, @pos = 1
exec connectViewToTest @viewName = 'getEventFounderNameAndPhone', @testName = 'test1'

create or alter procedure populateTableEventFounder(@rows int ) as
    while @rows > 0 begin
        insert into EventFounder
            (EFid, first_name, last_name, email, phone)
        values
            (@rows, replace(concat('first_name_', str(@rows)), ' ', ''), replace(concat('last_name_', str(@rows)), ' ', ''), 'testing',replace(concat('07000000', str(floor(rand()*89 + 10))), ' ', ''))
        set @rows = @rows - 1
    end
go

exec runTest @testName = 'test1'

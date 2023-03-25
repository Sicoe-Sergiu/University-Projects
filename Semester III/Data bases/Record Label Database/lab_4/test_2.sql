use Record_Label
go
exec addToTables @tableName = 'ArtistManager'
exec addToTables @tableName = 'Producer'
go
create or alter view getArtistManagerAndProducer as
    select ArtistManager.first_name, ArtistManager.last_name, P.name
    from ArtistManager
    full join Producer P on ArtistManager.AMid = P.manager_id
go

exec addToViews @viewName = 'getArtistManagerAndProducer'
exec addToTests @testName = 'test2'
exec connectTableToTest @tableName = 'ArtistManager', @testName = 'test2', @rows = 1000, @pos = 2
exec connectTableToTest @tableName = 'Producer', @testName = 'test2', @rows = 1000, @pos = 3
exec connectViewToTest @viewName = 'getArtistManagerAndProducer', @testName = 'test2'
go
create or alter procedure populateTableArtistManager(@rows int) as
    while @rows > 0 begin
        insert into ArtistManager
            (AMid, first_name, last_name, email, phone)
        VALUES
            (@rows, replace(concat('first_name_', str(@rows)), ' ', ''), replace(concat('last_name_', str(@rows)), ' ', ''), 'TEST', replace(concat('07000000', str(floor(rand()*89 + 10))), ' ', ''))
        SET @rows = @rows - 1
    end

go
create or alter procedure populateTableProducer(@rows int) as
    while @rows > 0 begin
        insert into Producer
        (Pid, name, manager_id)
        VALUES
            (@rows, replace(concat('Producer_name_', str(@rows)), ' ', ''), @rows)
        SET @rows = @rows - 1
    end
go

exec runTest @testName = 'test2'

delete from Views
delete from TestRunTables
delete from TestRunViews
delete from TestRuns
delete from Tables
delete from Tests
delete from TestViews
delete from TestTables


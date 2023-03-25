use Record_Label
go

exec addToTables @tableName = 'Track'
exec addToTables @tableName = 'Producer'

go
create or alter view getProducerAndTrack as
    select P.name as producer_name, T.name as track_name
    from Producer P
    full join Track T on P.Pid = T.producer_id
    group by P.name , T.name
go

exec addToViews @viewName = 'getProducerAndTrack'
go
exec addToTests @testName = 'test3'
go
exec connectTableToTest @tableName = 'Producer', @testName = 'test3', @rows = 1000, @pos = 19
exec connectTableToTest @tableName = 'Track', @testName = 'test3', @rows = 1000, @pos = 20
exec connectViewToTest @viewName = 'getProducerAndTrack', @testName = 'test3'
go

create or alter procedure populateTableProducer( @rows int) as
    while @rows > 0 begin
        insert into Producer
        (Pid, name, manager_id)
    values
        (@rows, replace(concat('Producer_name', str(@rows)), ' ', ''), 1)
        set @rows = @rows - 1
    end
go

create or alter procedure populateTableTrack( @rows int) as
    while @rows > 0 begin
        insert into Track
        (Tid, name, bpm, producer_id, no_visualisations)
    values
        (@rows,replace(concat('Track_name', str(@rows)), ' ', ''), 0, @rows, 0)
        set @rows = @rows - 1
    end
go

select * from Track
select * from Producer
select * from ArtistManager

exec runTest @testName = 'test3'

delete from Producer
delete from Track
delete from ArtistManager

insert into ArtistManager
values (1,'ar','ar','mama',02727282)
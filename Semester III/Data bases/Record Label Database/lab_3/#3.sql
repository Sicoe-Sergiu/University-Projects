use Record_Label

-------create table proc

create or alter procedure CreateTableSinger
    as
create table Singer(
    Sid int not null ,
    stage_name varchar(30),
    first_name varchar(30),
    last_name varchar(30),
    manger_id int
)
go;

exec CreateTableSinger

-------- drop table proc

create procedure DeleteTableSinger
    as
    drop table Singer
go;

exec DeleteTableSinger

--- add column proc

create procedure AddColRating
    as
    alter table Singer
    add rating int
go;
exec AddColRating

--- drop column proc

create procedure DropColRating
    as
    alter table Singer
    drop column rating
go;
exec DropColRating

---- modify the type of col proc to float

create or alter procedure ChangeTypeRating_to_float
    as
    alter table Singer
    alter column rating float
go;
exec ChangeTypeRating_to_float

---- modify the type of col proc to int

create or alter procedure ChangeTypeRating_to_int
    as
    alter table Singer
    alter column rating int
go;
exec ChangeTypeRating_to_int

-- add DEFAULT constraint to table event on date field

create procedure AddConstraintDefDateToday_to_Event
    as
    alter table Event
    add constraint df_date
        DEFAULT getdate() for date
go;

exec AddConstraintDefDateToday_to_Event

---- remove DEFAULT constraint to table event on date field

create procedure DropConstraintDefDateToday_to_Event
    as
    alter table Event
    drop constraint df_date
go;

exec DropConstraintDefDateToday_to_Event

--add primary key to table singer (Sid)

create procedure AddPrimaryKey_Sid
as
    alter table Singer
    add constraint pk_sid primary key (Sid)
go;

exec AddPrimaryKey_Sid

-- drop primary key Sid in Singer

create procedure DropPrimaryKey_Sid
as
    alter table Singer
    drop constraint pk_sid
go;

exec DropPrimaryKey_Sid


--add candidate key in Singer

create or alter procedure AddCandidateKey_stage_name
as
    alter table Singer
    add stage_nickname varchar(30) not null unique default 'stage_name'

go;

exec AddCandidateKey_stage_name

--drop candidate key in Singer

create procedure DropCandidateKey_stage_name
as
    alter table Singer
    drop column stage_name
go;

exec DropCandidateKey_stage_name

-- add foreign key in singer

create procedure AddForeignKey_managerId
as
    alter table Singer
    add constraint fk_manager_id
        foreign key (manger_id) references ArtistManager(AMid)
go;

exec AddForeignKey_managerId

-- drop foreign key in singer

create procedure DropForeignKey_managerId
as
    alter table Singer
    drop fk_manager_id
go;

exec DropForeignKey_managerId

------------------------------------------VERSIon

create table Versions (
	version int
	)

insert into Versions values (1) -- initial

create table ProceduresTable (
	fromV int,
	toV int,
	name varchar(100),
	primary key(fromV,toV)
	)

select * from ProceduresTable

insert into ProceduresTable values (1,2,'CreateTableSinger')
insert into ProceduresTable values (2,1,'DeleteTableSinger')
insert into ProceduresTable values (2,3,'AddColRating')
insert into ProceduresTable values (3,2,'DropColRating')
insert into ProceduresTable values (3,4,'ChangeTypeRating_to_float')
insert into ProceduresTable values (4,3,'ChangeTypeRating_to_int')
insert into ProceduresTable values (4,5,'AddConstraintDefDateToday_to_Event')
insert into ProceduresTable values (5,4,'DropConstraintDefDateToday_to_Event')
insert into ProceduresTable values (5,6,'AddPrimaryKey_Sid')
insert into ProceduresTable values (6,5,'DropPrimaryKey_Sid')
insert into ProceduresTable values (6,7,'AddCandidateKey_stage_name')
insert into ProceduresTable values (7,6,'DropCandidateKey_stage_name')
insert into ProceduresTable values (7,8,'AddForeignKey_managerId')
insert into ProceduresTable values (8,7,'DropForeignKey_managerId')

create or alter procedure goToVersion(@newV int) as
	declare @current int
	declare @procedure varchar(100)
	select @current=version from Versions

	if @newV > (select max(toV) from ProceduresTable)
		raiserror ('invalid version', 10, 1)

    if @newV < (select min(toV) from ProceduresTable)
		raiserror ('invalid version', 10, 1)

	if @current > @newV begin
		while @current > @newV begin
			select @procedure=name from ProceduresTable where fromV=@current and toV=@current-1
			execute (@procedure)
			set @current=@current-1
		end
	end

	else begin

		while @current < @newV begin
			select @procedure=name from ProceduresTable where fromV=@current and toV=@current+1
			execute (@procedure)
			set @current=@current+1
		end
	end

	update Versions set version=@newV

execute goToVersion 1

select * from Singer
drop table Singer
select * from Event
SELECT * FROM Versions

update Versions set version=1
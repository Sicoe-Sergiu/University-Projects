use Record_Label

----INSERT----
insert into EventFounder(EFid, first_name, last_name, email, phone)
    values (1, 'Sergiu', 'Sicoe', 'sergiusicoemarian@yahoo.com', '0770871505')

insert into EventFounder(EFid, first_name, last_name, email, phone)
    values (2, 'Marti', 'Vlad', 'vladmati10@yahoo.com', '0770871462')

insert into EventFounder(EFid, first_name, last_name, email, phone)
    values (3, 'Oana', 'Andrada', 'Oana.Andrada@yahoo.com', '0746043261')

insert into EventFounder(EFid, first_name, last_name, email, phone)
    values (4, 'Costel', 'Biju', 'Costel.Biju@yahoo.com', '0746095421')

use Record_Label

drop table ArtistManager
drop table Dj

create table ArtistManager(
    id int IDENTITY (1,1) primary key ,
    first_name varchar (30),
    last_name varchar(30),
    email varchar(30),
    phone varchar(11)
)

create table Dj(
    id int IDENTITY(1,1) primary key,
    nick_name varchar(30),
    full_name varchar(50),
    fee int,
    manager_id int,
    foreign key (manager_id) references ArtistManager(id)
)


--INSERT EVENT--

insert into Event(Eid, name, location, date, founder_id, capacity)
values (1, 'Mioritmic','Cluj-Napoca','2022-11-21', 1, 2500)

insert into Event(Eid, name, location, date, founder_id, capacity)
values (2, 'Holiday Mood','Azuga','2023-1-1', 2, 5000)

insert into Event(Eid, name, location, date, founder_id, capacity)
    values (3, 'Sun Waves','Crazy Beach Mamaia','2023-4-27', 2, 5000)

insert into Event(Eid, name, location, date, founder_id, capacity)
    values (4, 'UnParty','unknown','2022-12-12', 1, 350)

insert into Event(Eid, name, location, date, founder_id, capacity)
    values (5, 'Multiverse','Form Space','2022-11-04', 2, 600)

insert into Event(Eid, name, location, date, founder_id, capacity)
    values (6, 'UnParty','unknown','2023-1-1', 1, 500)

insert into Event(Eid, name, location, date, founder_id, capacity)
    values (7, 'UnParty','unknown','2023-3-15', 1, 400)



--INSERT SOUND ENGINEER--
insert into SoundEngineer(SEid, first_name, last_name, email, phone, event_id)
    values (1, 'Denis', 'Naste', 'denis.naste@gmail.com', '0746121529', 1)

insert into SoundEngineer(SEid, first_name, last_name, email, phone, event_id)
    values (2, 'Alex', 'Damian', 'alex.damian@gmail.com', '0746232362', 1)

--INSERT ARTIST MANAGER
insert into ArtistManager(first_name, last_name, email, phone)
    values('Tati', 'Tati', 'tati.tati@tati.com', '0737941245')

insert into ArtistManager(first_name, last_name, email, phone)
    values('Horatiu', 'Hategan', 'horatiu.hategan@yahoo.com', '0737331323')

insert into ArtistManager(first_name, last_name, email, phone)
    values('Clara', 'Cibu', 'Clara.Cibu@yahoo.com', '0737319427')

insert into ArtistManager(first_name, last_name, email, phone)
    values('Alisia', 'Filip', 'Alisia.Filip@yahoo.com', '0737331323')

insert into ArtistManager(first_name, last_name, email, phone)
    values('Claudiu', 'Damian', 'Claudiu.Damian@yahoo.com', '0737391436')


--insert DJ--
delete from Dj
insert into DJ(nick_name, full_name, fee, manager_id)
    values ('Priku', 'Adrian Niculae', 5000, 1)

insert into Dj(nick_name, fee, manager_id)
    values ('Prichindel', 4500, 1)

insert into DJ(nick_name, full_name, fee, manager_id)
    values ('Petre Inspirescu','Pedro', 5000, 1)

insert into Dj(nick_name, full_name, fee, manager_id)
    values ('Sepp','Teo', 4000, 2)

insert into Dj(nick_name, fee, manager_id)
    values ('Nu Zau',3900, 2)

-- insert into Dj(nick_name, full_name, fee, manager_id)
--     values (6, 'Traumer', 2)

insert into Dj(nick_name, full_name, fee, manager_id)
    values (7, 'Arapu', 2)

insert into Dj(nick_name, full_name, fee, manager_id)
    values (8, 'Raresh')

insert into Dj(nick_name, full_name, fee, manager_id)
    values (9, 'Sit')

insert into Dj(nick_name, full_name, fee, manager_id)
    values (10, 'rqz')

insert into Dj(nick_name, full_name, fee, manager_id)
    values (11, 'Gescu', 2)

insert into Dj(nick_name, full_name, fee, manager_id)
    values (12, 'Ricardo Villalobos')

select * from Dj

--insert Producer--

insert into Producer(Pid, name, manager_id)
    values (1, 'Rayzeh', 2)

insert into Producer(Pid, name, manager_id)
    values (2, 'Traumer', 1)

insert into Producer(Pid, name, manager_id)
    values (3, 'Alineat', 2)

insert into Producer(Pid, name, manager_id)
    values (4, 'KIRIK', 1)

insert into Producer(Pid, name, manager_id)
    values (5, 'Priku', 1)

insert into Producer(Pid, name, manager_id)
    values (6, 'Traumer', 2)

insert into Producer(Pid, name)
    values (7, 'Prichindel')

insert into Producer(Pid, name)
    values (8, 'Ricardo Villalobos')

select * from Producer

--insert Track--

insert into Track(Tid, name, bpm, producer_id, no_visualisations)
    values (1, 'Szs - Rasters (DubluD Remix) [URB019]', 125, 1, 1056)

insert into Track(Tid, name, bpm, producer_id, no_visualisations)
    values (2, 'Vinci', 126, 2, 530)

insert into Track(Tid, name, bpm, no_visualisations)
    values (3, 'Unknown - Rr [C2C001]', 124, 6034)

insert into Track(Tid, name, bpm, producer_id, no_visualisations)
    values (4, 'ZAkroi glaza', 125, 4, 4001)

insert into Track(Tid, name, bpm, producer_id, no_visualisations)
    values (5, 'After la Tiganu', 125, 3, 456)

insert into Track(Tid, name, bpm, producer_id, no_visualisations)
    values (6, 'Inspector Freeman [WNGVA001]', 126, 3,8900)

insert into Track(Tid, name, bpm, producer_id, no_visualisations)
    values (7, 'Trillo del Diavolo [WNG001]', 124, 3, 325)

select * from Track

--insert Album--

insert into Album(Aid, dj_id, name, nr_of_tracks)
    values (1, 5, 'Primu E De Proba', 9)

insert into Album(Aid, dj_id, name, nr_of_tracks)
    values (2, 3, 'Vin Ploile', 9)

insert into Album(Aid, dj_id, name, nr_of_tracks)
    values (3, 3, 'fabric 68: Petre Inspirescu', 12)

insert into Album(Aid, dj_id, name, nr_of_tracks)
    values (4, 1, 'Zori De Zi', 2)

insert into Album(Aid, dj_id, name, nr_of_tracks)
    values (5, 1, 'WYS026', 5)
select * from Album

--insert Mix--


insert into Mix(Mid, name, no_visualisations)
    values (1, 'Priku [GH003 - Podcast Series]', 2450)

insert into Mix(Mid, name, no_visualisations)
    values (2, 'Arapu [GH010 - Podcast Series]', 350)

insert into Mix(Mid, name, no_visualisations)
    values (3, 'Priku b2b Arapu - Citadela', 3500)

insert into Mix(Mid, name, no_visualisations)
    values (4, 'Traumer at UNUM Festival 2021', 4132)

insert into Mix(Mid, name, no_visualisations)
    values (5, 'Sepp & Nu Zau Sunrise Hub', 2903)

insert into Mix(Mid, name, no_visualisations)
    values (6, 'Petre Inspirescu Bipolar House', 367)

insert into Mix(Mid, name, no_visualisations)
    values (7, 'Prichindel Live Studio Session', 5300)

insert into Mix(Mid, name, no_visualisations)
    values (8, 'Prichindel Live BFA-02', 2035)

select * from Mix

--insert DjMix--

insert into DjMix (DMid, dj_id, mix_id)
values (1, 1, 1);

insert into DjMix (DMid, dj_id, mix_id)
values (2, 1, 3);

insert into DjMix (DMid, dj_id, mix_id)
values (3, 7, 2);

insert into DjMix (DMid, dj_id, mix_id)
values (4, 7, 3);

insert into DjMix (DMid, dj_id, mix_id)
values (5, 6, 4);

insert into DjMix (DMid, dj_id, mix_id)
values (6, 4, 5);

insert into DjMix (DMid, dj_id, mix_id)
values (7, 5, 5);

insert into DjMix (DMid, dj_id, mix_id)
values (8, 3, 6);

insert into DjMix (DMid, dj_id, mix_id)
values (9, 2, 8);

insert into DjMix (DMid, dj_id, mix_id)
values (10, 2, 8);

--violate foreign key
insert into DjMix (DMid, dj_id, mix_id)
values (11, 15, 88);
---------------------------------------

select *
from Event;

--insert DjEvent--

insert into DjEvent (DEid, artist_id, event_id)
values (1, 1, 1)

insert into DjEvent (DEid, artist_id, event_id)
values (2, 1, 2)

insert into DjEvent (DEid, artist_id, event_id)
values (3, 1, 3)

insert into DjEvent (DEid, artist_id, event_id)
values (4, 2, 1)

insert into DjEvent (DEid, artist_id, event_id)
values (5, 2, 2)

insert into DjEvent (DEid, artist_id, event_id)
values (6, 2, 3)

insert into DjEvent (DEid, artist_id, event_id)
values (7, 3, 2)

insert into DjEvent (DEid, artist_id, event_id)
values (8, 1, 3)

insert into DjEvent (DEid, artist_id, event_id)
values (9, 4, 3)

insert into DjEvent (DEid, artist_id, event_id)
values (10, 5, 3)

insert into DjEvent (DEid, artist_id, event_id)
values (11, 6, 3)

insert into DjEvent (DEid, artist_id, event_id)
values (12, 7, 2)

insert into DjEvent (DEid, artist_id, event_id)
values (13, 4, 1)

insert into DjEvent (DEid, artist_id, event_id)
values (14, 5, 1)

insert into DjEvent (DEid, artist_id, event_id)
values (15, 7, 3)


--------UPDATE--------

select * from  Album

update Album
    set nr_of_tracks = 3
        where dj_id = 5 or dj_id = 1
update Album
    set nr_of_tracks = 3
        where dj_id < 1

update Event
    set capacity = 5100
        where capacity between 3000 and 5000

update Mix
    set name = 'Prichindel mix'
        where name like '%Live%'

---------DELETE--------

delete from Track
    where producer_id is null

delete from Album
    where Album.Aid in (2, 5)

use Record_Label
delete from ArtistManager
delete from Producer




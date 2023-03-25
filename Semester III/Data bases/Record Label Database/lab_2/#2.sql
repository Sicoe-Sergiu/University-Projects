use Record_Label
--UNION--
select * from Event

select name
from Mix
union
select name
from Album

select name, bpm from Track
    where bpm = 126 or bpm = 124

--INTERSECTION--

select stage_name from Dj
intersect
select name from Producer

select distinct * from Dj
    where stage_name in ('Priku', 'Traumer')

--difference--

select name from Event
except
select name from Event
    where location = 'Azuga'

select distinct * from Event
    where name not in ('Untold','Neversea', 'Sun Waves')

--INNER JOIN_______________

select stage_name, Album.name, DjEvent.event_id
    from ((Dj
        inner join Album on Dj.Did = Album.dj_id)
        inner join DjEvent on Dj.Did = DjEvent.DEid)

------LEFT JOIN------

select * from Track
select * from Album

select Producer.name, Producer.Pid, Track.producer_id, Track.name
    from Producer
        left join Track on Pid = Track.producer_id

-------Right join----------

select Dj.stage_name, Did, Album.dj_id, Album.name
    from Dj
        right join Album on Did = Album.dj_id

---------FULL JOIN----------- many to many

select DjEvent.artist_id, DjMix.dj_id
    from DjEvent
        full join DjMix on DjEvent.artist_id = DjMix.dj_id


---g. 2 queries with a subquery in the FROM clause--

select eve.name, eve.date
    from (select *                --select all events with cap =5000/5100 and name 'sun Waves'
            from Event
                where capacity in (5100, 5000)) eve
            where name in ('Sun Waves')


select tr.name
    from(select *          --select all tracks with bpm =126/124 and no producer
            from Track
                where bpm in (126, 124)) tr
        where producer_id is null

--e. 2 queries with the IN operator and a subquery in the WHERE clause;
-- in at least one case, the subquery must include a subquery in its own WHERE clause;

select  * from Dj

select stage_name, Did       --select all dj with an album with more than 4 tracks
    from Dj
        where Did in(select dj_id
                        from Album
                            where nr_of_tracks >= 5)

select *               --select all dj with an mix with id < 3
    from Dj
        where Did in(select dj_id
                        from DjMix
                            where mix_id < 3)

--f. 2 queries with the EXISTS operator and a subquery in the WHERE clause;


select stage_name
from Dj
where not exists(select *       --select all the dj without an album
                 from Album
                  where Did = Album.dj_id)

select first_name, last_name
from ArtistManager
where exists(select *       -- select managers who manege a producer with a track with 124 bpm
             from Producer
             where Pid in (select producer_id
                           from Track
                           where bpm = 124))

--h. 4 queries with the GROUP BY clause, 3 of which also contain the HAVING clause;
-- use the aggregation operators: COUNT, SUM, AVG, MIN, MAX;

select dj_id, avg(nr_of_tracks) as AVR_no_tracks
from Album
where nr_of_tracks > 3                    --select all the dj who have an album with more than
group by dj_id                            --3 tracks and show the dj with avg of tracks >5
having avg(nr_of_tracks) > 5              -- gruped by id and ordered desc by id
order by dj_id desc


select name, max(capacity) as MaxCap --all events with max cap > 200 group by name ord by max cap
from Event
group by name
having max(capacity) > 200
order by max(capacity)

select producer_id, Max(bpm) as max_bpm
from Track                                   --tracks grouped by producer with max bpm < 126
group by producer_id
having max(bpm) <= 125


select manager_id, count(manager_id) as count_managerID
from Producer
group by manager_id
having count(manager_id) > 1


--4 queries using ANY and ALL to introduce a subquery in the WHERE clause (2 queries per operator);
-- rewrite 2 of them with aggregation operators, and the other 2 with IN / [NOT] IN.

select name,no_visualisations --select the tracks with more visuals than all the mixes
from Track
where no_visualisations > all (select no_visualisations
                               from Mix)
--rewrite__in

select name,no_visualisations --select the tracks with more visuals than all the mixes
from Track
where no_visualisations > (select max(no_visualisations)
                               from Mix)
------------------------------------------

select name, no_visualisations
from Mix                  --all mixes with the nr of visuals = with any nr of visuals from track
where no_visualisations = any (select no_visualisations
                               from Track)

select name, no_visualisations
from Mix                  --all mixes with more visuals than the track with lowest nr of visuals
where no_visualisations in (select no_visualisations
                               from Track)

--------------------------------------------
select stage_name, Did
from Dj
where Did = any (select artist_id
                 from DjEvent)

--rewrite__in
select stage_name, Did
from Dj
where Did in (select artist_id
                 from DjEvent)
----------------------------------------------

select name, no_visualisations
from Track
where no_visualisations < any(select no_visualisations
                              from Mix)

select name, no_visualisations
from Track
where no_visualisations < (select max(no_visualisations)
                              from Mix)

---------------------------------------------------------------


--top
select top 2 *
from Dj

select top 4 *
from Producer

--group by
select name, max(capacity) as MaxCap --all events with max cap > 200 group by name ord by max cap
from Event
group by name
having max(capacity) > (select avg(capacity)
                        from Event)

select producer_id, Max(bpm) as max_bpm
from Track                                   --tracks grouped by producer with max bpm < 126
group by producer_id
having max(bpm) > (select avg(bpm)
                   from Track)

--arithmetics in select clause
select name,(capacity + Event.access_price)
from Event
where (capacity + Event.access_price) > 1000

select (first_name +' '+ last_name) as 'Full name'
from SoundEngineer

select (first_name +' '+ last_name) as 'Full name'
from EventFounder



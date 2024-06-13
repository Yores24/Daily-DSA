# Write your MySQL query statement below
with abc as (select requester_id as id from requestaccepted union all select accepter_id as id from requestaccepted)

select id, count(id) as num from abc group by id order by count(id) desc limit 1
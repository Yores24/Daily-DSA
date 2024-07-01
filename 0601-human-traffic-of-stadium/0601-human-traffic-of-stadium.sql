# Write your MySQL query statement below
with abc as (select * ,row_number() over(order by id) as rnk  from stadium where people>=100)

select id,visit_date,people from abc where id-rnk in (select (id-rnk) from abc group by(id-rnk) having count(*)>=3)
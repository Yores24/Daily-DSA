# Write your MySQL query statement below
select name from salesperson where name not in (select sp.name
from salesperson sp left join orders od on sp.sales_id=od.sales_id left join company c on c.com_id=od.com_id where c.name="RED")
SELECT round(sum(tiv_2016),2) as tiv_2016 
FROM insurance
WHERE (lat, lon) IN (
    SELECT lat, lon
    FROM insurance
    GROUP BY lat, lon
    HAVING COUNT(*) = 1
)and tiv_2015 in (select tiv_2015 from insurance group by tiv_2015 having count(pid)>1)


-- Define the CTEs
WITH abc AS (
    SELECT MAX(salary) AS sal, departmentId AS id
    FROM employee
    GROUP BY departmentId
),
abc2 AS (
    SELECT e.salary AS sal, e.name AS employeeName, e.departmentId AS did, d.name AS departmentName
    FROM employee e
    LEFT JOIN department d ON e.departmentId = d.id
)

-- Main query
SELECT abc2.departmentName AS Department, abc2.employeeName AS Employee, abc2.sal AS Salary
FROM abc
JOIN abc2 ON abc.sal = abc2.sal AND abc.id = abc2.did;

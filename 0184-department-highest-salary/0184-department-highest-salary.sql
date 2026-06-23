-- # Write your MySQL query statement below
-- select D.name as Department,E.name Employee, E.salary as Salary
-- from Department D
-- join Employee E
-- on D.id = E.departmentId
-- where E.salary = (
--     select max(salary) from Employee 
--     where departmentId = E.departmentId
-- );


-- Optimization
SELECT Department, Employee, Salary
FROM (
    SELECT d.name AS Department,
           e.name AS Employee,
           e.salary AS Salary,
           DENSE_RANK() OVER (
               PARTITION BY e.departmentId
               ORDER BY e.salary DESC
           ) AS rnk
    FROM Employee e
    JOIN Department d
    ON e.departmentId = d.id
) t
WHERE rnk = 1;

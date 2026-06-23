# Write your MySQL query statement below
select D.name as Department,E.name Employee, E.salary as Salary
from Department D
join Employee E
on D.id = E.departmentId
where E.salary = (
    select max(salary) from Employee 
    where departmentId = E.departmentId
);


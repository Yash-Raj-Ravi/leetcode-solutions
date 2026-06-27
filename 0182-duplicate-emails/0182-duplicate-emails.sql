# Write your MySQL query statement below
select Distinct E1.email as Email from Person E1
join Person E2 where E1.email=E2.email AND E1.id!=E2.id;

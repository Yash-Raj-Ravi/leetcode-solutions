# Write your MySQL query statement below
delete P1 from Person P1 join Person P2
where P1.id> P2.id AND P1.email=P2.email;
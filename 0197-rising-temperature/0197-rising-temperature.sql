# Write your MySQL query statement below
select W1.id from Weather W1
join Weather W2
where Datediff(w1.recordDate,W2.recordDate)=1 AND w1.temperature > w2.temperature;
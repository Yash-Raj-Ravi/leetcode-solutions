# Write your MySQL query statement below
select S.product_id,P.product_name from Sales S
join Product P 
on S.product_id=P.product_id
group by S.product_id
having min(sale_date)>="2019-01-01"  AND max(sale_date)<= "2019-03-31";
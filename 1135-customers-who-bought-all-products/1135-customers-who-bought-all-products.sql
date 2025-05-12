# Write your MySQL query statement below

select customer_id from (select Distinct * from Customer) as C group by customer_id having count(product_key) = (select count(*) from Product) 
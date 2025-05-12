# Write your MySQL query statement below
with LessDate as (
    select * from Products where change_date<= '2019-08-16' 
),Closedate as (
    select product_id, new_price as price from Products where change_date = (select max(change_date) from LessDate where Products.product_id = LessDate.product_id)
), 
unique_prod as (
select Distinct product_id from Products
)



select unique_prod.product_id as product_id , ifnull(price,10) as price from unique_prod Left join closedate on unique_prod.product_id = closedate.product_id;

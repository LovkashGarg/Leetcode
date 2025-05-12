# Write your MySQL query statement below
select Round(avg(First_order=customer_pref_delivery_date),4)*100.00 as immediate_percentage from (select customer_id, min(order_date) as First_order, MIN(customer_pref_delivery_date)  AS customer_pref_delivery_date from Delivery group by customer_id ) as T ;

# Write your MySQL query statement below
with first_year_product as (
    select product_id, min(year) as Year from Sales group by product_id
)

select f.product_id, f.Year as first_year, quantity , price  from first_year_product as f Left join Sales on f.product_id = Sales.product_id and f.Year = Sales.year; 





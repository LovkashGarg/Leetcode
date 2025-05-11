# Write your MySQL query statement below
select score, DENSE_RANK() over(order by score Desc) as 'rank' from Scores order by score Desc;



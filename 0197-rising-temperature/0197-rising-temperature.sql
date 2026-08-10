# Write your MySQL query statement below
select id 
from (
    select id ,
            recorddate,
           temperature ,
           lag(recorddate) over(order by recorddate) as prevdate,
           lag(temperature) over(order by recorddate) as prevtemp
    from weather
) w
where datediff(recordDate , prevdate) = 1 and temperature > prevtemp
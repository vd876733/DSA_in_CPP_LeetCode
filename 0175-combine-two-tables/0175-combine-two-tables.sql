# Write your MySQL query statement below
select p.LastName , p.firstName , a.city , a.state
from Person p
Left join Address a
On p.personId = a.personId
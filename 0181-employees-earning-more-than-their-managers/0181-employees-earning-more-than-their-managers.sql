-- # Write your MySQL query statement below
select e.name as Employee 
from Employee as e
where e.salary > (select m.salary from Employee as m where m.id = e.managerId)


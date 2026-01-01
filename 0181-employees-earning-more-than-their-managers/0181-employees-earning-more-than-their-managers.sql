# Write your MySQL query statement below
select e.name as Employee
from Employee e
where e.salary > (select m.salary from Employee m where m.id = e.managerId)
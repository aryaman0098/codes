-- Write your PostgreSQL query statement below
select 
    t.name,
    t.bonus
from (
    select 
        e.name,
        b.bonus
    from
        Employee e
    left join Bonus b
    on e.empId = b.empId
) as t
where t.bonus < 1000 or t.bonus is null;
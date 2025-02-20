select w1.id
from Weather as w1
where w1.temperature > (
    select w2.temperature
    from Weather as w2
    where age(w1.recordDate, w2.recordDate) = interval '1 day'
)
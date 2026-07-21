-- Write your PostgreSQL query statement below
SELECT today.id 
FROM Weather yesterday
CROSS JOIN Weather today
WHERE today.recorddate - yesterday.recorddate = 1
    AND today.temperature > yesterday.temperature;
-- SELECT today.id
-- FROM Weather today
-- JOIN Weather yesterday
-- ON today.recordDate - yesterday.recordDate = 1
-- WHERE today.temperature > yesterday.temperature;$0
# Write your MySQL query statement below



# SELECT x.id
# FROM (
#     SELECT t1.id, t1.temperature AS t1_temperature, t2.temperature AS t2_temperature
#     FROM Weather AS t1
#     INNER JOIN Weather AS t2 ON t1.id = t2.id + 1
#     WHERE t1.id IS NOT NULL AND t2.id IS NOT NULL AND t1.temperature < t2.temperature
# ) AS x;



SELECT w1.id
FROM Weather w1
JOIN Weather w2 ON w1.recordDate = w2.recordDate + INTERVAL 1 DAY
WHERE w1.temperature > w2.temperature;

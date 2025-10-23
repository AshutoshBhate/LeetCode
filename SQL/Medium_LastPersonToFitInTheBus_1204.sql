# Write your MySQL query statement below

WITH 
    Cummulative_Sum AS (
                        SELECT 
                            person_id, person_name, turn, SUM(weight) OVER (ORDER BY turn) as weightUntilNow
                        FROM 
                            Queue
                        )

SELECT 
    person_name 
FROM 
    Cummulative_Sum 
WHERE 
    weightUntilNow <= 1000 
ORDER BY 
    weightUntilNow DESC 
LIMIT 1;
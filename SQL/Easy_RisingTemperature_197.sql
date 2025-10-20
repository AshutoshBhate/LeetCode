SELECT 
    T1.id 
FROM 
    Weather as T1 
JOIN 
    Weather as T2 on datediff(T1.recordDate, T2.recordDate) = 1 
WHERE
    T1.temperature > T2.temperature;
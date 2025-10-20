SELECT 
    A_Start.machine_id, ROUND(AVG(A_End.timestamp - A_Start.timestamp), 3) AS processing_time 
FROM 
    Activity as A_Start 
JOIN 
    Activity as A_End 
ON
    A_Start.machine_id = A_End.machine_id AND A_Start.process_id = A_End.process_id AND A_Start.activity_type = 'start' AND A_End.activity_type = 'end' 
GROUP BY 
    A_Start.machine_id;
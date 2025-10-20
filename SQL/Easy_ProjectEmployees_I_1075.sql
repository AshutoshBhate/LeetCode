SELECT
    onjoin.project_id, ROUND(SUM(joined.experience_years)/COUNT(DISTINCT joined.employee_id), 2) AS average_years 
FROM 
    Project as onjoin 
JOIN 
    Employee as joined 
ON 
    onjoin.employee_id = joined.employee_id 
GROUP BY
    project_id;
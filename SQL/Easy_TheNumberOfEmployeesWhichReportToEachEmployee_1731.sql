SELECT 
    joinby.employee_id, joinby.name, COUNT(joinby.employee_id) as reports_count, ROUND(AVG(jointo.age), 0) as average_age
FROM
    Employees as jointo
INNER JOIN
    Employees as joinby
ON
    jointo.reports_to = joinby.employee_id
GROUP BY
    joinby.employee_id
ORDER BY 
    joinby.employee_id ASC;
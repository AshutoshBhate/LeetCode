SELECT 
    E1.name 
FROM 
    Employee as E1 
JOIN
    Employee as E2 on E1.id = E2.managerId 
GROUP BY
    E1.id, E1.name 
HAVING
    count(E2.id) > 4;
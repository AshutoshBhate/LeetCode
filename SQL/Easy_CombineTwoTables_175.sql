SELECT
    P.firstname, P.lastName, A.city, A.state 
FROM 
    Person as P 
LEFT OUTER JOIN 
    Address 
AS 
    A 
ON 
    P.personId = A.personId;
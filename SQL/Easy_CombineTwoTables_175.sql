select 
    P.firstname, P.lastName, A.city, A.state 
from 
    Person as P 
left outer join 
    Address as A 
on 
    P.personId = A.personId;
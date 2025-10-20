SELECT 
    customer_id, COUNT(customer_id) AS count_no_trans 
FROM 
    Visits 
LEFT JOIN 
    Transactions on Visits.visit_id = Transactions.visit_id where Transactions.visit_id is NULL 
GROUP BY 
    Visits.customer_id;
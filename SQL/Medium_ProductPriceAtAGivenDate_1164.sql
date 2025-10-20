SELECT 
    jointo.product_id AS product_id, jointo.new_price AS price
FROM 
    Products AS jointo
RIGHT JOIN 
    (SELECT joinby.product_id AS O_product_id, MAX(joinby.change_date) AS O_price
    FROM Products AS joinby
    WHERE change_date <= "2019-08-16"
    GROUP BY product_id) AS random_name
ON 
    jointo.change_date = random_name.O_price AND jointo.product_id = random_name.O_product_id
    
UNION

SELECT 
    product_id, 10 AS price
FROM 
    Products
WHERE 
    product_id NOT IN (
        SELECT 
            product_id
        FROM 
            Products
        WHERE 
            change_date <= "2019-08-16"
        GROUP BY 
            product_id
    );
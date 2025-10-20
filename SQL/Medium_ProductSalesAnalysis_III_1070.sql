SELECT
    og_Sales.product_id, og_Sales.year AS first_year, og_Sales.quantity, og_Sales.price
FROM
    Sales as og_Sales
JOIN
    (SELECT
        MIN(year) AS df_year, product_id AS df_product_id
    FROM
        Sales
    GROUP BY
        product_id) AS df_Sales
ON
    og_Sales.year = df_Sales.df_year AND og_Sales.product_id = df_Sales.df_product_id;
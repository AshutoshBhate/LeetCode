SELECT
    ROUND(SUM(CASE WHEN order_date = customer_pref_delivery_date THEN 1 ELSE 0 END) * 100/COUNT(customer_id), 2) AS immediate_percentage
FROM
    Delivery AS D_og
JOIN
    (SELECT
        customer_id AS customer_id_fg, MIN(order_date) AS order_date_fg
    FROM
        Delivery
    GROUP BY
        customer_id) AS D_fg
ON
    D_og.order_date = D_fg.order_date_fg AND D_og.customer_id = D_fg.customer_id_fg;
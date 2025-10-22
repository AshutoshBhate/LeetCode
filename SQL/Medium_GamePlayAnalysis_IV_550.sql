SELECT
    ROUND(
        COUNT(T2.player_id) / COUNT(T_first.player_id), 
        2
    ) AS fraction
FROM 
    (
        SELECT 
            player_id, 
            MIN(event_date) AS first_login_date
        FROM 
            Activity
        GROUP BY 
            player_id
    ) AS T_first
LEFT JOIN 
    Activity AS T2 
    ON T_first.player_id = T2.player_id 
    AND T2.event_date = DATE_ADD(T_first.first_login_date, INTERVAL 1 DAY);
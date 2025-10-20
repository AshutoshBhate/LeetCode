SELECT 
    Original.user_id, IFNULL(ROUND(COUNT(DISTINCT Con_Confirmed.time_stamp)/(COUNT(DISTINCT Con_Confirmed.time_stamp) + COUNT(DISTINCT Con_Timeout.time_stamp)), 2), 0) as confirmation_rate
FROM
    Signups as Original
LEFT JOIN 
    Confirmations as Con_Timeout on Original.user_id = Con_Timeout.user_id AND Con_Timeout.action = 'timeout' 
LEFT JOIN 
    Confirmations as Con_Confirmed on Original.user_id = Con_Confirmed.user_id AND Con_Confirmed.action = 'confirmed' 
GROUP BY 
    Original.user_id
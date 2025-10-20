SELECT 
    contest_id, ROUND((COUNT(DISTINCT Register.user_id)/(SELECT COUNT(user_id) FROM Users))*100 , 2) AS percentage
FROM
    Register
GROUP BY
    Register.contest_id
ORDER BY
    percentage DESC, Register.contest_id ASC;
SELECT
    MAX(num) as num
FROM
    (SELECT
        num
    FROM
        MyNumbers
    GROUP BY
        num
    HAVING
        COUNT(num) < 2
    ORDER BY
        num DESC) AS UniqueNumbers;
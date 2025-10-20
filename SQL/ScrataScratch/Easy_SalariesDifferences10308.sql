SELECT 
    ABS(MAX(CASE WHEN occupation.department = 'engineering' THEN main.salary END) - 
        MAX(CASE WHEN occupation.department = 'marketing' THEN main.salary END)
        ) AS salary_difference
FROM
    db_employee as main 
JOIN 
    db_dept as occupation 
ON 
    main.department_id = occupation.id;
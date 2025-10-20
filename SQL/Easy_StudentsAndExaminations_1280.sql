SELECT 
    St.student_id, St.student_name, Su.subject_name, COUNT(Ex.student_id) as attended_exams
FROM
    Students as St 
CROSS JOIN
    Subjects as Su
LEFT OUTER JOIN
    Examinations as Ex on St.student_id = Ex.student_id AND Ex.subject_name = Su.subject_name
GROUP BY 
    St.student_id, Su.subject_name
ORDER BY 
    St.student_id asc;

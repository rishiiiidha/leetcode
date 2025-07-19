# Write your MySQL query statement below

with rankedSeries AS (
    SELECT salary, departmentId, DENSE_RANK() OVER(PARTITION BY departmentId ORDER BY salary DESC) as Id FROM  Employee 
)


SELECT d.name AS Department, e.name AS Employee, e.salary AS Salary FROM Employee e JOIN Department d ON e.departmentId = d.id  WHERE (e.salary,e.departmentId) IN (SELECT salary,departmentId FROM rankedSeries where id<=3);
# Write your MySQL query statement below
SELECT DISTINCT l1.num as ConsecutiveNums  from Logs l1, Logs l2, Logs l3 where l1.num = l2.num AND l2.num = l3.num AND l3.id = l2.id+1 AND l2.id = l1.id+1; 
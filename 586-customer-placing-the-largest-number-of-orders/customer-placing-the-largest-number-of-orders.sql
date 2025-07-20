# Write your MySQL query statement below
WITH new_table AS(
SELECT COUNT(order_number) as cnt, customer_number FROM Orders GROUP BY customer_number)

SELECT customer_number from new_table ORDER BY cnt DESC LIMIT 1;
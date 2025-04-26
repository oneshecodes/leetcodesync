# Write your MySQL query statement below
SELECT c.name as Customers
FROM customers c 
WHERE c.id NOT IN (SELECT o.customerId FROM orders o);
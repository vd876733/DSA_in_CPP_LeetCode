# Write your MySQL query statement below
-- Write your PostgreSQL query statement below
# Write your MySQL query statement below
SELECT *
FROM products
WHERE REGEXP_LIKE(
    description,
    '\\bSN[0-9]{4}-[0-9]{4}\\b',
    'c'
)
ORDER BY product_id;
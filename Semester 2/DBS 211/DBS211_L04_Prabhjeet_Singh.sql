-- ***********************
-- Name: Prabhjeet Singh
-- ID: 127024214
-- Date: 10 FEB 2022
-- Purpose: Lab 04 DBS211
-- ***********************

-- Q1 SOLUTION --
SELECT customernumber,   --1
       customername,     --2
      TO_CHAR(paymentdate,'Mon DD, YYYY') AS "PAYMENT DATE",  --3
       amount  --4
FROM payments JOIN customers
USING (customernumber)
WHERE country = 'Canada'
ORDER BY 1;
           
--Q2 SOLUTION--
SELECT  DISTINCT employeenumber,      --1
       firstname || ' ' || lastname AS "EMPLOYEE FULL NAME",   --2
       email                --3
FROM employees e LEFT JOIN customers c
ON e.employeenumber = c.salesrepemployeenumber
WHERE salesrepemployeenumber  IS NULL
ORDER BY 2;


--Q3 SOLUTION--
CREATE VIEW vw_customer_order AS
SELECT customernumber,
       ordernumber,
       orderdate,
       productname,
       quantityordered,
       priceeach
FROM customers JOIN orders
USING(customernumber)
JOIN orderdetails
USING(ordernumber)
JOIN products
USING(productcode);

--Q4 SOLUTION--
SELECT *
FROM vw_customer_order
JOIN orderdetails
USING(ordernumber)
WHERE customernumber = 124
ORDER BY ordernumber,
orderlinenumber;

--Q5 SOLUTION--
SELECT customernumber,
       contactfirstname,
       contactlastname,
       phone,
       creditlimit
FROM customers
WHERE NOT EXISTS (
    SELECT 0
    FROM orders
    WHERE orders.customernumber = customers.customernumber
)
ORDER BY 1;

--Q6 SOLUTION--
CREATE VIEW vw_employee_manager AS
SELECT e1.employeenumber,
       e1.lastname,
       e1.firstname,
       e1.extension,
       e1.email,
       e1.officecode,
       e1.reportsto,
       e1.jobtitle,
       e2.firstname || ' ' || e2.lastname AS Manager
FROM employees e1
LEFT JOIN employees e2
ON e1.reportsto = e2.employeenumber;

--Q7 SOLUTION--
CREATE OR REPLACE VIEW vw_employee_manager AS 
SELECT e1.employeenumber,
       e1.lastname,
       e1.firstname,
       e1.extension,
       e1.email,
       e1.officecode,
       e1.reportsto,
       e1.jobtitle,
       e2.firstname || ' ' || e2.lastname AS Manager
FROM employees e1
LEFT JOIN employees e2
ON e1.reportsto = e2.employeenumber
WHERE e1.reportsto IS NOT NULL;

--Q8 SOLUTION--
DROP VIEW vw_employee_manager;
DROP VIEW vw_customer_order;
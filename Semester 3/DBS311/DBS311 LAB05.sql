--------------------------------------------(ANSWER 1)
SELECT officecode AS "Office Code",city AS "City",
CASE
WHEN state = 'CA' THEN 'California'
   WHEN state = 'NY' THEN 'New York'
   WHEN state IS NULL THEN 'Outside of USA'
   ELSE state
END AS "State"
FROM offices;
         
----------------------------------------------------------------------------------------------------------------------(ANSWER 2)
SELECT customers.customernumber,
       customers.customerName,CONCAT('$',FORMAT(t2.totalinvoices,2)) AS "Total Invoices",
       CONCAT('$',FORMAT(t1.totalpayments,2)) AS "Total Payments",
       CONCAT('$',FORMAT(t2.totalinvoices - t1.totalpayments,2)) AS "Outstanding Balance",
CASE
WHEN (t2.totalinvoices - t1.totalpayments) > 100000 THEN 'On Hold'
   WHEN (t2.totalinvoices - t1.totalpayments) BETWEEN 50000 AND 100000 THEN 'New purchases must be paid in advance'
   ELSE 'Must get a 50% deposit on new orders'
END AS "Status"
FROM customers
INNER JOIN (SELECT customernumber,SUM(amount) AS totalpayments
FROM payments
GROUP BY customernumber) t1 ON customers.customernumber = t1.customernumber
INNER JOIN (SELECT customernumber,SUM(quantityordered * priceeach) AS totalinvoices
FROM orders
INNER JOIN orderdetails ON orders.orderNumber = orderdetails.orderNumber
GROUP BY customernumber)  t2 ON customers.customerNumber = t2.customerNumber
WHERE (t2.totalinvoices - t1.totalpayments) > 0
ORDER BY (t2.totalinvoices - t1.totalpayments) DESC;

-------------------------------------------------------------------------------------------------------------------------------
SELECT c.customerNumber,
         customerName,
         TotalOrderValue as "TOTAL Invoices",
         TotalPayment-TotalOrderValue As "Outstanding Balance",
         TotalPayment,
         CASE WHEN TotalPayment-TotalOrderValue = 100000 then 'On Hold'
WHEN TotalPayment-TotalOrderValue between 50000 and 100000 THEN 'New purchases must be paid in advance'
WHEN TotalPayment-TotalOrderValue between 0 and 50000 THEN 'Must get a 50% deposit on new orders' else 'OverLimit' end Status
FROM customers c JOIN (
SELECT customernumber,count(customernumber) as totalOrderValue FROM orderdetails od JOIN orders o
ON od.orderNumber=o.orderNumber 
GROUP BY customerNumber)m 
ON c.customerNumber=m.customerNumber;


---------------------------------------------------------------------------------
SELECT c.customerNumber,
         customerName,
          TO_CHAR(SUM(priceeach * quantityordered), 'L999G999D99' ,'NLS_CURRENCY = ''$''  NLS_ISO_CURRENCY = Canada')  AS "Total_Invoices" ,
       TO_CHAR(SUM(amount),  'L999G999D99' ,'NLS_CURRENCY = ''$''  NLS_ISO_CURRENCY = Canada') AS "Total_Payments",
       TO_CHAR(SUM(priceeach * quantityordered),'L999G999D99' ,'NLS_CURRENCY = ''$''  NLS_ISO_CURRENCY = Canada')  - TO_CHAR(SUM(amount), 'L999G999D99' ,'NLS_CURRENCY = ''$''  NLS_ISO_CURRENCY = Canada') AS "Outstanding Balance"
         CASE WHEN Total_Invoices-Total_Payments = 100000 then 'On Hold'
WHEN Total_Invoices-Total_Paymentse between 50000 and 100000 THEN 'New purchases must be paid in advance'
WHEN Total_Invoices-Total_Payments between 0 and 50000 THEN 'Must get a 50% deposit on new orders' else 'OverLimit' end Status
FROM customers c
JOIN orders ON orders.customernumber = c.customernumber
JOIN orderdetails od ON od.ordernumber = orders.ordernumber
GROUP BY c.customername
ORDER BY 4 DESC;
SELECT MAX(priceeach * quantityordered) AS "Highest Invoice Total"
FROM orderdetails;

-----------------------------
SELECT customers.customername AS "Customer Name"
FROM customers
WHERE customers.customernumber IN (SELECT orders.customernumber
FROM orderdetails
JOIN orders ON orders.ordernumber = orderdetails.ordernumber
GROUP BY orders.customernumber
ORDER BY MAX(orderdetails.priceeach * orderdetails.quantityordered) DESC
FETCH FIRST 1 ROWS ONLY);
--------------------------------------------------
SELECT customers.customername AS "Customer Name",   ----1 
        MAX(orderdetails.priceeach * orderdetails.quantityordered) AS "Invoice_Amount"    ----2
FROM customers
JOIN orders ON orders.customernumber = customers.customernumber
JOIN orderdetails  ON orderdetails.ordernumber = orders.ordernumber
GROUP BY customers.customername
ORDER BY 2 DESC
FETCH FIRST 1 ROWS ONLY;
---------------------------------------------------- (TRY) 4TH  
SELECT customers.customername,
TO_CHAR(SUM(orderdetails.priceeach * orderdetails.quantityordered),'L999G999D99' ,'NLS_CURRENCY = ''$'' NLS_ISO_CURRENCY =Canada') AS "Total_Invoices"   ---1
TO_CHAR((SELECT SUM(amount) --2
FROM payments JOIN customers ON payments.customernumber = customers.customernumber
WHERE customers.customername = customers.customername),'L999G999D99' , 'NLS_CURRENCY = ''$''  NLS_ISO_CURRENCY = Canada') AS "Total Payments",
TO_CHAR((SUM(orderdetails.priceeach * orderdetails.quantityordered)  ---3
(SELECT SUM(amount) ---4
FROM payments JOIN customers 
ON payments.customernumber = customers.customernumber
WHERE customers.customername = customers.customername)),'L999G999D99' , 'NLS_CURRENCY = ''$''  NLS_ISO_CURRENCY = Canada') AS "Outstanding Balance"
FROM customers 
JOIN orders ON orders.customernumber = customers.customernumber
JOIN orderdetails  ON orderdetails.ordernumber = orders.ordernumber
GROUP BY customers.customername
ORDER BY 4 DESC;

---------------------------------------------------------------------------- (2ND TRY)
SELECT customername AS "Customer",
       TO_CHAR(SUM(orderdetails.priceeach * orderdetails.quantityordered),  'L999G999' ,'NLS_CURRENCY = ''$''  NLS_ISO_CURRENCY = Canada'), AS "Total Invoices",
       TO_CHAR((
       SELECT SUM(amount)
       FROM payments JOIN customers ON
       payments.customernumber = customers.customernumber), 'L999G999' ,'NLS_CURRENCY = ''$''  NLS_ISO_CURRENCY = Canada'), AS "Total Payments",
       TO_CHAR(SUM(orderdetails.priceeach * orderdetails.quantityordered) - TO_CHAR((
       SELECT SUM(amount))
       FROM payments JOIN customers ON
       payments.customernumber = customers.customernumber),  'L999G999' ,'NLS_CURRENCY = ''$''  NLS_ISO_CURRENCY = Canada') AS "Outstanding Balances"
       FROM customers 
JOIN orders ON orders.customernumber = customers.customernumber
JOIN orderdetails  ON od.ordernumber = orders.ordernumber
GROUP BY customers.customername;









-----------------------------------   (3RD TRY)
SELECT c.customername,
TO_CHAR(SUM(od.priceeach * od.quantityordered),'L999G999D99') AS "Total Invoices", 
TO_CHAR((SELECT SUM(amount) FROM payments JOIN customers ON payments.customernumber = customers.customernumber
WHERE customers.customername = c.customername),'L999G999D99') AS "Total Payments",
TO_CHAR((SUM(od.priceeach * od.quantityordered)- (SELECT SUM(amount) FROM payments JOIN customers 
ON payments.customernumber = customers.customernumber
WHERE customers.customername = c.customername)),'L999G999D99') AS "Outstanding Balance"
FROM customers c
JOIN orders ON orders.customernumber = c.customernumber
JOIN orderdetails od ON od.ordernumber = orders.ordernumber
GROUP BY c.customername
ORDER BY 4 DESC;


---------------------------------------------------   (4TH TRY)
SELECT customername,
       TO_CHAR(SUM(priceeach * quantityordered), 'L999G999D99' ,'NLS_CURRENCY = ''$''  NLS_ISO_CURRENCY = Canada') AS "Total_Invoices",
       TO_CHAR(SUM(amount),  'L999G999D99' ,'NLS_CURRENCY = ''$''  NLS_ISO_CURRENCY = Canada') AS "Total_Payments",
       TO_CHAR(SUM(priceeach * quantityordered),'L999G999D99' ,'NLS_CURRENCY = ''$''  NLS_ISO_CURRENCY = Canada')  - TO_CHAR(SUM(amount), 'L999G999D99' ,'NLS_CURRENCY = ''$''  NLS_ISO_CURRENCY = Canada') AS "Outstanding Balance"
FROM customers
JOIN orders ON customers.customernumber = orders.customernumber
JOIN orderdetails ON orders.ordernumber = orderdetails.ordernumber
JOIN payments ON customers.customernumber = payments.customernumber
GROUP BY customername;


-------------------------------------------------------- (FINAL TRY)
SELECT c.customername,
TO_CHAR(SUM(od.priceeach * od.quantityordered),'L999G999D99' 'NLS_CURRENCY = ''$''  NLS_ISO_CURRENCY = Canada' ) AS "Total Invoices", 
TO_CHAR((SELECT SUM(amount) FROM payments JOIN customers ON payments.customernumber = customers.customernumber
WHERE customers.customername = c.customername),'L999G999D99' 'NLS_CURRENCY = ''$''  NLS_ISO_CURRENCY = Canada') AS "Total Payments",
TO_CHAR((SUM(od.priceeach * od.quantityordered)- (SELECT SUM(amount) FROM payments JOIN customers 
ON payments.customernumber = customers.customernumber
WHERE customers.customername = c.customername)),'L999G999D99' 'NLS_CURRENCY = ''$''  NLS_ISO_CURRENCY = Canada') AS "Outstanding Balance"
FROM customers c
JOIN orders ON orders.customernumber = c.customernumber
JOIN orderdetails od ON od.ordernumber = orders.ordernumber
GROUP BY c.customername
ORDER BY 4 DESC;
       







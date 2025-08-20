-----
SELECT ROUND (AVG(priceeach * quantity ordered), 2)
FROM orderdetails;


---------------
SELECT productlines.productline,
      COUNT(products.productcode) AS "TOTAL PRODUCTS"
FROM productlines
JOIN products ON products.productlineid = productlines.productlineid
GROUP BY productline
ORDER BY count(productname) DESC;

--------------------------------------------
SELECT productlines.productline,
      COUNT(products.productcode) AS "TOTAL PRODUCTS"
FROM productlines
JOIN products ON products.productlineid = productlines.productlineid
GROUP BY productline
HAVING count(products.productcode) >=12
ORDER BY count(productname) DESC;

--------------------------------------------
SELECT orders.ordernumber,
       orders.orderdate,
       SUM(orderdetails.priceeach) AS "ORDER_TOTAL_AMOUNT"
FROM orders,orderdetails
WHERE orders.ordernumber = orderdetails.ordernumber
GROUP BY orders.ordernumber, orders.orderdate
ORDER BY orders.orderdate DESC,
         ORDER_TOTAL_AMOUNT DESC;
         
----------------------------------------------
SELECT customers.customernumber,
       customers.customername,
       TO_CHAR(ROUND(SUM(orderdetails.priceeach * quantityordered), 0), 'L999G999' ,'NLS_CURRENCY = ''$''  NLS_ISO_CURRENCY = Canada') AS "ORDER_TOTAL_AMOUNT",
       COUNT(orders.ordernumber) AS "TOTAL ORDERS"
FROM customers
JOIN orders ON orders.customernumber = customers.customernumber
JOIN orderdetails ON orders.ordernumber = orderdetails.ordernumber
WHERE orders.customernumber = customers.customernumber
GROUP BY customers.customernumber,
         customers.customername
         ORDER BY "ORDER_TOTAL_AMOUNT" DESC;
      


-------------------------------------------------






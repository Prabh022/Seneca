SELECT customernumber
FROM customers
ORDER BY customernumber ASC;
--LIMIT 10; (Add these line if needs to limit rows to 10)
 /*
OUTPUT
CUSTOMERNUMBER
--------------
           103
           112
           114
           119
           121
           124
           125
           128
           129
           131
*/
--------------------------------------------------------------
SELECT customernumber
FROM customers
INTERSECT
SELECT customernumber
FROM orders
ORDER BY customernumber ASC;
--LIMIT 10; (Add these line if needs to limit rows to 10)
 /*
OUTPUT
CUSTOMERNUMBER
--------------
           103
           112
           114
           119
           121
           124
           128
           129
           131
           141
*/
--------------------------------------------------------------

SELECT customernumber
FROM customers
MINUS
SELECT customernumber
FROM orders
ORDER BY customernumber ASC;
--LIMIT 10; (Add these line if needs to limit rows to 10)
/*
OUTPUT
CUSTOMERNUMBER
--------------
           125
           168
           169
           206
           223
           237
           247
           273
           293
           303
EXPLANATION-
The MINUS set operator is used in the query in question 3 so that all of the customers who have never placed an order will be
returned. First, all of the customer numbers are taken from the customers table and selected by the query. The MINUS operator 
is then utilized to clear out any and all customer numbers that are already present in the orders database, leaving behind only
those customer numbers that are absent from the orders table. The results are subsequently sorted, in ascending order by 
customer number, and the number of total results is capped at 10.
*/
-------------------------------------------
SELECT customernumber, contactlastname, contactfirstname
FROM customers
WHERE customernumber IN
(SELECT customernumber
FROM customers
MINUS
SELECT customernumber
FROM orders)
ORDER BY customernumber ASC;
/*
OUTPUT
CUSTOMERNUMBER CONTACTLASTNAME                                    CONTACTFIRSTNAME                                  
-------------- -------------------------------------------------- --------------------------------------------------
           125 Piestrzeniewicz                                    Zbyszek                                           
           168 Franco                                             Keith                                             
           169 de Castro                                          Isabel                                            
           206 Walker                                             Brydey                                            
           223 Kloss                                              Horst                                             
           237 Camino                                             Alejandra                                         
           247 Messner                                            Renate                                            
           273 Franken                                            Peter                                             
           293 Harrison                                           Ed                                                
           303 Schuyler                                           Bradley           
EXPLANATION- 
The MINUS set operator is used in the query in question 3 so that all of the customers who have never placed an order will be 
returned. First, all of the customer numbers are taken from the customers table and selected by the query. The MINUS operator is
then utilized to clear out any and all customer numbers that are already present in the orders database, leaving behind only 
those customer numbers that are absent from the orders table. The results are subsequently sorted, in ascending order by 
customer number, and the number of total results is capped at 10.
*/

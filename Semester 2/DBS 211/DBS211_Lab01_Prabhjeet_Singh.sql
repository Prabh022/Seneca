--ANSWER 1
CUSTOMERNUMBER: 103
CUSTOMERNAME: Atelier graphique
CONTACTLASTNAME: Schmitt
CONTACTFIRSTNAME: Carine
PHONE: 40.32.2555
ADDRESSLINE1: 54, rueRoyale
ADDRESSLINE2: NULL
CITY: Nantes
STATE: NULL
POSTALCODE: 44000
COUNTRY: France
SALESREPEMPLOYEENUMBER: 1370
CREDITLIMIT: 21000.00

--ANSWER 2
Table Name     Rows     Columns
CUSTOMERS       122        13
EMPLOYEES       23         8
OFFICES         7          9
ORDERDETAILS    2996       5
ORDERS          326        6
PAYMENTS        273        4
PRODUCTLINES    7          4
PRODUCTS        110        9

--ANSWER 3
SQL> describe offices;
Name         Null?    Type         
------------ -------- ------------ 
OFFICECODE   NOT NULL VARCHAR2(10) 
CITY         NOT NULL VARCHAR2(50) 
PHONE        NOT NULL VARCHAR2(50) 
ADDRESSLINE1 NOT NULL VARCHAR2(50) 
ADDRESSLINE2          VARCHAR2(50) 
STATE                 VARCHAR2(50) 
COUNTRY      NOT NULL VARCHAR2(50) 
POSTALCODE   NOT NULL VARCHAR2(15) 
TERRITORY    NOT NULL VARCHAR2(10) 

--ANSWER 4
When we run the script SELECT * FROM employee; it printed the whole details of
the employees in an ascending order of EMPLOYEENUMBER, however in the case of 
SELECT * FROM customers ORDER BY ContactLastName; script it have printed the 
all details of the customers but in an ascending order of Contact Last name and 
started with that customers from A to most descending letter.

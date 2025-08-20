-- ***********************
-- Name: Prabhjeet Singh
-- ID: 127024214
-- Date: 31 JAN 2022
-- Purpose: Lab 03 DBS211
-- ***********************

SET AUTOCOMMIT ON;

-- Q1 SOLUTION --
INSERT INTO employees2
SELECT *
FROM employees;

-- Q2 SOLUTION –
INSERT INTO employees2(employeenumber,
            lastname,
            firstname,
            extension,
            email,
            officecode,
            reportsto,
            jobtitle)
VALUES(1703,
        'Singh',
        'Prabhjeet',
        'x2222',
        'prabhjeet-singh3@myseneca.ca',
         4,
        '1088',
        'Head Cashier');
    
--Q3 SOLUTION --
INSERT INTO employees2(employeenumber,
            lastname,
            firstname,
            extension,
            email,
            officecode,
            reportsto,
            jobtitle)
VALUES(1704,
        'Singh',
        'Rajwinder',
        'x6548',
        'rajsingh58242@gamil.com',
         4,
        '1703',
        'Cashier');
        
-- Q4 SOLUTION --
DELETE FROM employees2
WHERE firstname = 'Prabhjeet';
-- No it didn't work as it showed a error report - ORA-02292: integrity constraint (DBS211_221ZB23.SYS_C001913984) violated - child record found
-- As we are assigned as a reportsto one employee which we created.

--Q5 SOLUTION --
DELETE FROM employees2
WHERE firstname = 'Rajwinder';
DELETE FROM employees2
WHERE firstname = 'Prabhjeet';
-- Yes, now it is deleted because now no one is linked to us through reportsto us. So it was now deleted.

--Q6 SOLUTION --
INSERT ALL
INTO employees2 VALUES(1703,
        'Singh',
        'Prabhjeet',
        'x2222',
        'prabhjeet-singh3@myseneca.ca',
         4,
        '1088',
        'Head Cashier')
    INTO employees2 VALUES(1704,
        'Singh',
        'Rajwinder',
        'x6548',
        'rajsingh58242@gamil.com',
         4,
        '1088',
        'Cashier')
        SELECT *
        FROM dual;

--Q7 SOLUTION --
DELETE FROM employees2
WHERE lastname = 'Singh'
AND reportsto = 1088
AND officecode = 4;

--Q8 SOLUTION --
UPDATE employees2
SET firstname = 'Prabhjeet',
    lastname = 'Singh'
WHERE employeenumber = 1002;

--Q9 SOLUTION --
DELETE FROM employees2;



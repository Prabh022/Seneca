-- ***********************
-- Name: Prabhjeet Singh
-- ID: 127024214
-- Date: 21 FEB 2022
-- Purpose: Lab 06 DBS211
-- ***********************
--PART A TRANSACTIONS --
-- Q1 SOLUTION --
CREATE TABLE new_employees AS
(SELECT *
FROM employees
WHERE 1=2);

--Q2 SOLUTION--
SET AUTOCOMMIT OFF;
SET TRANSACTION READ WRITE;

--Q3 SOLUTION--
INSERT ALL
  INTO new_employees VALUES (100, 'Patel', 'Ralph', 22333, 'rpatel@mail.com', 1, NULL, 'Sales Rep')
  INTO new_employees VALUES (101, 'Denis', 'Betty', 33444, 'bdenis@mail.com', 4, NULL, 'Sales Rep')
  INTO new_employees VALUES (102, 'Biri', 'Ben', 44555, 'bbirir@mail.com', 2, NULL, 'Sales Rep')
  INTO new_employees VALUES (103, 'Newman', 'Chad', 66777, 'cnewman@mail.com', 3, NULL, 'SalesRep')
  INTO new_employees VALUES (104, 'Ropeburn', 'Audrey', 77888, 'aropebur@mail.com', 1, NULL, 'Sales Rep')
SELECT * FROM dual;

--Q4 SOLUTION--
SELECT * FROM new_employees 
WHERE employeenumber BETWEEN 100 AND 104;
-- number of rows are selected:  5

--Q5 SOLUTION--
ROLLBACK;
SELECT * FROM new_employees;
-- number of rows are selected:  23
--Q6 SOLUTION--
INSERT INTO new_employees
SELECT *
FROM employees;
COMMIT;
 
--23 rows are selected

--Q7 SOLUTION--
UPDATE new_employees
SET jobtitle = 'Unknown';

--Q8 SOLUTION--
SELECT *
FROM new_employees;
COMMIT;

--Q9 SOLUTION--
-- a--
SELECT *
FROM new_employees;
ROLLBACK;

-- ALL rows are still having jobtitle unknown as committ was done before so rollback didnt did anything as nothing was in buffer

-- b --
-- No, revert was not effective was commit was done before so nothing was in buffer zone, so rollback cant revert anything.

-- c --
-- The difference between this revert compared to task 5 as in task 5 commit was not done so, all those changes were in  bufferzone as changes were temporary, so , it was reverted, however here, commit was done, so nothing was in bufferzone and commit make changes permanent.

--Q10 SOLUTION --
BEGIN
DELETE 
FROM new_employees
WHERE jobtitle = 'Unknown';
END;

--Q11 SOLUTION --
CREATE VIEW vw_new_emps AS
SELECT *
FROM new_employees
ORDER BY lastname,
         firstname;

--Q12 SOLUTION --
 --a--
 ROLLBACK;
SELECT * FROM new_employees;
 -- Now there are no employees in the ne_employees table.
 
 -- b --
 --No deletion was not undone,  As here END means it will commit, which means all the changes were permanent which we cant revert back.
 
 -- Q13 SOLUTION --
 BEGIN
 INSERT ALL
  INTO new_employees VALUES (100, 'Patel', 'Ralph', 22333, 'rpatel@mail.com', 1, NULL, 'Sales Rep')
  INTO new_employees VALUES (101, 'Denis', 'Betty', 33444, 'bdenis@mail.com', 4, NULL, 'Sales Rep')
  INTO new_employees VALUES (102, 'Biri', 'Ben', 44555, 'bbirir@mail.com', 2, NULL, 'Sales Rep')
  INTO new_employees VALUES (103, 'Newman', 'Chad', 66777, 'cnewman@mail.com', 3, NULL, 'SalesRep')
  INTO new_employees VALUES (104, 'Ropeburn', 'Audrey', 77888, 'aropebur@mail.com', 1, NULL, 'Sales Rep')
SELECT * FROM dual;
END;

-- Q14 SOLUTION --
SAVEPOINT A;

-- Q15 SOLUTION --
UPDATE new_employees
SET jobtitle = 'Unknown';

--Q16 SOLUTION --
SELECT *
FROM new_employees;
ROLLBACK TO A;
-- When i undo the transaction upto savepoint and fetched the data it was still there as savepoint was created as jobtitle updation was donw after savepoint created so it was reseted.

-- Q17 SOLUTION --
SELECT *
FROM new_employees;
ROLLBACK;
-- The difference in this data was that here jobtitle of all 23 rows is Unknown.

-- PART B --
-- Q18 SOLUTION --
REVOKE ALL ON new_employees FROM public;

--Q19 SOLUTION --
GRANT READ ON new_employees TO dbs211_221i44;

--Q20 SOLUTION --
GRANT INSERT,UPDATE,DELETE ON new_employees TO dbs211_221i44;

--Q21 SOLUTION --
REVOKE ALL ON new_employees FROM dbs211_221i44;

--Q22 SOLUTION --
DROP TABLE new_employees;
DROP VIEW vw_new_emps;
COMMIT;
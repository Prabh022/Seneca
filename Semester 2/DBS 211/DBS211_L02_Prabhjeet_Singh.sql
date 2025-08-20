-- ***********************
-- Name: Prabhjeet Singh
-- ID: 127024214
-- Date: 26- JAN - 2022
-- Purpose: Lab 02 DBS211
-- ***********************

-- Q1 SOLUTION --
 SELECT officecode,
        city,
        state,
        country,
        phone
        FROM offices;
--OUTPUT
OFFICECODE CITY                                               STATE                                              COUNTRY                                            PHONE                                             
---------- -------------------------------------------------- -------------------------------------------------- -------------------------------------------------- --------------------------------------------------
1          San Francisco                                      CA                                                 USA                                                +1 650 219 4782                                   
2          Boston                                             MA                                                 USA                                                +1 215 837 0825                                   
3          NYC                                                NY                                                 USA                                                +1 212 555 3000                                   
4          Paris                                                                                                 France                                             +33 14 723 4404                                   
5          Tokyo                                              Chiyoda-Ku                                         Japan                                              +81 33 224 5000                                   
6          Sydney                                                                                                Australia                                          +61 2 9264 2451                                   
7          London                                                                                                UK                                                 +44 20 7877 2041                                  

--Q2 SOLUTION --
SELECT employeenumber, --1
       firstname,      --2
       lastname,       --3
       extension       --4
       FROM employees
       where officecode = 1
       ORDER BY 1;
--OUTPUT
EMPLOYEENUMBER FIRSTNAME                                          LASTNAME                                           EXTENSION 
-------------- -------------------------------------------------- -------------------------------------------------- ----------
          1002 Diane                                              Murphy                                             x5800     
          1056 Mary                                               Patterson                                          x4611     
          1076 Jeff                                               Firrelli                                           x9273     
          1143 Anthony                                            Bow                                                x5428     
          1165 Leslie                                             Jennings                                           x3291     
          1166 Leslie                                             Thompson                                           x4065     

--Q3 SOLUTION --
SELECT customernumber,  --1
       customername,    --2 
       contactlastname || ', ' || contactfirstname AS "Customer Name",  --3
       phone  --4
       FROM customers
       where country = 'Canada'
       ORDER BY 2;
--OUTPUT 
CUSTOMERNUMBER CUSTOMERNAME                                       Customer Name                                                                                          PHONE                                             
-------------- -------------------------------------------------- ------------------------------------------------------------------------------------------------------ --------------------------------------------------
           202 Canadian Gift Exchange Network                     Tamuri, Yoshi                                                                                          (604) 555-3392                                    
           233 Québec Home Shopping Network                       Fresnière, Jean                                                                                        (514) 555-8054                                    
           260 Royal Canadian Collectables, Ltd.                  Lincoln, Elizabeth                                                                                     (604) 555-4555                                    

--Q4 SOLUTION --
SELECT DISTINCT customernumber --1
FROM payments
ORDER BY 1;
--OUTPUT --

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
           144

CUSTOMERNUMBER
--------------
           145
           146
           148
           151
           157
           161
           166
           167
           171
           172
           173

CUSTOMERNUMBER
--------------
           175
           177
           181
           186
           187
           189
           198
           201
           202
           204
           205

CUSTOMERNUMBER
--------------
           209
           211
           216
           219
           227
           233
           239
           240
           242
           249
           250

CUSTOMERNUMBER
--------------
           256
           259
           260
           276
           278
           282
           286
           298
           299
           311
           314

CUSTOMERNUMBER
--------------
           319
           320
           321
           323
           324
           328
           333
           334
           339
           344
           347

CUSTOMERNUMBER
--------------
           350
           353
           357
           362
           363
           379
           381
           382
           385
           386
           398

CUSTOMERNUMBER
--------------
           406
           412
           415
           424
           447
           448
           450
           452
           455
           456
           458

CUSTOMERNUMBER
--------------
           462
           471
           473
           475
           484
           486
           487
           489
           495
           496

--Q5 SOLUTION --
SELECT customernumber,  --1
       checknumber,     --2
       amount           --3
FROM payments
where amount < 1500
OR amount > 120000
ORDER BY 3 DESC;
--OUTPUT
CUSTOMERNUMBER CHECKNUMBER                                            AMOUNT
-------------- -------------------------------------------------- ----------
           141 JE105477                                            120166.58
           121 FD317790                                              1491.38
           381 MS154481                                               1128.2
           398 JPMR4544                                               615.45

--Q6 SOLUTION --
SELECT productcode,   --1
       productname,   --2
       buyprice,      --3
       msrp,          --4
       msrp - buyprice AS "MARKUP", --5
       ROUND((100 *  ((msrp - buyprice) / BuyPrice)),1) AS "PERCMARKUP"  --6
 
       FROM products
       WHERE (100 *  ((msrp - buyprice) / BuyPrice)) > 140
       ORDER BY 6;
-- OUTPUT --
PRODUCTCODE     PRODUCTNAME                                                              BUYPRICE       MSRP     MARKUP PERCMARKUP
--------------- ---------------------------------------------------------------------- ---------- ---------- ---------- ----------
S18_2432        1926 Ford Fire Engine                                                       24.92      60.77      35.85      143.9
S12_3990        1970 Plymouth Hemi Cuda                                                     31.92       79.8      47.88        150
S24_4620        1961 Chevrolet Impala                                                       32.33      80.84      48.51        150
S18_2625        1936 Harley Davidson El Knucklehead                                         24.23      60.57      36.34        150
S24_3420        1937 Horch 930V Limousine                                                    26.3      65.75      39.45        150


       
       
--Q7 SOLUTION --
SELECT productcode,    --1
       productname,    --2
       quantityinstock   --3
FROM products
WHERE productname LIKE '%co%'
OR productname LIKE '%Co%'
ORDER BY 3;
--OUTPUT
PRODUCTCODE     PRODUCTNAME                                                            QUANTITYINSTOCK
--------------- ---------------------------------------------------------------------- ---------------
S12_3891        1969 Ford Falcon                                                                  1049
S18_4721        1957 Corvette Convertible                                                         1249
S24_2840        1958 Chevy Corvette Limited Edition                                               2542
S24_1444        1970 Dodge Coronet                                                                4074
S18_1662        1980s Black Hawk Helicopter                                                       5330
S18_2957        1934 Ford V8 Coupe                                                                5649
S18_3259        Collectable Wooden Train                                                          6450
S24_3856        1956 Porsche 356A Coupe                                                           6600
S24_3949        Corsair F4U ( Bird Cage)                                                          6812
S12_3148        1969 Corvair Monza                                                                6906
S700_2610       The USS Constitution Ship                                                         7083

PRODUCTCODE     PRODUCTNAME                                                            QUANTITYINSTOCK
--------------- ---------------------------------------------------------------------- ---------------
S24_1937        1939 Chevrolet Deluxe Coupe                                                       7332
S24_1628        1966 Shelby Cobra 427 S/C                                                         8197
S18_1342        1937 Lincoln Berline                                                              8693
S18_2325        1932 Model A Ford J-Coupe                                                         9354
S24_3432        2002 Chevy Corvette                                                               9446


--Q8 SOLUTION --
SELECT customernumber,    --1
       contactfirstname,  --2
       contactlastname    --3
FROM customers
WHERE contactfirstname LIKE 'S%E%'
OR contactfirstname LIKE 'S%e%'
OR contactfirstname LIKE 's%E%'
OR contactfirstname LIKE 's%e%'
ORDER BY 1;
--OUTPUT --
CUSTOMERNUMBER CONTACTFIRSTNAME                                   CONTACTLASTNAME                                   
-------------- -------------------------------------------------- --------------------------------------------------
           319 Steve                                              Frick                                             
           450 Sue                                                Frick                                             
           459 Sven                                               Ottlieb                                           
           471 Sean                                               Clenahan                                          
           475 Steve                                              Thompson                                          
           487 Sue                                                Taylor     
SELECT tblmodel.modelname AS "Model",
       tblvehicle.vehicleyear AS "Year",
       TO_CHAR(tblvehicle.vehicleprice,'L99G999D99','NLS_NUMERIC_CHARACTERS = ''.,''
       NLS_CURRENCY = ''$''  NLS_ISO_CURRENCY = Canada') AS "Price",
     TO_CHAR(tblvehicle.vehiclekm, '999G999') AS "KM"                                 
FROM tblmodel 
JOIN tblvehicle ON tblmodel.modelid = tblvehicle.modelid
ORDER BY tblvehicle.vehicleyear DESC, 
        tblmodel.modelname ASC;
        
        
-------------------------------------------------
SELECT  tblmanufacture.manufacturename AS "MANUFACTURER" ,      ---1
       tblbrand.brandname AS "BRAND"      ---2
FROM tblmanufacture  
 LEFT OUTER JOIN tblbrand ON tblmanufacture.manufactureid = tblbrand.manufactureid
ORDER BY 1,
         2;
--------------------------------------------


SELECT  DISTINCT tblmanufacture.manufacturename AS "MANUFACTURE",    ---1
         tblmodel.modelname AS "MODEL"      ---2
FROM tblmanufacture
JOIN tblbrand ON tblbrand.manufactureid = tblmanufacture.manufactureid
JOIN tblmodel ON tblmodel.brandid = tblbrand.brandid
-- WHERE modelname IS NOT NULL (we can use this if there was any modelname was null)
ORDER BY 1,
         2;



----------------------------------------------


SELECT tblmodel.modelname AS "MODEL",       ---1
       tblvehicle.vehicleyear AS "Year",    ---2
        TO_CHAR(tblvehicle.vehiclekm,'99G999') AS "Km",       ---3
       TO_CHAR(tblvehicle.vehicleprice,'L99G999D99','NLS_NUMERIC_CHARACTERS = ''.,''
NLS_CURRENCY = ''$'' 
NLS_ISO_CURRENCY = Canada') AS  "Price",  --4
tbloption.optiondesc AS "Option"
FROM tblmodel
JOIN tblvehicle ON tblmodel.modelid = tblvehicle.modelid
JOIN tbloptiondetail ON tbloptiondetail.vehicleid = tblvehicle.vehicleid
JOIN tbloption ON tbloptiondetail.optionid = tbloption.optionid
WHERE optiondesc =  'Heated mirrors';


--------------------------------




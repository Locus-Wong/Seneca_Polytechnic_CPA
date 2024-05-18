--Name: Tsz Wa Wong
--Student ID: 152181228
--Date: 25 Jan 2024
--DBS211 – Lab 03
SET AUTOCOMMIT ON; 
SELECT *
FROM retailcustomers
WHERE upper(contactfirstname) LIKE 'S%E%' OR upper(contactfirstname) LIKE 'SE%';
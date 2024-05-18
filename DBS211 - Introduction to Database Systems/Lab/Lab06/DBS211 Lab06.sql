--Name: Tsz Wa Wong
--Student ID: 152181228
--Date: 15 Feb 2024
--DBS211 - Lab 06
SET AUTCOMMIT OFF;
SET TRANSACTION READ WRITE;

CREATE TABLE newcustomers AS
SELECT * FROM retailcustomers WHERE 1=2;

INSERT ALL
INTO newcustomers (customernumber, customername, contactlastname, contactfirstname, phone, addressline1, city, country)
VALUES (100, 'Ralph Patel', 'Patel', 'Ralph', 2233355555, '10 SenecaWay', 'Paris', 'France')
INTO newcustomers (customernumber, customername, contactlastname, contactfirstname, phone, addressline1, city, country)
VALUES (101, 'Betty Denis', 'Betty', 'Denis', 3344455555, '110 SenecaWay', 'Chicago', 'USA')
INTO newcustomers (customernumber, customername, contactlastname, contactfirstname, phone, addressline1, city, country)
VALUES (102, 'Ben Biri', 'Ben', 'Biri', 44555445544, '13000 SenecaWay', 'Toronto', 'Canada')
INTO newcustomers (customernumber, customername, contactlastname, contactfirstname, phone, addressline1, city, country)
VALUES (103, 'Chad Newman', 'Chad', 'Newman', 66777332233, '12 SenecaWay', 'Mexico city', 'Mexico')
INTO newcustomers (customernumber, customername, contactlastname, contactfirstname, phone, addressline1, city, country)
VALUES (104, 'Audrey Ropeburn', 'Audrey', 'Ropeburn', 7788811212, '15000 SenecaWay', 'Havana', 'Cuba')
INTO newcustomers (customernumber, customername, contactlastname, contactfirstname, phone, addressline1, city, country)
VALUES (105, 'Preston Lucy', 'Preston', 'Lucy', 45555511111, '12 SenecaWay', 'Charlotte', 'USA') 
SELECT * FROM dual;
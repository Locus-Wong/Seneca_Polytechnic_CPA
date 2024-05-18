--Name: Tsz Wa Wong
--Student ID: 152181228
--Date: 8 Feb 2024
--DBS211 - Lab 05
SET AUTOCOMMIT ON;
CREATE TABLE movies(
    movieid INT PRIMARY KEY,
    title VARCHAR(35) NOT NULL,
    releaseYear INT NOT NULL,
    director INT NOT NULL,
    score DECIMAL(3,2),
    CONSTRAINT score_chk CHECK (score < 10 AND score > 3)
 );
 
 CREATE TABLE actors(
     actorid INT PRIMARY KEY,
    firstname VARCHAR(20) NOT NULL,
    lastname VARCHAR(30) NOT NULL
 );	
 
 CREATE TABLE castings(
    movieid INT,
    actorid INT,
    PRIMARY KEY (movieid, actorid),
    CONSTRAINT movieid_fk FOREIGN KEY (movieid) REFERENCES movies(movieid),
    CONSTRAINT actorid_fk FOREIGN KEY (actorid) REFERENCES actors(actorid)
);

CREATE TABLE directors(
    directorid INT PRIMARY KEY,
    firstname VARCHAR(20) NOT NULL,
    lastname VARCHAR(30) NOT NULL
);

ALTER TABLE movies
ADD CONSTRAINT director_fk FOREIGN KEY (director) REFERENCES directors(directorid);

ALTER TABLE movies
ADD CONSTRAINT title_unique UNIQUE (title);

INSERT ALL
INTO directors VALUES (1010, 'Rob', 'Minkoff')
INTO directors VALUES (1020, 'Bill', 'Condon')
INTO directors VALUES (1050, 'Josh', 'Cooley')
INTO directors VALUES (2010, 'Brad', 'Bird')
INTO directors VALUES (3020, 'Lake', 'Bell')
SELECT * FROM dual;

INSERT ALL
INTO movies VALUES (100, 'The Lion King', 2019, 3020, 3.50)
INTO movies VALUES (200, 'Beauty and the Beast', 2017, 1050, 4.20)
INTO movies VALUES (300, 'Toy Story 4', 2019, 1020, 4.50)
INTO movies VALUES (400, 'Mission Impossible', 2018, 2010, 5.00)
INTO movies VALUES (500, 'The Secret Life of Pets', 2016, 1010, 3.90)
SELECT * FROM dual;

DROP TABLE castings;    
DROP TABLE movies; 
DROP TABLE actors; 
DROP TABLE directors; 

CREATE TABLE employeecopy AS
SELECT * FROM retailemployees WHERE 1=2;

ALTER TABLE employeecopy
ADD username VARCHAR2(50 BYTE);

INSERT INTO employeecopy (employeenumber, lastname, firstname, extension, email, officecode, reportsto, jobtitle)
SELECT 
    employeenumber,
    lastname,
    firstname,
    extension,
    email,
    officecode,
    reportsto,
    jobtitle
FROM retailemployees;

UPDATE employeecopy SET
    username = CONCAT(employeenumber, '@seneca.ca');

DELETE FROM employeecopy;

SELECT * FROM employeecopy;

DROP TABLE employeecopy; 


INSERT INTO retailemployees (employeenumber, lastname, firstname, extension, email, officecode, reportsto, jobtitle)
VALUES
(1964, 'Wong', 'Tsz Wa', 'x1234', 'twwong9@myseneca.ca', '4', 1088, 'Cashier');

SELECT *
FROM retailemployees
WHERE retailemployees.employeenumber = 1964;

UPDATE retailemployees SET
    jobtitle = 'Head Cashier'
    WHERE retailemployees.employeenumber = 1964;


INSERT INTO retailemployees (employeenumber, lastname, firstname, extension, email, officecode, reportsto, jobtitle)
VALUES 
(1111, 'Tom', 'Tommy', 'x3478', 'tom1954@myseneca.ca', '4', 1964, 'Cashier');


DELETE FROM retailemployees
WHERE retailemployees.employeenumber = 1111;

DELETE FROM retailemployees
WHERE retailemployees.employeenumber = 1964;

INSERT ALL 
INTO retailemployees VALUES (1964, 'Wong', 'Tsz Wa', 'x1234', 'twwong9@myseneca.ca', '4', 1088, 'Cashier')
INTO retailemployees VALUES (1111, 'Tom', 'Tommy', 'x3478', 'tom1954@myseneca.ca', '4', 1964, 'Cashier')
SELECT * FROM dual;

DELETE FROM retailemployees
WHERE retailemployees.employeenumber = 1111 OR retailemployees.employeenumber = 1964;

INSERT INTO retailorders (ordernumber, orderdate, requireddate, shippeddate, status, comments, customernumber)
VALUES
(14523, '2021-09-17', '2021-09-22', '2021-09-24', 'Shipped', 'Fast Delivery', 112);

INSERT INTO retailproducts (productcode, productname, productline, retailproductscale, productvendor, productdescription, quantityinstock, buyprice, msrp)
VALUES
('S111_111', '2020 Bugatti Veyron', 'Classic Cars', '1:36', 'ATV Auto Industry', 'With full innovative technology', 10, 35420, 99999);


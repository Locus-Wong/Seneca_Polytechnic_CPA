--DBS211 Group 7
--MS3-Database Scripting and Creation
--Group Members:Ruolin Wu, Tsz Wa Wong, Yong Li
--MS3: View for business

--Overview:
--This database is meticulously crafted for external use from the customer's perspective.
--Customers will be able to register an account for themselves and their pets, manage and edit
--these accounts, browse available services details, make appointments, view previous medical histories
--for their pets.
--On top of external uses, we also provided extra insights to use these data internally from the
--clinic perspective for any future possibilities to fits the needs of the clinics.


--User login/registration & Profile management/editing
--Upon creating a profile, users can effortlessly store and update details fot both themselves and their pets. 
--With the ability to access comprehensive information about their pets and make necessary modifications,
--users can stay informed and in control. By adding a (WHERE OWNERID = ***) after (ON O.OWNERID = P.OWNERID),
--a specific client account can be selected for review/edit.
--Possible internal use: the clinic can leverage this application to promptly retrieve pet statuses and owner information, 
--facilitating efficient customer maintenance and target customers analysis.
CREATE VIEW USERINFO AS(
SELECT P.PETID,P.PETSNAME,P.BREEDS,P.AGE,P.PETTYPE, 
O.OWNERFIRSTNAME||' '||O.OWNERLASTNAME AS OWNERNAME,
O.OWNERADDRESS,O.OWNEREMAIL,O.OWNERPHONENUM
FROM OWNERS O INNER JOIN PETS P 
ON O.OWNERID = P.OWNERID
);
DROP VIEW USERINFO;
SELECT * FROM USERINFO;


--Check medical history
--Based on this database, the application serves as a centralized hub for storing all pets' medical treatment records,
--ensuring convenient access for owners to monitor their pets' medical history in case of an emergency. 
--Possible external use: it enables clinics and veterinarians to swiftly diagnose the latest illnesses by providing comprehensive medical history.
--By facilitating thorough analysis and diagnosis, this database empowers both veterinarians and pet owners to effectively 
-- assess and address their pets' health needs.
CREATE VIEW MEDICALHISTORY AS(
SELECT O.OWNERFIRSTNAME||' '||O.OWNERLASTNAME AS OWNERNAME, P.PETSNAME,P.BREEDS,P.AGE,P.ISNEUTERED,
P.PETTYPE,A.APPOINTMENTDATE AS CHECKDATE,A.SERVICENAME,A.REASONFORVISIT
FROM OWNERS O INNER JOIN PETS P
ON O.OWNERID = P.OWNERID INNER JOIN APPOINTMENTS A
ON P.PETID = A.PETID
);
DROP VIEW MEDICALHISTORY;
SELECT * FROM MEDICALHISTORY;


--Making appointment independently
--This database provides the featured function for the clients to make appointments on their own instead of calling the clinic 
--and making appointments with the help of a staff.  The clients can log in to the APP, check the schedule of a specific doctor or clinic, 
--find out the date and time which is not occupied. Appointments can be made any time, not only when the clinic is open.
CREATE VIEW MAKEAPPOINTMENT AS(
SELECT A.APPOINTID,A.APPOINTMENTDATE AS UNAVAILABLE_DATE, A.APPOINTMENTTIME AS UNAVAILABLE_TIME,
V.VETFIRSTNAME||' '||V.VETLASTNAME AS VETNAME,
V.VETEMAIL
FROM APPOINTMENTS A INNER JOIN veterinarians V
USING(VETID) LEFT JOIN CLINIC C 
USING(CLINICID)
);
SELECT * FROM MAKEAPPOINTMENT;
DROP VIEW MAKEAPPOINTMENT;


--Possible external use from the clinic's perspective:
--This database is crafted to facilitate informed decision-making, particularly concerning income generation.
--By cataloging services provided by each doctor along with their respective prices, the database enables the clinic to analyze revenue streams efficiently.
--This analysis identifies top-performing services and doctors contributing to maximum income, while also highlighting underutilized services. 
--Such insights empower businesses to make strategic marketing decisions, optimizing resource allocation for enhanced profitability.
CREATE VIEW CLINICINCOME AS(
SELECT C.CLINICNAME,C.CLINICADDRESS, V.VETFIRSTNAME||' '||V.VETLASTNAME AS VETNAME,A.SERVICENAME,S.PRICE AS SUBTOTAL
FROM CLINIC C INNER JOIN VETERINARIANS V 
ON C.CLINICID = V.CLINICID INNER JOIN APPOINTMENTS A
ON V.VETID = A.VETID INNER JOIN SERVICES S
ON A.SERVICENAME = S.SERVICENAME
);
SELECT * FROM CLINICINCOME;
DROP VIEW CLINICINCOME;


--Brose services details:
--Drawing from this comprehensive database, the application encompasses extensive details about doctors, 
--services, and clinics. This empowers users to easily search for their preferred doctor or clinic to avail specific services. 
--Additionally, users can effortlessly ascertain which services are offered by each clinic, 
--facilitating informed decision-making regarding their healthcare needs.
CREATE VIEW CLINICSERVICES AS(
SELECT S.SERVICENAME, S.SERVICEDES, S.PRICE, V.VETFIRSTNAME||' '||V.VETLASTNAME AS VETNAME, 
V.VETEMAIL,C. CLINICNAME, C.CLINICADDRESS,C.CLINICEMAIL
FROM SERVICES S INNER JOIN APPOINTMENTS A
ON S.SERVICENAME = A.SERVICENAME
INNER JOIN veterinarians V
ON V.VETID = A.VETID
INNER JOIN CLINIC C USING(CLINICID)
);
SELECT * FROM CLINICSERVICES;
DROP VIEW CLINICSERVICES;

COMMIT;
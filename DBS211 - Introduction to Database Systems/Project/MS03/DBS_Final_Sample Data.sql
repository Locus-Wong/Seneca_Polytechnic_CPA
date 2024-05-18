--DBS211 Group 7
--MS3-Database Scripting and Creation
--Group Members:Ruolin Wu, Tsz Wa Wong, Yong Li
--MS3: Sample Data

--Insert one row of pet clinic information into the table:
INSERT INTO CLINIC
VALUES(100,'Seneca clinic','1550 Finch Ave','senecaclinic@gmail.com',14163057799);
--It is successful,so insert the rest 20 records:
INSERT ALL
INTO CLINIC VALUES(101,'Hero clinic','8899 Finch Ave','heroclinic@gmail.com',14163058888)
INTO CLINIC VALUES(102,'Box clinic','1222 Keel Ave','boxclinic@gmail.com',14160002233)
INTO CLINIC VALUES(103,'Goodlife clinic','1222 Hardon Dr','goodlifeclinic@gmail.com',12320002233)
INTO CLINIC VALUES(104,'Sun clinic','12 Post Ave','sunclinic@gmail.com',14161112233)
INTO CLINIC VALUES(105,'Fancy clinic','88 Finch Street','fancyclinic@gmail.com',14165552233)
INTO CLINIC VALUES(106,'Moon clinic','1222 Kate Ave','moonclinic@gmail.com',14169992233)
INTO CLINIC VALUES(107,'Petty clinic','100 Markham Ave','petty@gmail.com',14160008833)
INTO CLINIC VALUES(108,'The best clinic','1222 Lantain Ave','thebestclinic@gmail.com',14160002200)
INTO CLINIC VALUES(109,'The First clinic','East Keel Ave','thefirstclinic@gmail.com',14160009987)
INTO CLINIC VALUES(110,'Look clinic','Kine Ave','kineclinic@gmail.com',13160002233)
INTO CLINIC VALUES(111,'Tommy clinic','1000 Finch Ave','tommyclinic@gmail.com',14363058888)
INTO CLINIC VALUES(112,'Second clinic','100 book street','secondclinic@gmail.com',14560002233)
INTO CLINIC VALUES(113,'Third clinic','101 ave','thirdclinic@gmail.com',14250002233)
INTO CLINIC VALUES(114,'West clinic','west look ave','westclinic@gmail.com',14169983456)
INTO CLINIC VALUES(115,'East clinic','east look ave','eastclinic@gmail.com',14161112345)
INTO CLINIC VALUES(116,'Football clinic','234 Markham ave','footballclinic@gmail.com',14162343455)
INTO CLINIC VALUES(117,'Lion clinic','122 Markham Ave','lineclinic@gmail.com',14160009999)
INTO CLINIC VALUES(118,'Bird clinic','9 High Part Ave','birdclinic@gmail.com',14161112345)
INTO CLINIC VALUES(119,'CK clinic','1222 Hight Park Ave','ckclinic@gmail.com',14162223456)
INTO CLINIC VALUES(120,'Love clinic','299 Party Ave','loveclinic@gmail.com',14134565667)
SELECT * FROM DUAL;
SELECT * FROM CLINIC;

--insert one row of vet information into the table:
INSERT INTO VETERINARIANS
VALUES(200,100,'Tony','Stark','doctor1@gmail.com',14161112222);
--It is successful,so insert the rest 21 records:
INSERT ALL
INTO  VETERINARIANS VALUES(201,101,'Tom','Stark','doctor1@gmail.com',14161113333)
INTO  VETERINARIANS VALUES(202,102,'John','Doe','doctor1@gmail.com',14161112345)
INTO  VETERINARIANS VALUES(203,103,'Tan','Su','doctor1@gmail.com',14162341234)
INTO  VETERINARIANS VALUES(204,104,'Jo','Susan','doctor1@gmail.com',14162346789)
INTO  VETERINARIANS VALUES(205,105,'Anni','Lu','doctor1@gmail.com',14161112222)
INTO  VETERINARIANS VALUES(206,106,'Genny','Bi','doctor1@gmail.com',14161114444)
INTO  VETERINARIANS VALUES(207,107,'Tomas','Ham','doctor1@gmail.com',14161115555)
INTO  VETERINARIANS VALUES(208,108,'Hanna','Tong','doctor1@gmail.com',14162223456)
INTO  VETERINARIANS VALUES(209,109,'Bill','Tony','doctor1@gmail.com',14169991234)
INTO  VETERINARIANS VALUES(210,110,'Amy','Su','doctor1@gmail.com',14168882345)
INTO  VETERINARIANS VALUES(211,111,'Aew','Blue','doctor1@gmail.com',14167771234)
INTO  VETERINARIANS VALUES(212,112,'Bool','Liu','doctor1@gmail.com',14162225432)
INTO  VETERINARIANS VALUES(213,113,'Isic','Nuton','doctor1@gmail.com',14161112233)
INTO  VETERINARIANS VALUES(214,114,'Jerry','Mao','doctor1@gmail.com',14161112267)
INTO  VETERINARIANS VALUES(215,115,'Jack','Stark','doctor1@gmail.com',14161112277)
INTO  VETERINARIANS VALUES(216,116,'Jason','Jajon','doctor1@gmail.com',14161112312)
INTO  VETERINARIANS VALUES(217,117,'Chris','Lin','doctor1@gmail.com',14161111212)
INTO  VETERINARIANS VALUES(218,118,'Wu','Li','doctor1@gmail.com',14161123434)
INTO  VETERINARIANS VALUES(219,119,'Tong','BK','doctor1@gmail.com',14161114532)
INTO  VETERINARIANS VALUES(220,120,'Susan','Ham','doctor1@gmail.com',14161110101)
INTO  VETERINARIANS VALUES(221,101,'Bill','Doe','doctor1@gmail.com',14161112220)
SELECT * FROM DUAL;
SELECT * FROM VETERINARIANS;

--insert one row of service information into the table:
INSERT INTO SERVICES
VALUES('ultrosound',88.5,'check bones and body');
--It is successful,so insert the rest 20 records:
INSERT ALL
INTO SERVICES VALUES('eyecheck',50,'check the eyes of pet')
INTO SERVICES VALUES('toothcheck',98.5,'check tooth')
INTO SERVICES VALUES('generalCT',45.5,'scan the whole body')
INTO SERVICES VALUES('injection',22.5,'include the fee of medicine')
INTO SERVICES VALUES('bodycheck',100,'general body check')
INTO SERVICES VALUES('footcheck',38.5,'check bones and feet')
INTO SERVICES VALUES('bloodtest',68.5,'test blood')
INTO SERVICES VALUES('headCT',78.5,'CT for head only')
INTO SERVICES VALUES('bodyCT',99.5,'CT check for whole body')
INTO SERVICES VALUES('toothsurgery',45.5,'include extraction and implant tooth')
INTO SERVICES VALUES('toothCT',46.5,'CT check for teeth')
INTO SERVICES VALUES('footsurgery',28.5,'the surgery for all feet')
INTO SERVICES VALUES('footCT',18.5,'CT check for foot')
INTO SERVICES VALUES('headMRI',88.5,'MRI check for head')
INTO SERVICES VALUES('bodyMRI',58.5,'MRI check for body')
INTO SERVICES VALUES('footMRI',68,'MRI check for all feet')
INTO SERVICES VALUES('earclean',28.5,'clean the ears and disinfect')
INTO SERVICES VALUES('skintest',58.9,'for skin or hair illness')
INTO SERVICES VALUES('eyeoperation',88.2,'surgery for eyes')
INTO SERVICES VALUES('fractureoperation',78.3,'include body check and bones check')
SELECT * FROM DUAL;
SELECT * FROM SERVICES;

--insert one row of owner information into the table:
INSERT INTO OWNERS
VALUES(300,'Tom','Doe','tomdoe001@gmail.com','88 Markham Road','L6E0N8',14164445555);

INSERT ALL
INTO OWNERS VALUES(301,'Tommy','Doe','tomdoe002@gmail.com','88 Finch Road','L6E0N8',14164442345)
INTO OWNERS VALUES(302,'Bill','Stark','tomdoe003@gmail.com','882 Keel Road','L6E0N8',14164441224)
INTO OWNERS VALUES(303,'Jack','Li','tomdoe112@gmail.com','88 Fen Road','L6E0N8',14164447890)
INTO OWNERS VALUES(304,'Jacky','Lu','tomdoe998@gmail.com','12 Finch Ave','L6E0N8',14164445555)
INTO OWNERS VALUES(305,'Anni','Li','tomdoe1109@gmail.com','100 Seneca Road','L6E0N8',14164445555)
INTO OWNERS VALUES(306,'Burl','Doe','tomdoe1234@gmail.com','88 High park Road','L6E0N8',14164565555)
INTO OWNERS VALUES(307,'Cydia','Susan','tomdoe112@gmail.com','90 Person Road','L6E0N8',14164445678)
INTO OWNERS VALUES(308,'Dool','TK','tomdo111@gmail.com','10 Markham Ave','L6E0N8',14164445555)
INTO OWNERS VALUES(309,'Jasper','Li','tomdoe222@gmail.com','23 East Markham Road','L6E0N8',14164445555)
INTO OWNERS VALUES(310,'John','Lu','tomdoe333@gmail.com','88 West Markham Road','L6E0N8',14164432345)
INTO OWNERS VALUES(311,'Thmoas','Hana','tomdoe444@gmail.com','88 East Markham Road','L6E0N8',14164441234)
INTO OWNERS VALUES(312,'Joe','Tang','tomdoe555@gmail.com','11 East Finch Road','L6E0N8',14164440000)
INTO OWNERS VALUES(313,'Jay','Tony','tomdoe221@gmail.com','88 West Finch Road','L6E0N8',14164445522)
INTO OWNERS VALUES(314,'Cash','Chives','tomdoe221@gmail.com','1090 Road','L6E0N8',14164445513)
INTO OWNERS VALUES(315,'Ann','Queen','tomdoe561@gmail.com','88 Street Road','L6E0N8',14164445590)
INTO OWNERS VALUES(316,'Amy','Park','tomdoe678@gmail.com','12 Farm Road','L6E0N8',14164445235)
INTO OWNERS VALUES(317,'May','Queen','tomdoe789@gmail.com','883 Main Road','L6E0N8',14164441235)
INTO OWNERS VALUES(318,'March','Lu','tomdoe789@gmail.com','100 Main Road','L6E0N8',14164443455)
INTO OWNERS VALUES(319,'August','Wong','tomdoe0111@gmail.com','88 East Main Road','L6E0N8',14162245555)
INTO OWNERS VALUES(320,'June','Park','tomdoe4444@gmail.com','190 Markham Dr','L6E0N8',14164567555)
SELECT * FROM DUAL;

SELECT * FROM OWNERS;

--insert one row of pet information into the table:
INSERT INTO PETS
VALUES(400,300,'Lucky','Husky',10,'Yes','Dog');

INSERT ALL
INTO PETS VALUES(401,301,'Sunny','Husky',10,'Yes','Dog')
INTO PETS VALUES(402,302,'Lulu','Sheperd',2,'No','Dog')
INTO PETS VALUES(403,303,'Money','Bombay',4,'Yes','Cat')
INTO PETS VALUES(404,304,'Moon','Ragdoll',2,'Yes','Cat')
INTO PETS VALUES(405,305,'Sun','Husky',6,'Yes','Dog')
INTO PETS VALUES(406,306,'Blue','Husky',1,'No','Dog')
INTO PETS VALUES(407,307,'Tom','Husky',8,'Yes','Cat')
INTO PETS VALUES(408,308,'Amy','Persian',6,'Yes','Cat')
INTO PETS VALUES(409,309,'WaWa','Husky',11,'Yes','Dog')
INTO PETS VALUES(410,310,'Sunny','Husky',10,'No','Rabbit')
INTO PETS VALUES(411,311,'Lucky','Husky',13,'No','Dog')
INTO PETS VALUES(412,312,'Moon','Persian',3,'Yes','Cat')
INTO PETS VALUES(413,313,'Fighter','noname',4,'Yes','Ruster')
INTO PETS VALUES(414,314,'Cow','Husky',2,'No','Dog')
INTO PETS VALUES(415,315,'Bee','Husky',5,'Yes','Dog')
INTO PETS VALUES(416,315,'Lucky','Bark',10,'No','Dog')
INTO PETS VALUES(417,316,'Lucky','British',4,'Yes','Cat')
INTO PETS VALUES(418,317,'Lucky','Husky',10,'Yes','Dog')
INTO PETS VALUES(419,318,'Lucky','Husky',3,'No','Dog')
INTO PETS VALUES(420,319,'August','British',5,'No','Cat')
INTO PETS VALUES(421,320,'Lisa','Husky',8,'Yes','Dog')
INTO PETS VALUES(422,318,'Barky','Husky',1,'No','Rabbit')
INTO PETS VALUES(423,301,'Lucky','Husky',9,'Yes','Dog')
INTO PETS VALUES(424,302,'Hony','Ragdoll',10,'Yes','Cat')
SELECT * FROM DUAL;
SELECT * FROM PETS;

--insert one row of appointment information into the table:
INSERT INTO APPOINTMENTS
VALUES(500,400,'ultrosound',200,TO_DATE('2023-03-15', 'YYYY-MM-DD'),'10:30am','Regular checkup');
--Insert the rest 20 appointments data:
INSERT ALL
INTO APPOINTMENTS VALUES(501,401,'eyecheck',201,TO_DATE('2023-03-15', 'YYYY-MM-DD'),'11:30am','The two eyes tear a lot recently.')
INTO APPOINTMENTS VALUES(502,402,'toothcheck',202,TO_DATE('2023-03-16', 'YYYY-MM-DD'),'9:30am','Regular teeth check up')
INTO APPOINTMENTS VALUES(503,403,'generalCT',203,TO_DATE('2023-04-16', 'YYYY-MM-DD'),'10:30am','Surgery follow up.')
INTO APPOINTMENTS VALUES(504,404,'injection',204,TO_DATE('2023-06-16', 'YYYY-MM-DD'),'11:30am','Take the seasonal flu shot.')
INTO APPOINTMENTS VALUES(505,405,'bodycheck',205,TO_DATE('2023-02-16', 'YYYY-MM-DD'),'1:30Pm','Annually physical check up.')
INTO APPOINTMENTS VALUES(506,406,'footcheck',206,TO_DATE('2023-03-17', 'YYYY-MM-DD'),'9:30am','Maybe there is a bone issue need to exam.')
INTO APPOINTMENTS VALUES(507,407,'bloodtest',207,TO_DATE('2023-03-17', 'YYYY-MM-DD'),'10:30am','The blood test for preparation of surgery.')
INTO APPOINTMENTS VALUES(508,408,'headCT',208,TO_DATE('2023-03-17', 'YYYY-MM-DD'),'11:30am','CT for head check up.')
INTO APPOINTMENTS VALUES(509,409,'bodyCT',209,TO_DATE('2023-01-18', 'YYYY-MM-DD'),'10:30am','Regular checkup')
INTO APPOINTMENTS VALUES(510,410,'toothsurgery',210,TO_DATE('2023-07-18', 'YYYY-MM-DD'),'11:30am','Tooth Extraction')
INTO APPOINTMENTS VALUES(511,411,'toothCT',211,TO_DATE('2023-11-19', 'YYYY-MM-DD'),'10:30am','Post check up for tooth surgery')
INTO APPOINTMENTS VALUES(512,412,'footsurgery',212,TO_DATE('2023-08-19', 'YYYY-MM-DD'),'11:30am','The foot bone fracture operation.')
INTO APPOINTMENTS VALUES(513,413,'footCT',213,TO_DATE('2023-09-20', 'YYYY-MM-DD'),'9:30am','Surgery follow up checkup.')
INTO APPOINTMENTS VALUES(514,414,'headMRI',214,TO_DATE('2023-05-21', 'YYYY-MM-DD'),'10:30am','MRI check for head bone.')
INTO APPOINTMENTS VALUES(515,415,'bodyMRI',215,TO_DATE('2023-06-22', 'YYYY-MM-DD'),'10:30am','Regular checkup')
INTO APPOINTMENTS VALUES(516,416,'footMRI',216,TO_DATE('2023-03-23', 'YYYY-MM-DD'),'10:30am','Regular MRI check for post-surgery.')
INTO APPOINTMENTS VALUES(517,417,'earclean',217,TO_DATE('2023-02-24', 'YYYY-MM-DD'),'11:30am','Clean and disinfect the ears')
INTO APPOINTMENTS VALUES(518,418,'ultrosound',218,TO_DATE('2023-11-25', 'YYYY-MM-DD'),'10:30am','Regular ultrosound checkup')
INTO APPOINTMENTS VALUES(519,418,'earclean',219,TO_DATE('2023-08-25', 'YYYY-MM-DD'),'11:30am','Disinfect and clean the ears.')
INTO APPOINTMENTS VALUES(520,419,'ultrosound',220,TO_DATE('2023-07-26', 'YYYY-MM-DD'),'10:30am','Regular checkup')
INTO APPOINTMENTS VALUES(521,419,'bloodtest',201,TO_DATE('2023-03-27', 'YYYY-MM-DD'),'10:30am','Prepare test for foot surgery.')
INTO APPOINTMENTS VALUES(522,420,'ultrosound',202,TO_DATE('2023-03-28', 'YYYY-MM-DD'),'11:30am','Follow up checkup.')
SELECT * FROM DUAL;
SELECT * FROM APPOINTMENTS;



COMMIT;


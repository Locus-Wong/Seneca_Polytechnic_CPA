--Name: Ruolin Wu, Tsz Wa Wong, Yong Li
--Date: 12 Apr 2024
--DBS211 Project MS03 - Business Reports (GROUP 7)
SET AUTOCOMMIT ON;

-- The purpose of this view is to allow clinic staff to easily retrieve the medical records of a pet. This enables the clinic staff to quickly perform any necessary surgery for the pet in case of an emergency.
-- This feature also enables pet owners to access their pets' medical records, helping them understand their pets' health status, know when the next appointment is, and make appointments themselves if needed.
-- Use specific appointID as an input to receive the record, e.g. 12345.
CREATE VIEW checkAppointments AS (
SELECT 
    app.appointID, 
    pets.petsName, 
    pets.breeds,
    pets.age,
    app.serviceName, 
    pets.ownerID, 
    app.vetID, 
    clinic.clinicName,
    app.reasonForVisit, 
    app.appointmentDate, 
    app.appointmentTime,  
    
FROM appointment app INNER JOIN pets ON app.petID = pets.petID INNER JOIN owners ON pets.ownerID = owners.ownerID INNER JOIN vet ON app.vetID = vet.vetID INNER JOIN clinic ON vet.clinicID = clinic.clinicID
WHERE app.appointID = 12345
);

-- The purpose of this view is to allow pet owners to check the services offered by the clinic. This helps them choose the clinic that best suits their pets' needs and is located near their home.
-- Use a specific clinic ID as an input to receive the record, e.g. 12345.
CREATE VIEW checkClinicServices AS (
SELECT
    clinic.clinicID
    clinic.clinicName,
    clinic.clinicAddress,
    clinic.clinicPhoneNum,
    service.serviceName,
    service.serviceDes,
    service.price

FROM clinic INNER JOIN vet ON clinic.clinicID = vet.clinicID INNER JOIN appointment app ON vet.vetID = app.vetID INNER JOIN service ON app.serviceName = service.serviceName
WHERE clinic.clinicID = 12345
);

-- The purpose of this view is to allow pet owners to check the services offered by vets and their costs, as different vets provide different services at different prices. This helps pet owners choose a vet that best suits their pets' needs and fits within their budget.
-- Use a specific vet ID as an input to receive the record, e.g. 12345.
CREATE VIEW checkVetServices AS (
SELECT
    vet.vetID
    vet.vetFirstName,
    vet.vetLastName,
    vet.vetPhoneNum,
    service.serviceName,
    service.serviceDes,
    service.price

FROM vet INNER JOIN appointment app ON vet.vetID = app.vetID INNER JOIN service ON app.serviceName = service.serviceName
WHERE vet.vetID = 12345
);

-- The purpose of this view is to allow clinic to check the information of the pet owner. This helps the clinic staff to contact the pet owner in case of an emergency or to inform them about their pets' health status.
-- Use a specific pet ID as an input to receive the record, e.g. 12345.
CREATE VIEW checkPetOwnerInfo AS (
SELECT
    pets.petID
    owner.ownerFirstName,
    owner.ownerLastName,
    owner.ownerAddress,
    owner.ownerPhoneNum,
    owner.ownerEmail,
    owner.ownerPostalCode

FROM pets INNER JOIN owner ON pets.ownerID = owner.ownerID
WHERE pets.petID = 12345
);
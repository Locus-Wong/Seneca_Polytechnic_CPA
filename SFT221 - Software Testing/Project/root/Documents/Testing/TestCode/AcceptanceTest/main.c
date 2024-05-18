#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "mapping.h"
#include "shipment.h"

int main() {
    // Initialize map and trucks
    struct Map mainMap = populateMap();
    struct Truck trucks[3];
    int numTrucks = 3;

    // Define truck routes
    trucks[0].routeSymbol = BLUE;
    trucks[0].DeliveryPath = getBlueRoute();
    trucks[0].capacityPercentage = 0;
    trucks[0].volumePercentage = 0;
    trucks[0].numberOfShipments = 0;

    trucks[1].routeSymbol = GREEN;
    trucks[1].DeliveryPath = getGreenRoute();
    trucks[1].capacityPercentage = 0;
    trucks[1].volumePercentage = 0;
    trucks[1].numberOfShipments = 0;

    trucks[2].routeSymbol = YELLOW;
    trucks[2].DeliveryPath = getYellowRoute();
    trucks[2].capacityPercentage = 0;
    trucks[2].volumePercentage = 0;
    trucks[2].numberOfShipments = 0;

    // User input for shipments
    double weight, volume;
    struct Point destination;
    printf("Enter shipment details (weight, volume, destRow, destCol): ");
    scanf("%lf %lf %d %d", &weight, &volume, &destination.row, &destination.col);

    struct Shipments newShipment = { weight, volume, destination };

    // Find a suitable truck
    int truckIndex = CalculateTruckAvailability(trucks, numTrucks, newShipment);
    if (truckIndex != -1) {
        // Load the shipment onto the truck
        if (LoadShipmentOntoTruck(&trucks[truckIndex], newShipment) == 0) {
            printf("Shipment loaded onto truck %d\n", truckIndex + 1);
            printMap(&mainMap, 1, 0);
        }
        else {
            printf("Failed to load shipment onto truck %d\n", truckIndex + 1);
        }
    }
    else {
        printf("No suitable truck found. Ships tomorrow.\n");
    }

    return 0;
}





// This is a scenrio without using any user inputs
//int main() {
//    // Step 1: Create the map
//    struct Map cityMap = populateMap();
//
//    // Step 2: Define routes and trucks
//    struct Route blueRoute = getBlueRoute();
//    struct Route greenRoute = getGreenRoute();
//    struct Route yellowRoute = getYellowRoute();
//
//    struct Truck trucks[3];
//    trucks[0].routeSymbol = 'B';
//    trucks[0].DeliveryPath = blueRoute;
//    trucks[0].capacityPercentage = 0;
//    trucks[0].volumePercentage = 0;
//    trucks[0].numberOfShipments = 0;
//
//    trucks[1].routeSymbol = 'G';
//    trucks[1].DeliveryPath = greenRoute;
//    trucks[1].capacityPercentage = 0;
//    trucks[1].volumePercentage = 0;
//    trucks[1].numberOfShipments = 0;
//
//    trucks[2].routeSymbol = 'Y';
//    trucks[2].DeliveryPath = yellowRoute;
//    trucks[2].capacityPercentage = 0;
//    trucks[2].volumePercentage = 0;
//    trucks[2].numberOfShipments = 0;
//
//    // Step 3: Define shipments
//    struct Shipments shipment1 = { 50.0, 1.0, {10, 10} };
//    struct Shipments shipment2 = { 200.0, 2.0, {15, 15} };
//    struct Shipments shipment3 = { 100.0, 1.5, {18, 18} };
//
//    // Step 4: Process each shipment
//    int truckIndex;
//    for (int i = 0; i < 3; i++) {
//        struct Shipments currentShipment = (i == 0) ? shipment1 : (i == 1) ? shipment2 : shipment3;
//        truckIndex = CalculateTruckAvailability(trucks, 3, currentShipment);
//
//        if (truckIndex != -1) {
//            printf("Truck %d is available for shipment %d.\n", truckIndex + 1, i + 1);
//            if (LoadShipmentOntoTruck(&trucks[truckIndex], currentShipment) == 0) {
//                printf("Shipment %d loaded onto truck %d.\n", i + 1, truckIndex + 1);
//            }
//            else {
//                printf("Failed to load shipment %d onto truck %d.\n", i + 1, truckIndex + 1);
//            }
//        }
//        else {
//            printf("No trucks available for shipment %d. It will be shipped tomorrow.\n", i + 1);
//        }
//    }
//
//    // Step 5: Print final map and truck statuses
//    printMap(&cityMap, 1, 0);
//    for (int i = 0; i < 3; i++) {
//        printf("Truck %d has %d shipments.\n", i + 1, trucks[i].numberOfShipments);
//    }
//
//    return 0;
//}


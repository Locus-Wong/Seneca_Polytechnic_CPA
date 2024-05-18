#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "mapping.h"
#include "shipment.h"

int main(void)
{
    // Initialize map and trucks
    struct Map baseMap = populateMap();
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
        struct Map routeMap = baseMap;

    printf("=================\n");
    printf("Seneca College Deliveries\n");
    printf("=================\n");
    routeMap = addRoute(&baseMap, &trucks[0].DeliveryPath);
    routeMap = addRoute(&routeMap, &trucks[1].DeliveryPath);
    routeMap = addRoute(&routeMap, &trucks[2].DeliveryPath);
    printMap(&routeMap, 1, 1);
    // User input for shipments
    double weight = 0;
    double volume = 0;
    int isExit = 0;
    char destination[4];
    struct Point destPoint;
    int destRow = 0;
    int destCol = 0;
    int num1 = 0;
    int num2 = 0;
    do
    {
        isExit = 0;
        printf("Enter shipment weight, box size and destination (0 0 x to stop): ");
        scanf("%lf %lf %3s", &weight, &volume, destination);
            if (weight != 0 && volume != 0 && destination[0] != 'x')
            {
                if (destination[2] != '\0')  // XXX
                {
                    if (destination[0] == '2') // max 24
                    {
                        if (destination[1] != '0' && destination[1] != '1' && destination[1] != '2' && destination[1] != '3' && destination[1] != '4')
                        {
                            printf("Invalid destination\n");
                            continue;
                        }
                    }
                    else if (destination[2] == 'z' || destination[2] == 'Z') // max Y
                    {
                        printf("Invalid destination\n");
                        continue;
                    }
                    num1 = destination[0] - '0'; // Convert first character to int
                    num2 = destination[1] - '0'; // Convert second character to int
                    destRow = num1 * 10 + num2 - 1;
                    destCol = destination[2] - 'A';
                }
                else
                {
                    if (destination[1] != '\0') // XX
                    {
                        if (destination[1] == 'z' || destination[1] == 'Z')
                        {
                            printf("Invalid destination\n");
                            continue;
                        }
                        destRow = destination[0] - '0' - 1; // Convert first character to int
                        destCol = destination[1] - 'A';
                    }

                }
                if (volume != .5 && volume != 1 && volume != 5)
                {
                    printf("Invalid size\n");
                    continue;
                }
                else if (weight < 1 || weight > 1200)
                {
                    printf("Invalid weight (must be 1 - 1200 Kg.)\n");
                    continue;
                }
                destPoint.row = destRow;
                destPoint.col = destCol;
                struct Shipments newShipment = { weight, volume, destPoint };
                int clostestTruckIndex = -1;
                clostestTruckIndex = FindNearestTruck(&routeMap, destPoint, trucks, 3);
                if (clostestTruckIndex != -1)
                {
                    if (LoadShipmentOntoTruck(&trucks[clostestTruckIndex], newShipment) == 0)
                    {

                        printf("Ship on ");
                        if (trucks[clostestTruckIndex].routeSymbol == BLUE)
                        {
                            printf("BLUE LINE");
                        }
                        else if (trucks[clostestTruckIndex].routeSymbol == GREEN)
                        {
                            printf("GREEN LINE");
                        }
                        else if (trucks[clostestTruckIndex].routeSymbol == YELLOW)
                        {
                           printf("YELLOW LINE");
                        }
                    }
                    else
                    {
                        struct Truck newTrucks[2];
                        if (clostestTruckIndex == 0)
                        {
                            newTrucks[0] = trucks[1];
                            newTrucks[1] = trucks[2];
                        }
                        else if (clostestTruckIndex == 1)
                        {
                            newTrucks[0] = trucks[0];
                            newTrucks[1] = trucks[2];
                        }
                        else if (clostestTruckIndex == 2)
                        {
                            newTrucks[0] = trucks[0];
                            newTrucks[1] = trucks[1];
                        }
                        clostestTruckIndex = -1;
                        clostestTruckIndex = FindNearestTruck(&routeMap, destPoint, newTrucks, 2);
                        if (clostestTruckIndex != -1)
                        {
                            if (LoadShipmentOntoTruck(&trucks[clostestTruckIndex], newShipment) == 0)
                            {
                                printf("Ship on ");
                                if (newTrucks[clostestTruckIndex].routeSymbol == BLUE)
                                {
                                    printf("BLUE LINE");
                                }
                                else if (newTrucks[clostestTruckIndex].routeSymbol == GREEN)
                                {
                                    printf("GREEN LINE");
                                }
                                else if (newTrucks[clostestTruckIndex].routeSymbol == YELLOW)
                                {
                                    printf("YELLOW LINE");
                                }       
                            }
                            else
                            {
                                printf("Failed to load shipment onto the suitable truck\n");
                                printf("Ships tomorrow.\n");
                            }
                        }
						else
						{
							printf("No suitable truck found\n");
						}
                    }

                }
				else
				{
					printf("No suitable truck found\n");
				}
            }
            else
            {
                isExit = 1;
                printf("Thanks for shipping with Seneca!\n\n");
                printf("Update Truck Map:\n");
                routeMap = addRoute(&baseMap, &trucks[0].DeliveryPath);
                routeMap = addRoute(&routeMap, &trucks[1].DeliveryPath);
                routeMap = addRoute(&routeMap, &trucks[2].DeliveryPath);
                printMap(&routeMap, 1, 1);
            }
    } while (isExit == 0);
    
   
    return 0;
}
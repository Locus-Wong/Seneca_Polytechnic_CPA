#include "shipment.h"
#include <stdio.h>
#include <stdlib.h>

// Mock implementation of loading a shipment onto a truck
int LoadShipmentOntoTruck(struct Truck* truck, struct Shipments shipment) {
    if (truck->numberOfShipments < MAX_SHIPMENTS) {
        truck->shipments[truck->numberOfShipments] = shipment;
        truck->numberOfShipments++;
        truck->capacityPercentage += (shipment.weight / MAX_CAPACITY) * 100;
        truck->volumePercentage += (shipment.volume / MAX_VOLUME) * 100;
        return 0; // Success
    }
    return -1; // Failure or array full
}

// Finding available trucks for a shipment
int CalculateTruckAvailability(const struct Truck* trucks, int numTrucks, struct Shipments shipment)
{
    int selectedTruck = -1;
    double afterShip_CapacityPercentage = 0;
    double afterShip_VolumePercentage = 0;
    for (int i = 0; i < numTrucks; i++)
    {
        afterShip_CapacityPercentage = trucks[i].capacityPercentage + (shipment.weight / MAX_CAPACITY) * 100;
        afterShip_VolumePercentage = trucks[i].volumePercentage + (shipment.volume / MAX_VOLUME) * 100;

        if (afterShip_CapacityPercentage < 100 && afterShip_VolumePercentage < 100)
        {
            if (selectedTruck == -1)
            {
                selectedTruck = i;
            }
            if (i != selectedTruck)
			{
                if (trucks[selectedTruck].capacityPercentage + (shipment.weight / MAX_CAPACITY) * 100 + trucks[selectedTruck].volumePercentage + (shipment.volume / MAX_VOLUME) * 100 > (afterShip_CapacityPercentage + afterShip_VolumePercentage))
				{
					selectedTruck = i;
				}
			}

        }
    }
    return selectedTruck;
}

// Mock implementation of updating the route for a specified truck
int updateTruckRoute(struct Truck* truck, struct Map map) {
    if (!truck) return -1;
    
    struct Point startPoint = { 0, 0 };
    struct Point destinationPoint = { map.numRows - 1, map.numCols - 1 };
    
    struct Route newRoute = shortestPath(&map, startPoint, destinationPoint);
    
    if (newRoute.numPoints > 0) {
        truck->DeliveryPath = newRoute;
        return 0; // Assuming success
    } else {
        return -1; //Failed to find a new route
    }
}

// Mock implementation of finding the nearest truck to a specified delivery point
int FindNearestTruck(const struct Map* map, struct Point deliveryPoint, const struct Truck* trucks, int numTrucks)
{
    struct Route tempShortestPath;
    struct Route currentShortestPath = shortestPath(map, trucks[0].DeliveryPath.points[0], deliveryPoint);
    int truckIndex = -1;
    for (int i = 0; i < numTrucks; i++)
    {
        for (int j = 0; j < trucks[i].DeliveryPath.numPoints; j++)
        {

            tempShortestPath = shortestPath(map, trucks[i].DeliveryPath.points[j], deliveryPoint);
            if (tempShortestPath.numPoints < currentShortestPath.numPoints)
            {
                currentShortestPath = tempShortestPath;
                truckIndex = i;
            }
        }
    }
    return truckIndex;
}

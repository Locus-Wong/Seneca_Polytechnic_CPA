#ifndef SHIPMENT_H
#define SHIPMENT_H

#include "mapping.h"

#define MAX_CAPACITY 1200
#define MAX_VOLUME 50
#define HALF_CUBIC_METER 0.5
#define ONE_CUBIC_METER 1
#define FIVE_CUBIC_METERS 5
#define MAX_SHIPMENTS 100

/*
 * @brief Represents a shipment with weight, volume, and destination point.
 */
struct Shipments
{
    double weight;          /**< The weight of the shipment */
    double volume;          /**< The volume of the shipment */
    struct Point shipmentPoint;    /**< The destination point of the shipment */
};

/*
 * @brief Represents a truck with its route, capacity, volume, and shipments.
 */
struct Truck
{
    char routeSymbol;                           /**< Symbol indicating the truck's route */
    double capacityPercentage;                  /**< Percentage of capacity filled by upcoming shipments */
    double volumePercentage;                    /**< Percentage of volume filled by upcoming shipments */
    int numberOfShipments;                      /**< Number of shipments in this truck */
    struct Shipments shipments[MAX_SHIPMENTS]; /**< Array of shipments in the truck */
    struct Route DeliveryPath;                  /**< Route information including deversion symbol and divert points */
};

/*
 * Loads a shipment onto a specified truck.
 *
 * @param Truck* truck - Pointer to the truck onto which the shipment is to be loaded.
 * @param Shipments shipment - The shipment to be loaded onto the truck.
 * @return int - Returns 0 if the shipment is successfully loaded, -1 otherwise.
 */
int LoadShipmentOntoTruck(struct Truck* truck, struct Shipments shipment);

/*
 * Updates the route for a specified truck.
 *
 * @param Truck* truck - Pointer to the truck whose route is to be updated.
 * @param Map map - The current map, including any obstacles or changes.
 * @return int - Returns 0 if the route is successfully updated, -1 otherwise.
 */
int updateTruckRoute(struct Truck* truck, struct Map map);


/*
 * Calculates the availability of trucks for a shipment.
 * @param Truck* trucks - Array of trucks to search.
 * @param int numTrucks - Number of trucks in the array.
 * @param Shipments shipment - The shipment for which to find an available truck.
 * @return int - The index of the available truck in the trucks array; returns -1 if no suitable truck is found.
 */
int CalculateTruckAvailability(const struct Truck* trucks, int numTrucks, struct Shipments shipment);


/*
 * Finds the nearest truck to a specified delivery point.
 * @param Map map - The map of the delivery area.
 * @param Point deliveryPoint - The delivery point for which to find the nearest truck.
 * @param Truck* trucks - Array of trucks to search.
 * @param Route* currentShortestPath - The current shortest path to the delivery point.
 * @param int numTrucks - Number of trucks in the array.
 * @return int - The index of the nearest truck in the trucks array; returns -1 if no suitable truck is found.
 */
int FindNearestTruck(const struct Map* map, struct Point deliveryPoint,  struct Truck* trucks, int numTrucks);
#endif



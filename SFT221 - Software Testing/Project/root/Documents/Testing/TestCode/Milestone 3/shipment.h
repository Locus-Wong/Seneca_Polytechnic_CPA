#ifndef SHIPMENT_H
#define SHIPMENT_H
#define MAX_CAPACITY 1200
#define MAX_VOLUME 50
#define HALF_CUBIC_METER 0.5
#define ONE_CUBIC_METER 1
#define FIVE_CUBIC_METERS 5
#define MAX_SHIPMENTS 100

#include "mapping.h"
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
 * Calculates the efficiency of a truck's route.
 *
 * @param Map map - The map of the delivery area.
 * @param Truck truck - The truck for which to calculate route efficiency.
 * @return double - Numeric value representing the route's efficiency; higher values are better.
 */
double CalculateRouteEfficiency(struct Map map, struct Truck truck);

/*
 * Updates the route for a specified truck.
 *
 * @param Truck* truck - Pointer to the truck whose route is to be updated.
 * @param Map map - The current map, including any obstacles or changes.
 * @return int - Returns 0 if the route is successfully updated, -1 otherwise.
 */
int UpdateTruckRoute(struct Truck* truck, struct Map map);

/*
 * Finds the nearest truck to a specified delivery point.
 *
 * @param Point deliveryPoint - The delivery point for which to find the nearest truck.
 * @param Truck trucks[] - Array of trucks to search.
 * @param int numTrucks - Number of trucks in the array.
 * @return int - The index of the nearest truck in the trucks array; returns -1 if no suitable truck is found.
 */
int FindNearestTruck(struct Point deliveryPoint, struct Truck trucks[], int numTrucks);
#endif



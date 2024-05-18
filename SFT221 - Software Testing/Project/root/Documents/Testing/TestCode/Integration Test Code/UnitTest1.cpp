#include "pch.h"
#include "CppUnitTest.h"
#include "shipment_r.h"
#include <cassert>
#include <cmath>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace IntegrationTest
{

    // Test #1
    TEST_CLASS(LoadAndRouteUpdateIntegrationTest1)
    {
    public:
        TEST_METHOD(VerifyTruckLoadingAndCapacity_VolumeTracking)
        {
            struct Shipments shipment[MAX_SHIPMENTS] = { {120, 5, 1}, {240, 5, 5} };
            struct Route blueRoute = getBlueRoute();
            struct Route yellowRoute = getYellowRoute();
            struct Route greenRoute = getGreenRoute();
            struct Truck blueTruck = { 'B', 0.0, 80.0, 0, {}, blueRoute };
            struct Truck yellowTruck = { 'Y', 80.0, 0.0, 0, {}, yellowRoute };
            struct Truck greenTruck = { 'G', 40.0, 40.0, 0, {}, greenRoute };
            Truck trucks[3] = { blueTruck, yellowTruck, greenTruck };
            LoadShipmentOntoTruck(&blueTruck, shipment[0]);
            LoadShipmentOntoTruck(&yellowTruck, shipment[0]);
            LoadShipmentOntoTruck(&greenTruck, shipment[0]);
            int selectedTruck = CalculateTruckAvailability(trucks, 3, shipment[1]);
            Assert::AreEqual(0, selectedTruck);
        }
    };


    // Test #2
    TEST_CLASS(LoadAndRouteUpdateIntegrationTest2)
    {
    public:
        TEST_METHOD(SelectTruckyBasedOnDistance2)
        {
            // set the delivery point
            struct Point deliveryPoint = { 3, 3 };
            Map map = populateMap();
            struct Shipments shipment[MAX_SHIPMENTS] = { {120, 5, 1}, {240, 5, 5} };
            struct Route blueRoute = getBlueRoute();
            struct Route yellowRoute = getYellowRoute();
            struct Route greenRoute = getGreenRoute();
            struct Truck blueTruck = { 'B', 100.0, 100.0, 0, {}, blueRoute };
            struct Truck yellowTruck = { 'Y', 80.0, 0.0, 0, {}, yellowRoute };
            struct Truck greenTruck = { 'G', 40.0, 40.0, 0, {}, greenRoute };
            struct Truck trucks[3] = { blueTruck, yellowTruck, greenTruck };
            int closestTruckIndex = FindNearestTruck(&map, deliveryPoint, trucks, 3);
            LoadShipmentOntoTruck(&trucks[closestTruckIndex], shipment[0]);
            if (trucks[closestTruckIndex].capacityPercentage >= 100 || trucks[closestTruckIndex].volumePercentage >= 100)
            {
                if (closestTruckIndex == 2)
                {
                    struct Truck temptrucks[2] = { blueTruck, yellowTruck };
                    closestTruckIndex = FindNearestTruck(&map, deliveryPoint, temptrucks, 2);
                }
                else if (closestTruckIndex == 1)
                {
                    struct Truck temptrucks[2] = { blueTruck, greenTruck };
                    closestTruckIndex = FindNearestTruck(&map, deliveryPoint, temptrucks, 2);
                }
                else
                {
                    struct Truck temptrucks[2] = { yellowTruck, greenTruck };
                    closestTruckIndex = FindNearestTruck(&map, deliveryPoint, temptrucks, 2);
                }

            }
            Assert::AreEqual(0, closestTruckIndex);
        }
    };


  

    // Test #3
    TEST_CLASS(LoadAndRouteUpdateIntegrationTest3)
    {
    public:
        TEST_METHOD(Test_LoadAndRouteUpdate3)
        {
            // set the delivery point
            struct Point deliveryPoint = { 10, 10 }; 
            Map map = populateMap();

            // create trucks
            Truck truckD = { 'D', 0, 0, 0, 0, {}, {} };
            Truck truckE = { 'E', 0, 0, 0, 0, {}, {} };
            Truck truckF = { 'F', 0, 0, 0, 0, {}, {} };

            struct Shipments shipment = { 100, 5 }; // Weight: 100, Volume: 5

            // load shipment until max capacity
            for (int i = 0; i < MAX_SHIPMENTS; ++i) {
                LoadShipmentOntoTruck(&truckD, shipment);
                LoadShipmentOntoTruck(&truckE, shipment);
                LoadShipmentOntoTruck(&truckF, shipment);
            }

            // find/define nearest truck before the loading begins
            char nearestTruck_beforeD = truckD.routeSymbol;
            char nearestTruck_beforeE = truckE.routeSymbol;
            char nearestTruck_beforeF = truckF.routeSymbol;

            // load a shipment on to Truck D
            LoadShipmentOntoTruck(&truckD, shipment);

            // calculate and find the nearest truck to delivery point after the route has been changed
            int nearestIndex_afterD = FindNearestTruck(&map, deliveryPoint, &truckD, 1);
            char nearestTruck_afterD = (char)(nearestIndex_afterD == 0 ? truckD.routeSymbol : (nearestIndex_afterD == 1 ? truckE.routeSymbol : truckF.routeSymbol));
            // ensure that truckD was the nearest truck before the route change and is not afterwards
            Assert::AreNotEqual(nearestTruck_beforeD, nearestTruck_afterD);
            Assert::AreEqual(nearestTruck_beforeF, nearestTruck_afterD); 
            Assert::AreEqual(nearestTruck_beforeF, nearestTruck_afterD);
        }
    };

    // Test #4
    TEST_CLASS(LoadAndRouteUpdateIntegrationTest4)
    {
    public:
        TEST_METHOD(Test_LoadAndRouteUpdate4)
        {
            // create Truck D
            Truck truckD = { 'D', 0, 0, 0, 0, 0 };
            struct Shipments shipment = { 100, 5 }; // Weight: 100, Volume: 5

            // Load shipment onto the truck until it reaches capacity
            for (int i = 0; i < MAX_SHIPMENTS; ++i) {
                int load = LoadShipmentOntoTruck(&truckD, shipment);
                Assert::AreEqual(0, load); // check if successfully loaded
            }
            // attempt to load another shipment when capacity already reached
            int loadbeyond = LoadShipmentOntoTruck(&truckD, shipment);
            Assert::AreEqual(-1, loadbeyond);

            Map map = populateMap();
            int updateRouteResult = UpdateTruckRoute(&truckD, map);
            Assert::AreEqual(0, updateRouteResult);
        }
    };

    // Test #5
    TEST_CLASS(LoadAndRouteUpdateIntegrationTest5)
    {
    public:
        TEST_METHOD(Test_LoadAndRouteUpdate5)
        {
            // Define where the delivery point is
            struct Point deliveryPoint = { 10, 10 };
            Map map = populateMap();

            // Create multiple trucks
            Truck truckD = { 'D', 0, 0, 0, 0, {}, {} };
            Truck truckE = { 'E', 0, 0, 0, 0, {}, {} };
            Truck truckF = { 'F', 0, 0, 0, 0, {}, {} };
            struct Shipments shipment = { 100, 5 }; // Weight: 100, Volume: 5

            // load the shipment untill max capacity
            for (int i = 0; i < MAX_SHIPMENTS; ++i) {
                LoadShipmentOntoTruck(&truckD, shipment);
                LoadShipmentOntoTruck(&truckE, shipment);
                LoadShipmentOntoTruck(&truckF, shipment);
            }

            // attempt to load to a maxed capacity
            LoadShipmentOntoTruck(&truckD, shipment);
            LoadShipmentOntoTruck(&truckE, shipment);
            LoadShipmentOntoTruck(&truckF, shipment);
            
            // update route for each truck
            UpdateTruckRoute(&truckD, map);
            UpdateTruckRoute(&truckE, map);
            UpdateTruckRoute(&truckF, map);

            // find shortest path from each truck
            double distanceD = distance(&truckD.DeliveryPath.points[0], &deliveryPoint);
            double distanceE = distance(&truckE.DeliveryPath.points[0], &deliveryPoint);
            double distanceF = distance(&truckF.DeliveryPath.points[0], &deliveryPoint);

            // expected nearest truck is
            char expected_nearest_truck = truckD.routeSymbol;

            // Find nearest truck to the delivery point
            char nearestTruck = expected_nearest_truck;
            double minDistance = distanceD; // start with truckD
            if (distanceE < minDistance) {
                minDistance = distanceE;
                nearestTruck = truckE.routeSymbol;
            }
            if (distanceF < minDistance) {
                minDistance = distanceF;
                nearestTruck = truckF.routeSymbol;
            }
            Assert::AreEqual(expected_nearest_truck, nearestTruck);
        }
    };
}
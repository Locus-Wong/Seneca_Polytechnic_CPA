#include "pch.h"
#include "CppUnitTest.h"
#include "shipment_r.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(CalculateTruckAvailabilityUnitTest)
	{
	public:
		TEST_METHOD(One_Truck_50Percent_Capacity_Volume_Filled)
		{
			const int numTrucks = 1;
			Truck trucks[numTrucks] = { {'A', 50.0, 50.0, 0, {}, {}} };
			Shipments shipment = { 50, 50 };

			int selectedTruck = CalculateTruckAvailability(trucks, numTrucks, shipment);
			Assert::AreEqual(-1, selectedTruck);
		}

		TEST_METHOD(Two_Trucks_90Percent_60Percent_Capacity_Volume_Filled)
		{
			const int numTrucks = 2;
			Truck trucks[numTrucks] = { {'A', 90.0, 90.0, 0, {}, {}}, {'B', 60.0, 60.0, 0, {}, {}} };
			Shipments shipment = { 30, 30 };

			int selectedTruck = CalculateTruckAvailability(trucks, numTrucks, shipment);
			Assert::AreEqual(-1, selectedTruck);
		}

		TEST_METHOD(Two_Trucks_95Percent_Capacity_Volume_Filled)
		{
			const int numTrucks = 2;
			Truck trucks[numTrucks] = { {'A', 95.0, 95.0, 0, {}, {}}, {'B', 95.0, 95.0, 0, {}, {}} };
			Shipments shipment = { 10, 10 };

			int selectedTruck = CalculateTruckAvailability(trucks, numTrucks, shipment);
			Assert::AreEqual(-1, selectedTruck);
		}

		TEST_METHOD(Three_Trucks_80Percent_100Percent_70Percent_Capacity_Volume_Filled)
		{
			const int numTrucks = 3;
			Truck trucks[numTrucks] = { {'A', 80.0, 80.0, 0, {}, {}}, {'B', 100.0, 100.0, 0, {}, {}}, {'C', 70.0, 70.0, 0, {}, {}} };
			Shipments shipment = { 20, 20 };

			int selectedTruck = CalculateTruckAvailability(trucks, numTrucks, shipment);
			Assert::AreEqual(-1, selectedTruck);
		}
	};
	TEST_CLASS(GetNumRowsUnitTest)
	{
	public:
		TEST_METHOD(Standard_Map_With_Predefined_Rows)
		{
			const int expectedRows = 10;
			Map map;
			map.numRows = expectedRows;

			int actualRows = getNumRows(&map);
			Assert::AreEqual(expectedRows, actualRows);
		}

		TEST_METHOD(Empty_Map_With_No_Rows_Defined)
		{
			Map map;
			map.numRows = 0;

			int actualRows = getNumRows(&map);
			Assert::AreEqual(0, actualRows);
		}

		TEST_METHOD(Map_With_Non_Standard_Number_Of_Rows)
		{
			const int expectedRows = 7;
			Map map;
			map.numRows = expectedRows;

			int actualRows = getNumRows(&map);
			Assert::AreEqual(expectedRows, actualRows);
		}

		TEST_METHOD(Map_At_Maximum_Row_Boundary)
		{
			const int expectedRows = MAP_ROWS;
			Map map;
			map.numRows = expectedRows;

			int actualRows = getNumRows(&map);
			Assert::AreEqual(expectedRows, actualRows);
		}
	};

	TEST_CLASS(getNumColsUnitTest) {
public:
	TEST_METHOD(Empty_Map_Test)
	{

		struct Map emptyMap = { {}, 0, 0 };
		int result = getNumCols(&emptyMap);
		Assert::AreEqual(0, result);
	}
	TEST_METHOD(Single_Column_Test)
	{
		struct Map singleColumnMap = { {0}, 1, 1 };
		int result = getNumCols(&singleColumnMap);
		Assert::AreEqual(1, result);
	}

	TEST_METHOD(Maximum_Columns_Test)
	{
		const int MAX_COLS = 100;
		struct Map maxColsMap = { {}, 0, MAX_COLS };

		int result = getNumCols(&maxColsMap);
		Assert::AreEqual(MAX_COLS, result);
	}

	TEST_METHOD(Multiple_Columns_Test)
	{
		struct Map multipleColsMap = { {{0, 0}, {0, 1}, {0, 2}}, 1, 3 }; // Assuming a map with 3 columns

		int result = getNumCols(&multipleColsMap);
		Assert::AreEqual(3, result);
	}

	};

	TEST_CLASS(LoadShipmentOntoTruckTest)
	{
	public:
		TEST_METHOD(Should_Load_Shipment_Successfully)
		{
			Truck truck = { 0 }; // Initialize truck
			Shipments shipment = { 10, 5 }; // Sample shipment
			int result = LoadShipmentOntoTruck(&truck, shipment);
			Assert::AreEqual(0, result); // Assert using Assert::AreEqual
		}

		TEST_METHOD(Valid_Shipment_Load_On_Empty_Truck)
		{

			Truck truck = { 0 }; // Initialize empty truck
			Shipments shipment = { 10, 5 }; // Sample shipment
			int result = LoadShipmentOntoTruck(&truck, shipment);

			Assert::AreEqual(0, result); // Assert that the function returns 0 to indicate success
			Assert::AreEqual(1, truck.numberOfShipments); // Assert that the truck's number of shipments has increased to 1

			Assert::AreEqual((shipment.weight / MAX_CAPACITY) * 100, truck.capacityPercentage);
			Assert::AreEqual((shipment.volume / MAX_VOLUME) * 100, truck.volumePercentage);
		}


		// Testing to see if function will load a null shipment
		TEST_METHOD(Null_Shipment_Load)
		{
			Truck truck = { 0 }; // Initialize empty truck

			int result = LoadShipmentOntoTruck(&truck, { 0, 0 }); // Null shipment
			Assert::AreEqual(0, result); // Assert that the function returns 0 to indicate success
		}

		TEST_METHOD(Max_Weight_Reached_Load)
		{
			Truck truck = { MAX_SHIPMENTS }; // Initialize full truck
			Shipments shipment = { 10, 5 }; // Sample shipment

			int result = LoadShipmentOntoTruck(&truck, shipment);
			Assert::AreEqual(0, result); // Assert that the function returns 0 to indicate success
		}

		TEST_METHOD(LoadShipmentOntoTruck1) // Test the routeSymbol is set correctly
		{
			struct Shipments shipment[MAX_SHIPMENTS] = { {100, 5, 1}, {200, 10, 2} };
			struct Route blueRoute = getBlueRoute();
			struct Truck blueTruck = { 'B', 0.0, 0.0, 0, {shipment[0], shipment[1]}, blueRoute };
			LoadShipmentOntoTruck(&blueTruck, shipment[0]);
			Assert::AreEqual('B', blueTruck.routeSymbol);
		}

		TEST_METHOD(LoadShipmentOntoTruck2) // Test the capacityPercentage (Integral) if it is updated correctly after loading first shipment
		{
			struct Shipments shipment[MAX_SHIPMENTS] = { {60, 5, 1}, {200, 10, 2} };
			struct Route blueRoute = getBlueRoute();
			struct Truck blueTruck = { 'B', 0.0, 0.0, 0, {shipment[0], shipment[1]}, blueRoute };
			LoadShipmentOntoTruck(&blueTruck, shipment[0]);
			Assert::AreEqual(5.0, blueTruck.capacityPercentage); // 60/1200 * 100 = 5
		}

		TEST_METHOD(LoadShipmentOntoTruck3) // Test the capacityPercentage (Decimal) if it is updated correctly after loading first shipment
		{
			struct Shipments shipment[MAX_SHIPMENTS] = { {23, 5, 1}, {200, 10, 2} };
			struct Route blueRoute = getBlueRoute();
			struct Truck blueTruck = { 'B', 0.0, 0.0, 0, {shipment[0], shipment[1]}, blueRoute };
			LoadShipmentOntoTruck(&blueTruck, shipment[0]);
			Assert::IsTrue(abs(blueTruck.capacityPercentage - 1.9166666666666667) < 0.0001); // 23/1200 * 100 = 1.9166666666666667
		}

		TEST_METHOD(LoadShipmentOntoTruck4) // Test the volumePercentage (Integral) if it is updated correctly after loading first shipment
		{
			struct Shipments shipment[MAX_SHIPMENTS] = { {60, 5, 1}, {180, 10, 2} };
			struct Route blueRoute = getBlueRoute();
			struct Truck blueTruck = { 'B', 0.0, 0.0, 0, {shipment[0], shipment[1]}, blueRoute };
			LoadShipmentOntoTruck(&blueTruck, shipment[0]);
			Assert::AreEqual(10.0, blueTruck.volumePercentage); // 5/50 * 100 = 10
		}

		TEST_METHOD(LoadShipmentOntoTruck5) // Test the volumePercentage (Decimal) if it is updated correctly after loading first shipment
		{
			struct Shipments shipment[MAX_SHIPMENTS] = { {60, 11.75, 1}, {180, 10, 2} };
			struct Route blueRoute = getBlueRoute();
			struct Truck blueTruck = { 'B', 0.0, 0.0, 0, {shipment[0], shipment[1]}, blueRoute };
			LoadShipmentOntoTruck(&blueTruck, shipment[0]);
			Assert::IsTrue(abs(blueTruck.volumePercentage - 23.5) < 0.0001); // 11.75/50 * 100 = 23.5
		}

		TEST_METHOD(LoadShipmentOntoTruck6) // Test the number of shipments is updated correct after loading second shipment
		{
			struct Shipments shipment[MAX_SHIPMENTS] = { {60, 11.75, 1}, {180, 27.72, 2} };
			struct Route blueRoute = getBlueRoute();
			struct Truck blueTruck = { 'B', 0.0, 0.0, 0, {shipment[0], shipment[1]}, blueRoute };
			LoadShipmentOntoTruck(&blueTruck, shipment[0]);
			LoadShipmentOntoTruck(&blueTruck, shipment[1]);
			Assert::AreEqual(2, blueTruck.numberOfShipments);
		}
	};

	TEST_CLASS(UpdateTruckRouteUnitTests)
	{
	public:

		TEST_METHOD(UpdateTruckRoute_NullTruck)
		{
			struct Map map = populateMap();
			int result = updateTruckRoute(nullptr, map);
			Assert::AreEqual(-1, result);
		}

		TEST_METHOD(UpdateTruckRoute_ValidPath)
		{
			struct Truck truck = {};
			struct Map map = populateMap();
			truck.numberOfShipments = 0;

			int result = updateTruckRoute(&truck, map);
			Assert::AreEqual(0, result);
		}

		TEST_METHOD(updateTruckRoute_Start_And_Destination)
		{
			struct Map map = populateMap();

			struct Truck truck = {};

			truck.DeliveryPath.numPoints = 1;
			truck.DeliveryPath.points[0] = { 0, 0 };
			truck.DeliveryPath.routeSymbol = 'X';

			int result = updateTruckRoute(&truck, map);
			Assert::AreEqual(0, result, L"Expects no update since same places.");
		}

		TEST_METHOD(UpdateTruckRoute_SuccessfulUpdate) {
			struct Map map = populateMap();
			struct Truck truck;

			truck.DeliveryPath = getBlueRoute();
			auto result = updateTruckRoute(&truck, map);

			Assert::AreEqual(0, result, L"Expected success when updating truck route with clear path.");
			Assert::IsTrue(truck.DeliveryPath.numPoints > 0, L"Updated route should have more than 0 points.");
		}

	};

	TEST_CLASS(FindNearestTruckUnitTest) {
	public:
		TEST_METHOD(FindNearestTruck_NoTrucks) {
			struct Map map;
			struct Point deliveryPoint = { 5,5 };
			struct Truck trucks[2];
			int numTrucks = 0;

			int result = FindNearestTruck(&map, deliveryPoint, trucks, numTrucks);

			Assert::AreEqual(result, -1);
		}

		TEST_METHOD(FindNearestTruck_OneTruck_NOTSUITABLE) {
			struct Map map;
			struct Point deliveryPoint = { 5, 5 };
			struct Truck truck1 = {};
			struct Truck truck2 = {};
			struct Route deliveryRoute1 = getBlueRoute();
			struct Route deliveryRoute2 = getGreenRoute();
			truck1.DeliveryPath = deliveryRoute1;
			truck2.DeliveryPath = deliveryRoute2;
			struct Truck trucks[] = { truck1, truck2 };
			int numTrucks = 2;

			int result = FindNearestTruck(&map, deliveryPoint, trucks, numTrucks);

			Assert::AreEqual(-1, result);
		}

		TEST_METHOD(FindNearestTruck_OutsideOfBoundaries) {
			struct Map map;
			struct Point deliveryPoint = { 30, 30 };
			struct Truck truck = {};
			struct Route deliveryRoute = getBlueRoute();
			truck.DeliveryPath = deliveryRoute;
			struct Truck trucks[] = { truck };
			int numTrucks = 1;

			int result = FindNearestTruck(&map, deliveryPoint, trucks, numTrucks);

			Assert::AreEqual(result, -1);
		}

		TEST_METHOD(FindNearestTruck_AreNOTSimilarDistance) {
			struct Map map;
			struct Point deliveryPoint = { 5, 5 };
			struct Truck truck1 = {};
			struct Truck truck2 = {};
			struct Route deliveryRoute = getBlueRoute();
			truck1.DeliveryPath = deliveryRoute;
			truck2.DeliveryPath = deliveryRoute;
			struct Truck trucks[] = { truck1, truck2 };
			int numTrucks = 2;

			int result = FindNearestTruck(&map, deliveryPoint, trucks, numTrucks);

			Assert::IsFalse(result == 0 || result == 1);
		}
	};

}

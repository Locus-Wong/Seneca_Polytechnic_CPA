#include "pch.h"
#include "CppUnitTest.h"
#include "readInfo_r.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LoadShipmentOntoTruckUnitTest
{
	TEST_CLASS(LoadShipmentOntoTruckUnitTest)
	{
	public:
		
		TEST_METHOD(LoadShipmentOntoTruck1) // Test the routeSymbol is set correctly
		{
			struct Shipments shipment[MAX_SHIPMENTS] = { {100, 5, 1}, {200, 10, 2} };
			struct Route blueRoute = getBlueRoute();
			struct Truck blueTruck = { 'B', 0.0, 0.0, 0, {shipment[0], shipment[1]}, blueRoute};
			LoadShipmentOntoTruck(&blueTruck, shipment[0]);
			Assert::AreEqual('B', blueTruck.routeSymbol);
		}

		TEST_METHOD(LoadShipmentOntoTruck2) // Test the routeSymbol is set correctly
		{
			struct Shipments shipment[MAX_SHIPMENTS] = { {100, 5, 1}, {200, 10, 2} };
			struct Route blueRoute = getBlueRoute();
			struct Truck blueTruck = { 'G', 0.0, 0.0, 0, {shipment[0], shipment[1]}, blueRoute };
			LoadShipmentOntoTruck(&blueTruck, shipment[0]);
			Assert::AreEqual('G', blueTruck.routeSymbol);
		}

		TEST_METHOD(LoadShipmentOntoTruck3) // Test the routeSymbol is set correctly
		{
			struct Shipments shipment[MAX_SHIPMENTS] = { {100, 5, 1}, {200, 10, 2} };
			struct Route blueRoute = getBlueRoute();
			struct Truck blueTruck = { 'Y', 0.0, 0.0, 0, {shipment[0], shipment[1]}, blueRoute };
			LoadShipmentOntoTruck(&blueTruck, shipment[0]);
			Assert::AreEqual('Y', blueTruck.routeSymbol);
		}

		TEST_METHOD(LoadShipmentOntoTruck4) // Test the capacityPercentage (Integral) if it is updated correctly after loading first shipment
		{
			struct Shipments shipment[MAX_SHIPMENTS] = { {60, 5, 1}, {200, 10, 2} };
			struct Route blueRoute = getBlueRoute();
			struct Truck blueTruck = { 'B', 0.0, 0.0, 0, {shipment[0], shipment[1]}, blueRoute };
			LoadShipmentOntoTruck(&blueTruck, shipment[0]);
			Assert::AreEqual(5.0, blueTruck.capacityPercentage); // 60/1200 * 100 = 5
		}

		TEST_METHOD(LoadShipmentOntoTruck5) // Test the capacityPercentage (Integral) if it is updated correctly after loading second shipment
		{
			struct Shipments shipment[MAX_SHIPMENTS] = { {60, 5, 1}, {180, 10, 2} };
			struct Route blueRoute = getBlueRoute();
			struct Truck blueTruck = { 'B', 0.0, 0.0, 0, {shipment[0], shipment[1]}, blueRoute };
			LoadShipmentOntoTruck(&blueTruck, shipment[0]);
			LoadShipmentOntoTruck(&blueTruck, shipment[1]);
			Assert::AreEqual(20.0, blueTruck.capacityPercentage); // 240/1200 * 100 = 20
		}

		TEST_METHOD(LoadShipmentOntoTruck6) // Test the capacityPercentage (Decimal) if it is updated correctly after loading first shipment
		{
			struct Shipments shipment[MAX_SHIPMENTS] = { {23, 5, 1}, {200, 10, 2} };
			struct Route blueRoute = getBlueRoute();
			struct Truck blueTruck = { 'B', 0.0, 0.0, 0, {shipment[0], shipment[1]}, blueRoute };
			LoadShipmentOntoTruck(&blueTruck, shipment[0]);
			Assert::IsTrue(abs(blueTruck.capacityPercentage - 1.9166666666666667) < 0.0001); // 23/1200 * 100 = 1.9166666666666667
		}

		TEST_METHOD(LoadShipmentOntoTruck7) // Test the capacityPercentage (Decimal) if it is updated correctly after loading first shipment
		{
			struct Shipments shipment[MAX_SHIPMENTS] = { {23, 5, 1}, {44, 10, 2} };
			struct Route blueRoute = getBlueRoute();
			struct Truck blueTruck = { 'B', 0.0, 0.0, 0, {shipment[0], shipment[1]}, blueRoute };
			LoadShipmentOntoTruck(&blueTruck, shipment[0]);
			LoadShipmentOntoTruck(&blueTruck, shipment[1]);
			Assert::IsTrue(abs(blueTruck.capacityPercentage - 5.583333333333333) < 0.0001); // 67/1200 * 100 = 5.583333333333333
		}



		TEST_METHOD(LoadShipmentOntoTruck8) // Test the volumePercentage (Integral) if it is updated correctly after loading first shipment
		{
			struct Shipments shipment[MAX_SHIPMENTS] = { {60, 5, 1}, {180, 10, 2} };
			struct Route blueRoute = getBlueRoute();
			struct Truck blueTruck = { 'B', 0.0, 0.0, 0, {shipment[0], shipment[1]}, blueRoute };
			LoadShipmentOntoTruck(&blueTruck, shipment[0]);
			Assert::AreEqual(10.0, blueTruck.volumePercentage); // 5/50 * 100 = 10
		}

		TEST_METHOD(LoadShipmentOntoTruck9) // Test the volumePercentage (Integral) if it is updated correctly after loading second shipment
		{
			struct Shipments shipment[MAX_SHIPMENTS] = { {60, 5, 1}, {180, 10, 2} };
			struct Route blueRoute = getBlueRoute();
			struct Truck blueTruck = { 'B', 0.0, 0.0, 0, {shipment[0], shipment[1]}, blueRoute };
			LoadShipmentOntoTruck(&blueTruck, shipment[0]);
			LoadShipmentOntoTruck(&blueTruck, shipment[1]);
			Assert::AreEqual(30.0, blueTruck.volumePercentage); // 15/50 * 100 = 30
		}

		TEST_METHOD(LoadShipmentOntoTruck10) // Test the volumePercentage (Decimal) if it is updated correctly after loading first shipment
		{
			struct Shipments shipment[MAX_SHIPMENTS] = { {60, 11.75, 1}, {180, 10, 2} };
			struct Route blueRoute = getBlueRoute();
			struct Truck blueTruck = { 'B', 0.0, 0.0, 0, {shipment[0], shipment[1]}, blueRoute };
			LoadShipmentOntoTruck(&blueTruck, shipment[0]);
			Assert::IsTrue(abs(blueTruck.volumePercentage - 23.5) < 0.0001); // 11.75/50 * 100 = 23.5
		}

		TEST_METHOD(LoadShipmentOntoTruck11) // Test the volumePercentage (Decimal) if it is updated correctly after loading second shipment
		{
			struct Shipments shipment[MAX_SHIPMENTS] = { {60, 11.75, 1}, {180, 27.72, 2} };
			struct Route blueRoute = getBlueRoute();
			struct Truck blueTruck = { 'B', 0.0, 0.0, 0, {shipment[0], shipment[1]}, blueRoute };
			LoadShipmentOntoTruck(&blueTruck, shipment[0]);
			LoadShipmentOntoTruck(&blueTruck, shipment[1]);
			Assert::IsTrue(abs(blueTruck.volumePercentage - 78.94) < 0.0001); // 39.47/50 * 100 = 78.94
		}

		TEST_METHOD(LoadShipmentOntoTruck12) // Test the number of shipments is updated correct after loading first shipment
		{
			struct Shipments shipment[MAX_SHIPMENTS] = { {60, 11.75, 1}, {180, 27.72, 2} };
			struct Route blueRoute = getBlueRoute();
			struct Truck blueTruck = { 'B', 0.0, 0.0, 0, {shipment[0], shipment[1]}, blueRoute };
			LoadShipmentOntoTruck(&blueTruck, shipment[0]);
			Assert::AreEqual(1, blueTruck.numberOfShipments);
		}

		TEST_METHOD(LoadShipmentOntoTruck13) // Test the number of shipments is updated correct after loading second shipment
		{
			struct Shipments shipment[MAX_SHIPMENTS] = { {60, 11.75, 1}, {180, 27.72, 2} };
			struct Route blueRoute = getBlueRoute();
			struct Truck blueTruck = { 'B', 0.0, 0.0, 0, {shipment[0], shipment[1]}, blueRoute };
			LoadShipmentOntoTruck(&blueTruck, shipment[0]);
			LoadShipmentOntoTruck(&blueTruck, shipment[1]);
			Assert::AreEqual(2, blueTruck.numberOfShipments);
		}
	};
}

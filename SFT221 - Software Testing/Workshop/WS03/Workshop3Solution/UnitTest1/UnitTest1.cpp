#include "pch.h"
#include "CppUnitTest.h"
#include "readInfo_r.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
namespace MathTestSuite
{
	TEST_CLASS(Verification_Blackbox)
	{
	public:
		TEST_METHOD(postalCodeTest)
		{
			// valid input (upper case with white space)
			struct Customer c = { "John", "Doe", "123 Main St.", "Toronto", "ON", "M2N 0G1" };
			int result = postalCodeVerification(c.postalCode);
			Assert::AreEqual(1, result);
		}
		TEST_METHOD(postalCodeTest2)
		{
			// valid input (upper case without white space)
			struct Customer c = { "John", "Doe", "123 Main St.", "Toronto", "ON", "M2N0G1" };
			int result = postalCodeVerification(c.postalCode);
			Assert::AreEqual(1, result);
		}

		TEST_METHOD(postalCodeTest3)
		{
			// valid input (lower case with white space)
			struct Customer c = { "John", "Doe", "123 Main St.", "Toronto", "ON", "m2n 0g1" };
			int result = postalCodeVerification(c.postalCode);
			Assert::AreEqual(1, result);
		}

		TEST_METHOD(postalCodeTest4)
		{
			// valid input (lower case without white space)
			struct Customer c = { "John", "Doe", "123 Main St.", "Toronto", "ON", "m2n0g1" };
			int result = postalCodeVerification(c.postalCode);
			Assert::AreEqual(1, result);
		}

		TEST_METHOD(postalCodeTest5)
		{
			// valid input (mixed case with white space)
			struct Customer c = { "John", "Doe", "123 Main St.", "Toronto", "ON", "m2N 0g1" };
			int result = postalCodeVerification(c.postalCode);
			Assert::AreEqual(1, result);
		}

		TEST_METHOD(postalCodeTest6)
		{
			// valid input (mixed case without white space)
			struct Customer c = { "John", "Doe", "123 Main St.", "Toronto", "ON", "M2n0g1" };
			int result = postalCodeVerification(c.postalCode);
			Assert::AreEqual(1, result);
		}

		TEST_METHOD(postalCodeTest7)
		{
			// valid input (upper case with many white space)
			struct Customer c = { "John", "Doe", "123 Main St.", "Toronto", "ON", "M  2 N 0  G  1 " };
			int result = postalCodeVerification(c.postalCode);
			Assert::AreEqual(1, result);
		}

		TEST_METHOD(postalCodeTest8)
		{
			// valid input (lower case with many white space)
			struct Customer c = { "John", "Doe", "123 Main St.", "Toronto", "ON", "m  2 n 0  g  1 " };
			int result = postalCodeVerification(c.postalCode);
			Assert::AreEqual(1, result);
		}


		TEST_METHOD(postalCodeTest9)
		{
			// valid input (mixed case with many white space)
			struct Customer c = { "John", "Doe", "123 Main St.", "Toronto", "ON", "M  2 n 0  g  1 " };
			int result = postalCodeVerification(c.postalCode);
			Assert::AreEqual(1, result);
		}

		TEST_METHOD(postalCodeTest10)
		{
			// valid input (upper case with leading white space)
			struct Customer c = { "John", "Doe", "123 Main St.", "Toronto", "ON", "   M2N 0G1" };
			int result = postalCodeVerification(c.postalCode);
			Assert::AreEqual(1, result);
		}

		TEST_METHOD(postalCodeTest11)
		{
			// valid input (lower case with leading white space)
			struct Customer c = { "John", "Doe", "123 Main St.", "Toronto", "ON", "   m2n 0g1" };
			int result = postalCodeVerification(c.postalCode);
			Assert::AreEqual(1, result);
		}

		TEST_METHOD(postalCodeTest12)
		{
			// valid input (mixed case with leading white space)
			struct Customer c = { "John", "Doe", "123 Main St.", "Toronto", "ON", "    M2n0g1" };
			int result = postalCodeVerification(c.postalCode);
			Assert::AreEqual(1, result);
		}

		TEST_METHOD(postalCodeTest13)
		{
			// valid input (upper case with trailing white space)
			struct Customer c = { "John", "Doe", "123 Main St.", "Toronto", "ON", "M2N 0G1    " };
			int result = postalCodeVerification(c.postalCode);
			Assert::AreEqual(1, result);
		}

		TEST_METHOD(postalCodeTest14)
		{
			// valid input (lower case with trailing white space)
			struct Customer c = { "John", "Doe", "123 Main St.", "Toronto", "ON", "m2n 0g1    " };
			int result = postalCodeVerification(c.postalCode);
			Assert::AreEqual(1, result);
		}

		TEST_METHOD(postalCodeTest15)
		{
			// valid input (mixed case with trailing white space)
			struct Customer c = { "John", "Doe", "123 Main St.", "Toronto", "ON", "M2n0g1    " };
			int result = postalCodeVerification(c.postalCode);
			Assert::AreEqual(1, result);
		}

		TEST_METHOD(postalCodeTest16)
		{
			// valid input (upper case with leading white space and trailing white space)
			struct Customer c = { "John", "Doe", "123 Main St.", "Toronto", "ON", "   M2N 0G1   " };
			int result = postalCodeVerification(c.postalCode);
			Assert::AreEqual(1, result);
		}

		TEST_METHOD(postalCodeTest17)
		{
			// valid input (lower case with leading white space and trailing white space)
			struct Customer c = { "John", "Doe", "123 Main St.", "Toronto", "ON", "   m2n 0g1   " };
			int result = postalCodeVerification(c.postalCode);
			Assert::AreEqual(1, result);
		}

		TEST_METHOD(postalCodeTest18)
		{
			// valid input (mixed case with leading white space and trailing white space)
			struct Customer c = { "John", "Doe", "123 Main St.", "Toronto", "ON", "    M2n0g1    " };
			int result = postalCodeVerification(c.postalCode);
			Assert::AreEqual(1, result);
		}

		TEST_METHOD(postalCodeTest19)
		{
			// valid input (upper case with many leading white space and trailing white space)
			struct Customer c = { "John", "Doe", "123 Main St.", "Toronto", "ON", " M 2 N 0  G  1 " };
			int result = postalCodeVerification(c.postalCode);
			Assert::AreEqual(1, result);
		}

		TEST_METHOD(postalCodeTest20)
		{
			// valid input (lower case with many leading white space and trailing white space)
			struct Customer c = { "John", "Doe", "123 Main St.", "Toronto", "ON", "  m 2 n 0  g 1 " };
			int result = postalCodeVerification(c.postalCode);
			Assert::AreEqual(1, result);
		}


		TEST_METHOD(postalCodeTest21)
		{
			// valid input (mixed case with many leading white space and trailing white space)
			struct Customer c = { "John", "Doe", "123 Main St.", "Toronto", "ON", "  M 2 n 0  g 1 " };
			int result = postalCodeVerification(c.postalCode);
			Assert::AreEqual(1, result);
		}

		TEST_METHOD(postalCodeTest22)
		{
			// invalid input (upper case with a special character)
			struct Customer c = { "John", "Doe", "123 Main St.", "Toronto", "ON", "M2N,0G1" };
			int result = postalCodeVerification(c.postalCode);
			Assert::AreEqual(0, result);
		}

		TEST_METHOD(postalCodeTest23)
		{
			// invalid input (lower case with a special character)
			struct Customer c = { "John", "Doe", "123 Main St.", "Toronto", "ON", "m2n,0g1" };
			int result = postalCodeVerification(c.postalCode);
			Assert::AreEqual(0, result);
		}

		TEST_METHOD(postalCodeTest24)
		{
			// invalid input (mixed case with a special character)
			struct Customer c = { "John", "Doe", "123 Main St.", "Toronto", "ON", "M2n,0G1" };
			int result = postalCodeVerification(c.postalCode);
			Assert::AreEqual(0, result);
		}

		TEST_METHOD(postalCodeTest25)
		{
			// invalid input (upper case with special characters)
			struct Customer c = { "John", "Doe", "123 Main St.", "Toronto", "ON", "@$%^#M2N 0G1!&*" };
			int result = postalCodeVerification(c.postalCode);
			Assert::AreEqual(0, result);
		}

		TEST_METHOD(postalCodeTest26)
		{
			// invalid input (lower case with special characters)
			struct Customer c = { "John", "Doe", "123 Main St.", "Toronto", "ON", "@$%^#m2n 0g1!&*" };
			int result = postalCodeVerification(c.postalCode);
			Assert::AreEqual(0, result);
		}

		TEST_METHOD(postalCodeTest27)
		{
			// invalid input (mixed case with special characters)
			struct Customer c = { "John", "Doe", "123 Main St.", "Toronto", "ON", "@$%^#M2n 0G1!&*" };
			int result = postalCodeVerification(c.postalCode);
			Assert::AreEqual(0, result);
		}

	};

	TEST_CLASS(Verification_Whitebox)
	{
	public:
		TEST_METHOD(postalCodeTest)
		{
			// invalid input (empty string)
			struct Customer c = { "John", "Doe", "123 Main St.", "Toronto", "ON", ""};
			int result = postalCodeVerification(c.postalCode);
			Assert::AreEqual(0, result);
		}

		TEST_METHOD(postalCodeTest1)
		{
			// invalid input (NULL)
			struct Customer c = { "John", "Doe", "123 Main St.", "Toronto", "ON", NULL};
			int result = postalCodeVerification(c.postalCode);
			Assert::AreEqual(0, result);
		}

		TEST_METHOD(postalCodeTest2)
		{
			// invalid input (string with only white spaces)
			struct Customer c = { "John", "Doe", "123 Main St.", "Toronto", "ON", "   " };
			int result = postalCodeVerification(c.postalCode);
			Assert::AreEqual(0, result);
		}

		TEST_METHOD(postalCodeTest3)
		{
			// invalid input (string with only tabs)
			struct Customer c = { "John", "Doe", "123 Main St.", "Toronto", "ON", "\t\t" };
			int result = postalCodeVerification(c.postalCode);
			Assert::AreEqual(0, result);
		}

		TEST_METHOD(postalCodeTest4)
		{
			// invalid input (string with only tabs)
			struct Customer c = { "John", "Doe", "123 Main St.", "Toronto", "ON", "M2N \t0G1" };
			int result = postalCodeVerification(c.postalCode);
			Assert::AreEqual(0, result);
		}
		TEST_METHOD(postalCodeTest5)
		{
			// invalid input (string with only newlines)
			struct Customer c = { "John", "Doe", "123 Main St.", "Toronto", "ON", "\n\n" };
			int result = postalCodeVerification(c.postalCode);
			Assert::AreEqual(0, result);
		}

		TEST_METHOD(postalCodeTest6)
		{
			// invalid input (string with only newline)
			struct Customer c = { "John", "Doe", "123 Main St.", "Toronto", "ON", "M2N \n0G1" };
			int result = postalCodeVerification(c.postalCode);
			Assert::AreEqual(0, result);
		}
	};
}
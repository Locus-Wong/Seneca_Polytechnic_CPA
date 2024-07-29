/*
 Name: Tsz Wa Wong
 Email: twwong9@myseneca.ca
 Student ID: 152181228
 Date: 20 Jul 2024
 I declare that this submission is the result of my own work and
 I only copied the code that my professor provided to complete my
 workshops and assignments. This submitted piece of work has not
 been shared with any other student or 3rd party content provider.
 */
#ifndef SENECA_CUSTOMERORDER_H
#define SENECA_CUSTOMERORDER_H
#include <string>
#include "Station.h"
namespace seneca
{
	class CustomerOrder
	{
		struct Item
		{
			std::string m_itemName{};
			size_t m_serialNumber{ 0 };
			bool m_isFilled{ false };
			Item(const std::string& src) : m_itemName(src) {};
		};

		std::string m_name{}; // – the name of the customer
		std::string m_product{}; // – the name of the product being assembled
		size_t m_cntItem{}; // a count of the number of items in the customer's order
		Item** m_lstItem{}; // Each element of the array points to a dynamically allocated object of type Item 
		static size_t m_widthField;
	public:
		CustomerOrder() = default;
		CustomerOrder(const std::string& record);
		CustomerOrder(const CustomerOrder& src); // Copy constructor
		CustomerOrder& operator=(const CustomerOrder& src) = delete; // Copy assignment operator
		CustomerOrder(CustomerOrder&& src) noexcept; // Move constructor
		CustomerOrder& operator=(CustomerOrder&& src) noexcept; // Move assignment operator

		~CustomerOrder();
		bool isItemFilled(const std::string& itemName) const;
		bool isOrderFilled() const;
		void fillItem(Station& station, std::ostream& os);
		void display(std::ostream& os) const;
	};
}
#endif
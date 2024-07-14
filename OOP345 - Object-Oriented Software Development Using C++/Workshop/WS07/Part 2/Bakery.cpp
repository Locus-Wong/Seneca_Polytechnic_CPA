/*
 Name: Tsz Wa Wong
 Email: twwong9@myseneca.ca
 Student ID: 152181228
 Date: 13 Jul 2024
 I declare that this submission is the result of my own work and
 I only copied the code that my professor provided to complete my
 workshops and assignments. This submitted piece of work has not
 been shared with any other student or 3rd party content provider.
 */
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include "Bakery.h"
namespace seneca
{
	Bakery::Bakery(const char* filename)
	{
		auto removeSpace = [](std::string& name) -> std::string&
		{
				size_t start = name.find_first_not_of(' '); // Find the first non-space character
				size_t end = name.find_last_not_of(' '); // Find the last non-space character
				if (start != std::string::npos && end != std::string::npos)
				{
					name = name.substr(start, end - start + 1); // Extract the substring without leading and trailing spaces
				}
				else
				{
					name.clear(); // The string is all spaces
				}
				return name;

		};
		std::ifstream file(filename);
		if (file.is_open())
		{
			std::string line;
			while (std::getline(file, line))
			{
				BakedGood bg;
				std::string bakedTypeStr = line.substr(0, 8);
				bg.m_description = line.substr(8, 20);
				bg.m_shelfLife = std::stoi(line.substr(28, 14));
				bg.m_stock = std::stoi(line.substr(42, 8));
				bg.m_price = std::stod(line.substr(50, 6));
				bakedTypeStr = removeSpace(bakedTypeStr);
				bg.m_description = removeSpace(bg.m_description);
				if (bakedTypeStr == "Bread")
				{
					bg.m_type = BakedType::BREAD;
				}
				else
				{
					bg.m_type = BakedType::PASTERY;
				}
				m_goods.push_back(bg); // Add the BakedGood object to the vector
			}
			file.close();
		}
		else
		{
			throw "File not found";
		}
	}

	void Bakery::showGoods(std::ostream& os) const
	{
		std::for_each(m_goods.begin(), m_goods.end(), [&os](const BakedGood& bg)
			{
				os << bg << std::endl;
			});

		// Calculate total stock
		int totalStock = std::accumulate(m_goods.begin(), m_goods.end(), 0, [](int totalStock, const BakedGood& bg) // 0 for int initial value
			{
				return totalStock + bg.m_stock;
			});

		// Calculate total price
		double totalPrice = std::accumulate(m_goods.begin(), m_goods.end(), 0.0, [](double totalPrice, const BakedGood& bg) // 0.0 for double initial value
			{
				return totalPrice + bg.m_price;
			});

		os << "Total Stock: " << totalStock << std::endl;
		os << "Total Price: " << std::fixed << std::setprecision(2) << totalPrice << std::endl;
	}

	void Bakery::sortBakery(const std::string& field)
	{
		std::sort(m_goods.begin(), m_goods.end(), [field](const BakedGood& bg1, const BakedGood& bg2)
			{
				if (field == "Description")
				{
					return bg1.m_description < bg2.m_description;
				}
				else if (field == "Shelf")
				{
					return bg1.m_shelfLife < bg2.m_shelfLife;
				}
				else if (field == "Stock")
				{
					return bg1.m_stock < bg2.m_stock;
				}
				else
				{
					return bg1.m_price < bg2.m_price;
				}
			});
	}

	std::vector<BakedGood> Bakery::combine(const Bakery& other)
	{
		std::vector<BakedGood> combinedGoods = m_goods; // Make a copy of current goods
		std::vector<BakedGood> temp = m_goods; // Make a copy of current goods
		combinedGoods.insert(combinedGoods.end(), other.m_goods.begin(), other.m_goods.end()); // Append other's goods to combinedGoods
		m_goods = combinedGoods; // Update m_goods
		sortBakery("Price"); // call sortBakery to avoid using the same algorithm twice across two different functions
		combinedGoods = m_goods; // Make a copy of the updated goods
		m_goods = temp; // Restore m_goods
		sortBakery("Price"); // sort for out of stock output
		return combinedGoods; // Return the combined and sorted collection
	}

	bool Bakery::inStock(const std::string& desc, const BakedType& type) const
	{
		// Searches for the first element in a range that satisfies a given condition
		auto it = std::find_if(m_goods.begin(), m_goods.end(), [desc, type](const BakedGood& bg)
			{
				return bg.m_description == desc && bg.m_type == type;
			});

		return it != m_goods.end(); // Returns true if the element is found, false otherwise
	}

	std::list<BakedGood> Bakery::outOfStock(const BakedType& type) const
	{
		std::list<BakedGood> outOfStockGoods; // List to store out of stock goods

		// Copies elements from one range to another, selectively based on a condition
		std::copy_if(m_goods.begin(), m_goods.end(), std::back_inserter(outOfStockGoods), [type](const BakedGood& bg)
			{
				return bg.m_type == type && bg.m_stock == 0;
			});

		return outOfStockGoods;
	}

	std::ostream& operator<<(std::ostream& out, const BakedGood& b)
	{
		out << "* " << std::left << std::setw(10) << (b.m_type == BakedType::BREAD ? "Bread" : "Pastry")
			<< " * " << std::setw(20) << b.m_description
			<< " * " << std::setw(5) << b.m_shelfLife
			<< " * " << std::setw(5) << b.m_stock
			<< " * " << std::right << std::setw(8) << std::fixed << std::setprecision(2) << b.m_price << " *";
		return out;
	}
}
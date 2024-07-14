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
#ifndef SENECA_BAKERY_H
#define SENECA_BAKERY_H
#include <string>
#include <vector>
#include <list>
namespace seneca
{
	enum class BakedType
	{
		BREAD, PASTERY
	};

	class BakedGood
	{
	public:
		BakedType m_type{};
		std::string m_description;
		int m_shelfLife{};
		int m_stock{};
		double m_price{};
	};

	class Bakery
	{
		std::vector<BakedGood> m_goods{};
		public:
			Bakery(const char* filename);
			void showGoods(std::ostream& os) const;
			void sortBakery(const std::string& field);
			std::vector<BakedGood> combine(const Bakery&);
			bool inStock(const std::string& desc, const BakedType& type) const;
			std::list<BakedGood> outOfStock(const BakedType& type) const;
	};

	std::ostream& operator<<(std::ostream& out, const BakedGood& b);
}
#endif
#include <iostream>
#include <iomanip>
#include "Bakery.h"
#include "Bakery.h" // intentional

int cout = 0; // won't compile if headers don't follow convention

void printstars(std::ostream& os, size_t cnt)
{
  for (auto i = 0u; i < cnt; ++i)
    os << "*";
  os << std::endl;
}

void printheader(const char* prompt, std::ostream& os)
{
  os << prompt << '\n';
  os << std::left << std::setw(15) << "Type" << std::setw(23) << "Description"
     << std::setw(8) << "Shelf" << std::setw(8) << "Stock"
     << std::right << std::setw(8) << "Price" << std::endl;
}

int main(int argc, char *argv[])
{
  std::cout << "Command Line:\n";
  std::cout << "--------------------------\n";
  for (int i = 0; i < argc; ++i)
    std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
  std::cout << "--------------------------\n\n";

  seneca::Bakery bakery(argv[1]);
  ::printheader("The original bakery" ,std::cout);
  ::printstars(std::cout, 64);
  bakery.showGoods(std::cout);
  ::printstars(std::cout, 64);

  // sort breads by desc, pastries by shelflife
  bakery.sortBakery("Description");
  ::printheader("Bakery sorted by desc", std::cout);
  ::printstars(std::cout, 64);
  bakery.showGoods(std::cout);
  ::printstars(std::cout, 64);

  bakery.sortBakery("Shelf");
  ::printheader("Bakery sorted by shelf", std::cout);
  ::printstars(std::cout, 64);
  bakery.showGoods(std::cout);
  ::printstars(std::cout, 64);

  // combine both bread and pastries
  ::printheader("The combined collection ordered by price", std::cout);
  ::printstars(std::cout, 64);
  auto combined = bakery.combine(bakery); // combine with self
  for (auto& x : combined)
    std::cout << x << std::endl;
  ::printstars(std::cout, 64);

  std::cout << "What is in stock?" << std::endl;
  if (bakery.inStock("Crossiant", seneca::BakedType::PASTERY))
    std::cout << "Crossiants are in stock" << std::endl;
  if (!(bakery.inStock("Candy Bread", seneca::BakedType::BREAD)))
    std::cout << "Candy Bread are not in stock" << std::endl;
  ::printstars(std::cout, 64);

  std::cout << "Out of Stock Pastries" << std::endl;
  auto oosPastry = bakery.outOfStock(seneca::BakedType::PASTERY);
  for (auto& x : oosPastry)
    std::cout << x << std::endl;
  ::printstars(std::cout, 64);

  std::cout << "Out of Stock Breads" << std::endl;
  auto oosBread = bakery.outOfStock(seneca::BakedType::BREAD);
  for (auto& x : oosBread)
    std::cout << x << std::endl;
  ::printstars(std::cout, 64);

  return cout;
}

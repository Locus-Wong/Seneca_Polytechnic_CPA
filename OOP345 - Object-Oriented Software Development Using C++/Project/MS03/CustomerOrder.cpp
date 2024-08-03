/*
 Name: Tsz Wa Wong
 Email: twwong9@myseneca.ca
 Student ID: 152181228
 Date: 03 Aug 2024
 I declare that this submission is the result of my own work and
 I only copied the code that my professor provided to complete my
 workshops and assignments. This submitted piece of work has not
 been shared with any other student or 3rd party content provider.
 */
#include <string>
#include <iomanip>
#include "Utilities.h"
#include "CustomerOrder.h"
namespace seneca
{
size_t CustomerOrder::m_widthField = 0;
CustomerOrder::CustomerOrder(const std::string& record)
{
    Utilities util;
    size_t pos = 0;
    bool more = true;
    m_name = util.extractToken(record, pos, more); // Extract the customer name
    m_product = util.extractToken(record, pos, more); // Extract the product name/order name
    m_cntItem = 0;
    m_lstItem = nullptr;
    while (more)
    {
        std::string temp = util.extractToken(record, pos, more); // Extract the item name
        Item** tempArray = new Item * [m_cntItem + 1];
        for (size_t i = 0; i < m_cntItem; ++i)
        {
            tempArray[i] = m_lstItem[i]; // Copy the ex of the array to the new array
        }
        tempArray[m_cntItem] = new Item(temp); // Dynamically allocate memory for the new item
        delete[] m_lstItem;
        m_lstItem = tempArray;
        ++m_cntItem;
    }
    if (util.getFieldWidth() > m_widthField)
    {
        m_widthField = util.getFieldWidth();
    }
}
CustomerOrder::CustomerOrder(const CustomerOrder& src)
{
    throw "Error"; // The copy constructor should throw an exception if called
}
CustomerOrder::CustomerOrder(CustomerOrder&& src) noexcept : m_name{ src.m_name }, m_product{ src.m_product }, m_cntItem{ src.m_cntItem }, m_lstItem{src.m_lstItem}
{
    // set the source object to a safe empty state
    src.m_name = "";
    src.m_product = "";
    src.m_cntItem = 0;
    src.m_lstItem = nullptr;
}

CustomerOrder& CustomerOrder::operator=(CustomerOrder&& src) noexcept
{
    if (this != &src)
    {
        // Deallocate the memory pointed to by the current object
        if (m_lstItem != nullptr)
        {
            for (size_t i = 0; i < m_cntItem; ++i)
            {
                delete m_lstItem[i]; // Deallocates the memory pointed to by each element of the array
            }
            delete[] m_lstItem; // Deallocates the memory pointed to by the array
        }
        // Copy the data from the source object
        m_name = src.m_name;
        m_product = src.m_product;
        m_cntItem = src.m_cntItem;
        m_lstItem = src.m_lstItem;
        // set the source object to a safe empty state
        src.m_name = "";
        src.m_product = "";
        src.m_cntItem = 0;
        src.m_lstItem = nullptr;
    }
    return *this;
}
CustomerOrder::~CustomerOrder()
{
    for (size_t i = 0; i < m_cntItem; ++i)
    {
        delete m_lstItem[i]; // Deallocates the memory pointed to by each element of the array
    }
    delete[] m_lstItem; // Deallocates the memory pointed to by the array
}
bool CustomerOrder::isItemFilled(const std::string& itemName) const
{
    bool isFilled = true;
    for (size_t i = 0; i < m_cntItem; ++i) {
        if (m_lstItem[i]->m_itemName == itemName)
        {
            if (m_lstItem[i]->m_isFilled == false)
            {
                isFilled = false; // if the item is not filled, return false
            } 
        }
    }
    return isFilled; // if all the iterms with the same name in the order are filled or the itemName doesn't exist in the order, return true
}
bool CustomerOrder::isOrderFilled() const
{
    for (size_t i = 0; i < m_cntItem; ++i)
    {
        if (m_lstItem[i]->m_isFilled == false)
        {
            return false; // if any item is not filled, return false
        }
    }
    return true; // if all items are filled, return true
}
void CustomerOrder::fillItem(Station& station, std::ostream& os)
{
    std::string itemName = station.getItemName();
    
    for (size_t i = 0; i < m_cntItem; ++i)
    {
        if (m_lstItem[i]->m_itemName == itemName && m_lstItem[i]->m_isFilled == false) // check if the item is not filled and the item name matches
        {
            if (station.getQuantity() > 0 ) // check if the station has inventory
            {
                m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
                m_lstItem[i]->m_isFilled = true;
                station.updateQuantity(); // subtracts 1 from the inventory
                os << "    Filled " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << std::endl;
                break; // only fill one item at a time
            }
            else
            {
                os << "    Unable to fill " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << std::endl;
            }
        }
    }
}
void CustomerOrder::display(std::ostream& os) const
{
    os << m_name << " - " << m_product << std::endl;
    for (size_t i = 0; i < m_cntItem; ++i)
    {
        os << "[" << std::right << std::setw(6) << std::setfill('0') << m_lstItem[i]->m_serialNumber << "] " << std::left
        << std::setw(static_cast<int>(m_widthField)) << std::setfill(' ') << m_lstItem[i]->m_itemName << " - "
        << (m_lstItem[i]->m_isFilled ? "FILLED" : "TO BE FILLED") << std::endl;
    }
}
}

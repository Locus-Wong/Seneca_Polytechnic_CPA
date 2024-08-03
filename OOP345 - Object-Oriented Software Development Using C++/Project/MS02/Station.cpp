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
#include <iostream>
#include <string>
#include <iomanip>
#include "Station.h"
#include "Utilities.h"
namespace seneca
{
	size_t Station::m_widthField = 0;
	unsigned int Station::id_generator = 0;

	Station::Station(const std::string& record)
	{
		size_t pos = 0;
		bool more = true;
		Utilities util;
		m_stationName = util.extractToken(record, pos, more);
		m_serialNumber = std::stoi(util.extractToken(record, pos, more)); // Convert the string to an integer
		m_qty = std::stoi(util.extractToken(record, pos, more)); // Convert the string to an integer
		// Update the widthField before extracting the station description, so that description does not affect the widthField
		if (m_stationName.size() > m_widthField)
		{
			m_widthField = m_stationName.size();
		}
		if (util.getFieldWidth() > m_widthField)
		{
			m_widthField = util.getFieldWidth();
		}
		m_stationDesc = util.extractToken(record, pos, more);
		m_stationId = ++id_generator; // Every time a new instance is created, the current value of the id_generator is stored in that instance, and id_generator is incremented.
	}

	const std::string& Station::getItemName() const
	{
		return m_stationName;
	}

	size_t Station::getNextSerialNumber()
	{
		return m_serialNumber++;
	}

	size_t Station::getQuantity() const
	{
		return m_qty;
	}

	void Station::updateQuantity()
	{
		m_qty--;
	}

	void Station::display(std::ostream& os, bool full) const
	{
		if (full)
		{
			os << std::setfill('0') << std::right << std::setw(3) << m_stationId << " | " 
				<< std::setfill(' ') << std::left << std::setw(static_cast<int>(m_widthField)) << m_stationName
				<< " | " << std::setfill('0') << std::right << std::setw(6) << m_serialNumber
				<< " | " << std::setfill(' ') <<  std::right << std::setw(4) << m_qty << " | " 
				<< std::left << m_stationDesc << std::endl;
		}
		else
		{
			os << std::setfill('0') << std::right << std::setw(3) << m_stationId << " | " 
				<< std::setfill(' ')  << std::left << std::setw(static_cast<int>(m_widthField)) << m_stationName
				<< " | " << std::setfill('0') << std::right << std::setw(6) << m_serialNumber
				<< " | " << std::endl;
		}
	}

}

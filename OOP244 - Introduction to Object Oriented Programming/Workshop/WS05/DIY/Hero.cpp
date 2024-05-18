//Name: Tsz Wa Wong
//Email: twwong9@myseneca.ca
//Student ID: 152181228
//Date: 21 Feb 2024
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Hero.h"
#include "Power.h"

using namespace std;
namespace seneca
{
	Hero::Hero()
	{
		m_name[0] = '\0';
		m_powers = nullptr;
		m_noOfPowers = 0;
		m_powerLevel = 0;
	}

Hero::Hero(const char* name, const Power* powers, const int noOfPowers) :m_name{}, m_powers(nullptr), m_noOfPowers{}, m_powerLevel{} // appear in the same order as they appear in the class definition
	{
		if (name && name[0] != '\0' && powers && noOfPowers)
		{
			strncpy(m_name, name, MAX_NAME_LENGTH);
			m_powers = new Power[noOfPowers];
			if (m_powers)
			{
				for (int i = 0; i < noOfPowers; i++)
				{
					m_powers[i] = powers[i];
				}
				m_noOfPowers = noOfPowers;
				for (int i = 0; i < noOfPowers; i++)
				{
					//The sum of the rarity of all the heroes' powers multiplied by the total count of powers.
					m_powerLevel += m_powers[i].checkRarity();

					if (i == noOfPowers - 1)
					{
						m_powerLevel *= noOfPowers;
					}
				}
			}
			else 
			{
				delete[] m_powers;
				m_powers = nullptr;
			}
			
		}
		else
		{
			*this = Hero();
		}
	}

	Hero::~Hero()
	{
		delete[] m_powers;
		m_powers = nullptr;
	}

	Power* Hero::getPower() const
	{
		return m_powers;
	}

	const char* Hero::getName() const
	{
		return m_name;
	}

	const int Hero::getNoOfPowers() const
	{
		return m_noOfPowers;
	}

	const int Hero::getPowerLevel() const
	{
		return m_powerLevel;
	}

	bool Hero::isEmpty() const
	{
		return !(m_name[0] != '\0' && m_powers && m_noOfPowers && m_powerLevel);
	}

	Hero& Hero::operator=(const Hero& hero) // copy assignment operator
	{
		if (this != &hero) // avoid self-assignment
		{
			delete[] m_powers;
			m_powers = nullptr;
			if (!hero.isEmpty())
			{
				strncpy(m_name, hero.m_name, MAX_NAME_LENGTH);
				m_noOfPowers = hero.m_noOfPowers;
				m_powerLevel = hero.m_powerLevel;
				m_powers = new Power[m_noOfPowers];
				if (m_powers)
				{
					for (int i = 0; i < m_noOfPowers; i++)
					{
						m_powers[i] = hero.m_powers[i];
					}
				}
				else
				{
					delete[] m_powers;
					m_powers = nullptr;
				}
			}
		}
		return *this;
	}
	

	Hero& Hero::operator+=(const Power& power)
	{
		if (!power.isEmpty())
		{
			Power* temp = new Power[m_noOfPowers + 1];
			if (temp) 
			{
				for (int i = 0; i < m_noOfPowers; i++)
				{
					temp[i] = m_powers[i];
				}
				temp[m_noOfPowers] = power;
				delete[] m_powers;
				m_powers = temp;
			}
			else
			{
				delete[] temp;
				temp = nullptr;
			}
			Hero tempHero(m_name, m_powers, m_noOfPowers + 1); // create a temporary object with the new power
			*this = tempHero; // call the copy assignment operator
		} // destory the temporary object after the scope

		return *this;
	}

	Hero& Hero::operator-=(const int powerLevelDrop)
	{
		if (powerLevelDrop > 0)
		{
			m_powerLevel -= powerLevelDrop;
		}
		return *this;
	}

	bool Hero::operator<(const Hero& otherHero) const
	{
		if (!otherHero.isEmpty())
		{
			if (m_powerLevel < otherHero.m_powerLevel)
			{
				return true;
			}
		}
		return false;
	}

	bool Hero::operator>(const Hero& otherHero) const
	{
		if (!otherHero.isEmpty())
		{
			if (m_powerLevel > otherHero.m_powerLevel)
			{
				return true;
			}
		}
		return false;
	}

	Hero& Hero::operator<<(const Power& power)
	{
		*this += power;
		return *this;
	}


	Hero& operator>>(const Power& power, Hero& hero)
	{
		if (!power.isEmpty() && !hero.isEmpty())
		{
			hero << power;
		}
		return hero;
	}

	std::ostream& Hero::display(std::ostream& ostr) const
	{
		if (!this->isEmpty()) // check if the hero is not empty
		{
			ostr << "Name: " << getName() << std::endl;
				displayDetails(m_powers, m_noOfPowers);
            ostr << "Power Level: " << getPowerLevel();
		}
		return ostr;
	}


}

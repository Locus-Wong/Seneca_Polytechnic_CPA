//Name: Tsz Wa Wong
//Email: twwong9@myseneca.ca
//Student ID: 152181228
//Date: 21 Feb 2024
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef HERO_H
#define HERO_H
#include "Power.h"
namespace seneca {

	class Hero
	{
        char m_name[MAX_NAME_LENGTH];
        Power* m_powers;
        int m_noOfPowers;
        int m_powerLevel;

	public:
		Hero();
		Hero(const char* name, const Power* powers, const int noOfPowers); // 3 parameters constructor
		~Hero(); // will deallocate the memory of the powers of a hero.
		
		Power* getPower() const;
		const char* getName() const;
		const int getNoOfPowers() const;
		const int getPowerLevel() const;

		bool isEmpty() const;

		Hero& operator=(const Hero& hero); // copy assignment operator
		Hero& operator+=(const Power& power); // will add a power to the hero's list of powers and update the power level of the hero.
		Hero& operator-=(const int powerLevelDrop); // will decrease the power level of the hero by the integer value received.
		bool operator<(const Hero& otherHero) const; 
		bool operator>(const Hero& otherHero) const; 
	    Hero& operator<<(const Power& power); // will add power to the hero and update the hero accordingly.
	
		std::ostream& display(std::ostream& ostr = std::cout) const;
	};

	Hero& operator>>(const Power& power, Hero& hero); // set as non-member function to avoid too many argument for operator >>




}
#endif

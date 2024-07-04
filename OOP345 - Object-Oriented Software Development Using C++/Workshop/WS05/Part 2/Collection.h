/*
 Name: Tsz Wa Wong
 Email: twwong9@myseneca.ca
 Student ID: 152181228
 Date: 13 June 2024
 I declare that this submission is the result of my own work and
 I only copied the code that my professor provided to complete my
 workshops and assignments. This submitted piece of work has not
 been shared with any other student or 3rd party content provider.
 */
#ifndef SENECA_COLLECTION_H
#define SENECA_COLLECTION_H
#include <iostream>
#include <string>
namespace seneca {

template<typename T>
class Collection
{
	std::string m_nameOfCollection{};
	T* items{};
	size_t m_size{};
	void (*m_observer)(const Collection<T>&, const T&) {}; // a pointer to a function
public:
	Collection(std::string nameOfCollection) : m_nameOfCollection(nameOfCollection), items{}, m_size(0), m_observer{} {}
	Collection(const Collection& src) = delete;
	Collection& operator=(const Collection& src) = delete;
	~Collection()
	{
		delete[] items;
		items = nullptr;
	}
	const std::string& name() const
	{
		return m_nameOfCollection;
	}
	size_t size() const
	{
		return m_size;
	}
	void setObserver(void (*observer)(const Collection<T>&, const T&)) { // receives a pointer to a function as a parameter
																		// library.setObserver(bookAddedObserver); and theCollection.setObserver(movieAddedObserver); will call this function
		m_observer = observer;
	}
	Collection<T>& operator+=(const T& item)
	{
		for (size_t i = 0; i < m_size; i++)
		{
			if (items[i].title() == item.title())
			{
				return *this;
			}
		}
		T* temp = new T[m_size + 1];
		for (size_t i = 0; i < m_size; i++)
		{
			temp[i] = items[i];
		}
		temp[m_size] = item;
		delete[] items;
		items = temp;
		m_size++;

		// Call the observer function if m_observer is not null
		if (m_observer != nullptr)
		{
			m_observer(*this, item);
		}
		return *this;
	}

	// Access an item by index
	T& operator[](size_t idx) const
	{
		if (idx >= m_size)
		{
			throw std::out_of_range("Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(m_size) + "] items.");
		}
		return items[idx];
	}

	// Access an item by title
	T* operator[](const std::string& title) const // theCollection["Dark Phoenix"]; will call this function
	{
		for (size_t i = 0; i < m_size; i++)
		{
			if (items[i].title() == title)
			{
				return &items[i];
			}
		}
		return nullptr;
	}
	
};

template<typename T>
std::ostream& operator<<(std::ostream& ostr, const Collection<T>& collection)
{
	for (size_t i = 0; i < collection.size(); i++)
	{
		ostr << collection[i];
	}
	return ostr;
}

}
#endif
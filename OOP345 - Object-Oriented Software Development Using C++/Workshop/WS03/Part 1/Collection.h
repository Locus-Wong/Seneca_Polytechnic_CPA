/*
 Name: Tsz Wa Wong
 Email: twwong9@myseneca.ca
 Student ID: 152181228
 Date: 30 May 2024
 I declare that this submission is the result of my own work and
 I only copied the code that my professor provided to complete my
 workshops and assignments. This submitted piece of work has not
 been shared with any other student or 3rd party content provider.
 */
#ifndef SENECA_COLLECTION_H
#define SENECA_COLLECTION_H
#include <iostream>
#include "Book.h"
namespace seneca {
template<typename T, unsigned int C>
class Collection
{
    static T m_smallestItem;
    static T m_largestItem;
    unsigned int currentSize{};
    
protected:
    T m_items[C]{};
    void setSmallestItem(const T& src){
        if(src < m_smallestItem){
            m_smallestItem = src;
        }
    }
    void setLargestItem(const T& src){
        if(src > m_largestItem){
            m_largestItem = src;
        }
    }
    T& operator[]( const unsigned int index) {
        return m_items[index];
    }
    
    void incrSize(){
        currentSize++;
    }
    
public:
    static T getSmallestItem() {
        return m_smallestItem;
    }
    static T getLargestItem() {
        return m_largestItem;
    }
    unsigned int size() const{
        return currentSize;
    }
    unsigned int capacity() const{
        return C;
    }
    bool operator+=(const T& src) {
        if(currentSize < C){
            (*this)[currentSize++] = src; // explicitly call T& operator[]( const unsigned int index)
            setLargestItem(src);
            setSmallestItem(src);
            return true;
        }
        return false;
    }
    void print(std::ostream& ostr) const{
        ostr << "[" ;
        for (size_t i = 0; i < currentSize; i++){
            ostr << m_items[i];
            if ( i != currentSize -1 ){
                ostr << ",";
            }
        }
        ostr << "]\n";
    }
};

template<typename T, unsigned int C>
T Collection<T, C>::m_smallestItem = 9999;

template<typename T, unsigned int C>
T Collection<T, C>::m_largestItem = -9999;

template<>
Book Collection<Book, 10>::m_smallestItem = Book("", 1, 10000);// call Book 3-args constructor

template<>
Book Collection<Book, 10>::m_largestItem = Book("", 10000, 1);

template<>
Book Collection<Book, 72>::m_smallestItem = Book("", 1, 10000);

template<>
Book Collection<Book, 72>::m_largestItem = Book("", 10000, 1);

template<>
void Collection<Book, 10>::print(std::ostream& ostr) const{
    ostr << "| ---------------------------------------------------------------------------|" << std::endl;
    for (unsigned int i = 0; i < currentSize; i++){
        ostr << "| " ;
        m_items[i].print(ostr);
        ostr << " |" << std::endl;
    }
    ostr << "| ---------------------------------------------------------------------------|" << std::endl;
}

template<>
void Collection<Book, 72>::print(std::ostream& ostr) const{
    ostr << "| ---------------------------------------------------------------------------|" << std::endl;
    for (unsigned int i = 0; i < currentSize; i++){
        ostr << "| " ;
        m_items[i].print(ostr);
        ostr << " |" << std::endl;
    }
    ostr << "| ---------------------------------------------------------------------------|" << std::endl;
}

}
#endif

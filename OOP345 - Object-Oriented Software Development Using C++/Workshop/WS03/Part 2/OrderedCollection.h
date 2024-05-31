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
#ifndef SENECA_ORDEREDCOLLECTION_H
#define SENECA_ORDEREDCOLLECTION_H
#include "Collection.h"
namespace seneca{
template<typename T>
class OrderedCollection : public Collection <T, 72>{
public:
    bool operator+=(const T& src){
        size_t insertIndex = 0;
        if(Collection <T, 72>::size() < 72){
            for (size_t i = 0; i < Collection <T, 72>::size(); i++){
                if(Collection <T, 72>::m_items[i] < src)
                {
                    ++insertIndex;
                }
            }
        }
        if(insertIndex < Collection <T, 72>::size()){
            for (size_t i = 71; i > insertIndex; --i){
                Collection <T, 72>::m_items[i] = Collection <T, 72>::m_items[i-1];
            }
        }
        if(Collection <T, 72>::size() < 72){
            Collection <T, 72>::m_items[insertIndex] = src;
            Collection <T, 72>::incrSize();
            Collection <T, 72>::setLargestItem(src);
            Collection <T, 72>::setSmallestItem(src);
            return true;
        }
        return false;
    }
};

}


#endif

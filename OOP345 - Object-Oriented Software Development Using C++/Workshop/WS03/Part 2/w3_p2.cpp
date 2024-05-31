// Workshop 3 - Templates

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "Book.h"
#include "Book.h" // intentional
#include "Collection.h"
#include "Collection.h" // intentional
#include "OrderedCollection.h"
#include "OrderedCollection.h" // intentional

int cout = 0; // won't compile if headers don't follow convention regarding namespaces

int main(int argc, char** argv)
{
    std::cout << "Command Line:\n";
    std::cout << "--------------------------\n";
    for (int i = 0; i < argc; ++i)
        std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
    std::cout << "--------------------------\n\n";

    // int, double, and Book data testing templated classes
    unsigned numBooks = 6;
    int ints[]{ 25, 30, 20, 15, 25, 5, 35 };
    double doubles[]{ 7.8, 9.10, 3.4, 1.2, 2.3, 6.7 };
    seneca::Book books[]{
        seneca::Book("Software Architecture for Busy Developers", 7, 174), // call Book::Book(const std::string& title, unsigned nChapters, unsigned nPages)
        seneca::Book("Low-Code Application Development with Appian",16,462),
        seneca::Book("Natural Language Processing with TensorFlow", 11, 514),
        seneca::Book("Learning DevOps",17,560),
        seneca::Book("SQL for Data Analytics",9,540),
        seneca::Book("Deciphering Object-Oriented Programming with C++",21,594),
    };

    std::cout << "1. Book tester >>> ===========================================================" << std::endl;
    std::cout << "total books: " << numBooks << std::endl;
    std::cout << "------------------------------------------------------------------------------" << std::endl;
    for (auto i = 0u; i < numBooks-1; i++) {
        std::cout << "| " << i + 1 << ".";
        books[i].print(std::cout) << "|" << std::endl;; // call ostream& Book::print(ostream& os) const{
    }
    std::cout << "| " << numBooks << ".";
    std::cout << books[numBooks - 1] << "|" << std::endl; // call ostream& operator<<(ostream& os, const Book& bk
    std::cout << "============================================================== <<< Book tester" << std::endl << std::endl;

    std::cout << "2. Collection tester for int and 10 >>> ======================================" << std::endl;
    {        // Collection tester for int-type
        seneca::Collection<int, 10> icol;
        for (const auto& i : ints)
            icol += i;
        std::cout << "(smallest,largest) items: (" << icol.getSmallestItem() << "," << icol.getLargestItem() << ")" << std::endl; // call T Collection<int, 10>::getSmallestItem() const
        std::cout << "size/capacity: " << icol.size() << "/" << icol.capacity() << std::endl;
        std::cout << "Contents: ";
        icol.print(std::cout); // call void Collection<int, 10>::print(std::ostream& ostr) const
    }
    std::cout << "========================================= <<< Collection tester for int and 10" << std::endl;
    std::cout << std::endl;

    std::cout << "3. Collection tester for double and 10 >>>====================================" << std::endl;
    {// Collection tester for double-type
        seneca::Collection<double, 10> dcol;
        for (const auto& d : doubles)
            dcol += d; // call bool Collection<double, 10>::operator+=(const T& src)
        std::cout << "(smallest,largest) items: (" << dcol.getSmallestItem() << "," << dcol.getLargestItem() << ")" << std::endl;
        std::cout << "size/capacity: " << dcol.size() << "/" << dcol.capacity() << std::endl; // call unsigned int Collection<double, 10>::size() const
        std::cout << "Contents: ";
        dcol.print(std::cout); // call void Collection<double, 10>::print(std::ostream& ostr) const
    }
    std::cout << "====================================== <<< Collection tester for double and 10" << std::endl;
    std::cout << std::endl;

    std::cout << "4. Collection tester for Book and 10 >>> =====================================" << std::endl;
    {// Collection tester for Book-type, capacity 10
        std::cout << "[After creating collection in empty state]" << std::endl;
        seneca::Collection<seneca::Book, 10> bcol; // use Book::Book() : m_title{}, m_numChapters{}, m_numPages{}{}
        std::cout << "Book with smallest pages-to-chapters ratio (initial-default state): " << std::endl;
        bcol.getSmallestItem().print(std::cout) << " |" << std::endl; // use Template Specializations: Book Collection<Book, 10>::m_smallestItem = Book("", 1, 10000);
        std::cout << "Book with largest pages-to-chapters ratio (initial-deault-state): " << std::endl;
        bcol.getLargestItem().print(std::cout) << " |" << std::endl; // use Template Specializations: Book Collection<Book, 10>::m_largestItem = Book("", 10000, 1);
        std::cout << "size/capacity: " << bcol.size() << "/" << bcol.capacity() << std::endl;
        std::cout << std::endl;

        // Part 2 tester follows from here 

        std::cout << "[After adding Six books to the collection]" << std::endl;
        for(const auto& b : books)
            bcol += b; // use bool Book::operator>(const Book& src) const and bool Book::operator<(const Book& src) const
        std::cout << "Book with smallest pages-to-chapters ratio: " << std::endl;
        bcol.getSmallestItem().print(std::cout) << std::endl; // call ostream& Book::print(ostream& os) const
        std::cout << "Book with largest pages-to-chapters ratio: " << std::endl;
        bcol.getLargestItem().print(std::cout) << std::endl; // call ostream& Book::print(ostream& os) const
        std::cout << "size/capacity: " << bcol.size() << "/" << bcol.capacity() << std::endl;
        std::cout << std::endl;
        std::cout << "Collection content:\n";
        bcol.print(std::cout); // use Template Specializations: call void Collection<Book, 10>::print(std::ostream& ostr) const
    }
    std::cout << "======================================== <<< Collection tester for Book and 10" << std::endl;
    std::cout << std::endl;

    std::cout << "5. OrderedCollection tester for int >>> ===========================================" << std::endl;
    {        // Collection tester for int-type
        seneca::OrderedCollection<int> oicol;
        for(const auto& i : ints)
            oicol += i;
        std::cout << "(smallest,largest) items: (" << oicol.getSmallestItem() << "," << oicol.getLargestItem() << ")" << std::endl;
        std::cout << "size/capacity: " << oicol.size() << "/" << oicol.capacity() << std::endl;
        std::cout << "Contents: ";
        oicol.print(std::cout); // call void Collection <T, 72>::print(std::ostream& ostr) const
    }
    std::cout << "============================================= <<< OrderedCollection tester for int " << std::endl;
    std::cout << std::endl;

    std::cout << "6. OrderedCollection tester for double >>> ========================================" << std::endl;
    {// Collection tester for double-type
        seneca::OrderedCollection<double> odcol;
        for(const auto& d : doubles)
            odcol += d;
        std::cout << "(smallest,largest) items: (" << odcol.getSmallestItem() << "," << odcol.getLargestItem() << ")" << std::endl;
        std::cout << "size/capacity: " << odcol.size() << "/" << odcol.capacity() << std::endl;
        std::cout << "Contents: ";
        odcol.print(std::cout); // call void Collection <T, 72>::print(std::ostream& ostr) const
    }
    std::cout << "========================================== <<< OrderedCollection tester for double " << std::endl;
    std::cout << std::endl;

    std::cout << "7. OrderedCollection tester for Book >>> ==========================================" << std::endl;
    {// OrderedCollection tester for Book-type
        std::cout << "[After creating collection in empty state]" << std::endl;
        seneca::OrderedCollection<seneca::Book> obcol; // call class OrderedCollection : public Collection <T, 72>
        std::cout << "Book with smallest pages-to-chapters ratio (initial-default state): " << std::endl;
        obcol.getSmallestItem().print(std::cout) << std::endl; // use Template Specializations: Book Collection<Book, 72>::m_smallestItem = Book("", 1, 10000);
        std::cout << "Book with largest pages-to-chapters ratio (initial-deault-state): " << std::endl;
        obcol.getLargestItem().print(std::cout) << std::endl; // use Template Specializations: Book Collection<Book, 72>::m_largestItem = Book("", 10000, 1);
        std::cout << "size/capacity: " << obcol.size() << "/" << obcol.capacity() << std::endl;
        std::cout << std::endl;

        std::cout << "[After adding six books to the collection]" << std::endl;
        for(const auto& b : books)
            obcol += b;
        std::cout << "Book with smallest pages-to-chapters ratio: " << std::endl;
        obcol.getSmallestItem().print(std::cout) << std::endl; // call ostream& Book::print(ostream& os)
        std::cout << "Book with largest pages-to-chapters ratio: " << std::endl;
        obcol.getLargestItem().print(std::cout) << std::endl; // call ostream& Book::print(ostream& os)
        std::cout << "size/capacity: " << obcol.size() << "/" << obcol.capacity() << std::endl;
        std::cout << std::endl;
        std::cout << "List of OrderedCollection Books: " << std::endl;
        obcol.print(std::cout); // use Template Specializations: void Collection<Book, 72>::print(std::ostream& ostr) const
    }
    std::cout << "============================================ <<< OrderedCollection tester for Book " << std::endl;
    std::cout << std::endl;

    return cout;
}

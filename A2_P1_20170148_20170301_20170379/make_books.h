#ifndef MAKE_BOOKS_H
#define MAKE_BOOKS_H
#include <map>
#include <utility>
#include <string>
#include"books.h"
using namespace std ;

class make_books
{
public:
    make_books();
    void addbook();
    void searchbyname();
    void searchbyauthor();
    void listbooks();
    void update();
    void findhighestversionsofbooks();

private:
    map<string, books> b;
};

#endif // MAKE_BOOKS_H

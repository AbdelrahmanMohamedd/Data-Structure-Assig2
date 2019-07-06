#ifndef BOOKS_H
#define BOOKS_H
#include"books.h"
#include<iostream>
#include <string>
using namespace std;

class books
{
private:
    ///has name, author, publish year and number of available versions
    string nameofbook ;
    string nameofauthor ;
    int publishyear ;
    int numberofversions;
public:

    books();
    books(string bname,string auname, int year, int numv);

    void setName(string val)
    {
        nameofbook = val;
    }

    string getName() const
    {
        return nameofbook;
    }

    void setauthorname(string val)
    {
        nameofauthor = val;
    }

    string getauthorname() const
    {
        return nameofauthor;
    }

    void setyear(int val)
    {
        publishyear = val;
    }

    int getyear() const
    {
        return publishyear;
    }
    void setversions(int val)
    {
        numberofversions = val;
    }

    int getversions() const
    {
        return numberofversions;
    }


    friend istream& operator>>(istream& is, books& bo);
    friend ostream& operator<<(ostream& os, books& bo);




    ~books();



};

#endif // BOOKS_H

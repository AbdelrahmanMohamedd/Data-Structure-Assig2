#include "books.h"
#include<iostream>
#include<string>

using namespace std ;

books::books(){}

books::books(string bname,string auname, int year, int numv)
    :nameofbook(bname),nameofauthor(auname),publishyear(year),numberofversions(numv){}

istream& operator>>(istream& is, books& bo)
{
    is >> bo.nameofbook >> bo.nameofauthor >> bo.publishyear>>bo.numberofversions;
    return is;
}

ostream& operator<<(ostream& os, books& bo) {
    os << bo.nameofbook << " " << bo.nameofauthor << " " << bo.publishyear<<" "<<bo.numberofversions;
    return os;
}
books::~books(){}

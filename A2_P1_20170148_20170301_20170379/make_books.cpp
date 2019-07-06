#include "make_books.h"
#include"books.h"
#include <iostream>
#include <string>
#include <map>
#include <utility>
#include <algorithm>

using namespace std ;

make_books::make_books() {}
void make_books::addbook()
{
    cout << "enter the book data : book name _ author name _ year _ number of versions \n ";
    books bo;
    cin >> bo;
    b[bo.getName()] = bo;
    // b[bo.getauthorname()] = bo;
}
void make_books::searchbyname()
{
    cout << "enter the book name: ";
    string key;
    cin >> key;
    if (b.find(key) != b.end())
    {
        cout << b[key] << '\n';
    }
}
void make_books::searchbyauthor()
{
    string author;

    cout<<"enter author name: ";
    cin>>author;
    map<string,books>::iterator it;
    for(it=b.begin();it!=b.end();it++){
        if(it->second.getauthorname()==author)
        {
            cout<<it->second<<endl;
            return;
        }
    }
    cout<<"book not found.";
}
void make_books::listbooks()
{
    for (map<string, books>::iterator it = b.begin(); it != b.end(); it++)
    {
        cout << it->second << '\n';
    }
}
void make_books::update ()
{
    cout << "enter the name of the book you want to update: ";
    string key;
    cin >> key;
    if (b.find(key) != b.end())
    {
        int new_num;
        cin >> new_num;
        b[key].setversions(new_num);
    }
    else
    {
        cout << "The book can't be found.\n";
    }
}

void make_books::findhighestversionsofbooks()
{
    int max_v = -1 ;
    map<string,books>::iterator itr ;
    for (itr = b.begin();itr != b.end() ; itr++ ){

        if(itr->second.getversions()>max_v){
            max_v = itr->second.getversions();
        }
    }
    for (itr = b.begin();itr != b.end() ; itr++ ){

        if(itr->second.getversions()==max_v){
            cout<<itr->second<<endl;
        }
    }

};





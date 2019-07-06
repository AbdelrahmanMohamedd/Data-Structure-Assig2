#include <iostream>
#include"make_books.h"
using namespace std;

int main()
{
    make_books bk;
    while (true)
    {
        cout << "1- Add book\n";
        cout << "2- Search book by name\n";
        cout << "3- Search book by author name\n";
        cout << "4- List books in alphabetical order\n";
        cout << "5- Update number of versions\n";
        cout << "6- Find book has the highest number of versions \n";
        cout << "Please enter your choice:\n ";
        cout << endl;

        char ch;
        cin >> ch;
        switch (ch)
        {
        case '1':
        {
            bk.addbook();
            break;
        }
        case '2':
        {
            bk.searchbyname();
            break;
        }
        case '3':
        {
            bk.searchbyauthor();
            break;
        }
        case '4':
        {
            bk.listbooks();
            break;
        }
        case '5':
        {
            bk.update();
            break;
        }
            /*  case '6':
              {
                  bk.findhighestversionsofbooks();
                  break;
              }

              cout << endl;*/
        }
    }
    return 0;
}

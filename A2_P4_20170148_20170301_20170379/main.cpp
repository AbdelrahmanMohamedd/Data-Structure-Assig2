#include <iostream>
#include <vector>
#include <algorithm>


using namespace std ;


bool make_triangle(vector<int>& sides)///make a vector to store data
{
    sort(sides.begin(), sides.end());///sort data
    int l_in = sides.size() - 1;
    while (l_in > 0)
    {
        int f_in = 0;///refer to first index
        int j = l_in - 1;
        while (f_in < j)
        {
            if (sides[f_in] + sides[j] > sides[l_in])///check if this condition true or not
            {
                return true;
            }
            else
            {
                f_in++;
            }
        }
        l_in--;
    }
    return false;
}

int main()
{
    vector<int> list1;
    /*int i,h,k;
    cout<<"enter numbers:: \n";
    cin>>i;
    cin>>h;
    cin>>k;
    list1.push_back(i);
    list1.push_back(h);
    list1.push_back(k);*/
    list1.push_back(4);
    list1.push_back(1);
    list1.push_back(2);
    cout <<"is correct ?  "<< make_triangle(list1) << endl;

    vector<int> list2;
    list2.push_back(5);
    list2.push_back(4);
    list2.push_back(3);
    list2.push_back(1);
    list2.push_back(2);
    cout <<"is correct ?  "<< make_triangle(list2) << endl;

    return 0;
}


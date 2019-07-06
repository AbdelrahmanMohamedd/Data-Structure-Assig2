#include <iostream>
#include <fstream>
#include <time.h>
#include <chrono>
using namespace std;
///======================================================================
int seedGenerator ()
{   srand(time(0));
    int number=rand();
    number=(number*9876)%900;
    return number;
    }
///===================================================================================
void RandomNumbersGenrator ( int Randoms[] ,  int sizz) {
    srand(seedGenerator());
    for (int position=0 ; position<sizz ; position++)
    { Randoms[position]= ((rand()*9876)%10000);
    }
}
///===================================================================================
int BinarySearch(int data[], int lower, int higher, int key)
{

   int middle = (lower + higher)/2;
    if(key == data[middle])
        return middle+1;
    if (higher <= lower)
        return (key > data[lower])?  (lower + 1): lower;
    if(key > data[middle])
        return BinarySearch(data, key, middle+1, higher);
    return BinarySearch(data, key, lower, middle-1);
}
///===================================================================================
void insertionSort(int arr[], int siz){
    int i , j , key ;
    for ( int i = 1 ; i<siz ; i++) {
        key= arr[i];
        j=i-1;
    while ( j>=0 && arr[j]>key){
        arr[j+1]=arr[j];
        j--;
    }
    arr[j+1]=key;
    }
}
///===================================================================================
//void printArray(int arr[], int n)
//{   int i;
//    for (i = 0; i < n; i++){
//        cout<<arr[i]<<" ";
//    }
//}
///===================================================================================
void BinaryInsertionSort(int data[], int n)
{
    int i , j , k , selected , location ;
    for (i = 1; i < n; ++i)
    {
        j = i - 1;
        selected = data[i];       // find location where selected should be inseretd
        location = BinarySearch(data, selected, 0, j);
        while (j >= location)// Move all elements after location to create space
        {
            data[j+1] = data[j];
            j--;
        }
        data[j+1] = selected;
    }
}
///===================================================================================
int main()
{
    fstream myfile;
    myfile.open("InsertionSort VS BinaryInsertionSort.csv" , ios:: in | ios :: out | ios::app);
    int sizee ;
    cout<<endl<<"Enter the size of the array to be sorted : "<<endl;
	cin >>sizee ;
	int x[sizee];
	int y[sizee];
	RandomNumbersGenrator( x , sizee);
	RandomNumbersGenrator( y , sizee);

    auto Insertionstart = chrono::high_resolution_clock::now();
         insertionSort(x,sizee);
    auto InsertionFinish = chrono::high_resolution_clock::now();
    auto InsertionTime = InsertionFinish - Insertionstart;
    auto microsec1 = std::chrono::duration_cast<std::chrono::microseconds>(InsertionTime).count();

    auto BinaryInsertionStart = chrono::high_resolution_clock::now();
         BinaryInsertionSort(y,sizee);
    auto BinaryInsertionFinish = chrono::high_resolution_clock::now();
    auto BinaryInsertionTime = BinaryInsertionFinish - BinaryInsertionStart;
    auto microsec2 = std::chrono::duration_cast<std::chrono::microseconds>(BinaryInsertionTime).count();
    cout  << "Insertion Sort Duaration:       " << microsec1 <<"  Microseconds " << endl;
    cout  << "BinaryInsertion Sort Duaration: " << microsec2 <<"  Microseconds " << endl;
    myfile << microsec1 << "," << microsec2 << endl ;
    myfile.close();
    return 0;
}

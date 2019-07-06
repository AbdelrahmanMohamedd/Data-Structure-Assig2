#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <time.h>
#include <chrono>
#include <ctime>
using namespace std;
///======================================================================
int seedGenerator ()
{   srand(time(0));
    int number=rand();
    number=(number*9876)%900;
    return number;
    }
///======================================================================
void RandomNumsGenerator(int RandArr[] , int sizz )
{   srand(seedGenerator());
    for (int index = 0; index <sizz; index++)
    {  RandArr[index] =  ((rand()*9876)%10000);
    }
}
///======================================================================
void quickSort(int arr[], int left, int right)
{   int pivot = (left + right) / 2;
    int i = left, j = right;
    while (i <= j)
    {
        while (arr[i] < arr[pivot])
            i++;
        while (arr[j] > arr[pivot])
            j--;
        if (i <= j)
        {   int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }
    if (left < j)  quickSort(arr, left, j);
    if (i < right) quickSort(arr, i, right);
}
///======================================================================
void mergeSort(int arr[], int left, int right)
{   if (left < right)
    {   int mid = (left +right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
        int h, i, j;        //merge
        vector<int> temp;
        h = left;
        j = ((left + right) / 2) + 1;
        while ((h <= mid) && (j <= right))
        {   if (arr[h] <= arr[j])
            {   temp.push_back( arr[h] );
                h++;
            }
            else
            {   temp.push_back( arr[j] );
                j++;
            }
        }
        if (h>mid)
        {
            for (int k = j; k <= right; k++)
            {   temp.push_back(arr[k]);
            }
        }
        else
        {
            for (int k = h; k <= mid; k++)
            {   temp.push_back(arr[k]);
            }
        }
        vector<int>::iterator it = temp.begin();
        for (int k = left; it != temp.end(), k <= right; it++, k++)
            arr[k] = *it;
    }
}
///======================================================================
int main(){
 fstream file1,file2,file3,file4,file5;
    file1.open("1-QuickTest.csv" ,ios::in|ios::out|ios::app);
    file2.open("2-MergeTest.csv" ,ios::in|ios::out|ios::app);
    file5.open("3-Both Quick & Merge.csv" ,ios::in|ios::out|ios::app);
//  file3.open("1-quicktest.txt" ,ios::in|ios::out|ios::app);
//  file4.open("2-mergetest.txt" ,ios::in|ios::out|ios::app);
	int siz ;
	cout<<endl<<"Enter the number of the data that you want to sort in the test :"<<endl;
	cin >>siz ;
	int x[siz];
	int y[siz];
	int j=0; //counter to get averages
for (int i=0 ; i <= 100000 ; i+=5000){
	RandomNumsGenerator( x , siz);
	RandomNumsGenerator( y , siz);
	cout << endl << "For an Array of " << i <<" items" <<endl ;

    auto quickStart = chrono::high_resolution_clock::now();
    quickSort(x,0,siz-1);
    auto quickFinish = chrono::high_resolution_clock::now();
    auto quickTime = quickFinish - quickStart;
    auto microsec1 = std::chrono::duration_cast<std::chrono::microseconds>(quickTime).count();
    cout  << "Quick Sort Duaration: "<< microsec1 <<"  Microseconds " << endl;
    file1 << microsec1 << endl;
//  file3 << microsec1<< endl;

    auto mergeStart = chrono::high_resolution_clock::now();
    mergeSort(y, 0, siz-1);
    auto mergeFinish = chrono::high_resolution_clock::now();
    auto mergeTime = mergeFinish - mergeStart;
    auto microsec2 = std::chrono::duration_cast<std::chrono::microseconds>(mergeTime).count();
    cout  << "Merge Sort Duaration: " << microsec2 <<"  Microseconds " << endl;
    file2 << microsec2 <<endl;
//  file4 << microsec2 <<endl;
    file5 << microsec1 << "," << microsec2 <<endl;

    j++;
    auto avgmergeTime=mergeTime/j;
    auto avgquickTime=quickTime/j;
    if (avgmergeTime>avgquickTime)  cout<<"So,Quick Sort is Faster"<<" for "<< i <<" Items "<<endl ;
    else cout<<"So,Merge Sort is Faster "<<" for "<< i <<" Items "<<endl ;

//const clock_t  quickstart=clock();
//    quickSort(x,0,siz-1);
//cout << float( clock () - quickstart )/  CLOCKS_PER_SEC  << " Microseconds" << endl<< endl;
//file1 << float( clock () - quickstart )/  CLOCKS_PER_SEC << endl ;
////const clock_t mergestart = clock();
//    mergeSort(y, 0, siz-1);
//cout << float( clock () - mergestart )/  CLOCKS_PER_SEC  << " Microseconds" << endl << endl;
//file2 << float( clock () - mergestart )/  CLOCKS_PER_SEC << endl ;}
file1.close();
file2.close();
cout <<endl<< " >>> Check the created files to see the time estimated for each sort <<<" <<endl<<endl;
//system("gnuplot -p -e \"plot 'C:\\Users\\ag\\Desktop\\A2_20170148_20170301_20170379\\A2_P5_20170148_20170301_20170379\\mergetest.txt' with lines,'C:\\Users\\ag\\Desktop\\A2_20170148_20170301_20170379\\A2_P5_20170148_20170301_20170379\\mergetest.txt' with lines\"");
return 0;
}

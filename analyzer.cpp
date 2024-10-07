#include <iostream>
#include <vector>
#include <string>
#include "StringData.h"
using namespace std;

int linear_search(vector<string> container, string element)
{
    long long start = systemTimeNanoseconds();
    int index = -1;
    for(int i = 0; i < container.size(); i++)
    {
        if(element == container[i])
        {
            index = i;
        }
    }
    long long end = systemTimeNanoseconds();
    cout << "\nTime for linear search: " << (end - start)/1000.0 << " seconds" << endl;

    return index;
}

int binary_search(vector<string> container, string element)
{
    long long start = systemTimeNanoseconds();
    int max = container.size() - 1;
    int min = 0;
    int mid = (max + min) / 2;
    int index = -1;
    while(min <= max)
    {
        if (container[mid] == element)
        {
            index = mid;
            break;
        }
        else if (container[mid] > element)
        {
            max = mid - 1;
            mid = (max + min) / 2;
        }
        else if(container[mid] < element)
        {
            min = mid + 1;
            mid = (max + min) / 2;
        }
    }
    long long end = systemTimeNanoseconds();
    cout << "Time for binary search: " << (end - start)/1000.0 << " seconds" << endl;

    return index;
}

int main()
{
    long long start = systemTimeNanoseconds();
    vector<string> data = getStringData();
    long long end = systemTimeNanoseconds();
    cout << "Time to get data: " << (end - start)/1000.0  << " seconds" << endl;
    string element_1 = "not_here";
    string element_2 = "mzzzz";
    string element_3 = "aaaaa";

    int x = linear_search(data, element_1);
    int y = binary_search(data, element_1);
    cout << "Index of " << element_1 << " from linear search: " << x << endl;
    cout << "Index of " << element_1 << " from linear search: " << y << endl;

    x = linear_search(data, element_2);
    y = binary_search(data, element_2);
    cout << "Index of " << element_2 << " from linear search: " << x << endl;
    cout << "Index of " << element_2 << " from linear search: " << y << endl;

    x = linear_search(data, element_3);
    y = binary_search(data, element_3);
    cout << "Index of " << element_3 << " from linear search: " << x << endl;
    cout << "Index of " << element_3 << " from linear search: " << y << endl;
}
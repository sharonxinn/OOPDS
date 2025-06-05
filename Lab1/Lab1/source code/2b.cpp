#include <iostream>
using namespace std;

void ReadArray(int a[], int size);

int main()
{
    // The members of the array
    // int Numbers[ ] = {89, 75, 60, 36, 25, 44, 8, 52};
    const int size = 8;
    int Numbers[size];
    
    ReadArray(Numbers, size);
    int Max = Numbers[0];

    // Compare the members
    for (int i = 1; i < size; ++i) {
    if (Numbers[i] > Max)
    Max = Numbers[i];
    }

    // Announce the result
    cout << "The highest member value of the array is "
    << Max << "." << endl;
    return 0;
}

void ReadArray(int a[], int size){

    cout << "Enter " << size << " integers for the array:" << endl;

    for (int i = 0; i < size; ++i) {
        cout << "Element " << (i + 1) << ": ";
        cin >> a[i];
    }
}
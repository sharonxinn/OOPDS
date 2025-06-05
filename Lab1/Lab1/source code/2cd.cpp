#include <iostream>
using namespace std;

void ReadArray(int a[], int size);
void bubbleSort(int a[], int size);
void printArray(int a[], int size);

int main()
{
    // int Numbers[ ] = {89, 75, 60, 36, 25, 44, 8, 52};
    const int size = 8;
    int Numbers[size];
    
    ReadArray(Numbers, size);

    cout << "Original array: ";
    printArray(Numbers, size);

    bubbleSort(Numbers, size);

    cout << "Sorted array: ";
    printArray(Numbers, size);
    
}

void ReadArray(int a[], int size){

    cout << "Enter " << size << " integers for the array:" << endl;

    for (int i = 0; i < size; ++i) {
        cout << "Element " << (i + 1) << ": ";
        cin >> a[i];
    }
}

void bubbleSort(int arr[],int size){

    for (int i = 0; i < size - 1; i++) {       // Number of passes formula n-1
        for (int j = 0; j < size - i - 1; j++) { // Compare adjacent elements
            if (arr[j] > arr[j + 1]) {       // Swap if needed
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void printArray(int a[], int size){
    
    for(int i=0; i<size; i++){
        cout << a[i] << " ";
    }
    cout<<endl;
}
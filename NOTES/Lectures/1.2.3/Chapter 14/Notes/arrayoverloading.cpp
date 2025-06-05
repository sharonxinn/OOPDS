#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class Foo{
    private:
    int arr[5];

    public:
    int &operator[](int index){
        if(index < 0 || index >= 5){
            cout << "Index out of bounds" << endl;
            exit(1);
        }
        return arr[index];
    }
};
int main()
{
    Foo a;
    a[3]=88;
    a[2]=99;
    cout << a[2] << endl; // Output: 99

    for(int i=0; i<5; i++){
        a[i] = i * i*i;
    }
    for (int i=0; i<5; i++){
        cout << a[i] << " "; // Output: 0 1 8 27 64
    }
    cout << endl;


}
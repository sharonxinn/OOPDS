#include <iostream>
using namespace std;


int main(){
    int i, s_even, s_odd;

    do{
        cout << "Type a number: (0 to exit): ";
        cin >> i;

        if(i%2==0){
            s_even+=i;
        }
        else{
            s_odd+=i;
        }

    }while(i!=0);

    if(s_even!=0 || s_odd!=0){
        cout<< "Sum of even mumber is "<< s_even <<endl;
        cout<< "Sum of odd mumber is "<< s_odd <<endl;
    }
    

    return 0;

}


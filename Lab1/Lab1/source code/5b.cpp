#include <iostream>
using namespace std;


int main(){
    int i, max_even=0, min_odd=0;

    do{
        cout << "Type an integer number: (0 to exit): ";
        cin >> i;

        if(i%2==0){
            if(i>max_even){
                max_even=i;
            }
        }

        else{
            if(i<min_odd){
                min_odd=i;
            }
        }

    }while(i!=0);

    if(max_even!=0 && min_odd!=0){
        cout<< "Maximum of even mumber is "<< max_even <<endl;
        cout<< "Minumum of odd mumber is "<< min_odd <<endl;
    }

    else if(max_even!=0){
        cout<< "Maximum of even mumber is "<< max_even <<endl;
    }

    else if(min_odd!=0){
        cout<< "Minumum of odd mumber is "<< min_odd <<endl;
    }
    
    return 0;

}
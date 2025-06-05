#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class EncryptableString: public string {
public:
    void encrypt();
    EncryptableString(string s): string(s) {}
};

void EncryptableString::encrypt() {
        for (int k=0;k<this->length();k++){
            if ((*this)[k]=='z')
            {(*this)[k]='a';}
            else 
            {
                if ((*this)[k]=='Z')
                {
                    (*this)[k]='A';}
                else 
                {
                    (*this)[k]++;}
            }
        }
    
}

   
int main() {
    string str;
    cout << "This is an Encryption program. Enter a string to encrypt: ";
    cin >> str;

    EncryptableString s(str);
    s.encrypt();
    cout <<"Here is the encrypted string:";
    cout << s;
    cout << endl;
    return 0;
}
#include <iostream>
#include <fstream>
using namespace std;

class Encryption
{
    protected:
        ifstream inFile;
        ofstream outFile;
        int key;
    public:
        Encryption(char* inFileName, char*outFileName);
        ~Encryption();

        virtual char transform(char c) = 0;
        void encrypt();
        void setKey(int aKey){ key = aKey; }
};

Encryption::Encryption(char* inFileName, char*outFileName)
{
    inFile.open(inFileName);
    outFile.open(outFileName);
    if(!inFile)
    {
        cout << "Error opening input file." << endl;
        exit(1);
    }
    if(!outFile)
    {
        cout << "Error opening output file." << endl;
        exit(1);
    }
}

Encryption::~Encryption()
{
    inFile.close();
    outFile.close();
}

void Encryption::encrypt()
{
    char ch;
    char transCh;

    inFile.get(ch);
    while (!inFile.fail())
    {
        transCh = transform(ch);
        outFile.put(transCh);
        inFile.get(ch);
    }
}

class SimpleEncryption : public Encryption
{
    public:
        char transform(char ch)
        {
            return(ch + key);
        }
        SimpleEncryption(char* inFileName, char* outFileName) : Encryption(inFileName, outFileName)
        {} 
};

int main()
{
    char fileIn[]="fileIn.txt";
    char fileOut[]="fileOut.txt";   

    SimpleEncryption obfuscatr(fileIn, fileOut);

    cout<<"Enter a small integer as an encryption key ->";
    int key;
    cin>> key;
    obfuscatr.setKey(key);

    obfuscatr.encrypt();
    return 0;
}
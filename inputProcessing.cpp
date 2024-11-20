// c++ program to take an input and determine frequency of characters
#include <cstdlib> 
#include <iostream>
#include <vector>
//#include "huffman.cpp"
using namespace std; 

struct freqArr {
    // These should match unless something bad happens with you data
    // I'm not adding an enforcement mechanism yet

    //store array of chars
    vector<char> chars;

    //store frequencies 
    vector<int> freqs;
};

freqArr parseString(string s){
    //check each character and add to array
    //increase counter with each occurrence
    int sLen = s.length();

    freqArr parsedArr;

    for (int i = 0; i < sLen; i++)
    {
        bool isfound = false;
        char letter = s[i];

        while (isfound == false)
        {   
            for (int j = 0; j < parsedArr.chars.size(); j++)
            {
                if (parsedArr.chars[j] == letter)
                {
                    parsedArr.freqs[j] = parsedArr.freqs[j] + 1;
                    isfound = true;
                    break;
                }       
            }

            if(!isfound)
            {
                int arrpos = parsedArr.chars.size();
                parsedArr.chars.insert(parsedArr.chars.begin() + arrpos, letter);
                parsedArr.freqs.insert(parsedArr.freqs.begin() + arrpos, 1);
                isfound = true;
            }
        }
    }

    return parsedArr;

}

void printArr(freqArr f) {

    int finSize = f.chars.size();

    cout << "Array: ";

    for (int i = 0; i < finSize - 1 ; i++)
    {
        cout << f.chars[i] << ", ";
    }
    cout << f.chars[finSize - 1];
    cout << endl;
    
    cout << "Freq:  ";

    for (int i = 0; i < finSize - 1; i++)
    {
        cout << f.freqs[i] << ", ";
    }
    cout << f.freqs[finSize - 1];
    cout << endl;

    cout << "Size: " << finSize << endl;

}

//

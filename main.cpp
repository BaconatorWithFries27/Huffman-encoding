#include <cstdlib> 
#include <iostream>
#include <vector>
#include "huffman.cpp"
#include "inputProcessing.cpp"
using namespace std; 

int main(){

    string input;

    cout << "Enter text to process: \n";\
    getline(cin, input);

    cout << input << endl;

    freqArr steve = parseString(input);

    printArr(steve);

    int size = steve.chars.size();

    char arr[size];
    int freq[size];

    for (int i = 0; i < size; i++)
    {
        arr[i] = steve.chars[i];
        freq[i] = steve.freqs[i];
    }
    

    HuffmanCodes(arr, freq, size);

    return 0;
}
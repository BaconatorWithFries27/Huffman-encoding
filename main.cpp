#include <cstdlib> 
#include <iostream>
#include <vector>
//#include "huffman.cpp"
#include "inputProcessing.cpp"
#include "makeBitstream.cpp"
using namespace std; 

int main(){

    string input;

    cout << "Enter text to process: \n";\
    //getline(cin, input);
    input = "the quick brown fox jumps over the lazy dog.";
    cout << input << endl;

    freqArr steve = parseString(input);

    printArr(steve);

    int size = steve.chars.size();

    char arr[size];
    int freq[size];

    
    // this would be easy to parallelize eventually
    // (or rewrite the huff algo to accept vectors)
    for (int i = 0; i < size; i++) 
    {
        arr[i] = steve.chars[i];
        freq[i] = steve.freqs[i];
    }
    

    //HuffmanCodes(arr, freq, size);
    struct MinHeapNode* root = buildHuffmanTree(arr, freq, size);

    int intarr[MAX_TREE_HT], top = 0; 

	printCodes(root, intarr, top); 

    vector<char> bitstream = makeBitstream(root, input, freq);
    int bitlength = bitstream.size();
    string bitString[bitlength];
    for (int i = 0; i < bitlength; i++)
    {
        bitString[i] = bitstream[i];
        cout << bitString[i];
    }
    
    cout << endl;
    //decodeBitstream(root, bitstream);

    return 0;
}
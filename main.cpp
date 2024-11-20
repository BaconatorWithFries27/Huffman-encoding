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

    freqArr completedArrays = parseString(input);

    printArr(completedArrays);

    int size = completedArrays.chars.size();

    struct MinHeapNode* root = buildHuffmanTree(completedArrays.chars, completedArrays.freqs, size);

    int intarr[MAX_TREE_HT], top = 0; 

	printCodes(root, intarr, top); 

    string bitstream = makeBitstream(root, input, completedArrays.freqs);
    std::cout << std::dec << bitstream << endl;


    return 0;
}
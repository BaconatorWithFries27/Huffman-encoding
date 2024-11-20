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

    /* Ask inputProcessing to parse the input string into a freqArr ->
     * 1. Vector of all the character in the string,
     * 2. Vector of the frequency of occurrence of all character in the string.
     */
    freqArr completedArrays = parseString(input);

    printArr(completedArrays);

    int size = completedArrays.chars.size();

    // Build the huffman tree from the above freqArr struct
    struct MinHeapNode* root = buildHuffmanTree(completedArrays.chars, completedArrays.freqs, size);

    int intarr[MAX_TREE_HT], top = 0; 

	printCodes(root, intarr, top); 

    // Convert the input string into a bitstream using the above huffman tree.
    string bitstream = makeBitstream(root, input, completedArrays.freqs);
    std::cout << std::dec << bitstream << endl;


    return 0;
}
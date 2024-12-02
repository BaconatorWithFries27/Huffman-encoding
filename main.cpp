#include <cstdlib> 
#include <iostream>
#include <vector>
#include "inputProcessing.cpp"
#include "makeBitstream.cpp"
#include "BitStringDecoder.cpp"
#include <chrono>
using namespace std;
using namespace std::chrono;

int main(){
    auto start = high_resolution_clock::now();
    string input;

    cout << "Enter text to process: \n";\
    //getline(cin, input);
    input = "The quick brown fox jumps over the lazy dog.";
    cout << input << endl;

    /* Ask inputProcessing to parse the input string into a freqArr ->
     * 1. Vector of all the character in the string,
     * 2. Vector of frequency of occurrence of all characters in the string.
     */
    freqArr completedArrays = parseString(input);

    printArr(completedArrays);

    int size = completedArrays.chars.size();

    // Build the huffman tree from the above freqArr struct
    struct MinHeapNode* root = buildHuffmanTree(completedArrays.chars, completedArrays.freqs, size);

    int intarr[MAX_TREE_HT], top = 0; 

	printCodes(root, intarr, top); 

    // Convert the input string into a bitstream using the above huffman tree.
    string bitstream = makeBitString(root, input, completedArrays.freqs);
    std::cout << std::dec << bitstream << endl;

    cout<< "\nBeginning decoding process..." << endl;

    decode(bitstream, root);

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);

    cout << "\nRun time is: " << duration.count() << " microseconds" << endl;

}
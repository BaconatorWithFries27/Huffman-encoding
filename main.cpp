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
    getline(cin, input);
    //input = "The quick brown fox jumps over the lazy dog.";
    input = "Four score and seven years ago our fathers brought forth on this continent, "
            "a new nation, conceived in Liberty, and dedicated to the proposition that all men are created equal. "
            "Now we are engaged in a great civil war, testing whether that nation, or any nation so conceived and so dedicated, can long endure. "
            "We are met on a great battle-field of that war. We have come to dedicate a portion of that field, "
            "as a final resting place for those who here gave their lives that that nation might live. "
            "It is altogether fitting and proper that we should do this.But,in a larger sense, "
            "we can not dedicate—we can not consecrate—we can not hallow—this ground. The brave men, living and dead, "
            "who struggled here, have consecrated it, far above our poor power to add or detract. "
            "The world will little note, nor long remember what we say here, but it can never forget what they did here. "
            "It is for us the living, rather, to be dedicated here to the unfinished work which they who fought here "
            "have thus far so nobly advanced. It is rather for us to be here dedicated to the great task remaining "
            "before us—that from these honored dead we take increased devotion to that cause for which they gave the "
            "last full measure of devotion—that we here highly resolve that these dead shall not have died in vain—that "
            "this nation, under God, shall have a new birth of freedom—and that government of the people, by the people,"
            " for the people, shall not perish from the earth.";
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
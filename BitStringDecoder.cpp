/* This file is responsible for taking the completed string of bits, built by the rest of the program
* and converting it back to the original message.
 *
 */
#include <iostream>
using namespace std;

void decode(string bitString, struct MinHeapNode *root) {
    int counter = 0;
    MinHeapNode *originalRoot = root;
    string humanReadableString;

    char currBit;
    string potentialChar;
    int stringLength = bitString.length();

    for (int i = 0; i < stringLength; i++) {
        // Get the current bit in the bitString

        currBit = bitString[i];

        /* If that bit is a 1, check to see that it has a right child, if it does, append the potentialChar with a 1 and
        *  update the root to be the right child before continuing.
        */
        if (currBit == '1') {
            if (root->right) {
                potentialChar = potentialChar + "1";
                root = root->right;
            }
            /* If that bit is a 0, check to see that it has a left child, if it does, append the potentialChar with a 0 and
            *  update the root to be the left child before continuing.
            */
        } else {
            if (root->left) {
                potentialChar = potentialChar + "0";
                root = root->left;
            }
        }

        /* If the current node is a leaf, reference the potentialChar bitstring with the map of Alphanumeric characters to
         * bitstrings, append the alphanumeric string and continue.
        */
        if (isLeaf(root)) {
            root = originalRoot;
            bitmap bitmapOutput = getBitmap();

            for (int i = 0; i < bitmapOutput.binaryValues.size(); i++) {
                if (bitmapOutput.binaryValues[i] == potentialChar) {
                    cout << bitmapOutput.chars[i];
                    potentialChar = "";
                }
            }
        }
    }
}

void uintDecode(uintStream u, struct MinHeapNode *root){
    int veclen = u.vec.size();
    int decodeLen = veclen;
    if (u.len % 64 != 0) {decodeLen--;}

    string potentialChar;
    MinHeapNode *originalRoot = root;


    for (size_t i = 0; i < decodeLen; i++)
    {
        uint64_t num = u.vec[i];

        for (int j = 63; j >= 0; --j) {
        uint64_t mask = 1ULL << j;  // Create a mask with only the ith bit set
        if (num & mask)
        {
            if (root->right) {
                potentialChar = potentialChar + "1";
                root = root->right;
            } 
        } else {
            if (root->left) {
                potentialChar = potentialChar + "0";
                root = root->left;
            }
        }
        if (isLeaf(root)) {
            root = originalRoot;
            bitmap bitmapOutput = getBitmap();

            for (int i = 0; i < bitmapOutput.binaryValues.size(); i++) {
                if (bitmapOutput.binaryValues[i] == potentialChar) {
                    cout << bitmapOutput.chars[i];
                    potentialChar = "";
                }
            }
        }
        }
       
    }
      if (u.len % 64 != 0)
        {
             uint64_t num = u.vec[decodeLen];

        int modEnd = (63 - (u.len % 64) - 1);

        for (int j = 63; j >= modEnd; --j) {
        uint64_t mask = 1ULL << j;  // Create a mask with only the ith bit set
        if (num & mask)
        {
            if (root->right) {
                potentialChar = potentialChar + "1";
                root = root->right;
            } 
        } else {
            if (root->left) {
                potentialChar = potentialChar + "0";
                root = root->left;
            }
        }
        if (isLeaf(root)) {
            root = originalRoot;
            bitmap bitmapOutput = getBitmap();

            for (int i = 0; i < bitmapOutput.binaryValues.size(); i++) {
                if (bitmapOutput.binaryValues[i] == potentialChar) {
                    cout << bitmapOutput.chars[i];
                    potentialChar = "";
                }
            }
        }
        }
        }
        cout << endl;
    }
    


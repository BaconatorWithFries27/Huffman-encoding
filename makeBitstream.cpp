#include <iostream>
#include "huffman.cpp"
using namespace std;

struct bitmap {
    vector<char> chars;       // Store array of chars
    vector<string> binaryValues;    // Store binary representations as strings
};

bitmap bitmapOutput;

void makeBitmap(struct MinHeapNode* root, vector<int> arr, int top) {
    // Assign 0 to left edge and recurse
    if (root->left) { 
        arr[top] = 0; 
        makeBitmap(root->left, arr, top + 1); 
    } 

    // Assign 1 to right edge and recurse
    if (root->right) { 
        arr[top] = 1; 
        makeBitmap(root->right, arr, top + 1); 
    } 

    // Process leaf nodes
    if (isLeaf(root)) { 
        char nodechar = root->data;
        bitmapOutput.chars.push_back(nodechar);  // Add the character

        // Convert arr to string for this leaf's binary representation
        string result;
        for (int i = 0; i < top; ++i) {
            result += to_string(arr[i]);  // Convert each int to char and append
        }

        bitmapOutput.binaryValues.push_back(result);  // Add the binary representation as string
    }


}

// Wrapper function to call makeBitmap
//bitmap createBitmap(struct MinHeapNode* root, int arr[], int top) {
//    bitmap bitmapOutput;
//    return makeBitmap(root, arr, top, bitmapOutput);
//}

string makeBitString(MinHeapNode* root, string input, vector<int> arr) {

	//do stuff

	makeBitmap(root, arr, 0);

	//makeBitmap(root, arr, 0);

	int strSize = input.size();

	string huffmanString;

	for (int i = 0; i < strSize; i++) //match char to int map
	{
		char huffchar = input[i];
		int bitmapSize = bitmapOutput.chars.size();
		for (int j = 0; j < bitmapSize; j++)
		{
			if (huffchar == bitmapOutput.chars[j])
			{
				string tovec = bitmapOutput.binaryValues[j];
				huffmanString = huffmanString + tovec;
			}
		}
	}
	return huffmanString;
}

bitmap getBitmap() {
	return bitmapOutput;
}


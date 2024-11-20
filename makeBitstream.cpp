#include <cstdlib> 
#include <iostream>
//#include <vector>
#include "huffman.cpp"
using namespace std;

/*
struct bitmap {
    // These should match unless something bad happens with you data
    // I'm not adding an enforcement mechanism yet

    //store array of chars
    vector<char> chars;

    //store frequencies 
    vector<string> values;
};

bitmap makeBitmap(struct MinHeapNode* root, int arr[], int top){
	
	bitmap bitmapOutput;

	// Assign 0 to left edge and recur 
	if (root->left) { 

		arr[top] = 0; 
		makeBitmap(root->left, arr, top + 1); 
	} 

	// Assign 1 to right edge and recur 
	if (root->right) { 

		arr[top] = 1; 
		makeBitmap(root->right, arr, top + 1); 
	} 

	if (isLeaf(root)) { 

		char nodechar = root->data;
        int vecPos = bitmapOutput.chars.size();
		bitmapOutput.chars.insert(bitmapOutput.chars.begin() + vecPos, nodechar);

		vector<int> val;
		for (int i = 0; i < top; ++i){
            int valPos = val.size();
			val.insert(val.begin() + valPos, arr[i]);
		}

        int valSize = val.size();
    	string result;
        for (int i = 0; i < valSize; i++) {
        	result[i] = val[i];
    	}

     	bitmapOutput.values.insert(bitmapOutput.values.begin() + vecPos, result);
		
	}

	return bitmapOutput;
}*/

struct bitmap {
    vector<char> chars;       // Store array of chars
    vector<string> values;    // Store binary representations as strings
};

bitmap bitmapOutput;

void makeBitmap(struct MinHeapNode* root, int arr[], int top) {
    // Assign 0 to left edge and recur 
    if (root->left) { 
        arr[top] = 0; 
        makeBitmap(root->left, arr, top + 1); 
    } 

    // Assign 1 to right edge and recur 
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

        bitmapOutput.values.push_back(result);  // Add the binary representation as string
    }


}

// Wrapper function to call makeBitmap
//bitmap createBitmap(struct MinHeapNode* root, int arr[], int top) {
//    bitmap bitmapOutput;
//    return makeBitmap(root, arr, top, bitmapOutput);
//}


vector<char> makeBitstream(MinHeapNode* root, string input, int arr[]) {

    //do stuff
    
    makeBitmap(root, arr, 0);

    //makeBitmap(root, arr, 0);

    int strSize = input.size();

    vector<char> BSoutput; 

    for (int i = 0; i < strSize; i++) //match char to int map
    {
        char huffchar = input[i];
        int bitmapSize = bitmapOutput.chars.size();
        for (int j = 0; j < bitmapSize; j++)
        {
            if (huffchar == bitmapOutput.chars[j])
            {
                string tovec = bitmapOutput.values[j];
                int tovecSize = tovec.size();
                for (int k = 0; k < tovecSize; k++)
                {
                    BSoutput.insert(BSoutput.end(), tovec[k]);
                }
            }
        }
    }
    return BSoutput;
}


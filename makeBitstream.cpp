#include <cstdlib> 
#include <iostream>
//#include <vector>
#include "huffman.cpp"
using namespace std;

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
}

vector<string> makeBitstream(MinHeapNode* root, string input, int arr[]) {

    //do stuff
    vector<string> output; //this just causes infinite memory consumption

    bitmap ronald = makeBitmap(root, arr, 0);

    int strSize = input.size();

    for (int i = 0; i < strSize; i++) //match char to int map
    {
        char huffchar = input[i];
        int bitmapSize = ronald.chars.size();
        for (int j = 0; j < bitmapSize; j++)
        {
            if (huffchar == ronald.chars[j])
            {
                output.insert(output.end(), ronald.values[j]);
            }
            
        }
        
        
    }
    
    

    return output;
}


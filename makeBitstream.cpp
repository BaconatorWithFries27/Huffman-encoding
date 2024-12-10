#include <iostream>
#include "huffman.cpp"
//#include <omp.h>
using namespace std;

struct bitmap {
    vector<char> chars;       // Store array of chars
    vector<string> binaryValues;    // Store binary representations as strings
};

struct uintStream {
    vector<uint64_t> vec; // actual value
    int len; // length of stream
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

	makeBitmap(root, arr, 0);

    int numThreads = 1;

	int strSize = input.size();
	string huffmanString;
    int thread_id = 0;

#ifdef _OPENMP
        numThreads = omp_get_max_threads();
#endif
    int seglength = (strSize / numThreads);
	std::vector<string> privStr(numThreads);

#pragma omp parallel default(shared)
    {

#ifdef _OPENMP
        thread_id = omp_get_thread_num();
#endif

#pragma omp parallel for
        for (int i = 0; i < seglength; i++) //match char to int map
        {
            char huffchar = input[(thread_id * seglength) + i];
            int bitmapSize = bitmapOutput.chars.size();

            for (int j = 0; j < bitmapSize; j++)
            {
                if (huffchar == bitmapOutput.chars[j])
                {
                    string tovec = bitmapOutput.binaryValues[j];
                    privStr[thread_id] = privStr[thread_id] + tovec;
                }
            }
        }
    }
    
	for (size_t m = 0; m < numThreads; m++){
		huffmanString = huffmanString + privStr[m];
	//cout << huffmanString << endl;
	}

    if ((strSize % numThreads) != 0){
        int endParChar = seglength * numThreads;
        for (int i = endParChar; i < strSize; i++) //match char to int map
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
    }
    
	return huffmanString;
}

bitmap getBitmap() {
	return bitmapOutput;
}

uintStream stringToVec (string s){
    int strLen = s.length();
    int veclen = 8 * sizeof(uint64_t);
    int vecnum = strLen / veclen;
    
    uintStream ustream;

    vector<uint64_t> vec(vecnum + (strLen % veclen != 0 ? 1 : 0));

    for (size_t i = 0; i < vecnum; i++)
    {
        uint64_t pack = 0;
        for (size_t j = 0; j < veclen; j++)
        {
            if (s[(i * veclen) + j] == '1') {
                pack = (pack << 1) | 1;  // Shift left and set the least significant bit to 1
            } else if (s[(i * veclen) + j] == '0') {
                pack = (pack << 1);  // Shift left, implicitly setting the least significant bit to 0
            }
        }
        vec[i] = pack;
    }

    if (strLen % veclen != 0){
            cout << "mod: " << strLen % veclen << endl;
            uint64_t pack = 0;
            for (size_t j = 0; j < (strLen % veclen); j++)
            {
                if (s[(vecnum * veclen) + j] == '1') {
                    pack = (pack << 1) | 1;  // Shift left and set the least significant bit to 1
                } else if (s[(vecnum * veclen) + j] == '0') {
                    pack = (pack << 1);  // Shift left, implicitly setting the least significant bit to 0
                }
            }
        pack = pack << (veclen - (strLen % veclen));
        vec[vecnum] = pack;
    } 
    
    for (size_t i = 0; i < vec.size(); i++)
    {
        cout << vec[i];
    }
    cout << endl;
    
    ustream.vec = vec;
    ustream.len = strLen;

    return ustream;
}

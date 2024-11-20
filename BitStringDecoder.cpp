/* This file is responsible for taking the completed string of bits, built by the rest of the program
 * and converting it back to the original message.
 *
 */


void decode(string bitString, struct MinHeapNode* root) {
 cout << "The string is currently" << endl;
 std::cout << std::dec << bitString << endl;
 int counter = 0;
 MinHeapNode* originalRoot = root;
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
    root = root -> right;

   }
   /* If that bit is a 0, check to see that it has a left child, if it does, append the potentialChar with a 0 and
   *  update the root to be the left child before continuing.
   */
  } else {
   if (root->left) {
    potentialChar = potentialChar + "0";
    root = root -> left;

   }
  }

  /* If the current node is a leaf, reference the potentialChar bitstring with the map of Alphanumeric characters to
   * bitstrings, append the alphanumeric string and continue.
  */
  if (isLeaf(root)) {
   root = originalRoot;
   counter++;
  }








 }

 cout << counter << endl;

}
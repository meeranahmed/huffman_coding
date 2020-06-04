#ifndef TEST_H2
#define TEST_H2

// C++ Program for Huffman Coding
// using Priority Queue
#include <iostream>
#include <queue>
#include <unordered_map>
#include <string>
#include "oop_pgm.h"
using namespace std;

 std::unordered_map<uint8_t,int> freq_map (std::vector<uint8_t> image){
    std::unordered_map< uint8_t, int > pixelsfreq;
    for( unsigned int i = 0 ; i < image.size() ; ++i )
        pixelsfreq[ image[i] ]++;
    return pixelsfreq;

    void print_freq_map (std::unordered_map <uint8_t,int> const &m)
    {

        for (auto it = m.cbegin(); it != m.cend(); ++it)
        {
            std::cout << "{" << (*it).first << ": " << (*it).second << std::endl;
        }
    }
    // Maximum Height of Huffman Tree.
//#define MAX_SIZE 100

class HuffmanTreeNode 
{
public:

    // Stores character
    char data;

    // Stores frequency of
    // the character
    int freq;

    // Left child of the
    // current node
    HuffmanTreeNode* left;

    // Right child of the
    // current node
    HuffmanTreeNode* right;

    // Initializing the
    // current node
    HuffmanTreeNode(char character,
                    int frequency)
    {
        data = character;
        freq = frequency;
        left = NULL;
        right = NULL;
    }
}

// Custom comparator class
class Compare {
public:
    bool operator()(HuffmanTreeNode* a,
                    HuffmanTreeNode* b)
    {
        // Defining priority on
        // the basis of frequency
        return a->freq > b->freq;
    }
};

// Function to generate Huffman
// Encoding Tree
HuffmanTreeNode* generateTree(priority_queue<HuffmanTreeNode*,
                              vector<HuffmanTreeNode*>,
                                             Compare> pq)
{

    // We keep on looping till
    // only one node remains in
    // the Priority Queue
    while (pq.size() != 1) {

        // Node which has least
        // frequency
        HuffmanTreeNode* left = pq.top();

        // Remove node from
        // Priority Queue
        pq.pop();

        // Node which has least
        // frequency
        HuffmanTreeNode* right = pq.top();

        // Remove node from
        // Priority Queue
        pq.pop();

        // A new node is formed
        // with frequency left->freq
        // + right->freq

        // We take data as '$'
        // because we are only
        // concerned with the
        // frequency
        HuffmanTreeNode* node = new HuffmanTreeNode('$',
                                  left->freq + right->freq);
        node->left = left;
        node->right = right;

        // Push back node
        // created to the
        // Priority Queue
        pq.push(node);
    }

    return pq.top();
}

// Function to print the
// huffman code for each
// character.

// It uses arr to store the codes
void printCodes(HuffmanTreeNode* root,
                int arr[], int top)
{
    // Assign 0 to the left node
    // and recur
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left,
                   arr, top + 1);
    }

    // Assign 1 to the right
    // node and recur
    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }

    // If this is a leaf node,
    // then we print root->data

    // We also print the code
    // for this character from arr
    if (!root->left && !root->right) {
        cout << root->data << " ";
        for (int i = 0; i < top; i++) {
            cout << arr[i];
        }
        cout << endl;
    }
}

void HuffmanCodes(char data[],
                  int freq[], int size)
{

    // Declaring priority queue
    // using custom comparator
    priority_queue<HuffmanTreeNode*,
                   vector<HuffmanTreeNode*>,
                   Compare>
        pq;

    // Populating the priority
    // queue
    for (int i = 0; i < size; i++) {
        HuffmanTreeNode* newNode
            = new HuffmanTreeNode(data[i], freq[i]);
        pq.push(newNode);
    }

    // Generate Huffman Encoding
    // Tree and get the root node
    HuffmanTreeNode* root = generateTree(pq);

    // Print Huffman Codes
    int arr[MAX_SIZE], top = 0;
    printCodes(root, arr, top);
} 

//transverse the huffmantree and store the code in the map
unordered_map<uint8_t , string > huffmanCode;
encode (root , "" , huffmanCode);
print_freq_map(freq_map);

//print huffman Code
cout << " Huffman codes are :\n" << '\n';
for (auto pair: huffmanCode){
    cout << pair.first << " " << pair.second << '\n';
}
std::string string ="";
for (auto pair: huffmanCode){
    string+=pair.second;
}
std::cout<<"bits:   "<<string<<std::endl;
// Driver Code


#endif // TEST_H2

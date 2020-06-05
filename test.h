// C++ Program for Huffman Coding 
// using Priority Queue 
#include <iostream> 
#include <queue> 
#include <unordered_map>
#include "oop_pgm.h"
#include <string>
using namespace std; 
  
  std::unordered_map<uint8_t,int> freq_map (std::vector<uint8_t> image)
{
    std::unordered_map< uint8_t, int > pixelsfreq;
    for( unsigned int i = 0 ; i < image.size() ; ++i )
        pixelsfreq[ image[i] ]++;
    return pixelsfreq;

}
void print_freq_map (std::unordered_map <uint8_t,int> const &m)
{
    for (auto it = m.cbegin(); it != m.cend(); ++it) {
        std::cout << "{" << (*it).first << ": " << (*it).second << std::endl;
    }
}

/*
void calc(std::unordered_map<uint8_t,int> const m)
{
    unsigned int allfreq=0;
    for (auto it = m.cbegin(); it != m.cend(); ++it) {
        allfreq  = allfreq + (*it).second ;

    }
    std::cout<<allfreq;
}
*/

class HuffmanTreeNode { 
public: 
    // Stores character 
    uint8_t pixel ; 
  
    // Stores frequency of the character 
    int freq; 
  
    // Left child of the current node 
    HuffmanTreeNode* left; 
  
    // Right child of the current node 
    HuffmanTreeNode* right; 
  
    // Initializing the current node 
    HuffmanTreeNode(uint8_t character, 
                    int frequency) 
    { 
        pixel = character; 
        freq = frequency; 
        left = right = NULL; 
    } 
}; 
  
// Custom comparator class 
class Compare { 
public: 
    bool operator()(HuffmanTreeNode* l, 
                    HuffmanTreeNode* r) 
    { 
        // Defining priority on the basis of frequency 
        return l->freq > r->freq; 
    } 
}; 
  
// Function to generate Huffman Encoding Tree 
HuffmanTreeNode* generateTree(priority_queue<HuffmanTreeNode*, 
                              vector<HuffmanTreeNode*>, 
                                             Compare> pq) 
{ 
  
    // We keep on looping till only one node remains in the Priority Queue 
    while (pq.size() != 1) { 
  
        // Node which has least frequency 
        HuffmanTreeNode* left = pq.top(); 
  
        // Remove node from Priority Queue 
        pq.pop(); 
  
        // Node which has least frequency 
        HuffmanTreeNode* right = pq.top(); 
  
        // Remove node from Priority Queue 
        pq.pop(); 
  
        // A new node is formed with frequency left->freq + right->freq 
  
        // We take data as '$' because we are only concerned with the frequency 
        HuffmanTreeNode* node = new HuffmanTreeNode('$', 
                                  left->freq + right->freq); 
        node->left = left; 
        node->right = right; 
  
        // Push back node created to the Priority Queue 
        pq.push(node); 
    } 
  
    return pq.top(); 
} 
  
// Function to print the huffman code for each character. 
  
// It uses arr to store the codes 
void printCodes(HuffmanTreeNode* root, 
                uint8_t arr[], int top) 
{ 
    // Assign 0 to the left node and recur 
    if (root->left) { 
        arr[top] = 0; 
        printCodes(root->left, 
                   arr, top + 1); 
    } 
  
    // Assign 1 to the right node and recur 
    if (root->right) { 
        arr[top] = 1; 
        printCodes(root->right, arr, top + 1); 
    } 
  
    // If this is a leaf node,then we print root->data 
  
    // We also print the code for this character from arr 
    if (!root->left && !root->right) { 
        cout << root->pixel << " "; 
        for (int i = 0; i < top; i++) { 
            cout << arr[i]; 
        } 
        cout << endl; 
    } 
} 
  
void HuffmanCodes(std::unordered_map<uint8_t,int> freq_map) 
{ 
  
    // Declaring priority queue using custom comparator 
    priority_queue<HuffmanTreeNode*, 
                   vector<HuffmanTreeNode*>, 
                   Compare> 
        pq; 
  
    // Populating the priority queue 
    for (auto x : freq_map) { 
        HuffmanTreeNode* newNode 
            = new HuffmanTreeNode( x.first, x.second); 
        pq.push(newNode); 
    } 
  
    // Generate Huffman Encoding Tree and get the root node 
    HuffmanTreeNode* root = generateTree(pq); 
  
    // Print Huffman Codes 
    uint8_t x = pgm.num_pixels;
    uint8_t arr[ x ], top = 0; 
    printCodes(root, arr, top); 
} 

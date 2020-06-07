#ifndef DECODING_H
#define DECODING_H
#include <iostream>
#include <queue>
#include <unordered_map>
#include <string>
#include "oop_pgm.h"
#include <vector>
using namespace std;

// a tree node
struct HNode
{
    uint8_t pixel;
    int freq;
    HNode *left, *right;
};

// function to allocate a new node
HNode* gethnode (uint8_t pixel, int freq, HNode* left, HNode* right)
{
    HNode* node = new HNode();
    node->pixel = pixel;
    node->freq = freq;
    node->left = left;
    node->right = right;

    return node;
}
//comparison object to be used to order the heap
struct comparison
{
    bool operator()(HNode* l, HNode* r)
    {
        //highest priority item has lowest frequency
        return l->freq > r->freq;

    }
};

//traverse the huffman tree and decode the encoded string
std::string traverse_huffmantree(HNode* root , int &top_index , string str)
{
      std::string decoded = "";   
    if (root == nullptr)
        return 0;
    //found a leaf node
    if (!root->left && !root->right)
    {
        decoded+= (root->pixel);
        cout<< root->pixel;
        return 0;
    }
    top_index++;

    if (str[top_index]== '0')
        traverse_huffmantree (root->left , top_index , str);
    else
        traverse_huffmantree (root->right, top_index, str);
}


// Builds Huffman tree and decode the input
std::string decode( std::unordered_map<uint8_t,int> freq_map, std::string encoded)
{
    //creating a priority queue to store leaf nodes of huffmantree
    priority_queue<HNode* , vector<HNode*> , comparison >Pq;

    //create a leaf node for each character and add it to the priority_queue
    for(auto pair: freq_map) {
        Pq.push(gethnode(pair.first , pair.second , nullptr , nullptr));
    }

    //do it till there's more than 1 node in the queue
    while( Pq.size() != 1 )
    {
        //Removing the two nodes of the highest priority from the queue
        HNode* left= Pq.top();
        Pq.pop();
        HNode* right= Pq.top();
        Pq.pop();

        //create new internal node as parent of those two nodes
        // its frequency is the sum of their frequency
        //add this node to the priority_queue
        int sum = left->freq + right->freq;
        Pq.push(gethnode( '\0' , sum , left , right));
    }

    // root stores pointer to root of huffmantree
    HNode* root = Pq.top();

   
    //transverse the huffmantree again and decode the encoded string
    int top_index =-1;
    std::cout << " \nDecoded string is : \n ";
    while ( top_index < (int)encoded.size() - 1)
    {
        traverse_huffmantree(root , top_index , encoded);
    }

}
#endif // DECODING_H

#ifndef DECOMPRESS_H
#define DECOMPRESS_H
#include <iostream>
#include <queue>
#include <unordered_map>
#include <string>
#include "oop_pgm.h"
#include <vector>
using namespace std;

// a tree node
struct Node
{
    uint8_t pixel;
    int freq;
    Node *left, *right;
};

// function to allocate a new node
Node* getnode (uint8_t pixel, int freq, Node* left, Node* right)
{
    Node* node = new Node();
    node->pixel = pixel;
    node->freq = freq;
    node->left = left;
    node->right = right;

    return node;
}
//comparison object to be used to order the heap
struct comp
{
    bool operator()(Node* l, Node* r)
    {
        //highest priority item has lowest frequency
        return l->freq > r->freq;

    }
};

//traverse the huffman tree and decode the encoded string
void traverse_huffmantree(Node* root , int &top_index , string str)
{
    if (root == nullptr)
        return;
    //found a leaf node
    if (!root->left && !root->right)
    {
        cout<< root->pixel;
        return;
    }
    top_index++;

    if (str[top_index]== '0')
        decode (root->left , top_index , str);
    else
        decode (root->right, top_index, str);
}


// Builds Huffman tree and decode the input
std::unordered_map<uint8_t,string> decode( std::unordered_map<uint8_t,int> freq_map)
{
    //creating a priority queue to store leaf nodes of huffmantree
    priority_queue<Node* , vector<Node*> , comp >Pq;

    //create a leaf node for each character and add it to the priority_queue
    for(auto pair: freq_map) {
        Pq.push(getnode(pair.first , pair.second , nullptr , nullptr));
    }

    //do it till there's more than 1 node in the queue
    while( Pq.size() != 1 )
    {
        //Removing the two nodes of the highest priority from the queue
        Node* left= Pq.top();
        Pq.pop();
        Node* right= Pq.top();
        Pq.pop();

        //create new internal node as parent of those two nodes
        // its frequency is the sum of their frequency
        //add this node to the priority_queue
        int sum = left->freq + right->freq;
        Pq.push(getnode( '\0' , sum , left , right));
    }

    // root stores pointer to root of huffmantree
    Node* root = Pq.top();

   
    //transverse the huffmantree again and decode the encoded string
    int top_index =-1;
    std::cout << " \nDecoded string is : \n ";
    while ( top_index < (int)str.size() - 2)
    {
        traverse_huffmantree(root , top_index , str);
    }


}
#endif // DECOMPRESS_H
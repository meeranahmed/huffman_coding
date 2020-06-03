#ifndef HUFFMAN_H
#define HUFFMAN_H
#include <iostream>
#include <queue>
#include <unordered_map>
#include <string>
using namespace std;

// a tree node 
  struct Node
{
       char ch;
       int freq;
       Node *left, *right;
};

// function to allocate a new node 
Node* getnode (char ch, int freq, Node* left, Node* right)
{
 Node* node = new Node();
 node->ch = ch;
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
//traverse the huffman tree and store huffman codes in a map
void encode(Node* root, string str, unordered_map<char , string> &huffmanCode)
{
    if (root== nullptr)
    return;
    // found a leaf node
    if (!root->left && !root->right)
    {
        huffmanCode[root->ch] = str;
    }
    encode(root->left , str +"0" , huffmanCode);
    encode(root->right , str + "1", huffmanCode);

}
//traverse the huffman tree and decode the encoded string 
void decode(Node* root , int &top_index , string str)
{
    if (root == nullptr)
    return;
    //found a leaf node
    if (!root->left && !root->right)
    {
        cout<< root->ch;
        return;
    }
    top_index++;

    if (str[top_index]== '0')
    decode (root->left , top_index , str);
    else 
    decode (root->right, top_index, str);
}

#endif // HUFFMAN_H

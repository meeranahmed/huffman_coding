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
// Builds Huffman tree and decode the input
void buildhuffmanTree( char im.pixels_values)
{
    //creating a priority queue to store leaf nodes of huffmantree
    priority_queue<Node* , vector<Node*> , comp >Pq;
    //create a leaf node for each character and add it to the priority_queue
    for(auto pair: freq) {
        Pq.push(getnode(pair.first , pair.second , nullptr , nullptr));
    }
    //do it till there's more than 1 node in the queue
    while( Pq.size != 1 )
    {
        //Removing the two nodes of the highest priority from the queue
        Node* left= Pq.top();
        Pq.pop;
        Node* right= Pq.top();
        Pq.pop;

        //create new internal node as parent of those two nodes
        // its frequency is the sum of their frequency 
        //add this node to the priority_queue
        int sum = left->freq + right->freq;
        Pq.push(getn
            dnaCounter[ im.pixels_values[i] ]++;ode( '\0' , sum , left , right)); 
    }

    // root stores pointer to root of huffmantree
    Node* root = Pq.top();

    //transverse the huffmantree and store the code in the map
    unordered_map<char , string > huffmanCode;
    encode (root , "" , huffmanCode);
    
    //print huffman Code
    cout << " Huffman codes are :\n" << '\n';
    for (auto pair: huffmanCode){
        cout << pair.first << " " << pair.second << '\n';
    } 
   
   //print encoded string
   for (char ch: im.pixels_values){
       str += huffmanCode[ch];
   }
   cout << " \nEncoded string is :n\ " << str <<'\n';

   //transverse the huffmantree again and decode the encoded string
   int top_index =-1;
   cout << " \nDecoded string is : \n ";
   while ( top_index < (int)str.size - 2){
       decode (root , top_index , str);
   }
}
#endif // HUFFMAN_H

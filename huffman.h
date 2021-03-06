#ifndef HUFFMAN_H
#define HUFFMAN_H
#include <iostream>
#include <queue>
#include <unordered_map>
#include <string>
#include "oop_pgm.h"
using namespace std;
#include <bitset>

std::unordered_map<uint8_t,int> freq_map (std::vector<uint8_t> image){
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

void calc(std::unordered_map<uint8_t,int> const m)
{
    unsigned int allfreq=0;
    for (auto it = m.cbegin(); it != m.cend(); ++it) {
        allfreq  = allfreq + (*it).second ;

    }
    std::cout<<allfreq;
}

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
//traverse the huffman tree and store huffman codes in a map
void encode(Node* root, string str, unordered_map<uint8_t , string> &huffmanCode)
{
    if (root== nullptr)
        return;
    // found a leaf node
    if (!root->left && !root->right)
    {
        huffmanCode[root->pixel] = str;
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
std::unordered_map<uint8_t,string> buildhuffmanTree( std::unordered_map<uint8_t,int> freq_map)
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

    //transverse the huffmantree and store the code in the map
    unordered_map<uint8_t , string > huffmanCode;

    //print huffman Code
   /*cout << " Huffman codes are :\n" << '\n';
    for (auto pair: huffmanCode){
        cout << pair.first << " " << pair.second << '\n';
    }*/
    return huffmanCode;
     encode (root , "" , huffmanCode);
}


/*
    //print encoded string
    std::string str= "";
    for (auto ch: freq_map)
    {
        str += ch.second;
    }
    std::cout << " \nEncoded string is :n\ " << str <<std::endl;
    //transverse the huffmantree again and decode the encoded string
    int top_index =-1;
    std::cout << " \nDecoded string is : \n ";
    while ( top_index < (int)str.size() - 2)
    {
        decode (root , top_index , str);
    }
*/


std::string bit_string (std::vector <uint8_t> image,  unordered_map<uint8_t , string > hCode){
    std::string bitString="";
    //cout << " bit string  :\n" << '\n';
    for(auto ch : image){
        std::cout << hCode.at(ch);
        bitString += hCode.at(ch);
    }
    return bitString;
}

std::string byte_array (std::string bit_string)
{
    std::stringstream ss(bit_string);
    std::string byte_array ;
    while (ss.good()) {
        std::bitset<8> bits;
        ss >>bits;
        unsigned char c = char(bits.to_ulong());
        byte_array += c;
    }
   // std::cout <<"byte array :   " <<byte_array<<std::endl;
    std::cout<< "compressed size :   "<<byte_array.size()<<std::endl;
    return byte_array;
}
    // function iterates through the encoded string s
    // if s[i]=='1' then move to node->right
    // if s[i]=='0' then move to node->left
    // if leaf node append the node->data to our output string
/*
    std::string decode_file(struct Node* root, string s, unordered_map<uint8_t , string> &huffmanCode)
    {
        string ans = "";
        struct Node* curr = root;
        for (int i=0;i<s.size();i++)
        {
            if (s[i] == '0')
               curr = curr->left;
            else
               curr = curr->right;

            // reached leaf node
            if (curr->left==NULL and curr->right==NULL)
            {
                ans += curr->pixel;
                curr = root;
            }
        }
        // cout<<ans<<endl;
        return ans+'\0';
    }
*/



#endif // HUFFMAN_H

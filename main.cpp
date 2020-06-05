#include<iostream>
#include <map>
#include<unordered_map>
#include "huffman.h"
#include "oop_pgm.h"

int main()
{
    pgm im = PGM_READ(/home/mariam/oop_pgm);
    std::unordered_map<uint8_t,int> Frequency = freq_map (im.pixels_values);
    std::unordered_map<uint8_t,string> huffmanCode = buildhuffmanTree( Frequency);
    std::string string = bit_string(im.pixels_values,huffmanCode);
    std::string ByteArray = byte_array(string);
}

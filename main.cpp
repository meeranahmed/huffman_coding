#include<iostream>
#include<fstream>
#include <map>
#include<unordered_map>
#include "huffman.h"
#include "oop_pgm.h"
#include <queue>

int main(){

    pgm im = PGM_READ("/home/alaaessam/oop_pgm/NORMAL2-IM-1431-0001.pgm");
    std::unordered_map<uint8_t,int> Frequency = freq_map (im.pixels_values);
    std::unordered_map<uint8_t,string> huffmanCode = buildhuffmanTree( Frequency);
    std::string string = bit_string(im.pixels_values,huffmanCode);
    std::string ByteArray = byte_array(string);
   /* std::string decodedString ;
        decodedString = decode_file(Pq.top(), bit_string);
        cout << "\nDecoded Huffman Data:\n" << decodedString << endl; */
   std::ofstream file;
   file.open("serialize");
   file<<"p5"<<"\n"<<im.cols<<" "<<im.rows<<"\n"<<im.maxVal<<"\n"<<bit_string(im.pixels_values,huffmanCode);
   file.close();

    return 0; 
}

#include <iostream> 
#include "test.h"
#include <unordered_map>
#include <map>
#include "oop_pgm.h"
using namespace std ;

int main() 
{ 

    //int size = sizeof(data) / sizeof(data[0]); 

   pgm im = PGM_READ("/home/nouranne/oop_pgm/NORMAL2-IM-1431-0001.pgm");
    std::unordered_map<uint8_t,int> Frequency = freq_map (im.pixels_values);
    HuffmanCodes( Frequency);
 
    return 0; 
} 
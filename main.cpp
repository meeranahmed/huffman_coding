#include<iostream>
#include <map>
#include "oop_pgm.h"

void print_map(std::map<uint8_t,int> const &m)
{
    for (auto it = m.cbegin(); it != m.cend(); ++it) {
        std::cout << "{" << (*it).first << ": " << (*it).second << "}\n";
    }
}

void calc(std::map<uint8_t,int> const &m)
{
    unsigned int allfreq=0;
    for (auto it = m.cbegin(); it != m.cend(); ++it) {
        allfreq  = allfreq + (*it).second ;

    }
    std::cout<<allfreq;
}

int main()
{
    pgm im = PGM_READ("");

    //im.countFreq(im.pixels_values ,im.num_pixels);
    std::map< uint8_t, int > dnaCounter;
        for( unsigned int i = 0 ; i < im.pixels_values.size() ; ++i )
            dnaCounter[ im.pixels_values[i] ]++;

      //  print_map(dnaCounter);
       // std::cout<<dnaCounter.size()<<std::endl;
        calc(dnaCounter);



}

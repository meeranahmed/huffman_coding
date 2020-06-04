#ifndef OOP_PGM_H
#define OOP_PGM_H
#include <stdlib.h>
#include <stdint.h>
#include <string>
#include<vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include<cstdint>


struct pgm{

    unsigned int rows;
    unsigned int cols;
    unsigned int maxVal;
    std::string format;
    unsigned int num_pixels;
    std::vector< uint8_t> pixels_values;
};
pgm  PGM_READ(const std::string filepath){
    pgm read_pgm;
    std::ifstream s;
    s.open(filepath,std::ios::binary);
    if(!s)
    {
        std::cout << "not opened"<<std::endl;
        return read_pgm;
    }
    else std::cout<<"opened"<<std::endl;

    s>>read_pgm.format;

    s>>read_pgm.cols;
    s>>read_pgm.rows;
    read_pgm.num_pixels=read_pgm.cols*read_pgm.rows;
    std::cout<< "num of pixels "<<read_pgm.num_pixels<<std::endl;
    s>>read_pgm.maxVal;
    std::cout<< "MAXVAL"<< read_pgm.maxVal<<std::endl;
    read_pgm.pixels_values.resize(read_pgm.num_pixels);

    // read the elements in the pixelsvalues into the vector

    for(unsigned int i = 0;i<read_pgm.num_pixels;i++){
        //char temp;
        //s.read(&temp,1);
        //read_pgm.pixels_values[i]=temp;
        s>>read_pgm.pixels_values[i];
        /*char temp;

        s.read(&temp,1);
        read_pgm.pixels_values[i]=(uint8_t)temp;*/
    }

    if(read_pgm.num_pixels!=read_pgm.pixels_values.size()){
        std::cout<<"couldn't read all pixels"<<std::endl;
    }
    else std::cout <<"all has been read"<<std::endl;

return read_pgm;


}











#endif // OOP_PGM_H





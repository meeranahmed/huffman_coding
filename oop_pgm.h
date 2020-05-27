#ifndef OOP_PGM_H
#define OOP_PGM_H
#include <stdint.h>
#include <string>
#include<vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include<cstdint>

class pgm{
  private:
    unsigned int rows;
    unsigned int cols;
    unsigned int maxVal;
    std::string format;
    std::vector< char> grayvalues;

  private:
    void setrows(std::ifstream * stream){
        *stream>>rows;
    }
    void setcols(std::ifstream * stream){
        *stream>>cols;
    }
    void setformat(std::ifstream* stream){
        *stream>>format;
    }
    void setMaxVal (std::ifstream* stream){
        *stream>>maxVal;
    }

public:

     unsigned int getmaxval(){
         return maxVal;
     }
     std::vector<char>::size_type get_num_pixels(){
         return cols*rows;
     }
     /*void setgrayvalues(std::vector<short>gv){
         grayvalues=gv;
     }*/

     pgm PGM_READ(const std::string(filepath)){
         pgm read_pgm;
         std::ifstream s;
         s.open(filepath,std::ios_base::binary);
             if(!s)
             {
                 //std::cout << "not opened"<<std::endl;
                 return read_pgm;
             }
             setformat(&s);
             setcols(&s);
             setrows(&s);
            // std::cout<< "num of pixels  "<<get_num_pixels()<<std::endl;
             setMaxVal(&s);
            // std::cout<< "MAXVAL  "<< getmaxval() <<std::endl;
             read_pgm.grayvalues.resize(get_num_pixels());


    // read the elements in the file into a vector

             for(std::vector<char>::size_type i = 0;i<read_pgm.grayvalues.size();i++){
                 s>>read_pgm.grayvalues[i];

             }

            /* if(get_num_pixels()!=read_pgm.grayvalues.size()){
                 std::cout<<"couldn't read all pixels"<<std::endl;
             }
             else
             {
                 std::cout <<"all has been read"<<std::endl;
             }*/

            // std::cout<<read_pgm.grayvalues[6];
             return read_pgm;

     }

};
#endif // OOP_PGM_H





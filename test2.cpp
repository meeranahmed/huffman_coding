#include<iostream>
#include <map>
#include<unordered_map>
#include "test2.h"
#include "oop_pgm.h"
int main()
{
    char data[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    int freq[] = { 5, 9, 12, 13, 16, 45 };
    int size = sizeof(data) / sizeof(data[0]);

    HuffmanCodes(data, freq, size);
    return 0;
}

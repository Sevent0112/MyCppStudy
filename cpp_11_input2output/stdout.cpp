#include "stdout.h"

void div2(size_t n)
{
    if(n % 2 != 0)
    {
        std::cerr<<"the number must be a even number!"<<std::endl;
    }
    else
    {
        int result = n >> 1;
        std::cout<< "the result is "<<result<<std::endl;
    }

}
#include "exception.h"

int main(int argc, char **argv)
{
    try
    {
        std::cout<<ratio(2.0, 3.0)<<std::endl;
    }
    catch(const char* exception)
    {
        std::cerr << exception << '\n';
    }
    
}
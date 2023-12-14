#include "overload.h"

int main(int argc, char** argv)
{
    Data data1(1, 2);
    Data data2(1, 3);
    Data data3 = data1 + data2;
    data3.print();
    std::cout<<data3<<std::endl;
    std::cin>>data1;
    data1++.print();
    (++data1).print();
    int i = 2;
    std::cout<< (i++) <<std::endl;

}
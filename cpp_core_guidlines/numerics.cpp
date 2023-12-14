#include<iostream>
#include<limits>

int main(int argc, char** argv)
{
    std::cout<<std::numeric_limits<int>::max()<<std::endl;
    std::cout<<std::numeric_limits<long long>::max()<<std::endl;
    std::cout<<std::numeric_limits<long>::min()<<std::endl;
    int a = 1;
    decltype(a) b;
    std::cout<<typeid(b).name()<<std::endl;
}
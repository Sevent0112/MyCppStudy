#include "utility/timer.h"

void foo()
{
    std::cout << "foo" << std::endl;
}

void bar(const std::string& str)
{
    std::cout << str << std::endl;
}

int main(int argc, char** argv)
{
    sevent::utility::Timer t1(3);
    t1.start(1000, bar, "abc");
    std::getchar();
    return 0;

}
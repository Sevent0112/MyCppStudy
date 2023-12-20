#include "timer/timer_manager.h"

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
    sevent::timer::TimerManager t;
    t.schedule(100, 3, foo);
    t.schedule(1500, 4, bar, "str");

    while(true)
    {
        t.update();
    }
    return 0;

}
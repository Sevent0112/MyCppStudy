#include "thread.h"

std::thread t;

int main(int argc, char** argv)
{
    std::thread thread1(print, "hello abc");
    if(thread1.joinable())
    {
        thread1.join();
    }
}
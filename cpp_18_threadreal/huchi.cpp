#include "huchi.h"

std::mutex mtx1;
int shared_data = 100;
void use_lock()
{
    while(true)
    {
        {
            std::lock_guard<std::mutex> lk_guard(mtx1);
            shared_data++;
            std::cout << "current thread is " << std::this_thread::get_id() << std::endl;
            std::cout << " shared data is " << shared_data << std::endl;
        }
        std::this_thread::sleep_for(std::chrono::microseconds(10));
    }
}

void test_lock()
{
    std::thread t1(use_lock);
    std::thread t2([](){
        while(true)
        {
            {
                std::lock_guard<std::mutex> lk_guard(mtx1);
                shared_data--;
                std::cout << "current thread is " << std::this_thread::get_id() << std::endl;
                std::cout << "shared data is " << shared_data << std::endl;
            }
            std::this_thread::sleep_for(std::chrono::microseconds(10));
        }
    });
    t1.join();
    t2.join();
}

void test_stack1()
{
    threadsafe_stack1<int> safe_stack;
    safe_stack.push(1);
    std::thread t1([&safe_stack](){
        if(!safe_stack.empty())
        {
            std::this_thread::sleep_for(std::chrono::seconds(10));
            safe_stack.pop();
        }
    });

    std::thread t2([&safe_stack](){
        if(!safe_stack.empty())
        {
            safe_stack.pop();
        }
    });

    t1.join();
    t2.join();
}


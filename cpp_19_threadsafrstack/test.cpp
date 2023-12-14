#include "threadsafe_stack.h"

void TestThreadSafeStack()
{
    threadsafe_stack<int> stack;
    std::thread consumer1(
        [&]()
        {
            for(;;)
            {
                std::shared_ptr<int> data = stack.pop();
                std::cout<< "consumer1: " << *data << std::endl; 
            }
        }
    );

    std::thread consumer2(
        [&]()
        {
            for(;;)
            {
                std::shared_ptr<int> data = stack.pop();
                std::cout<< "consumer2: " << *data << std::endl; 
            }
        }
    );


    std::thread producer1(
        [&]()
        {
            for(int i = 0; i < 100; ++i)
            {
                stack.push(i);
            }
        }
    );

    std::thread producer2(
        [&]()
        {
            for(int i = 100; i < 200; ++i)
            {
                stack.push(i);
            }
        }
    );


    consumer1.join();
    consumer2.join();
    producer1.join();
    producer2.join();

    
}

int main(int argc, char** argv)
{
    TestThreadSafeStack();
    return 0;
}
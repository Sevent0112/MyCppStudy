#include "condition.h"


std::mutex mtx;
std::condition_variable cv1;
std::condition_variable cv2;


void cout1(int& num)
{
    for(;;){std::unique_lock<std::mutex> lock(mtx);
    cv2.wait(lock, [&num]()
    {
        return num == 1;
    });
    num++;
    std::cout << "thread 2 print " << num << std::endl;
    cv1.notify_one();}
    
}


void cout2(int& num)
{
    for(;;){std::unique_lock<std::mutex> lock(mtx);
    cv1.wait(lock, [&num]()
    {
        return num == 2;
    });
    num--;
    std::cout << "thread 1 print " << num << std::endl;
    cv2.notify_one();}
    
}
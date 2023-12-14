#include "threadpool.h"
#include<iostream>

void print(int i, int j)
{
    std::cout<< i << j << std::endl;
}
int main(int argc, char** argv)
{
    ThreadPool pool(3);
    pool.submit(print, 1, 2);
    pool.submit(print, 2, 3);
    pool.submit(print, 4, 5);
    pool.shutdown();
}
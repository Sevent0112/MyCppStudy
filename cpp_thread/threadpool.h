#pragma once

#include<iostream>
#include<mingw.condition_variable.h>
#include<mingw.mutex.h>
#include<mingw.thread.h>
#include<vector>
#include<queue>

class ThreadPool
{
    private:
        std::vector<std::thread> workers;
        std::queue<std::function<void()>> tasks;
        std::mutex mtx;
        std::condition_variable cv;
        bool stop;

    public:
        ThreadPool(size_t numThreads):stop(false)
        {
            for (size_t i = 0; i < numThreads; i++)
            {
                /* code */
                workers.emplace_back([this](){
                    while(true)
                    {
                        std::function<void()> task;
                        {
                            std::unique_lock<std::mutex> lock(this->mtx);
                            cv.wait(lock, [this](){return !this->tasks.empty()||this->stop;});
                            if(stop && tasks.empty()) return;
                            task = tasks.front();
                            tasks.pop();
                        }
                        task();
                    }
                });
            }
        }

        template<class F>
        void enqueue(F&& f)
        {
            {
                std::unique_lock<std::mutex> lock(this->mtx);
                tasks.emplace(std::forward<F>(f));
            }
            cv.notify_one();
        }


        ~ThreadPool()
        {
            {
                std::unique_lock<std::mutex> lock(this->mtx);
                this->stop = true;
            }
            cv.notify_all();
            for(auto& worker:this->workers)
            {
                worker.join();
            }
        }
};
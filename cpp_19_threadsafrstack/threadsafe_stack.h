#pragma once
#include<iostream>
#include<memory>
#include<mingw.thread.h>
#include<mingw.mutex.h>
#include<mingw.condition_variable.h>
#include<stack>

struct empty_stack : std::exception
{
    const char* what() const throw();
};

template<class T>
class threadsafe_stack
{
    private:
        std::stack<T> data;
        std::mutex mtx;
        std::condition_variable cv;
    
    public:
        threadsafe_stack(){}
        threadsafe_stack(const threadsafe_stack& other)
        {
            std::lock_guard<std::mutex> lock(other.mtx);
            this->data = other.data;

        }

        threadsafe_stack& operator=(const threadsafe_stack&) = delete;

        void push(T& value)
        {
            std::lock_guard<std::mutex> lock(this->mtx);
            this->data.push(value);
            cv.notify_one();
        }  

        std::shared_ptr<T> pop()
        {
            std::unique_lock<std::mutex> lock(this->mtx);
            cv.wait(lock, [this](){
                if(data.empty())
                {
                    return false;
                }
                return true;
            });

            std::shared_ptr<T> res(std::make_shared<T>(this->data.top()));
            this->data.pop();
            return res;
        }

        bool empty() const
        {
            std::lock_guard<std::mutex> lock(this->mtx);
            return this->data.empty();
        }

        bool try_pop(T& val)
    {
        std::lock_guard<std::mutex> lock(this->mtx);
        if(this->data.empty()) return false;

        val = this->data.top();
        data.pop();
        return true;
    }


};
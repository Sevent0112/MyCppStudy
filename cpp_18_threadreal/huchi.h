#pragma once
#include<iostream>
#include<stack>
#include<mingw.thread.h>
#include<mingw.mutex.h>

extern std::mutex mtx1;
extern int shared_data;
void use_lock();

void test_lock();

struct empty_stack : std::exception
{
    const char* what() const throw();
};

template<typename T>
class threadsafe_stack1
{
    private:
        std::stack<T> data;
        mutable std::mutex m;

    public:
        threadsafe_stack1(){}
        threadsafe_stack1(const threadsafe_stack1& other)
        {
            std::lock_guard<std::mutex> lock(other.m);
            this->data = other.data;
        }

        threadsafe_stack1& operator= (const threadsafe_stack1&) = delete;

        void push(T new_value)
        {
            std::lock_guard<std::mutex> lock(this->m);
            data.push(std::move(new_value));
        }

        std::shared_ptr<T> pop()
        {
            std::lock_guard<std::mutex> lock(this->m);
            if(this->data.empty()) throw empty_stack();
            std::shared_ptr<T> const res(std::make_shared<T>(this->data.top()));
            auto element = data.top();
            data.pop();
            return res;
        }

        void pop(T& value)
        {
            std::lock_guard<std::mutex> lock(this->m);
            if(this->data.empty()) throw empty_stack();
            value = data.top();
            data.pop();
        }

        bool empty() const
        {
            std::lock_guard<std::mutex> lock(this->m);
            return data.empty();
        }
};

void test_stack1();
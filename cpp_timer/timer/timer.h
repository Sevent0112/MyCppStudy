#pragma once
#include<mingw.thread.h>
#include<atomic>
#include<iostream>
#include<functional>

namespace sevent::timer
{
    class Timer
    {
        public:
            Timer();
            Timer(int repeat);
            ~Timer();

            static int64_t now();

            template<class F, class... Args>
            void callback(int milliseconds, F&& func, Args&&... args)
            {
                m_period = milliseconds;
                m_func = std::bind(std::forward<F>(func), std::forward<Args>(args)...);
            }

            void on_timer();

        private:
            int64_t m_time;
            std::function<void()> m_func;
            int m_period;
            int m_repeat;

            friend class TimerManager;
            

    };
}
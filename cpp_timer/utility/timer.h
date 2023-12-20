#pragma once

#include<mingw.thread.h>
#include<atomic>
#include<iostream>

namespace sevent::utility
{
    class Timer
    {
        public:
            Timer();
            Timer(int repeat);
            ~Timer();

            template <class F, typename... Args>
            void start(int millisecond, F&& func, Args&&... args)   // start the timer
            {
                if(m_active.load())
                {
                    return;
                }
                m_period = millisecond;  // 间隔多长时间执行一次
                m_func = std::bind(std::forward<F>(func), std::forward<Args>(args)...);
                m_active.store(true);
                m_thread = std::thread([&](){
                    if(m_repeat < 0)
                    {
                        while(m_active.load())
                        {
                            std::this_thread::sleep_for(std::chrono::milliseconds(m_period));
                            if (!m_active.load())
                            {
                                return;
                            }
                            m_func();
                        }
                    }
                    else{
                        while (m_repeat > 0)
                        {
                            if(!m_active.load())
                            {
                                return;
                            }
                            std::this_thread::sleep_for(std::chrono::milliseconds(m_period));
                            if(!m_active.load())
                            {
                                return;
                            }
                            m_func();
                            m_repeat--;
                        }
                    }
                });
                m_thread.join();

            }   

            void stop();    // stop the timer

        private:
            std::thread m_thread;   // 计时线程
            std::atomic<bool> m_active; // 是否计时
            std::function<void()> m_func;
            int m_period;   // millisecond;
            int m_repeat;   // 重复触发多少次
    };
}
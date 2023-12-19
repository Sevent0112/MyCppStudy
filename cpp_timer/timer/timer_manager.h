#pragma once

#include<map>
#include "timer.h"

namespace sevent::timer
{
    class TimerManager
    {

        public:
            template<class F, class... Args>
            void schedule(int milliseconds, F&& func, Args&&... args);

            template<class F, class... Args>
            void schedule(int milliseconds, int repeat, F&& func, Args&&... args);

            void update();


        private:
            std::multimap<int64_t, Timer> m_timers;
    };

    template<class F, class... Args>
    void TimerManager::schedule(int milliseconds, F&& func, Args&&... args)
    {
        schedule(milliseconds, -1, std::forward<F>(f), std::forward<Args>(args)...);
    }

    template<class F, class... Args>
    void TimerManager::schedule(int milliseconds, int repeat, F&& func, Args&&... args)
    {
        Timer t(repeat);
        t.callback(milliseconds, std::forward<F>(f), std::forward<Args>(args)...);
        m_timers.isnert(std::make_pair(t.m_time, t));
    }
}
#include "timer.h"

using namespace sevent::utility;

Timer::Timer(): m_active(false), m_period(0), m_repeat(-1)
{
    //repeat -1 表示无限执行
}

Timer::Timer(int repeat) : m_active(false), m_period(0), m_repeat(repeat)
{
    
}

Timer::~Timer()
{
    this->stop();
}

void Timer::stop()
{
    m_active.store(false);
}
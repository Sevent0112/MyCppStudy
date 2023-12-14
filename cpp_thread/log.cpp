#include "log.h"

Log::Log(const std::string str): ofs(str, std::ios::app){}

Log& Log::GetInstance()
{
    static Log l("log.txt");
    return l;
}

void Log::log(const std::string& message)
{
    {
        std::lock_guard<std::mutex> lock(mtx);
        ofs << message << std::endl;
    }
}
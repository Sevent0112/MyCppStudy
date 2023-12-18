#include "log/log.h"
#include<chrono>
#include<locale>
using namespace sevent::utility;
int main(int argc, char** argv)
{
    Logger::GetInstance()->open("./test.log");
    // Logger::GetInstance()->log(Logger::Level::DEBUG, __FILE__, __LINE__, "hello");
    auto now = std::chrono::system_clock::now();
    std::time_t currentTime = std::chrono::system_clock::to_time_t(now);
}
#include "log/log.h"
using namespace sevent::utility;
int main(int argc, char** argv)
{
    Logger::GetInstance()->open("./test.log");
    // Logger::GetInstance()->log(Logger::Level::DEBUG, __FILE__, __LINE__, "hello");
    debug("hello world");
    info("type error");
    fatal("lalalal")
}
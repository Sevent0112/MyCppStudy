#include <iostream>
#include <fstream>
#include <mingw.mutex.h>
#include <ctime>

class Log {
public:
    static Log& getInstance() {
        static Log instance; // 静态局部变量确保单例的唯一实例
        return instance;
    }

    void log(const std::string& message) {
        std::lock_guard<std::mutex> lock(mutex);
        std::time_t now = std::time(nullptr);
        ofs << "[" << std::ctime(&now) << "] " << message << std::endl;
    }

    Log(const Log&) = delete; // 禁止拷贝构造
    Log& operator=(const Log&) = delete; // 禁止赋值运算符

private:
    Log() : ofs("log.txt", std::ios::app) {} // 构造函数私有化，防止外部创建实例

    std::ofstream ofs;
    std::mutex mutex;
};

int main() {
    Log& logger = Log::getInstance();

    logger.log("Logging started.");

    // Simulating logs
    for (int i = 0; i < 5; ++i) {
        logger.log("Log message " + std::to_string(i));
    }

    logger.log("Logging ended.");

    return 0;
}

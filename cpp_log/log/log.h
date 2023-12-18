#pragma once

#include<fstream>
#include<iostream>
#include<string>
#include<time.h>
#include<string.h>
#include<stdexcept>
#include<stdarg.h>
namespace sevent::utility
{

#define debug(format, ...) \
    Logger::GetInstance()->log(Logger::Level::DEBUG, __FILE__, __LINE__, format, ##__VA_ARGS__);

#define info(format, ...) \
    Logger::GetInstance()->log(Logger::Level::INFO, __FILE__, __LINE__, format, ##__VA_ARGS__);

#define warn(format, ...) \
    Logger::GetInstance()->log(Logger::Level::WARN, __FILE__, __LINE__, format, ##__VA_ARGS__);

#define error(format, ...) \
    Logger::GetInstance()->log(Logger::Level::ERROR, __FILE__, __LINE__, format, ##__VA_ARGS__);

#define fatal(format, ...) \
    Logger::GetInstance()->log(Logger::Level::FATAL, __FILE__, __LINE__, format, ##__VA_ARGS__);


class Logger
{
    public:
        enum class Level
        {
            DEBUG = 0,
            INFO,
            WARN,
            ERROR,
            FATAL,
            LEVEL_COUNT
        };

        void log(Level level, const char* file, int line, const char* format, ...);
        static Logger* GetInstance();
        void open(const std::string& filename);
        void close(const std::string& filename);
        void setLevel(int level);
        void setMax(int bytes);
        
    private:
        Logger();
        ~Logger();
        void rotate();
        
    private:
        std::string m_filename;
        std::ofstream m_fout;
        static const char* s_level[static_cast<int>(Level::LEVEL_COUNT)];
        static Logger* m_instance;
        Level m_level;
        int m_max;
        int m_len;

};


}
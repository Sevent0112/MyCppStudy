#pragma once
#include<iostream>
#include<fstream>
#include<mingw.mutex.h>
#include<string>


class Log
{
    public:
        Log(const Log&) = delete;
        Log& operator=(const Log&) = delete;

        static Log& GetInstance();

        void log(const std::string& str);

    private:
        std::ofstream ofs;
        std::mutex mtx;
        Log(const std::string str);
};
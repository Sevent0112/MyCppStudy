#pragma once

#include<iostream>
#include<fstream>
#include<string>

class Log
{
    private:
        std::ofstream ofs;
        Log(const std::string& filename):ofs("log.txt", std::ios::app){}

    public:
        static Log& GetInstance();
        void log(const std::string& str) const;
        ~Log();
};
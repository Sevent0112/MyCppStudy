#pragma once
#include<iostream>
#include<string.h>

class Mystring
{
    int buf_len;
    char* characters;
public:
    Mystring(int buf_len = 64, const char* data = nullptr)
    {
        this->buf_len = 0;
        this->characters = nullptr;
        create(buf_len, data);
        std::cout<<"gouzao"<<std::endl;
    }

    Mystring(const Mystring& mystring)
    {
        this->buf_len = 0;
        this->characters = nullptr;
        create(mystring.buf_len, mystring.characters);
        std::cout<<"fuzhi"<<std::endl;
    }

    Mystring& operator=(const Mystring& ms)
    {
        create(ms.buf_len, ms.characters);
        return *this;
    }

    ~Mystring()
    {
        delete[]this->characters;
        std::cout<<"xigou"<<std::endl;
    }

    bool create(const int& len, const char* data)
    {
        release();
        this->buf_len = len;
        if(this->buf_len != 0)
        {
            this->characters = new char[this->buf_len]{};
            if(data)
                strncpy(this->characters, data, this->buf_len);
        }
        return true;
    }

    bool release()
    {
        this->~Mystring();
        this->characters = nullptr;
    
    }

    friend std::ostream& operator<<(std::ostream& os, const Mystring& ms)
    {
        os << "buf_len = " << ms.buf_len;
        os << ", characters = " << static_cast<void*>(ms.characters);
        os << "[" << ms.characters << "]";
        return os;
    }
};
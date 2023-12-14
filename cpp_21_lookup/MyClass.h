#pragma once

#include<iostream>

class MyClass
{
    public:
        MyClass(int i) : _data(i){}

        friend std::ostream& operator<<(std::ostream& out, const MyClass& mc)
        {
            out << mc._data;
            return out;
        }

    private:
        int _data;
};
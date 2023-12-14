#pragma once
#include<iostream>
#include<string>

class Data
{
    private:
        int first;
        int second;
        
    public:
        Data(int _first, int _second);
        void print();
        friend Data operator+(const Data& data1, const Data& data2);
        friend std::istream& operator>>(std::istream& in, Data& data);
        friend std::ostream& operator<<(std::ostream& out, Data& data);

        Data operator++();
        Data operator++(int);

        Data operator--();
        Data operator--(int);



        
};


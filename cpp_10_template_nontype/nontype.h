#pragma once
#include<iostream>
#include<string>
#include<memory>

template<typename T, size_t rows, size_t cols>
class Mat
{
        T data[rows][cols];
    public:
        Mat(){}
        T getElement(size_t r, size_t c);
        bool setElement(size_t r, size_t c, T value);
};

template<typename T, size_t rows, size_t cols>
T Mat<T, rows, cols>::getElement(size_t r, size_t c)
{
    if(!(r < rows && c < cols)){
        std::cout<<"cerror: out of index"<<std::endl;
        return -1;
    }
    return data[r][c];
}

template<typename T, size_t rows, size_t cols>
bool Mat<T, rows, cols>::setElement(size_t r, size_t c, T value)
{
    if(!(r < rows && c < cols))
    {
        std::cout<<"cerror: out of index"<<std::endl;
        return false;
    }
    data[r][c] = value;
    return true;
}



#pragma once
#include<iostream>


class Mat
{
    public:
        enum DataType
        {
            TYPE8U,
            TYPE8S,
            TYPE32F,
            TYPE64F

        };
    private:
        DataType type;
        void* data;
    public:
        Mat(DataType type);
        DataType getType() const;

};
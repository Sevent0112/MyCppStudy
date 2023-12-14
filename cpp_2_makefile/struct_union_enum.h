#pragma once
#include<iostream>
enum datatype {TYPE_INT8 = 1, TYPE_INT16 = 2, TYPE_INT32 = 4, TYPE_INT64 = 64};
union ipv4address 
{
    std::uint32_t address32;
    std::uint8_t address8[4]; 
};

typedef
struct Point
{
    enum datatype type;
    union
    {
        std::int8_t data8[3];
        std::int16_t data16[3];
        std::int32_t data32[3];
        std::int64_t data64[3];
    };
} Point;

size_t datawidth(const Point& pt);
std::int64_t l1norm(const Point& pt);
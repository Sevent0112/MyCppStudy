#include "struct_union_enum.h"


size_t datawidth(const Point& pt)
{
    return size_t(pt.type) * 3;
}

std::int64_t l1norm(const Point& pt)
{
    size_t result = 0;
    switch(pt.type)
    {
        case (TYPE_INT8):
            result = abs(pt.data8[0]) + abs(pt.data8[1] ) + abs(pt.data8[2]);
            break;
        case (TYPE_INT16):
            result = abs(pt.data16[0]) + abs(pt.data16[1] ) + abs(pt.data16[2]);
            break;
        case (TYPE_INT32):
            result = abs(pt.data32[0]) + abs(pt.data32[1] ) + abs(pt.data32[2]);
            break;
        case (TYPE_INT64):
            result = abs(pt.data64[0]) + abs(pt.data64[1] ) + abs(pt.data64[2]);
            break;
    }
}
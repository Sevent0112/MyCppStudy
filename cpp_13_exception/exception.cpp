#include "exception.h"
float ratio(float a, float b)
{
    if( (a + b) < FLT_EPSILON)
        throw "the sum is too small to div";
    return (a - b)/(a + b);
}

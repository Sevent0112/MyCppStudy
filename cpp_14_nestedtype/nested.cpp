#include "nested.h"

Mat::Mat(DataType type):type(type), data(nullptr){}

Mat::DataType Mat::getType() const
{
    return this->type;
}

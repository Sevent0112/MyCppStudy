#include "overload.h"

Data::Data(int _first, int _second):first(_first), second(_second){}

void Data::print()
{
    std::cout<<this->first<<" : "<<this->second<<std::endl;
}

// Data Data::operator+(const Data& data)
// {
//     Data ans(this->first+data.first, this->second+data.second);
//     return ans;
// }

Data operator + (const Data& data1, const Data& data2)
{
    return Data(data1.first+data2.first, data1.second+data2.second);
}

std::istream& operator>>(std::istream& in, Data& data)
{
    std::cout<< "input :" << std::endl;
    in >> data.first >> data.second;
    return in;

}
std::ostream& operator<<(std::ostream& out, Data& data)
{
    out<<data.first<<" : "<<data.second;
}

Data Data:: operator++()
{
    this->first++;
    this->second++;
    return *this;
}
Data Data:: operator++(int)
{
    Data data(this->first++, this->second++);
    return data;
}

Data Data::operator--()
{
    this->first--;
    this->second--;
    return *this;
}
Data Data::operator--(int)
{
    Data data(this->first--, this->second--);
    return data;
}
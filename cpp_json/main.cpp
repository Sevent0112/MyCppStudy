#include<iostream>

using namespace std;

#include "json/json.h"

using namespace yazi::json;

int main(int argc, char** argv)
{
    Json arr;
    arr[0] = Json(true);
    arr[1] = 123;
    std::cout << arr.str() << std::endl;
}
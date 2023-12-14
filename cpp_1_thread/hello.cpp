#include"hello.h"
using namespace std;
char encrypt(const char &param)
{
    return param + 13;
}

char decrypt(const char &param)
{
    return param - 13;
}

void change(string &stringItem, char (*callbackFunction)(const char &))
{
    for(size_t i = 0; i < stringItem.size(); ++i)
    {
        stringItem[i] = callbackFunction(stringItem[i]);
    }
}



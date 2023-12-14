#include<iostream>
#include<string>
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


int main(int argc, char *argv[]){
    // if(argc != 1)
    // {
    //     std::cout<<"You input "<<argc<<" arguments" << std::endl;
    //     for(size_t i = 0; i < argc; ++i)
    //     {
    //         std::cout<<"arg "<<i<<" : "<<argv[i]<<std::endl;
    //     }
    // }

    string s{"abcd"};
    change(s, encrypt);
    cout<<s<<endl;
    change(s, decrypt);
    cout<<s<<endl;

}
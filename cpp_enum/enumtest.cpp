#include<iostream>
#include<fstream>


enum class Color
{
    RED,
    YELLOW,
    BLUE
};

enum color{
    RED,
    YELLOW,
    BLUE
};

std::ostream& operator<<(std::ostream& out, Color c)
{
    out<<"RED";
    return out;
}

int main(int argc, char** argv)
{
    Color c = Color::RED;
    std::cout<<c<<std::endl;
    std::ofstream ofs("abc.txt", std::ios::app);
    ofs<<"this is a filestream sample."<<std::endl;
    ofs.close();


}
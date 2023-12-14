#include "nested.h"

int main(int argc, char** argv)
{
    float a = 2.0;
    int x = 2;
    x = a;
    Mat mat(Mat::DataType::TYPE8U);
    if(mat.getType() == Mat::DataType::TYPE8U)
        std::cout<<"This type is 8u"<<std::endl;
    int i = 18;
    float *p1 = i;
}
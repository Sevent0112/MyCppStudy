#include "nontype.h"

template class Mat<int, 2, 2>;
typedef Mat<int, 2, 2> Mat22i;

int main()
{
    // Mat22i mat;
    // mat.setElement(2, 3, 256);
    // std::cout<< mat.getElement(2,3)<<std::endl;

    Mat<int , 2, 3> mat;
    mat.setElement(1, 2, 256);
    std::cout<<mat.getElement(1, 2)<<std::endl;

    Mat<float, 3, 1> vec;
    vec.setElement(2, 0, 3.1415926);
    std::cout<<vec.getElement(2, 0)<<std::endl;
    
}
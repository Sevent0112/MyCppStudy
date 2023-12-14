#include "struct_union_enum.h"
#include <iostream>

 int main(){
    Point pt;
    pt.type = TYPE_INT32;
    std::cout<<pt.type<<std::endl;
    pt.data16[0] = 12;
    pt.data16[1] = 13;
    pt.data16[2] = 14;
    ipv4address ip;
    ip.address8[0] = 1;
    ip.address8[1] = 0;
    ip.address8[2] = 0;
    ip.address8[3] = 127;

    std::cout<<sizeof(ip)<<std::endl;
    std::cout<<+ip.address8[3]<<"."<<+ip.address8[2]<<"."<<+ip.address8[1]<<"."<<+ip.address8[0]<<std::endl;
    std::cout<< std::hex;
    std::cout<<ip.address32<<std::endl;
   //  std::cout<< l1norm(pt) << std::endl;
 }
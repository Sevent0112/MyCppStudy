#include<iostream>
#include<omp.h>

using namespace std;
int main(){
    #pragma omp parallel for
    for (size_t i = 0; i < 100; i++)
    {
        /* code */
        cout<<i<<std::endl;
    }
    
}
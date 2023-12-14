#include "norm.h"
using namespace std;
int main()
{
    float (*norm_ptr)(float x, float y);
    norm_ptr = norm_l1;
    float len1 = norm_ptr(1.0f, 2.0f);
    cout<<len1<<endl;
}

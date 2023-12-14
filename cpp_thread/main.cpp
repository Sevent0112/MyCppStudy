#include "threadpool.h"
#include "log.h"


struct X
{
    X() = default;
    X(const X& )
    {
        std::cout<< " Copy ctor"<<std::endl;
    }
    X(X&&)
    {
        std::cout<<" Move ctor"<<std::endl;
    }

    X& operator=(X& x)
    {
        std::cout<< "Copy ctor1"<<std::endl;
        return x;
    }
};

X f(X x)
{
    return x;
}

void print(int i)
{
    std::cout<<i<<std::endl;
    std::cout<< "This is the " << i << "th thread!"<<std::endl; 
}

int main(int argc, char** argv)
{
    // ThreadPool pool(8);
    // for(size_t i = 0; i < 16; ++i)
    // {
    //     pool.enqueue([i](){
    //         print(i);
    //         std::this_thread::sleep_for(std::chrono::seconds(2));
    //     });
    // }
    // return 0;
    // X r = f(X{});
    Log& log = Log::GetInstance();
    log.log("abckabc");

}
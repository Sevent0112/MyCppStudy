#include "async.h"

std::string fetchDataFromDB(std::string query)
{
    std::this_thread::sleep_for(std::chrono::seconds(5));
    return "Data " + query;
}


void use_async()
{
    /**
     * 启动策略，定义在std::launch中
     * deferred：在std::future::get()/std::future.wait()时执行
     * std::async:异步执行，马上执行
     * std::launch::async | std::launch::async
     * **/
    std::future<std::string> resultFromDB = std::async(std::launch::async, fetchDataFromDB, "Data");
    std::cout<<"Doing something else ..." << std::endl;

    /**
     * std::future::get() 阻塞调用，会立即返回任务结果，只能调用一次，会消耗掉future
     * std::future::wait() 阻塞调用，会等待异步任务完成，不会返回结果，wait可以被多次调用
     * **/
    std::string dbData = resultFromDB.get();
    std::cout<<dbData<<std::endl;
}

int my_task()
{
    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::cout << "my task run 5s" << std::endl;
    return 1;
}


#pragma once

#include<mingw.thread.h>
#include<mingw.mutex.h>
#include<queue>
#include<mingw.condition_variable.h>
#include<functional>

template<class T>
class SafeQueue
{
    private:
        std::queue<T> m_queue;
        std::mutex mtx;

    public:
        SafeQueue(){}
        SafeQueue(const SafeQueue&& other){}
        ~SafeQueue(){}

        bool empty() const
        {
            std::unique_lock<std::mutex> lock(mtx);
            return m_queue.empty();
        }

        int size() const
        {
            std::unique_lock<std::mutex> lock(mtx);
            return m_queue.size();
        }

        void enqueue(const T& t)
        {
            std::unique_lock<std::mutex> lock(mtx);
            m_queue.emplace(t);
        }

        bool dequeue(T& t)
        {
            std::unique_lock<std::mutex> lock(mtx);
            if(m_queue.empty())
                return false;
            t = std::move(m_queue.front());
            m_queue.pop();
            return true;
        }
};

class ThreadPool
{
    private:
        class ThreadWorker
        {
            private:
                int m_id; //工作id
                ThreadPool *m_pool; //所属线程池
            public:
                ThreadWorker(){}
                ThreadWorker(int i, ThreadPool* pool) : m_id(i), m_pool(pool){}
                void operator()()
                {
                    std::function<void()> func;
                    bool dequeued;
                    while(!m_pool->m_shutdown)
                    {
                        {
                            std::unique_lock<std::mutex> lock(m_pool->m_conditional_mutex);
                            m_pool->m_conditional_lock.wait(lock, [&](){return !m_pool->m_queue.empty();});
                            dequeued = m_pool->m_queue.dequeue(func); 
                        }
                        if(dequeued) func();
                    }
                }
        };

        bool m_shutdown;
        SafeQueue<std::function<void()>> m_queue;
        std::vector<std::thread> m_threads;
        std::mutex m_conditional_mutex;
        std::condition_variable m_conditional_lock;

    public:
        ThreadPool(const int n_thread = 4) : m_threads(std::vector<std::thread>(n_thread)), m_shutdown(false){}
        ThreadPool(const ThreadPool&) = delete;
        ThreadPool(ThreadPool&&) = delete;
        ThreadPool& operator=(const ThreadPool&) = delete;
        ThreadPool& operator=(ThreadPool&&) = delete;

        void init()
        {
            for (unsigned i = 0; i < m_threads.size(); ++i)
            {
                m_threads[i] = std::thread(ThreadWorker(i, this));
            }
        }

        void shutdown()
        {
            m_shutdown = true;
            m_conditional_lock.notify_all();

            for(unsigned i = 0; i < m_threads.size(); ++i)
            {
                if(m_threads[i].joinable()) m_threads[i].join();
            }
        }

        template<typename Func, typename... Args>
        void submit(Func func, Args&&... args)
        {
            m_queue.enqueue([&](){func(std::forward<Args>(args)...);});
            m_conditional_lock.notify_one();
        }
};
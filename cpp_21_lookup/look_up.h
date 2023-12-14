#pragma once


#include<vector>
#include<list>
#include<memory>
#include<map>
#include<iterator>
#include<algorithm>
#include<mingw.thread.h>
#include<mingw.shared_mutex.h>

//模版化，模版的定义和实现要放在一个编译单元中
template<class Key, class Value, class Hash = std::hash<Key>>
class threadsafe_lookup_table
{
    private:
        class bucket
        {
            friend class threadsafe_lookup_table;// 后续要访问该类的private

            private:
                typedef std::pair<Key, Value> bucket_value; // bucket 中存储的单元类型
                typedef std::list<bucket_value> bucket_data;    // bucket本质是一个list
                typedef typename bucket_data::iterator bucket_iterator; // 重命名一下迭代器

                bucket_data data;   // 类成员 一个list
                mutable std::shared_mutex mutex;    // bucket的互斥变量，用于锁

                bucket_iterator find_entry_for(const Key& key)  // 一个核心查找函数，返回迭代器
                {
                    return std::find_if(data.begin(), data.end(), [&](const bucket_value& item){return item.first == key;});
                }

            public:
                //查找key值，找到则返回对应的value，否则返回默认值
                Value value_for(const Key& key, const Value& default_value)
                {
                    std::shared_lock<std::shared_mutex> lock(mutex);// 先上锁
                    auto found_entry = find_entry_for(key); // 查找
                    return found_entry == data.end()? default_value : found_entry->second;
                }

                void add_or_update_mapping(const Key& key, const Value& value)
                {
                    std::unique_lock<std::shared_mutex> lock(mutex);
                    auto found_entry = find_entry_for(key);
                    if(found_entry == data.end())
                    {
                        data.push_back(bucket_value{key, value});   // list的添加
                    }
                    else
                    {
                        found_entry->second = value;
                    }
                }

                void remove_mapping(const Key& key)
                {
                    std::unique_lock<std::shared_mutex> lock(mutex);
                    auto found_entry = find_entry_for(key);
                    if(found_entry != data.end())
                    {
                        data.erase(found_entry); // list 的删除
                    }

                }

        };

    private:
        std::vector<std::unique_ptr<bucket>> buckets;   //真正的表,一个vector元素为指向bucket的指针
        Hash hasher;    // hash函数

        bucket& get_bucket(const Key& key) const
        {
            const size_t bucket_index = hasher(key) % buckets.size();
            return *buckets[bucket_index];
        }

    public:
        threadsafe_lookup_table(unsigned num_buckets = 19, const Hash& hasher = Hash()):buckets(num_buckets), hasher(hasher)
        {
            for (unsigned i = 0; i < num_buckets; ++i)
            {
                buckets[i].reset(new bucket());   //智能指针重定向
            }
        }

        threadsafe_lookup_table(const threadsafe_lookup_table& other) = delete;
        threadsafe_lookup_table& operator=(const threadsafe_lookup_table& other) = delete;

        Value value_for(const Key& key, const Value& defaule_value) const
        {
            return get_bucket(key).value_for(key, defaule_value);
        }

        void add_or_update_mapping(const Key& key, const Value& value)
        {
            return get_bucket(key).add_or_update_mapping(key, value);
        }

        void remove_mapping(const Key& key)
        {
            return get_bucket(key).remove_mapping(key);
        }

        std::map<Key, Value> get_map()  const
        {
            std::vector<std::unique_lock<std::shared_mutex>> locks;
            for(unsigned i = 0; i < buckets.size(); ++i)
            {
                locks.push_back(std::unique_lock<std::shared_mutex>(buckets[i]->mutex)); //给每个bucket上锁
            }

            std::map<Key, Value> res;

            for (unsigned i = 0; i < buckets.size() ; ++i)
            {
                auto it = buckets[i]->data.begin();
                for(; it != buckets[i]->data.end(); ++it)
                {
                    res.insert(*it);
                }
            }

            return res;
        }
};








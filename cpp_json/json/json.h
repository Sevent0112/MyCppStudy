#pragma once

#include<string>
#include<vector>
#include<map>
#include<sstream>

namespace yazi
{
    namespace json
    {
        class Json
        {
            public:
                enum class Type
                {
                    json_null = 0,
                    json_bool,
                    json_int,
                    json_double,
                    json_string,
                    json_array,
                    json_object
                };

                Json();
                Json(bool value);
                Json(int value);
                Json(double value);
                Json(const char* value);
                Json(const std::string& value);
                Json(Type type);
                Json(const Json& ot);

                operator int();
                operator double();
                operator bool();
                operator std::string();

                bool operator==(const Json& ot);
                bool operator!=(const Json& ot);
                
                Json& operator[](int index);
                Json& operator[](const char* key);
                Json& operator[](const std::string& key);

                void operator=(const Json& ot);

                void append(const Json& other);

                std::string str() const;

                void copy(const Json& ot);
                void clear();

                typedef std::vector<Json>::iterator iterator;

                iterator begin()
                {
                    return m_value.m_array->begin();
                }

                iterator end()
                {
                    return m_value.m_array->end();
                }

                bool isNull() const {return m_type == Type::json_null;}
                bool isInt() const {return m_type == Type::json_int;}
                bool isDouble() const {return m_type == Type::json_double;}
                bool isString() const {return m_type == Type::json_string;}
                bool isArray() const {return m_type == Type::json_array;}
                bool isObject() const {return m_type == Type::json_object;}
                bool isBool() const {return m_type == Type::json_bool;}

                bool asBool() const;
                int asInt() const;
                double asDouble() const;
                std::string asString() const;

                bool has(int index);
                bool has(const char* key);
                bool has(const std::string& key);

                void rmeove(int index);
                void remove(const char* key);
                void remove(const std::string& key);


            private:
                union Value
                {
                    bool m_bool;
                    int m_int;
                    double m_double;
                    std::string* m_string;
                    std::vector<Json>* m_array;
                    std::map<std::string, Json>* m_object;

                };

                Type m_type;
                Value m_value;
        };
    }
}
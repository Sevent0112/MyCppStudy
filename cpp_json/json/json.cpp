#include "json.h"

using namespace yazi::json;

Json::Json() : m_type(Type::json_null)
{

}

Json::Json(bool value) : m_type(Type::json_bool)
{
    m_value.m_bool = value;
}

Json::Json(int value) : m_type(Type::json_int)
{
    m_value.m_int = value;
}


Json::Json(double value) : m_type(Type::json_double)
{
    m_value.m_double = value;
}

Json::Json(const char* value) : m_type(Type::json_string)
{
    m_value.m_string = new std::string(value);
}


Json::Json(const std::string& value) : m_type(Type::json_string)
{
    m_value.m_string = new std::string(value);
}

Json::Json(Type type) : m_type(type)
{
    switch(m_type)
    {
        case Type::json_null:
            break;
        case Type::json_bool:
            m_value.m_bool = false;
            break;
        case Type::json_int:
            m_value.m_int = 0;
            break;
        case Type::json_double:
            m_value.m_double = 0.0;
            break;
        case Type::json_string:
            m_value.m_string = new std::string("");
            break;
        case Type::json_array:
            m_value.m_array = new std::vector<Json>();
            break;
        case Type::json_object:
            m_value.m_object = new std::map<std::string, Json>();
        default:
            break;
    }
}

Json::Json(const Json& ot)
{
    copy(ot);
}


Json::operator int()
{
    if(m_type != Type::json_int)
    {
        throw "type error , no int value";
    }
    return m_value.m_int;
}

Json::operator double()
{
    if(m_type != Type::json_double)
    {
        throw "type error , no double value";
    }
    return m_value.m_double;
}

Json::operator bool()
{
    if(m_type != Type::json_bool)
    {
        throw "type error , no bool value";
    }
    return m_value.m_bool;
}

Json::operator std::string()
{
    if(m_type != Type::json_string)
    {
        throw "type error , no string value";
    }
    return *(m_value.m_string);
}


Json& Json::operator[](int index)
{
    if(m_type != Type::json_array)
    {
        m_type = Type::json_array;
        m_value.m_array = new std::vector<Json>();
    }

    if(index < 0)
    {
        throw "array[] index < 0";
    }

    int size = m_value.m_array->size();
    if(index >= size)
    {
        for(int i = size; i <= index; ++i)
        {
            (m_value.m_array)->push_back(Json());
        }
    }
    return (m_value.m_array)->at(index);
}

Json& Json::operator[](const char* key)
{
    std::string name(key);
    return (*(this))[name];
}

Json& Json::operator[](const std::string& key)
{
    if (m_type != Type::json_object)
    {
        clear();
        m_type = Type::json_object;
        m_value.m_object = new std::map<std::string, Json>();
    }
    return (*(m_value.m_object))[key];
}

void Json::operator=(const Json& ot)
{
    clear();
    copy(ot);
}

void Json::append(const Json& other)
{
    if(m_type != Type::json_array)
    {
        clear();
        m_type = Type::json_array;
        m_value.m_array = new std::vector<Json>();
    }

    m_value.m_array->push_back(other);

}


std::string Json::str() const
{
    std::stringstream ss;
    switch(m_type)
    {
        case Type::json_null:
            ss << "null";
            break;
        case Type::json_bool:
            if(m_value.m_bool)
                ss << "true";
            else ss << "false";
            break;
        case Type::json_int:
            ss << m_value.m_int;
            break;
        case Type::json_double:
            ss << m_value.m_double;
            break;
        case Type::json_string:
            ss << '\"' << m_value.m_string << '\"';
            break;
        case Type::json_array:
            {
                ss << '[';
                for(auto it = (m_value.m_array)->begin(); it != (m_value.m_array)->end(); it++)
                {
                    if (it != (m_value.m_array)->begin())
                    {
                        ss<< ",";
                    }
                    ss << it->str();
                }
                ss << "]";
                break;
            }
        case Type::json_object:
            {
                ss << '{';
                for(auto it = (m_value.m_object)->begin(); it != (m_value.m_object)->end(); it++)
                {
                    if (it != (m_value.m_object)->begin())
                    {
                        ss<< ",";
                    }
                    ss << '\"' << it->first << '\"' << ":" << it->second.str();
                }
                ss << "}";
                break;
            }
    }
    return ss.str();
}

void Json::copy(const Json& ot)
{
    m_type = ot.m_type;
    switch(m_type)
    {
        case Type::json_null:
            break;
        case Type::json_bool:
            m_value.m_bool = ot.m_value.m_bool;
            break;
        case Type::json_int:
            m_value.m_int = ot.m_value.m_int;
            break;
        case Type::json_double:
            m_value.m_double = ot.m_value.m_double;
            break;
        case Type::json_string:
            m_value.m_string = ot.m_value.m_string;
            break;
        case Type::json_array:
            m_value.m_array = ot.m_value.m_array;
            break;
        case Type::json_object:
            m_value.m_object = ot.m_value.m_object;
        default:
            break;
    }
}

void Json::clear()
{
    switch (m_type)
    {
        case Type::json_null:
            break;
        case Type::json_bool:
            m_value.m_bool = false;
            break;
        case Type::json_int:
            m_value.m_int = 0;
            break;
        case Type::json_double:
            m_value.m_double = 0.0;
            break;
        case Type::json_string:
            delete m_value.m_string;
            break;
        case Type::json_array:
            {
                for(auto it = (m_value.m_array)->begin(); it != (m_value.m_array)->end(); it++)
                {
                    it->clear();
                }
                delete m_value.m_array;
                break;
            }
        case Type::json_object:
            {
                for(auto it = (m_value.m_object)->begin(); it != (m_value.m_object)->end(); it++)
                {
                    (it->second).clear();
                }
                delete m_value.m_object;
                break;
            }
        default:
            break;
        m_type = Type::json_null;
    }
}


bool Json::operator==(const Json& ot)
{
    if (m_type != ot.m_type)
        return false;
    switch (m_type)
    {
        case Type::json_null:
            return true;
        case Type::json_int:
            return m_value.m_int == ot.m_value.m_int;
        case Type::json_double:
            return m_value.m_double == ot.m_value.m_double;
        case Type::json_bool:
            return !(m_value.m_bool^ot.m_value.m_bool);
        case Type::json_string:
            return (*(m_value.m_string)) == (*(ot.m_value.m_string));
        case Type::json_array:
            return m_value.m_array == ot.m_value.m_array;
        case Type::json_object:
            return m_value.m_object == m_value.m_object;
        default:
            break;
    }
}

bool Json::operator!=(const Json& ot)
{
    return !((*this)==ot);
}


bool Json::asBool() const
{
    if(m_type != Type::json_bool)
    {
        throw "type error, not bool value";
    }
    return m_value.m_bool;
}

int Json::asInt() const
{
    if(m_type != Type::json_int)
    {
        throw "type error, not int value";
    }
    return m_value.m_int;
}

double Json::asDouble() const
{
    if(m_type != Type::json_double)
    {
        throw "type error, not double value";
    }
    return m_value.m_double;
}

std::string Json::asString() const
{
    if(m_type != Type::json_string)
    {
        throw "type error, not string value";
    }
    return *(m_value.m_string);
}

bool Json::has(int index)
{
    if(m_type != Type::json_array)
    {
        return false;
    }
    int size = (m_value.m_array)->size();
    return (index >= 0 && index < size);
}

bool Json::has(const char* key)
{
    std::string str(key);
    return has(key);
}

bool Json::has(const std::string& key)
{
    if(m_type != Type::json_object)
    {
        return false;
    }
    return (m_value.m_object)->find(key) != m_value.m_object->end();
}


void Json::rmeove(int index)
{
    if(has(index))
    {
        (*(m_value.m_array))[index].clear();
        (m_value.m_array)->erase((m_value.m_array)->begin() + index);
    }
}

void Json::remove(const char* key)
{
    std::string name(key);
    remove(name);
}


void Json::remove(const std::string& key)
{
    if(has(key))
    {
        (*(m_value.m_object))[key].clear();
        (*(m_value.m_object)).erase(key);
    }
}
//
// Created by xobtah on 25/01/17.
//

#ifndef JASONIUM_JSON_HPP
#define JASONIUM_JSON_HPP

#include <string>
#include <map>
#include <typeinfo>
#include <boost/any.hpp>

#define OBJTYPE(type) decltype(typeid(type).name())

namespace Jasonium
{
    class Json
    {
    public:
        struct JsonValue
        {
            JsonValue() {}
            template <typename T>
            JsonValue(T const &value) : _value(value) {}

            template <typename T>
            void    operator=(T const &value) { _value = value; }

            template <typename T>
            T   Value() const
            { return (boost::any_cast<T>(_value)); }

            boost::any  _value;

        };

        Json();
        ~Json();

        JsonValue   &operator[](std::string);

        //Json        &Export(std::string const &fileName = "a.json");

    private:
        std::map<std::string, JsonValue> _data;
    };
}

#endif //JASONIUM_JSON_HPP

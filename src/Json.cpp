//
// Created by xobtah on 25/01/17.
//

#include <iostream>
#include <map>
#include <fstream>

#include "Json.hpp"

namespace ium
{
    /*
     *   Ctor & Dtor
     */

    Json::Json() {}

    Json::Json(const Json &js) : _data(js._data) {}

    Json    &Json::operator=(const Json &js)
    {
        if (this == &js)
            return (*this);
        _data = js._data;
        return (*this);
    }

    Json::~Json() {}

    /*
     *  Member functions
     */

    Json::JsonValue &Json::operator[](std::string key) { return (_data[key]); }
}
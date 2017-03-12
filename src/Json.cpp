//
// Created by xobtah on 25/01/17.
//

#include <iostream>
#include <map>
#include <fstream>

#include "Json.hpp"

namespace Jasonium
{
    /*
     *   Ctor & Dtor
     */

    Json::Json() {}

    Json::~Json() {}

    /*
     *  Member functions
     */

    Json::JsonValue &Json::operator[](std::string key) { return (_data[key]); }

    /*Json  &Json::Export(std::string const &fileName)
    {
        std::ofstream   file(fileName, std::ofstream::out);

        if (!file.is_open())
            return (*this);
        file << *this;
        file.close();
        return (*this);
    }*/
}
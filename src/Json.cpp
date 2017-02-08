//
// Created by xobtah on 25/01/17.
//

#include <iostream>
#include <map>
#include <fstream>

#include "Json.hpp"

std::ostream    &operator<<(std::ostream &os, const Jasonium::Json &json)
{
    std::map<std::string, std::string>  stringMap = json.GetStringMap();
    std::map<std::string, int>          intMap = json.GetIntMap();
    std::map<std::string, bool>         boolMap = json.GetBoolMap();
    int tabNb = 0;

    os << "{" << std::endl;
    tabNb++;
    for (std::map<std::string, std::string>::const_iterator it = stringMap.begin(); it != stringMap.end(); it++)
    {
        for (int i = 0; i < tabNb; i++) os << '\t';
        os << it->first << ": \"" << it->second << "\"";
        it++;
        if (it != stringMap.end() || intMap.size())
            os << ',';
        it--;
        os << "\n";
    }
    for (std::map<std::string, int>::const_iterator it = intMap.begin(); it != intMap.end(); it++)
    {
        for (int i = 0; i < tabNb; i++) os << '\t';
        os << it->first << ": " << std::to_string(it->second);
        it++;
        if (it != intMap.end() || boolMap.size())
            os << ',';
        it--;
        os << "\n";
    }
    for (std::map<std::string, bool>::const_iterator it = boolMap.begin(); it != boolMap.end(); it++)
    {
        for (int i = 0; i < tabNb; i++) os << '\t';
        os << it->first << ": " << (it->second ? "true" : "false");
        it++;
        if (it != boolMap.end())
            os << ',';
        it--;
        os << "\n";
    }
    os << "}";
    return (os);
}

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

    std::string &Json::StringField(std::string const &key) { return (_stringFields[key]); }
    int         &Json::IntField(std::string const &key) { return (_intFields[key]); }
    bool        &Json::BoolField(std::string const &key) { return (_boolFields[key]); }
    Json        &Json::JsonField(std::string const &key) { return (_jsonFields[key]); }

    std::map<std::string, std::string>  Json::GetStringMap() const { return (_stringFields); }
    std::map<std::string, int>          Json::GetIntMap() const { return (_intFields); }
    std::map<std::string, bool>         Json::GetBoolMap() const { return (_boolFields); }
    std::map<std::string, Json>         Json::GetJsonMap() const { return (_jsonFields); }

    Json  &Json::Export(std::string const &fileName)
    {
        std::ofstream   file(fileName, std::ofstream::out);

        if (!file.is_open())
            return (*this);
        file << *this;
        file.close();
        return (*this);
    }
}
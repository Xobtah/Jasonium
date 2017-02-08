//
// Created by xobtah on 25/01/17.
//

#ifndef JASONIUM_JSON_HPP
#define JASONIUM_JSON_HPP

#include <string>
#include <map>

namespace Jasonium
{
    class Json
    {
    public:
        Json();
        ~Json();

        std::string &StringField(std::string const&);
        int         &IntField(std::string const&);
        bool        &BoolField(std::string const&);
        Json        &JsonField(std::string const&);

        std::map<std::string, std::string>  GetStringMap() const;
        std::map<std::string, int>          GetIntMap() const;
        std::map<std::string, bool>         GetBoolMap() const;
        std::map<std::string, Json>         GetJsonMap() const;

        Json        &Export(std::string const &fileName = "a.json");

    private:
        std::map<std::string, std::string>  _stringFields;
        std::map<std::string, int>          _intFields;
        std::map<std::string, bool>         _boolFields;
        std::map<std::string, Json>         _jsonFields;
    };
}

#endif //JASONIUM_JSON_HPP

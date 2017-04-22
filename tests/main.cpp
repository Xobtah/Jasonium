//
// Created by xobtah on 25/01/17.
//

#include <iostream>
#include <string>

#include "../src/Json.hpp"

class   ExampleObj
{
public:
    ExampleObj(std::string mystring) : _string(mystring) {}
    ~ExampleObj() {}

    std::string &GetString() { return (_string); }

private:
    std::string _string;
};

class   JsonObj : public ium::Json {};

int main()
{
    ium::Json   obj;
    ium::Json   obj2;
    ExampleObj  exobj("ficelle");
    JsonObj     jsonobj;

    jsonobj["string"] = "my string";
    obj["test"] = 42;
    obj["lol"] = "kek";
    obj["ptdr"] = true;
    obj["exobj"] = exobj;
    obj["jsonobj"] = jsonobj;
    std::cout << obj["test"].Value<int>() << std::endl;
    std::cout << obj["lol"].Value<TYPENAME(std::string)>() << std::endl;
    std::cout << obj["ptdr"].Value<bool>() << std::endl;
    //std::cout << obj["exobj"].Value<TYPENAME(ExampleObj)>().GetString() << std::endl;
    //std::cout << obj["jsonobj"].Value<TYPENAME(JsonObj)>()["string"].Value<TYPENAME(std::string)>() << std::endl;
    obj2 = obj;
    std::cout << obj2["test"].Value<int>() << std::endl;
    std::cout << obj2["lol"].Value<TYPENAME(std::string)>() << std::endl;
    std::cout << obj2["ptdr"].Value<bool>() << std::endl;
    return (0);
}
//
// Created by xobtah on 25/01/17.
//

#include <iostream>
#include <string>
#include <typeinfo>

#include "../src/Json.hpp"

int main()
{
    Jasonium::Json    obj;

    /*obj.Export();*/

    obj["test"] = 42;
    obj["lol"] = "kek";
    obj["ptdr"] = true;
    std::cout << obj["test"].Value<int>() << std::endl;
    std::cout << obj["lol"].Value<OBJTYPE(std::string)>() << std::endl;
    std::cout << obj["ptdr"].Value<bool>() << std::endl;
    return (0);
}
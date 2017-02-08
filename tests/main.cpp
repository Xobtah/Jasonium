//
// Created by xobtah on 25/01/17.
//

#include <iostream>
#include <string>

#include "../src/Json.hpp"

int main()
{
    Jasonium::Json    obj;

    obj.StringField("lol") = "kek";
    obj.IntField("mdr") = 42;
    obj.BoolField("ptdr") = true;
    std::cout << obj.StringField("lol") << std::endl;
    std::cout << obj.IntField("mdr") << std::endl;
    std::cout << obj.BoolField("ptdr") << std::endl;
    obj.Export();
    //std::cout << obj << std::endl;
    return (0);
}
#pragma once

#include <string>

class Object
{
public:
    Object(const std::string &name = "Object");
    ~Object();

    void say_hello();
    void say_hello_to(const std::string &name);

private:
    const std::string m_name;
};
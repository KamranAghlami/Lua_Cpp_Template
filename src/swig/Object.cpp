#include "Object.h"

#include <iostream>

Object::Object(const std::string &name) : m_name(name)
{
    std::cout << "Constructing Object(\"" << m_name << "\")" << std::endl;
}

Object::~Object()
{
    std::cout << "Destructing Object(\"" << m_name << "\")" << std::endl;
}

void Object::say_hello()
{
    say_hello_to(m_name);
}

void Object::say_hello_to(const std::string &name)
{
    std::cout << "Hello, " << name << std::endl;
}

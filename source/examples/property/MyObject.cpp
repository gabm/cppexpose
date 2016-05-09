
#include "MyObject.h"

#include <iostream>


using namespace cppexpose;


MyObject::MyObject(const std::string & name)
: Object(name)
, String(this, "string", this, &MyObject::getString, &MyObject::setString)
, Int   (this, "int"   , this, &MyObject::getInt,    &MyObject::setInt)
, Float (this, "float",  this, &MyObject::getFloat,  &MyObject::setFloat)
, MyMood(this, "mood",   this, &MyObject::getMood,   &MyObject::setMood)
, Number(this, "number")
, m_string("Hello")
, m_int(1)
, m_float(0.1)
, m_mood(Mood::Sad)
{
}

MyObject::~MyObject()
{
}

void MyObject::print()
{
    std::cout << "string = '" << m_string << "'" << std::endl;
    std::cout << "int    = "  << m_int << std::endl;
    std::cout << "float  = "  << m_float << std::endl;
    std::cout << "mood   = "  << (int)m_mood << " (" << MyMood.asTyped()->toString() << ")" << std::endl;
    std::cout << std::endl;
}

std::string MyObject::getString() const
{
    return m_string;
}

void MyObject::setString(const std::string & value)
{
    m_string = value;
}

int MyObject::getInt() const
{
    return m_int;
}

void MyObject::setInt(const int & value)
{
    m_int = value;
}

float MyObject::getFloat() const
{
    return m_float;
}

void MyObject::setFloat(const float & value)
{
    m_float = value;
}

Mood MyObject::getMood() const
{
    return m_mood;
}

void MyObject::setMood(const Mood & value)
{
    m_mood = value;
}
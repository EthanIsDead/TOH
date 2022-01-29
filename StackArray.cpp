#include "StackArray.h"
#include <string>
#include <stdio.h>

StackArray::StackArray(int _length) : nextIn(0)
{
    length = _length; 
    stack = (Object*)calloc(length, sizeof(Object)); 
}

StackArray::~StackArray()
{
    
}

//push method (array based)
bool StackArray::push(Object data)
{
    if(nextIn == length)
        return false;

    *(stack + nextIn) = data; 
    nextIn++; 

    return true; 
}

Object* StackArray::pop()
{
    if(nextIn == 0)
        return nullptr; 
    
    nextIn--; 
    Object* data = (Object*)malloc(sizeof(Object)); 
    *data = *(stack + nextIn); 
    return data; 
}

void StackArray::clear()
{
    nextIn = 0; 
}

bool StackArray::isEmpty()
{
    return nextIn == 0; 
}

bool StackArray::isFull()
{
    return nextIn == length; 
}

int StackArray::size()
{
    return nextIn+1; 
}

std::string StackArray::toString()
{
    std::string str = ""; 

    for(int i = 0; i < nextIn; i++)
    {
        str = str + std::to_string((stack + i)->diameter); 

        if(i < nextIn)
            str += " "; 
    }

    return str; 
}



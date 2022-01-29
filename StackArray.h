#include <iostream>
#include "Object.h"

class StackArray
{
    public:
        StackArray(int _length); 
        ~StackArray(); 
        
        bool push(Object); 
        Object* pop(); 
        void clear(); 
        bool isEmpty(); 
        bool isFull(); 
        int size(); 
        std::string toString(); 

    private:
        Object *stack; 
        int nextIn; 
        int length; 
}; 
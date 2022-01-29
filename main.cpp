#include <iostream>
#include <stdlib.h>    
#include <time.h> 
#include <string>

#include "StackArray.h"
#include "Object.h"

void toh(int n, StackArray disks[], int src, int target, int aux); 

int main() 
{
    srand(time(NULL));

    std::cout << "Enter Number: "; 
    int num = -1; 
    std::cin >> num; 

    if(num == 0)
    {
        StackArray sa(10); 
        Object obj; 
        obj.diameter = 100; 
        bool result = sa.push(obj); 
        Object obj2 = *sa.pop(); 
        std::cout << obj2.diameter << std::endl; 
    }
    else if(num == 1)
    {
        StackArray rods[3] = { StackArray(10), StackArray(10), StackArray(10) };
        const int MAX_DIAMETER = 100; 
        const int MIN_DIAMETER = 10; 
        int numOfDisks = 4; 
        Object rodDisks[numOfDisks]; 

        for(int i = 0; i < numOfDisks; i++)
        {
            Object disk; 
            disk.diameter = (rand() % ((MAX_DIAMETER + 1) - MIN_DIAMETER)) + MIN_DIAMETER; 

            rodDisks[i] = disk; 
            disk.index = i; 
        }

        for(int i = 0; i < numOfDisks; i++)
        {
            for(int j = 0; j < numOfDisks; j++)
            {
                if(rodDisks[i].diameter > rodDisks[j].diameter)
                {
                    Object temp = rodDisks[i]; 
                    rodDisks[i] = rodDisks[j]; 
                    rodDisks[j] = temp; 
                }
            }
        }

        for(int i = 0; i < numOfDisks; i++)
        {
            rods[0].push(rodDisks[i]); 
        }
    
        for(int i = 0; i < 3; i++)
        {
            std::cout << "---------------------" << std::endl; 
            std::cout << rods[i].toString() << std::endl; 
        }

        std::cout << "<<--------------------->>" << std::endl; 

        //TOH
        toh(numOfDisks, rods, 0, 2, 1); 
    }
    else if(num == 2)
    {
 
        return 0; 
    }

    return 0; 
}

void toh(int n, StackArray disks[], int src, int target, int aux)
{
    for(int i = 0; i < 3; i++)
    {
        std::cout << "---------------------" << std::endl; 
        std::cout << disks[i].toString() << std::endl; 
    }

    std::cout << "<<--------------------->>" << std::endl; 

    if(n > 0)
    {
        toh(n-1, disks, src, aux, target); 

        disks[target].push(*disks[src].pop()); 

        toh(n-1, disks, aux, target, src); 
    }
}


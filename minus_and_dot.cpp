#include "func.hpp"
#ifndef MAIN_CPP

#define MAIN_CPP

#include <iostream>
#endif

char *minus_dot(const char *value, int length, int &Pos)
{   
    char *arr =  new char [length-2];
    int index = 0;
    int tmp_L = length;
    int posit = 0;
    int count_of_dot = 0;
    for(int i = 0; i <= length; i++)
    {
        if(value[i] == '.'  && value[0] == '-')
        {   
            Pos = position(value, arr, posit, count_of_dot,tmp_L);
        //  count_of_dot++;
        //  posit = i+1;
        //  posit = (length + 1) - posit;
        //  tmp_L -= 1;
            continue;
        }
        arr[index] = value[i];
        index++;
    }
    
    return arr;
    delete [] arr;
}


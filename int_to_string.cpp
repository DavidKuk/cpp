#include "func.hpp"
#ifndef MAIN_CPP
#define MAIN_CPP

#include <iostream>

#endif

char int_to_string(int num)
{
        char symbol = 0;
        if(num < 48 || num > 58){
              std::cout<<"Don't input space";
                return 0;
        }
        else{

                symbol = (char)num;
        }
        return symbol;
}



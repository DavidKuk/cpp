#include "func.hpp"
#ifndef MAIN_CPP
#define MAIN_CPP

#include <iostream>

#endif

int *string_to_int(const char *symbol)
{
        int length = 0;
        int len_sym = sizeof(symbol)-1;

        while(len_sym != 0)
        {
                length++;
                len_sym--;
        }

        int *res = new int [length];

        for(int i = 0; i < length; i++)
        {
                if(symbol[i] < 48 || symbol[i] > 58)
                        continue;
                else {
                	res[i] = symbol[i];
				}
        }

        return res;
}


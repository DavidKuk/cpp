#include "func.hpp"
#ifndef MAIN_CPP

#define MAIN_CPP

#include <iostream>

#endif

int position(const char *value, char * tmp_value, int &pos, int &count_of_dot, int length)
{
        int index = 0;
        for(int i = 0;i<=length;++i)
        {
                if(value[i] == '.' && value[0] != '-')
                {
                        count_of_dot++;
                        pos = i+1;
                        pos = length - pos;
                        continue;
                }
				if(value[0] == '-' && value[i] == '.')
				{
					count_of_dot++;
					pos = i+1;
					pos = length - pos;
					break;
				}
                tmp_value[index] = value[i];
                index++;
        }
        return pos;
}


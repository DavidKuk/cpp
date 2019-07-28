#ifndef MAIN_CPP

#define MAIN_CPP

#include <iostream>

#endif
template <typename T>
T function_for_minus (const char* value, int *ptr, int length, int tmp_length, const char argv_minus, int position, int divDegree)
{
        int *new_argvF = new int[length];
        int iterator = 0;       // elements of first argument
        T sum1 = 0;
        int j = 1;
        int l = 0;
        int arr [length];
        int units = 0;
        int degree = 1;
        int tmp_deg = 10;
        if(argv_minus == '-')
        {
                for(int i = 0; i < length; i++)
                {

                        if(value[i] == '-')
                        {
                                tmp_length--;
                                new_argvF = new int[tmp_length];
                        }
						else if(value[i] == '.' && value[0] == '-')
							tmp_length -= 2;
			
                        else
                        {
                                new_argvF[l] = int(ptr[j]-48);
                                j++;
                                l++;
                        }
                }
                
				length = tmp_length;

                while(tmp_length > 1)
                {
                        degree = degree * tmp_deg;
                        tmp_length--;
                }

                for(int j=0; j < length; ++j)
                        arr[j] = new_argvF[j];

                delete [] new_argvF;
                while(degree > 1)
                {
                        units = arr[iterator] * degree;
                        sum1 += units;
                        degree /= 10;
                        iterator++;
                }
                sum1 += arr[length - 1];
                sum1 *= (-1);
			
				if(position > 0)
				{
					sum1 /= divDegree;
                    std::cout <<"number -> " << double(sum1) << std::endl;
				}
				else
                    std::cout <<"number -> " << sum1 << std::endl;
        }	
        else
        {
                tmp_length = length;
                while(tmp_length > 1)
                {
                        degree = degree * tmp_deg;
                        tmp_length--;
                }

                int arr [length];
                for(int j=0; j < length; ++j){
                        arr[j] = int(ptr[j]-48);
                }


                while(degree > 1)
                {
                        units = arr[iterator] * degree;
                        sum1 += units;
                        degree /= 10;
                        iterator++;
                }


                if(length>1)
                        sum1 += arr[length - 1];
                else
                        sum1 += arr[length-1];

                if(position > 0){
                        sum1 = sum1/divDegree;
                        std::cout <<"number -> " << double(sum1) << std::endl;
                }
                else
                        std::cout <<"number -> " << sum1 << std::endl;
        }
        return sum1;
}


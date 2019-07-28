#include "func.hpp"
#ifndef MAIN_CPP

#define MAIN_CPP

#include<iostream>

#endif

double operation(double number1, double number2, const char *argv)
{
		int count = 0;
        double result = 0;
        char ch = *argv;

		for(int i = 0; i < 2; i++) 
			if(argv[i] != '\0')
				count++;
			
		if(count > 1) {
			std::cout << "Wrong operation(Input +, -, /, x):" << std::endl;
			return 0;
		}
	
        switch(ch)
        {
                case '+':
                        result = number1 + number2;
                        std::cout << number1 << " " << ch << " " << number2 << " = "; 
                break;
                case '-':
                        result = number1 - number2;
                        std::cout << number1 << " " << ch << " "  << number2 << " = "; 
                break;
                case 'x':
                        result =number1 * number2;
                        std::cout << number1 << " " << ch << " " << number2 << " = "; 
                break;
                case '/':
                        result = number1 / number2;
                        std::cout << number1 << " " << ch << " " << number2 << " = "; 
                break;
                default:
                        std::cout << "Wrong operation" << std::endl;
                        break;
        }
        return result;
}


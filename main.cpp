#ifndef MAIN_CPP

#define MAIN_CPP

#include <iostream>
#include "argument_sign.cpp"

#endif

#include "func.hpp"
#include <string>
#include <cmath>	// for function pow()
using namespace std;

int main(int argc,const char *argv[])
{
	int count_of_wrong_sym = 85;
	char Symbols[count_of_wrong_sym];	// count of wrong symbols to take arguments
	char index_symbol = 0;

	for(int i = 32; i < 128; i++)
	{
		if(i == 45 || i == 46)
			continue;
		if(i > 47 && i < 58)
			continue;
		Symbols[index_symbol] = char(i);
		index_symbol++;
	}


	if(argc<4){
		cout<<"\n Please write correct  \'sign\'<OPERAND1>\" \"<OPERATION / x + - >\" \"\'sign\'<OPERAND2> \n";
		return 0;		
	}
	const char *value1 = argv[1];
	const char *value2 = argv[3];

	int length = 0;		// length of argv[1]
	int length2 = 0;	// length of argv[2]

	int i = 0;	// index element argv[1]
	int i2 = 0;	// index element argv[2]
	
	int *ptr=NULL;
	int *ptr2=NULL;
	
	// first arument loop - to length
	while(argv[1][i] != '\0')
	{
		length++;
		i++;	
	}
	char *tmp_value1 = NULL;
	if(length > 1)
		tmp_value1 = new char[length-1];
	else
		tmp_value1 = new char[length];
	int pos = 0;
	int count_of_dot = 0;
	// position of first argument and count of dot
	int posit = position(value1, tmp_value1, pos, count_of_dot, length);

	/////////

	if(count_of_dot == 1) {
		length--;
	}
	
	int divDegree = pow(10,posit);

	for(int i = 0; i <= length; i++)
	{
		for(int j = 0; j < count_of_wrong_sym; j++)
		{
			if(value1[i] == Symbols[j] || value1[i+1] == '-')
			{
				cout << "First argument is wrong" << endl;
				cout << "Please write correct  \'sign\'<OPERAND1>\" \"<OPERATION / x + - >\" \"\'sign\'<OPERAND2> \n";
				return 0;
			}
		}
	}
	
	int tmp_length = length;
	for(int i = 0; i < length; i++) {
		if (value1[i] == '.' && value1[0] != '-'){
			tmp_length--;
			ptr = string_to_int(tmp_value1);
			break;
		}
		else if(length > 2 && value1[0] == '-' && value1[i] == '.')
		{
			int pos_for_func = 0;
			value1 = minus_dot(value1, length, pos_for_func);
			ptr = string_to_int(value1);
			break;
		}
		else {
      			ptr = string_to_int(value1);
		}
	}
	delete [] tmp_value1;

	char first_arg_minus = argv[1][0];
	 
//##########################################################	
	double sum1 = function_for_minus<double>(value1, ptr, length, tmp_length, first_arg_minus, posit, divDegree);
	//////////
	// second arument loop
	while(argv[3][i2] != '\0')
	{
		length2++;
		i2++;
	}
	///// SECOND ARGUMENT
	char *tmp_value2 = NULL;
	if(length2 > 1)
		tmp_value2 = new char[length2-1];
	else
		tmp_value2 = new char[length2];

	pos = 0;
	count_of_dot = 0;
	posit = position(value2, tmp_value2, pos, count_of_dot, length2);
	divDegree = 0;
	divDegree = pow(10, posit);
	if(count_of_dot == 1)
		length2--;

	int tmp_length2 = length2;


	for(int i = 0; i <= length2; i++)
	{
		for(int j = 0; j < count_of_wrong_sym; j++)
		{
			if(value2[i] == Symbols[j] || value2[i+1] == '-')
			{
				cout << "Second argument is wrong" << endl;
				cout << "Please write correct  \'sign\'<OPERAND1>\" \"<OPERATION / x + - >\" \"\'sign\'<OPERAND2> \n";
				return 0;
			}
		}
	}

	for(int i = 0; i < length2; i++) {
		if (value2[i] == '.' && value2[0] != '-'){
			tmp_length2--;
			ptr2 = string_to_int(tmp_value2);
			break;
		}
		else if(length2 > 2 && value2[0] == '-' && value2[i] == '.')
		{
			int pos_for_func = 0;
			value2 = minus_dot(value2, length2, pos_for_func);
			ptr2 = string_to_int(value2);
			break;
		}
		else 
			ptr2= string_to_int(value2);
	}

	delete [] tmp_value2;
	//second argument signed and unsigned
	char second_arg_minus = argv[3][0];
	
	double sum2 = function_for_minus<double>(value2, ptr2, length2, tmp_length2, second_arg_minus, posit, divDegree);

	double res = 0;
	const char *oper = argv[2];

	res = operation(sum1, sum2, oper);
	cout << res << endl;


	return 0;
}


#include "pch.h"
#include "print_and_create.cpp"
#include "get_result.cpp"
#include <iostream>
#include <fstream>
#include <time.h>

using namespace std;

int main()
{
	srand(time(NULL));
	create("First_input.bin");
	print_in("First_input.bin");
	create("Second_input.bin");
	print_in("Second_input.bin");
	ofstream Result_File("Result_output.bin", ios::binary);
	ifstream First_File("First_input.bin", ios::binary);
	if (!First_File.is_open())
	{
		Result_File << "Проверьте первый файл";
		Result_File.close();
		return 0;
	}
	ifstream Second_File("Second_input.bin", ios::binary);
	if (!Second_File.is_open())
	{
		Result_File << "Проверьте второй файл";
		Result_File.close();
		return 0;
	}
	get_result(First_File, Second_File, Result_File);
	Result_File.close();
	print_answer("Result_output.bin");
	return 0;
}
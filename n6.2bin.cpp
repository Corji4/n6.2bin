#include "pch.h"
#include <iostream>
#include <fstream>
#include <time.h>
#include "print_and_create.cpp"
#include "get_result.cpp"

using namespace std;

int main()
{
	srand(time(NULL));
	create("First_input.bin");
	print_input_file("First_input.bin");
	create("Second_input.bin");
	print_input_file("Second_input.bin");
	get_result("First_input.bin", "Second_input.bin", "Result_output.bin");
	print_output_file("Result_output.bin");
	return 0;
}
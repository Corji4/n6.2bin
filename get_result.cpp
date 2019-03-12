#include "pch.h"
#include <iostream>
#include <fstream>

using namespace std;

void get_result(ifstream &First_File, ifstream &Second_File, ofstream &Result_File)
{
	int First_Size, Second_Size;
	First_File.read(reinterpret_cast <char*> (&First_Size), sizeof(int));
	Second_File.read(reinterpret_cast <char*> (&Second_Size), sizeof(int));
	double First_Number, Second_Number;
	First_File.read(reinterpret_cast <char*> (&First_Number), sizeof(double));
	Second_File.read(reinterpret_cast <char*> (&Second_Number), sizeof(double));
	First_Size--;
	Second_Size--;
	while (First_Size >= 0 || Second_Size >= 0)
	{
		if (First_Size < 0)
		{
			Result_File.write(reinterpret_cast <char*> (&Second_Number), sizeof(double));
			Second_File.read(reinterpret_cast <char*> (&Second_Number), sizeof(double));
			Second_Size--;
			continue;
		}
		if (Second_Size < 0)
		{
			Result_File.write(reinterpret_cast <char*> (&First_Number), sizeof(double));
			First_File.read(reinterpret_cast <char*> (&First_Number), sizeof(double));
			First_Size--;
			continue;
		}
		if (First_Number > Second_Number)
		{
			Result_File.write(reinterpret_cast <char*> (&Second_Number), sizeof(double));
			Second_File.read(reinterpret_cast <char*> (&Second_Number), sizeof(double));
			Second_Size--;
			continue;
		}
		if (First_Number < Second_Number)
		{
			Result_File.write(reinterpret_cast <char*> (&First_Number), sizeof(double));
			First_File.read(reinterpret_cast <char*> (&First_Number), sizeof(double));
			First_Size--;
			continue;
		}
		if (First_Number == Second_Number)
		{
			Result_File.write(reinterpret_cast <char*> (&Second_Number), sizeof(double));
			First_File.read(reinterpret_cast <char*> (&First_Number), sizeof(double));
			First_Size--;
			Second_File.read(reinterpret_cast <char*> (&Second_Number), sizeof(double));
			Second_Size--;
		}
	}
}
#include "pch.h"
#include <iostream>
#include <fstream>

using namespace std;

void get_result(string First_name, string Second_name, string Result_name)
{
	ofstream Result_File(Result_name, ios::binary);
	ifstream First_File(First_name, ios::binary);
	ifstream Second_File(Second_name, ios::binary);
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
	Result_File.close();
}
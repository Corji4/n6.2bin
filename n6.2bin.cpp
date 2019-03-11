#include "pch.h"
#include <iostream>
#include <fstream>
#include <time.h>

using namespace std;

void get_result(ifstream &First_File, ifstream &Second_File, ofstream &Result_File);
void create(string name);
void print_answer(string name);
void print_in(string name);

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

void create(string name)
{
	double v = rand() % 5;
	ofstream file(name, ios::binary);
	file.clear();
	int size = rand() % 10 + 2;
	file.write(reinterpret_cast <char*> (&size), sizeof(int));
	for (int i = 0; i < size; i++)
	{
		v += rand() % 30;
		file.write(reinterpret_cast <char*> (&v), sizeof(double));
	}
	file.close();
}

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

void print_answer(string name)
{
	double v;
	ifstream file(name, ios::binary);
	file.read(reinterpret_cast <char*> (&v), sizeof(double));
	while (!file.eof())
	{
		cout << v << " ";
		file.read(reinterpret_cast <char*>(&v), sizeof(double));
	}
	cout << endl;
}

void print_in(string name)
{
	int k;
	double v;
	ifstream file(name, ios::binary);
	file.read(reinterpret_cast <char*> (&k), sizeof(int));
	file.read(reinterpret_cast <char*> (&v), sizeof(double));
	cout << k << endl;
	while (!file.eof())
	{
		cout << v << " ";
		file.read(reinterpret_cast <char*>(&v), sizeof(double));
	}
	cout << endl << endl;
}
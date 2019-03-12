#include "pch.h"
#include <iostream>
#include <fstream>

using namespace std;

void print_output_file(string name)
{
	double number_from_file;
	ifstream file(name, ios::binary);
	file.read(reinterpret_cast <char*> (&number_from_file), sizeof(double));
	while (!file.eof())
	{
		cout << number_from_file << " ";
		file.read(reinterpret_cast <char*>(&number_from_file), sizeof(double));
	}
	cout << endl;
	file.close();
}

void print_input_file(string name)
{
	int number_of_elements;
	double element_from_file;
	ifstream file(name, ios::binary);
	file.read(reinterpret_cast <char*> (&number_of_elements), sizeof(int));
	cout << number_of_elements << endl;
	file.read(reinterpret_cast <char*> (&element_from_file), sizeof(double));
	while (!file.eof())
	{
		cout << element_from_file << " ";
		file.read(reinterpret_cast <char*>(&element_from_file), sizeof(double));
	}
	cout << endl << endl;
}

void create(string name)
{
	double random_number = rand() % 5;
	ofstream file(name, ios::binary);
	file.clear();
	int size = rand() % 10 + 2;
	file.write(reinterpret_cast <char*> (&size), sizeof(int));
	for (int i = 0; i < size; i++)
	{
		random_number += rand() % 30 + 1;
		file.write(reinterpret_cast <char*> (&random_number), sizeof(double));
	}
	file.close();
}
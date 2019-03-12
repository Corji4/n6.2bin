#include "pch.h"
#include <iostream>
#include <fstream>

using namespace std;

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
#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
#include <sstream>

class Vector
{
public:
	Vector(int num);
	~Vector();
	

	void metodo();
	void mostrar();
private:
	int* vector;
	int cantidad;
	int tam;
	int* ptr;
};
#endif

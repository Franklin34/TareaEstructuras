#ifndef VECTORINT_H
#define VECTORINT_H
#include <iostream>
#include <sstream>

class VectorInt
{
private:
	int* vect;
	int conteo_max;
	int conteo;
public:
	VectorInt();
	VectorInt(int);
	VectorInt(const VectorInt& x);

	~VectorInt();

	void insertar(int);
	void borrar(int);

	int value_at(int);
	void change_value_at(int d, int i);

	std::string mostrar();

};
#endif

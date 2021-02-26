#ifndef NODO_H
#define NODO_H

#include <iostream>

using namespace std;

class Nodo
{
private:
	Nodo *sig;
	int data;
public:
	Nodo();
	Nodo(int );
	~Nodo();
	void borrar_todo();
	void imprimir();
	Nodo * getSig();
	void setSig(Nodo *);
	int getData();
	void setData(int );
};

#endif // NODE_H
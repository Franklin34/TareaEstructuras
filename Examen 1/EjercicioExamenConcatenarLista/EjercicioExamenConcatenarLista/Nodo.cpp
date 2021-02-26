#include "Nodo.h"

Nodo::Nodo()
{
	data = NULL;
	sig = NULL;
}

Nodo::Nodo(int valor)
{
	this->data = valor;
}

void Nodo::borrar_todo()
{
	if (sig)
		sig->borrar_todo();
	delete this;
}

void Nodo::imprimir()
{
	cout << data << " ";
}


Nodo* Nodo::getSig()
{
	return sig;
}

void Nodo::setSig(Nodo* nodoSig)
{
	this->sig = nodoSig;
}

int Nodo::getData()
{
	return data;
}

void Nodo::setData(int)
{
}

Nodo::~Nodo() {

}
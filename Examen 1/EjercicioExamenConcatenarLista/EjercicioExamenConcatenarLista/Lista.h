#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

#include "Nodo.h"

using namespace std;

class Lista
{
private:
	Nodo* cabecera;
	
public:
	Lista();
	~Lista();
	Lista(const Lista&);
	void insertar_final(int);
	void mostrarLista();
	Nodo* getCabecera() { return cabecera; }
	void borrar_todo();
};

#endif // LISTA_H

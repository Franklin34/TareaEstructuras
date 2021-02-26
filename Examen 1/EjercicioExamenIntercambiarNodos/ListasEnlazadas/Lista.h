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
	Nodo *cabecera;
	void borrar_todo();

public:
	Lista();
	~Lista();
	void insertar_final(int );
	void mostrarLista();
	void Intercambiar(Nodo*, Nodo*);

	Nodo* getCabecera() { return cabecera; }

	void agregarDerecha(int,int);

};

#endif // LISTA_H

#ifndef LISTASIMPLE_H
#define LISTASIMPLE_H

#include <iostream>

// Estructura para una lista enlazada simple
struct Nodo {
	int valor;
	Nodo* next;
};

void InsertarElemento(Nodo**, int);
void MostrarLista(Nodo*);
void BorrarLista(Nodo**);
bool ListaVacia(Nodo*);

#endif
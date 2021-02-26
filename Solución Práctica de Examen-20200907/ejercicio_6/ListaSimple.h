#ifndef LISTASIMPLE_H
#define LISTASIMPLE_H

#include <iostream>

// Estructura para una lista enlazada simple
struct Nodo {
	char valor;
	Nodo* next;
};

void InsertarElemento(Nodo**, char);
void MostrarLista(Nodo*);
void BorrarLista(Nodo**);
bool ListaVacia(Nodo*);

#endif
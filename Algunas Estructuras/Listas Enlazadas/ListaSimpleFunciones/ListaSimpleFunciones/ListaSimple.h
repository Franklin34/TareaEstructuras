// ListaSimple.h
// Autor: El Tigre
// Descripción: Declaración de la Lista Enlazada Simple de números enteros

#ifndef LISTA_H
#define LISTA_H

struct Nodo {
	int dato;  // publicos
	struct Nodo* next;
};

void Insertar(int, struct Nodo**);
void BorrarElemento(int, struct Nodo**);
void Limpiar(struct Nodo**);

#endif

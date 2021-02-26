// listasimple.cpp
// Autor: El Tigre
// Descripción: Definición de la Lista Simple. Este código es de ejemplo y no se recomienda su implementación, es necesario realizar cambios para
//              hacer la implementación más robusta.

#include "ListaSimple.h"

void Insertar(int x, struct Nodo** actual) {
	struct Nodo* nuevo = new Nodo;
	(*nuevo).dato = x;
	(*nuevo).next = nullptr;

	if (!*actual) {
		*actual = nuevo;
		return;
	}

	struct Nodo* tmp = *actual;
	while (tmp->next != nullptr)
		tmp = tmp->next;

	tmp->next = nuevo;
}

void BorrarElemento(int valor, struct Nodo** actual) {
	// Si la lista no tiene elementos
	if (!*actual)
		return;

	// Si el elemento a borrar es el primero
	struct Nodo* tmp = *actual;
	
	if ((*actual)->dato == valor) {
		*actual = (*actual)->next;
		delete tmp;
		return;
	}

	// Si la lista tiene varios elementos
	struct Nodo* tmp2 = tmp->next;
	
	while (tmp2 != nullptr) {
		if (tmp2->dato == valor) {
			tmp->next = tmp2->next;
			delete tmp2;
			return;
		}
		tmp = tmp2;
		tmp2 = tmp2->next;
	}
}

void Limpiar(struct Nodo** actual) {
	if (!*actual)
		return;

	struct Nodo* aux = *actual;
	while (!*actual) {
		aux = *actual;
		*actual = (*actual)->next;
		delete aux;
	}
}


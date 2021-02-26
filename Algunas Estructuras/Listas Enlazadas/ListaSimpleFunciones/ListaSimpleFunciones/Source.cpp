// Source.cpp
// Autor: El Tigre
// Descripción: Programa de ejemplo para probar la Lista Simple

#include "ListaSimple.h"
#include <iostream>
#include <vector>


void Mostrar(struct Nodo*);

int main() {

	struct Nodo* inicio = nullptr;

	std::cout << "Tam de *inicio: " << sizeof(inicio) << std::endl;
	std::cout << "Tam de Nodo: " << sizeof(struct Nodo) << std::endl;

	Insertar(8, &inicio);      
	Insertar(3, &inicio);      
	Insertar(7, &inicio);      
	Insertar(19, &inicio);
	Insertar(22, &inicio);

	Mostrar(inicio);

	BorrarElemento(7, &inicio);
	BorrarElemento(14, &inicio);
	BorrarElemento(3, &inicio);

	Mostrar(inicio);

	Limpiar(&inicio);

	return 0;
}

void Mostrar(struct Nodo* actual) {
	struct Nodo* aux = actual;
	
	while (aux) {
		std::cout << aux->dato << " ";
		aux = aux->next;
	}
	std::cout << std::endl << std::endl;
}
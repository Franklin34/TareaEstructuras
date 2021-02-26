#include "ListaSimple.h"

//Nodo* ConcatenarOrdenado(Nodo*&, Nodo*&);
Nodo* ConcatenarOrdenadoRecursivo(Nodo*&, Nodo*&,Nodo*&tmp,Nodo*&nuevo);

int main() {
	Nodo* primera = nullptr;
	Nodo* segunda = nullptr;

	InsertarElemento(&primera, 14);
	InsertarElemento(&primera, 22);
	InsertarElemento(&primera, 27);
	InsertarElemento(&primera, 30);
	InsertarElemento(&primera, 42);
	InsertarElemento(&primera, 54);
	std::cout << "Primera Lista: ";
	MostrarLista(primera);

	InsertarElemento(&segunda, 7);
	InsertarElemento(&segunda, 10);
	InsertarElemento(&segunda, 18);
	InsertarElemento(&segunda, 25);
	InsertarElemento(&segunda, 46);
	InsertarElemento(&segunda, 53);
	std::cout << "Segunda Lista: ";
	MostrarLista(segunda);
	
	std::cout << "Lista Concatenada - Version Recursiva: ";

	Nodo* tmp = nullptr;
	Nodo* nuevo = new Nodo;
	nuevo->next = nullptr;
	tmp = nuevo;

	Nodo* cuarto = ConcatenarOrdenadoRecursivo(primera, segunda, tmp, nuevo);
	MostrarLista(cuarto);

	return 0;
}
Nodo* ConcatenarOrdenadoRecursivo(Nodo*&primera, Nodo*&segunda, Nodo*&tmp, Nodo*& nuevo) {
	if (primera == nullptr && segunda == nullptr)
		return nullptr;

	if (primera != nullptr && segunda != nullptr) {
		if (primera->valor <= segunda->valor) {
			tmp->next = primera;
			primera = primera->next;
			return ConcatenarOrdenadoRecursivo(primera, segunda, tmp = tmp->next, nuevo);
		}
		else {
			tmp->next = segunda;
			segunda = segunda->next;
			return ConcatenarOrdenadoRecursivo(primera, segunda, tmp = tmp->next, nuevo);
		}
		tmp = tmp->next;
	 }

	tmp = nuevo->next;
	delete nuevo;
	return tmp;
}
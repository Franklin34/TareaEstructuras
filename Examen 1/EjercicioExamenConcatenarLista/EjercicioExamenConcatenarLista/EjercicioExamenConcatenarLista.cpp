#include "Lista.h"

Nodo* ConcatenarOrdenadoRecursivo(Nodo*, Nodo*, Nodo* tmp, Nodo* nuevo);
void mostrarListaConcatenada(Nodo*);

int main() {
	Lista lista1;
	lista1.insertar_final(13);
	lista1.insertar_final(45);
	lista1.insertar_final(23);
	lista1.insertar_final(7);
	lista1.insertar_final(67);
	lista1.insertar_final(19);
	
	lista1.mostrarLista();

	Lista lista2;
	lista2.insertar_final(19);
	lista2.insertar_final(65);
	lista2.insertar_final(23);
	lista2.insertar_final(79);
	lista2.insertar_final(12);
	lista2.insertar_final(20);

	lista2.mostrarLista();

	std::cout << "Lista Concatenada - Version Recursiva: ";

	Nodo* tmp = nullptr;
	Nodo* nuevo = new Nodo;
	nuevo->setSig(nullptr);
	tmp = nuevo;

	Nodo* tmp2 = lista1.getCabecera();
	Nodo* tmp3 = lista2.getCabecera();

	Nodo* cuarto = ConcatenarOrdenadoRecursivo(tmp2, tmp3, tmp, nuevo);


	mostrarListaConcatenada(cuarto);

	std::cout << '\n';


	delete nuevo;
}
Nodo* ConcatenarOrdenadoRecursivo(Nodo* primera, Nodo* segunda, Nodo* tmp, Nodo* nuevo) {
	if (primera == nullptr && segunda == nullptr)
		return nullptr;

	if (primera != nullptr && segunda != nullptr) {
		if (primera->getData() <= segunda->getData()) {
			tmp->setSig(primera);
			primera = primera->getSig();
			return ConcatenarOrdenadoRecursivo(primera, segunda, tmp = tmp->getSig(), nuevo);
		}
		else {
			tmp->setSig(segunda);
			segunda = segunda->getSig();
			return ConcatenarOrdenadoRecursivo(primera, segunda, tmp = tmp->getSig(), nuevo);
		}
		tmp = tmp->getSig();
	}

	if (primera != nullptr)
		tmp->setSig(primera);
	else
		tmp->setSig(segunda);

	tmp = nuevo->getSig();
	
	return tmp;
}
void mostrarListaConcatenada(Nodo*temp) {
	while (temp) {
		temp->imprimir();
		if (!temp->getSig());
		temp = temp->getSig();
	}
}
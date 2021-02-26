#include "lista_simple.h"
#include <iostream>

void Mostrar(const ListaSimple<int>&);

int main() {
	ListaSimple<int> lista;

	lista.Insertar(43);
	lista.Insertar(30);
	lista.Insertar(27);
	lista.Insertar(62);
	lista.Insertar(8);
	lista.Insertar(20);

	Mostrar(lista);

	lista.EliminarEnPos(3);

	Mostrar(lista);

	lista.BorrarLista();

	return 0;
}

void Mostrar(const ListaSimple<int>& l) {
	ListaSimple<int>::listaptr tmp;
	tmp = l.GetPrimerNodo();

	while (tmp != nullptr) {
		std::cout << tmp->valor << " ";
		tmp = tmp->next;
	}
	std::cout << "\n\n";
}
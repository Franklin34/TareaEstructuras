#include "ListaSimple.h"
#include <iostream>

void MostrarLista(const ListaSimple&);

int main() {
	
	ListaSimple l;

	l.Insertar(10);
	l.Insertar(2);
	l.Insertar(17);
	l.Insertar(8);
	l.Insertar(22);

	MostrarLista(l);

	l.Eliminar(2);

	MostrarLista(l);

	l.EliminarEnPos(1);

	MostrarLista(l);

	l.BorrarLista();

	return 0;
}

// Se para una referencia de la lista - no modifica la dirección de la lista original ni ninguno de sus valores
void MostrarLista(const ListaSimple& lista){
	if (lista.GetPrimerNodo() != nullptr) {
		ListaSimple::iterador tmp = lista.GetPrimerNodo();
		while (tmp != nullptr) {
			std::cout << tmp->valor << " ";
			tmp = tmp->next;
		}
	}
	std::cout << "\n\n";
}
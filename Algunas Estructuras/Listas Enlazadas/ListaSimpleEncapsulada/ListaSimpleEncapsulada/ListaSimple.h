// lista_simple.h
// Descripción: Definición de una lista enlazada simple - versión encapsulada (tanto el nodo como la lista)

#ifndef LISTA_SIMPLE_H
#define LISTA_SIMPLE_H

// Declaración de la lista
class ListaSimple {
private:
	struct Nodo {
		int valor;
		struct Nodo* next;
		Nodo(int v = 0, Nodo* n = nullptr) : valor{ v }, next{ n }{}
	};
	Nodo* inicio;

public:
	typedef Nodo* iterador;
	
	// Constructor default
	ListaSimple() { inicio = nullptr; }
	// Constructor de copia
	ListaSimple(const ListaSimple&);
	~ListaSimple() { BorrarLista(); }
	void Insertar(int);
	void Eliminar(int);
	void EliminarEnPos(size_t);
	void BorrarLista();
	iterador GetPrimerNodo() { return inicio; }
	iterador GetPrimerNodo() const { return inicio; }
};

#endif
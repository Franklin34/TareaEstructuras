#include "Pila.h"


Stack::Stack() : top{ -1 }, pila{ 0 } {}

Stack::~Stack() {
}


void Stack::push(const int elemento) {
	if (!estaLlena())
		pila[++top] = elemento;
}

// Recupera el elemento de la pila si no está vacía
int Stack::pop() {
	return (!estaVacia() ? pila[top--] : -1);
}

// Despliega el elemento de la pila sin eliminarlo
int Stack::peek() {
	return (!estaVacia() ? pila[top] : -1);
}

// Retorna "true" si la pila está vacía. "false", en caso contrario
bool Stack::estaVacia() {
	return (top == -1 ? true : false);
}

// Retorna "true" si la pila está vacía. "false", en caso contrario
bool Stack::estaLlena() {
	return (top == MAX - 1 ? true : false);
}
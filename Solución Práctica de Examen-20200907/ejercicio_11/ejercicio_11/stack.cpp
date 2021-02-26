#include "stack.h"

Stack::Stack() : top{ nullptr } {}


Stack::~Stack() {
	Nodo* tmp = top;
	while (top != nullptr) {
		top = top->next;
		delete tmp;
		tmp = top;
	}
}

void Stack::push(const int item) {
	Nodo* nuevo;

	try
	{
		nuevo = new Nodo;
	}
	catch (std::bad_alloc exception)
	{
		return;
	}

	nuevo->elemento = item;
	nuevo->next = top;
	top = nuevo;
}

int Stack::pop() {
	if (estaVacia())
		return -1;
	
	int valor;
	Nodo* tmp;
	
	valor = top->elemento;
	tmp = top;
	top = top->next;
	delete tmp;
	tmp = nullptr;
	return valor;
}

int Stack::peek() {
	return (!estaVacia() ? top->elemento : -1);
}

bool Stack::estaVacia() {
	return top == nullptr;
}
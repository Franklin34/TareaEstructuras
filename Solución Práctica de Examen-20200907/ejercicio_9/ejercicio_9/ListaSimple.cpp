#include "ListaSimple.h"

//Primero se verifica que se pueda crear memoria. Una vez creada la memoria, se realiza una 
//inserción simple, asignando el valor al nuevo nodo. El nodo recién insertado se convierte en el
//ultimo elemento de la lista
void InsertarElemento(Nodo** actual, int item) {
	Nodo* nuevo;

	try
	{
		nuevo = new Nodo;
	}
	catch (std::bad_alloc exception)
	{
		return;
	}

	nuevo->valor = item;

	if (ListaVacia(*actual)) {
		*actual = nuevo;
		(*actual)->next = nullptr;
	}
	else {
		Nodo* tmp;
		tmp = *actual;
		while (tmp->next != nullptr)
			tmp = tmp->next;
		tmp->next = nuevo;
		nuevo->next = nullptr;
		tmp = nullptr;
	}
	nuevo = nullptr;
}

//Recorre la lista enlazada mostrando el contenido de cada uno de los elementos
void MostrarLista(Nodo* actual) {
	if (ListaVacia(actual)) {
		return;
	}
	else
	{
		Nodo* tmp;
		tmp = actual;
		while (tmp != nullptr) {
			std::cout << tmp->valor << " ";
			tmp = tmp->next;
		}
		std::cout << std::endl << std::endl;
	}
}


//Con ayuda de un puntero auxiliar, se recorre la lista de inicio a fin, eliminando de la memoria cada uno de los nodos
//Esta función no retorna ningún valor
void BorrarLista(Nodo** actual) {
	Nodo* tmp;
	while (*actual != nullptr) {
		tmp = *actual;
		*actual = (*actual)->next;
		delete tmp;
	}
	*actual = nullptr;
}

//Función que devuelve "false" si la lista no está vacía, "true" en caso contrario
bool ListaVacia(Nodo* actual) {
	if (actual == nullptr)
		return true;
	return false;
}
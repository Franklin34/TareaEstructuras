// Ejercicio 12
// Insertar palabras desde un archivo en una lista doblemente enlazada, ordenado alfabéticamente y luego simular una búsqueda binaria

// NOTA: Este código es de ejemplo. La implementación de las librerías se realizó de esta manera
//       únicamente con fines didácticos y acomodar ambas funciones dentro del mismo código.

#include <iostream>
#include <string>
#include <fstream>

// Nodo de la lista doblemente enlazada
struct Nodo {
	std::string palabra;
	Nodo* prev = nullptr;
	Nodo* next = nullptr;
};

void InsertarOrdenado(Nodo*&, std::string);
void ImprimirLista(Nodo*);
void BorrarLista(Nodo*&);
Nodo* Buscar(std::string, Nodo*);
Nodo* GetMitad(Nodo*, Nodo*);

int main() {
	// Inicializamos la lista
	Nodo* inicio = nullptr;

	InsertarOrdenado(inicio, "archivo.txt");

	ImprimirLista(inicio);

	Nodo* encontro = Buscar("estructuras", inicio);

	std::cout << "\n\n\n\n\n" << encontro;

	BorrarLista(inicio);

	return 0;
}

// Inserta palabras leidas desde un archivo ordenadas alfabéticamente. No se insertan palabras repetidas
void InsertarOrdenado(Nodo*& actual, std::string nombreArchivo) {
	std::ifstream archivo;
	std::string texto;

	archivo.open("archivo.txt");

	if (!archivo.is_open())
		exit(EXIT_FAILURE);

	while (archivo >> texto) {
		// Creamos un nuevo nodo y guardamos la palabra
		Nodo* nuevo = new Nodo;
		nuevo->palabra = texto;

		// Si la lista está vacía, se inserta el elemento en la primera posición
		if (!actual) {
			actual = nuevo;
			actual->prev = nullptr;
			actual->next = nullptr;
		}
		else {
			// Si la palabra a insertar es menor que la primera de la lista, la insertamos antes y ordenamos los enlaces
			if (texto < actual->palabra) {
				nuevo->next = actual;
				nuevo->prev = nullptr;
				actual->prev = nuevo;
				actual = nuevo;
			}
			else {
				// En caso contrario, recorremos la lista hasta encontrar la posición correcta donde se debe insertar el nodo
				Nodo* tmp = actual;

				// Se recorre la lista hasta llegar al último nodo o hasta que el nodo siguiente tenga una palabra mayor que el texto leído
				while (tmp->next) {
					if (tmp->next->palabra >= texto)
						break;
					else
						tmp = tmp->next;
				}

				if (tmp->next != nullptr) {
					if (tmp->next->palabra != texto) {
						// Se acomodan los enlaces a la hora de insertar el nodo
						tmp->next->prev = nuevo;
						nuevo->next = tmp->next;
						tmp->next = nuevo;
						nuevo->prev = tmp;
					}
				}
				else {
						nuevo->next = tmp->next;
						nuevo->prev = tmp;
						tmp->next = nuevo;
				}
			}
		}
	}
	archivo.close();
}

// Imprime el contenido de la lista enlazada
void ImprimirLista(Nodo* tmp) {
	while (tmp) {
		std::cout << tmp->palabra << "\n";
		tmp = tmp->next;
	}
}

// Elimina la lista - libera memoria
void BorrarLista(Nodo*& actual) {
	Nodo* tmp;
	while (actual) {
		tmp = actual;
		actual = actual->next;
		delete tmp;
	}
	actual = nullptr;
}

// Simula una búsqueda binaria en una lista doblemente enlazada
Nodo* Buscar(std::string texto, Nodo* inicio) {
	if (!inicio)
		return nullptr;

	Nodo* primero = inicio;
	Nodo* ultimo = inicio->next;

	// Posicionamos el último puntero
	while (ultimo->next)
		ultimo = ultimo->next;

	while (primero != ultimo && primero != nullptr) {
		Nodo* medio = GetMitad(primero, ultimo);

		// Si la mitad es nullptr, retornamos
		if (!medio)
			return nullptr;
		
		// Si el puntero a la mitad contiene el valor que estamos buscando, retornamos el puntero
		if (medio->palabra == texto) 
			return medio;
		
		// Si el valor es mayor, buscamos por la izquierda
		if (texto < medio->palabra)
			ultimo = medio->prev;
		else
			primero = medio->next;
	}
	return nullptr;
}

// Obtiene un apuntador a la mitad de la lista
Nodo* GetMitad(Nodo* inicio, Nodo* fin) {
	if (!inicio)
		return nullptr;

	Nodo* tmp = inicio;
	Nodo* tmp2 = fin;

	while (tmp != tmp2) {
		if (tmp->next == tmp2)
			return tmp2;
		tmp = tmp->next;
		tmp2 = tmp2->prev;
	}
	return tmp;
}
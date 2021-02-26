// Ejercicio 9
// Cálculo del n-ésimo nodo a partir del final de la lista
// Complejidad de Tiempo:  O(n)

// NOTA: Este código es de ejemplo. La implementación de las librerías se realizó de esta manera
//       únicamente con fines didácticos y acomodar ambas funciones dentro del mismo código.
//       No se siguen buenas prácticas de orientación a objetos ni de diseño

#include "ListaSimple.h"
#include <ctime>
#include <cstdlib>

// Prototipos de función
void InsertarAleatorios(Nodo*&, const short unsigned int);
Nodo* ObtenerNodoDesdeUltimo(Nodo*, int);

int main() {
	//constante que define el tamaño del array
	const short unsigned int max = 10;  
	
	// Semilla generadora de números pseudoaleatorios
	srand(static_cast<unsigned int>(time(nullptr)));

	Nodo* Inicio { nullptr };

	// Inserta y muestra elementos en la lista enlazada simple
	InsertarAleatorios(Inicio, max);
	std::cout << "Lista Enlazada Simple: ";
	MostrarLista(Inicio);

	std::cout << "Tercer nodo desde el ultimo ----> " << ObtenerNodoDesdeUltimo(Inicio, 3)->valor << std::endl << std::endl;
	std::cout << "Decimo cuarto nodo desde el ultimo (fuera de la lista) ----> " << ObtenerNodoDesdeUltimo(Inicio, 14) << std::endl;
	
	BorrarLista(&Inicio);

	return 0;
}

void InsertarAleatorios(Nodo*& head, const short unsigned int cantidad) {
	int ran;      //variable que almacena un número generado aleatoriamente
	short unsigned int i;         //índice que ayuda a recorrer el array

	for (i = 0; i < cantidad; ++i) {
		ran = rand() % 100 + 1;
		InsertarElemento(&head, ran);
	}
}

Nodo* ObtenerNodoDesdeUltimo(Nodo* head, int pos) {
	Nodo* actual = nullptr;
	Nodo* tmp = head;

	for (int i = 0; i < pos && tmp; ++i) 
		tmp = tmp->next;

	while (tmp) {
		if (actual == nullptr)	
			actual = head;
		else
			actual = actual->next;
		tmp = tmp->next;
	}

	return actual;
}
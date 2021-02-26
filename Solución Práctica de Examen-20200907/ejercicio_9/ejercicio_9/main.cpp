// Ejercicio 9
// C�lculo del n-�simo nodo a partir del final de la lista
// Complejidad de Tiempo:  O(n)

// NOTA: Este c�digo es de ejemplo. La implementaci�n de las librer�as se realiz� de esta manera
//       �nicamente con fines did�cticos y acomodar ambas funciones dentro del mismo c�digo.
//       No se siguen buenas pr�cticas de orientaci�n a objetos ni de dise�o

#include "ListaSimple.h"
#include <ctime>
#include <cstdlib>

// Prototipos de funci�n
void InsertarAleatorios(Nodo*&, const short unsigned int);
Nodo* ObtenerNodoDesdeUltimo(Nodo*, int);

int main() {
	//constante que define el tama�o del array
	const short unsigned int max = 10;  
	
	// Semilla generadora de n�meros pseudoaleatorios
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
	int ran;      //variable que almacena un n�mero generado aleatoriamente
	short unsigned int i;         //�ndice que ayuda a recorrer el array

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
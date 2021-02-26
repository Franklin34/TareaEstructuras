// Ejercicio 11
// Invertir una pila solamente con operaciones push y pop

// NOTA: Este c�digo es de ejemplo. La implementaci�n de las librer�as se realiz� de esta manera
//       �nicamente con fines did�cticos y acomodar ambas funciones dentro del mismo c�digo.
//       No se siguen buenas pr�cticas de orientaci�n a objetos ni de dise�o

// Complejidad de Tiempo:  O(n2)
// Complejidad de Espacio: O(n)

#include "stack.h"

void InvertirPila(Stack*);
void InsertarAlFinal(Stack*, int);

int main() {

	Stack pila;

	pila.push(8);
	pila.push(2);
	pila.push(15);
	pila.push(17);

	// Comente la siguiente l�nea para no invertir la pila - compruebe la salida del programa
	//InvertirPila(&pila);

	while (!pila.estaVacia())
		std::cout << pila.pop() << "\n";

	return 0;
}

// Funci�n recursiva que invierte la pila
void InvertirPila(Stack* pila) {
	int num;
	if (pila->estaVacia())
		return;

	num = pila->pop();
	InvertirPila(pila);
	InsertarAlFinal(pila, num);
}

// Inserta el elemento al final de la pila - toma ventaja de la recursi�n
void InsertarAlFinal(Stack* pila, int num) {
	int tmp;
	if (pila->estaVacia()) {
		pila->push(num);
		return;
	}
	tmp = pila->pop();
	InsertarAlFinal(pila, num);
	pila->push(tmp);
}
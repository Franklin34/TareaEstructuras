// Ejercicio 11
// Invertir una pila solamente con operaciones push y pop

// NOTA: Este código es de ejemplo. La implementación de las librerías se realizó de esta manera
//       únicamente con fines didácticos y acomodar ambas funciones dentro del mismo código.
//       No se siguen buenas prácticas de orientación a objetos ni de diseño

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

	// Comente la siguiente línea para no invertir la pila - compruebe la salida del programa
	//InvertirPila(&pila);

	while (!pila.estaVacia())
		std::cout << pila.pop() << "\n";

	return 0;
}

// Función recursiva que invierte la pila
void InvertirPila(Stack* pila) {
	int num;
	if (pila->estaVacia())
		return;

	num = pila->pop();
	InvertirPila(pila);
	InsertarAlFinal(pila, num);
}

// Inserta el elemento al final de la pila - toma ventaja de la recursión
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
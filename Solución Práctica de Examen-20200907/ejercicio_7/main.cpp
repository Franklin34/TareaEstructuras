// Ejercicio 7
// Inversión de elementos de una cola
// Complejidad de Tiempo:  O(n)

#include <queue>
#include <stack>
#include <iostream>

void InvertirCola(std::queue<int>&);
void ImprimirCola(std::queue<int>&);

int main() {
	std::queue<int> cola;

	// Llenamos la cola con algunos valores
	for (short int i = 1; i <= 10; ++i)
		cola.push(i);

	ImprimirCola(cola);
	InvertirCola(cola);
	ImprimirCola(cola);

	// Eliminamos todos los elementos de la cola
	while (!cola.empty())
		cola.pop();

	return 0;
}

// Invierte los elementos de una cola FIFO utilizando
// una pila como contenedor auxiliar
void InvertirCola(std::queue<int>& c) {
	std::stack<int> pila;

	// Insertamos los elementos del frente de la cola en la pila
	// y los removemos de la cola
	while (!c.empty()) {
		pila.push(c.front());
		c.pop();
	}

	std::cout << pila.top() << '\n';
	// Insertamos los elementos de la pila nuevamente en la cola
	while (!pila.empty()) {
		c.push(pila.top());
		pila.pop();
	}
}

// Imprime los elementos de la cola
void ImprimirCola(std::queue<int>& c) {
	// Para imprimir la cola, necesitamos hacer una copia
	// de la cola original. En la cola de copia, imprimimos el inicio y luego lo
	// removemos
	std::queue<int> copiaCola = c;

	while (!copiaCola.empty()) {
		std::cout << copiaCola.front() << " ";
		copiaCola.pop();
	}
	std::cout << std::endl << std::endl;
}
// insercion.cpp
// Ejemplo que muestra el algoritmo de ordenamiento por insercion

#include <iostream>
#include <ctime>

#define MAX	10

// Genera números aleatorios del 1 al 100 y los guarda en el vector original
// La función recibe una copia al puntero del vector
void generarAleatorios(int v[]);

// Ordena los elementos del vector utilizando el algoritmo de insercion
// La función recibe una copia al puntero del vector
void insercion(int v[]);

// Imprime los elementos del vector
// La función recibe una copia al puntero del vector
void imprimeLista(int v[]);

int main() {
    int vector[MAX] = { 0 };

	generarAleatorios(vector);

	std::cout << "Elementos del vector original: ";
	imprimeLista(vector);

	insercion(vector);
	std::cout << std::endl << std::endl;
	std::cout << "Elementos del vector ordenado: ";
	imprimeLista(vector);
	
	std::cout << std::endl << std::endl;

	return 0;
}

void generarAleatorios(int v[]) {
	int ran;          //variable que almacena un número generado aleatoriamente

	srand(static_cast<unsigned int>(time(nullptr)));  //semilla que se usa para generar números pseudo-aleatorios
	
	for (int i = 0; i < MAX; ++i) {
		ran = rand() % 100 + 1;
		v[i] = ran;
	}
}

void insercion(int v[]) {  // Algoritmo de ordenamiento por selección, en orden ascendente
	int tmp, k;

	for (int i = 1; i < MAX; ++i) {
		tmp = v[i];
		k = i - 1;
		while (k >= 0 && tmp < v[k]) {
			v[k + 1] = v[k];
			--k;
		}
		v[k + 1] = tmp;
	}
}

void imprimeLista(int v[]) {
	for (int i = 0; i < MAX; ++i) {
		std::cout << v[i];
		std::cout << " ";
	}
}
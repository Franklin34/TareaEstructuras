// seleccion.cpp
// Ejemplo que muestra el algoritmo de ordenamiento por seleccion

#include <iostream>
#include <ctime>

#define MAX	10

// Genera números aleatorios del 1 al 100 y los guarda en el vector original
// La función recibe una copia al puntero del vector
void generarAleatorios(int v[]);

// Ordena los elementos del vector utilizando el algoritmo de seleccion
// La función recibe una copia al puntero del vector
void seleccion(int v[]);

// Devuelve la posición al elemento menor del vector
int getMenor(int v[], int);

// Intercambia dos elementos
void swap(int v[], int, int);

// Imprime los elementos del vector
// La función recibe una copia al puntero del vector
void imprimeLista(int v[]);

int main() {
    int vector[MAX] = { 0 };

	generarAleatorios(vector);

	std::cout << "Elementos del vector original: ";
	imprimeLista(vector);

	seleccion(vector);
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

void seleccion(int v[]) {  // Algoritmo de ordenamiento por selección, en orde ascendente
	int tmp;
	bool flag = true;

	for (int i = 0; i < MAX - 1; ++i) {
		tmp = getMenor(v, i);
		swap(v, i, tmp);
	}
}

int getMenor(int v[], int pos) {       // Devuelve la posición donde se encuentra el elemento menor del vector
	for (int i = pos + 1; i < MAX; ++i) {
		if (v[i] < v[pos])
			pos = i;
	}
	return pos;
}

void swap(int v[], int i, int j) {   // Intercambia los elementos en las posiciones 'i' y 'j'
	int tmp;
	tmp = v[i];
	v[i] = v[j];
	v[j] = tmp;
}

void imprimeLista(int v[]) {
	for (int i = 0; i < MAX; ++i) {
		std::cout << v[i];
		std::cout << " ";
	}
}
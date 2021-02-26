// main.cpp
// Autor: El Tigre
// Descripción: Invierte los elementos de un vector

#include <iostream>

// Prototipos de función
void imprimir(int*, int);
void inverso(int*, int);

int main() {
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	
	// Obtiene el tamaño del vector
	int tam = sizeof(array) / sizeof(array[0]);

	// Imprime los elementos de cada vector antes del intercambio
	std::cout << "Elementos del vector: ";
	imprimir(array, tam);
	std::cout << std::endl << std::endl;

	// Invierte los elementos
	inverso(array, tam);

	// Imprime los elementos del vector ya invertido
	std::cout << "Elementos del vector invertido: ";
	imprimir(array, tam);
	std::cout << std::endl;

	return 0;
}

void imprimir(int* v, int t) {

	// Aritmética de punteros - calcula el final del vector
	int* final = (v + (t - 1));

	while (v <= final)
		std::cout << *v++ << " ";
}


void inverso(int* v, int t) {

	// Aritmética de punteros - calcula el final del primer vector
	int* fin_v = (v + (t - 1));

	// Objeto temporal
	int* tmp = new int(0);

	// Utiliza dos punteros que se desplazan hacia la mitad del vector mientras
	// intercambian los elementos
	while (v < fin_v) {
		*tmp = *v;
		*v = *fin_v;
		*fin_v = *tmp;

		++v;
		--fin_v;
	}
	delete tmp;
	tmp = nullptr;
}
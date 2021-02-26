// main.cpp
// Autor: El Tigre
// Descripción: Determina el elemento menor de un vector de números de manera recursiva

#include <iostream>

int menor(const int[], int);

int main() {

	int v[] = { 45, 87, 30, 20, 58, 90, 44, 21, 35, 29 };

	std::cout << "Elemento menor del vector: " << menor(v, sizeof(v) / sizeof(v[0])) << std::endl;

	return 0;
}

int menor(const int array[], int tam) {
	if (tam == 1)
		return array[0];

	int val = menor(array, tam - 1);

	return val < array[tam - 1] ? val : array[tam - 1];
}
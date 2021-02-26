// main.cpp
// Autor: El Tigre
// Descripción: Implementación de la función Mergesort

#include <iostream>

void Mergesort(int*, int*, int, int);
void Merge(int*, int*, int, int, int);

int main() {
	int v[] = { 32, 43, 89, 12, 6, 3, 17, 28, 30, 11, 19, 54, 40, 14 };
	int t[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	int tam = sizeof(v) / sizeof(v[0]);

	std::cout << "Vector sin ordernar: ";
	for (int i = 0; i < tam; ++i)
		std::cout << v[i] << " ";
	std::cout << std::endl << std::endl;

	Mergesort(v, t, 0, tam);

	std::cout << "Vector ordenado: ";
	for (int i = 0; i < tam; ++i)
		std::cout << v[i] << " ";
	std::cout << std::endl << std::endl;

	return 0;
}

void Mergesort(int* s, int* tmp, int izq, int der) {
	int mitad;
	if (izq < der) {
		mitad = (izq + der) / 2;
		Mergesort(s, tmp, izq, mitad);
		Mergesort(s, tmp, mitad + 1, der);
		Merge(s, tmp, izq, mitad + 1, der);
	}
}

void Merge(int* s, int* tmp, int izq, int mitad, int der) {
	int i, fin, tam, pos;
	
	fin = mitad - 1;
	pos = izq;
	tam = der - izq + 1;

	while (izq <= fin && mitad <= der) {
		if (s[izq] <= s[mitad])
			tmp[pos++] = s[izq++];
		else
			tmp[pos++] = s[mitad++];
	}

	while (izq <= fin) 
		tmp[pos++] = s[izq++];

	while (mitad <= der)
		tmp[pos++] = s[mitad++];

	for (i = 0; i <= tam; ++i) {
		s[der] = tmp[der];
		--der;
	}
}
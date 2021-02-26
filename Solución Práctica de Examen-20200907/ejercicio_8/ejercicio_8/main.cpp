// Ejercicio 8
// Determina si los elementos de un vector se encuentran ordenados de manera ascendente
// de manera recursiva

#include <iostream>
#include <array>

#define MAX	10

template <std::size_t TAM>
bool EstaOrdenado(std::array<int, TAM>, int);

int main() {
	std::array<int, MAX> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	
	EstaOrdenado(v, v.size()) ? std::cout << "TRUE" : std::cout << "FALSE";
	
	v.empty();
	return 0;

}

// Función recursiva que determina si los elementos de un vector
// se encuentran ordenados
template <std::size_t TAM>
bool EstaOrdenado(std::array<int, TAM> s, int tam) {
	if (tam == 1)
		return true;
	return (s[tam - 1] < s[tam - 2]) ? false : EstaOrdenado(s, tam - 1);
}
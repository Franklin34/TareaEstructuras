// main.cpp
// Autor: El Tigre
// Descripción: Obtiene todos los elementos impares de un array de manera recursiva

#include <iostream>
#include <vector>

std::vector<int>* impares(int);

int main() {

	int x = 24;

	std::cout << "Numeros impares desde 1 hasta " << x << ": ";

	std::vector<int>* vector_impares = impares(x);
	std::vector<int>::iterator iter;

	for (iter = vector_impares->begin(); iter != vector_impares->end(); ++iter)
		std::cout << *iter << " ";
	
	// Hay que liberar la memoria asignada
	delete vector_impares;

	return 0;
}

std::vector<int>* impares(int num){
	
	if (num <= 1)
		return new std::vector<int>(1, 1);

	std::vector<int>* vec = impares(num - 1);
	
	if (num % 2 != 0)
		vec->push_back(num);
	return vec;
}
// main.cpp
// Autor: El Tigre
// Descripción: Determina si un número es primo de manera recursiva

#include <iostream>

bool primo(const int, int div = 2);

int main() {

	int num = 43;

	if (primo(num))
		std::cout << "Si es primo";
	else
		std::cout << "No es primo";

	return 0;
}

bool primo(const int num, int div) {
	// Si el divisor es mayor a la mitad del número
	// quiere decir que no existen divisores
	if ((div > num / 2))
		return (num == 1) ? false : true;

	if (num % div == 0)
		return false;
	
	return primo(num, div + 1);
}
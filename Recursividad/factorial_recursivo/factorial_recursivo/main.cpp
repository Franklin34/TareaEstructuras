// main.cpp
// Autor: El Tigre
// Descripción: Imprime el factorial de un número (se calcula de manera recursiva)

#include <iostream>

unsigned int factorial(int num);

int main() {
	unsigned int x = 5;

	std::cout << "\t\nFactorial de " << x << " = " << factorial(x);

	std::cout << std::endl << std::endl;

	return 0;
}

unsigned int factorial(int num) {
	if (num <= 1)
		return 1;
	else
		return num * factorial(num - 1);
}
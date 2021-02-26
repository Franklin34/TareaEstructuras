// main.cpp
// Autor: El Tigre
// Descripción: Invierte los dígitos de un número de manera recursiva

#include <iostream>

int invertido(int);

int main() {
	int x = 1234;

	std::cout << "Numero original:  " << x << std::endl;
	std::cout << "Numero invertido: " << invertido(x);
	std::cout << std::endl << std::endl;
}

int invertido(int n) {
	// Multiplicador
	int base = 1;

	// Obtenemos el valor posicional del dígito
	while (n / (base * 10)) {
		base *= 10;
	}

	if (n < 10)
		return n;
	else
		return ((n % 10) * base) + invertido(n / 10);
}
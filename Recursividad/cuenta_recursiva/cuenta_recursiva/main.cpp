// main.cpp
// Autor: David
// Descripción: muestra de binario a decimal de manera recursiva

#include <iostream>

int binary_decimal(int binario, int casilla = 0, int decimal = 0);

int main() {
	std::cout << binary_decimal(1100);
}

int binary_decimal(int binario, int casilla, int decimal) {
	if (binario == 0) {
		return decimal;
	}
	else {
		return binary_decimal(binario / 10, casilla+1, decimal + binario % 10 * pow(2, casilla));
	}
}


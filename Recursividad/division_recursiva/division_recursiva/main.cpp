// main.cpp
// Autor: El Tigre
// Descripción: Divide un número de manera recursiva

#include <iostream>

int division(int, int);

int main() {
	int x = 49;
	int y = 7;

	std::cout << "Division de " << x << " entre " << y << " = " << division(x, y);
	std::cout << std::endl << std::endl;
}

int division(int a, int b) {
	// Caso base
	if (b > a) {
		return 0;
	}
	else {
		return division(a - b, b) + 1;
	}
}
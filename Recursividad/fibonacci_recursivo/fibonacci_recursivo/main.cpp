// main.cpp
// Autor: El Tigre
// Descripción: Calcula la serie de Fibonacci de manera recursiva

#include <iostream>

unsigned int fibo(unsigned int num);

int main() {
	int x = 7;

	std::cout << "Fibonacci de " << x << " = " << fibo(x);

	std::cout << std::endl << std::endl;
	return 0;
}

unsigned int fibo(unsigned int num) {
	int x, y;
	if (num <= 1)
		return num;
	else {
		x = fibo(num - 1);
		y = fibo(num - 2);
		return x + y;
	}
}
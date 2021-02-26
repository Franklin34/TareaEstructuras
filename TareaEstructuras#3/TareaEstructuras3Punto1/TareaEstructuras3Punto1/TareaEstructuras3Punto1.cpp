#include <iostream>

int decimal_binario(int numero);

int main()
{
	std::cout << "Digite el numero decimal: ";
	int decimal;
	std::cin >> decimal;
	std::cout << "El numero en binario seria: " << decimal_binario(decimal) << '\n';
   
}
int decimal_binario(int numero) {
	if (numero < 2) {
		return numero;
	}
	else {
		return numero % 2 + (10 * decimal_binario(numero / 2));
	}
}

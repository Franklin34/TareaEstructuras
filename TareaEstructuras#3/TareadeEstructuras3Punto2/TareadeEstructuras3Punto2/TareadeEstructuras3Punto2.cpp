#include <iostream>

int binary_decimal(int binario, int casilla = 0, int decimal = 0);

int main() {
	std::cout << "Digite el numero binario para pasarlo a decimal: ";
	int binario;
	std::cin >> binario;
	std::cout << "El numero en binario seria: " << binary_decimal(binario) << std::endl;
}

int binary_decimal(int binario, int casilla, int decimal) {
	if (binario == 0) {
		return decimal;
	}
    return binary_decimal(binario / 10, casilla + 1, decimal + binario % 10 * pow(2, casilla));
}
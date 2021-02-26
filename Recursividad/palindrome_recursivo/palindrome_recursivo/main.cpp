// main.cpp
// Autor: El Tigre
// Descripción: Determina si una frase es un palíndrome de manera recursiva

#include <iostream>
#include <string>
#include <algorithm>

bool es_palindrome(std::string);

int main() {
	std::string cadena = "anita lava la tina";

	// Eliminamos los espacios en blanco de la cadena antes de enviarla a la función
	cadena.erase(std::remove_if(cadena.begin(), cadena.end(), std::isspace), cadena.end());

	(es_palindrome(cadena)) ? std::cout << "TRUE" : std::cout << "FALSE" << std::endl;

	return 0;
}

// Determina si una palabra es palíndrome
bool es_palindrome(std::string str) {
	// Si la palabra tiene una letra o menos, es un palíndrome
	if (str.length() <= 1)
		return true;

	// Verificamos si la primera y última letra son diferentes, en cuyo caso
	// no sería un palíndrome
	if (str[0] != str[str.length() - 1])
		return false;
	
	// Eliminamos la primera y última letra de la frase
	str = str.substr(1, str.length() - 2);

	// Llamada recursiva con la nueva cadena 
	return es_palindrome(str);
}
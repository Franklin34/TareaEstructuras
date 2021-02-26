// Ejercicio 4
// Validación de paréntesis utilizando una pila
// El programa acepta una cadena con el siguiente formato de ejemplo:  ([57+82]*[12-3])   - con o sin espacios

#include <stack>
#include <iostream>
#include <string>

bool ValidaParentesis(std::string);

int main(int argc, char** argv) {
	std::string entrada("7 - ((X * ((X + Y) / (J - 3)) + Y) / (4 - 2.5))");
	
	std::cout << std::endl << std::endl;

	if (ValidaParentesis(entrada))
		std::cout << "Parentesis balanceados..." << std::endl << std::endl;
	else
		std::cout << "Parentesis no estan balanceados..." << std::endl << std::endl;

	return 0;
}

// Determina si los paréntesis están balanceados o no
// para una expresión dada. Utiliza una pila
bool ValidaParentesis(std::string expresion) {
	std::stack<char> pila;
	bool esValida = true;
	char c, aux;

	for (std::string::size_type i = 0; i < expresion.size(); ++i) {
		c = expresion[i];
		if (c == '(' || c == '[' || c == '{')
			pila.push(c);
		else if (c == ')' || c == ']' || c == '}')
			if (pila.empty())
				esValida = false;
			else {
				aux = pila.top();
				pila.pop();
				if ((c == '(' && aux != ')') || (c == '[' && aux != ']') || (c == '{' && aux != '}'))
					esValida = false;
			}
	}
	if (!pila.empty())
		return false;
	return esValida;
}
// burbuja.cpp
// Ejemplo que muestra el algoritmo de ordenamiento burbuja

#include <iostream>
#include <ctime>

#define MAX	10

// Genera números aleatorios del 1 al 100 y los guarda en el vector original
// La función recibe el vector como referencia, así se evita realizar una copia del mismo
void generarAleatorios(int*);

// Ordena los elementos del vector utilizando el algoritmo de burbuja
// La función recibe una copia del puntero al vector
void burbuja(int v[]);

// Imprime los elementos del vector
// La función recibe el vector como referencia, así se evita realizar una copia del mismo
void imprimeLista(int*);

int main() {
    int vector[MAX] = { 0 };

	generarAleatorios(vector);

	std::cout << "Elementos del vector original: ";
	imprimeLista(vector);

	burbuja(vector);
	std::cout << std::endl << std::endl;
	std::cout << "Elementos del vector ordenado: ";
	imprimeLista(vector);
	
	std::cout << std::endl << std::endl;

	return 0;
}

void generarAleatorios(int* v) {
	int ran;          //variable que almacena un número generado aleatoriamente

	srand(static_cast<unsigned int>(time(nullptr)));  //semilla que se usa para generar números pseudo-aleatorios
	
	for (int i = 0; i < MAX; ++i) {
		ran = rand() % 100 + 1;
		*v++ = ran;
	}
}

void burbuja(int v[]) {
	int tmp;

	for (int i = 1; i < MAX; ++i) {
		for (int j = 0; j < MAX - 1; ++j) {
			if (v[j] > v[j + 1]) {       // Si el elemento en la posición 'j' es mayor al elemento en la posición
				tmp = v[j];              // 'j + 1', se intercambia  
				v[j] = v[j + 1];         // El elemento mayor se coloca en la posición n-1 en cada pasada 
				v[j + 1] = tmp;            

			}
		}
	}
}

void imprimeLista(int* v) {
	for (int i = 0; i < MAX; ++i) {
		std::cout << *v++;
		std::cout << " ";
	}
}




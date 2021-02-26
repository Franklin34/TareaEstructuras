// quicksort.cpp
// Ejemplo que muestra el algoritmo de ordenamiento quicksort recursivo

#include <iostream>
#include <ctime>

#define MAX	10

// Genera números aleatorios del 1 a MAX y los guarda en el vector original
// La función recibe una copia al puntero del vector
void generarAleatorios(int v[]);

// Ordena los elementos del vector utilizando el algoritmo quicksort
// La función recibe una copia al puntero del vector, y las posiciones baja y alta del espacio de ordenamiento
void quicksort(int v[], int, int);

// Devuelve la posición que se utiliza como punto de división
int particion(int v[], int, int);

// Intercambia dos elementos
void swap(int v[], int, int);

// Imprime los elementos del vector
// La función recibe una copia al puntero del vector
void imprimeLista(int v[]);

int main() {
	int vector[MAX] = { 0 };

	generarAleatorios(vector);

	std::cout << "Elementos del vector original: ";
	imprimeLista(vector);

	quicksort(vector, 0, MAX - 1);
	std::cout << std::endl << std::endl;
	std::cout << "Elementos del vector ordenado: ";
	imprimeLista(vector);

	std::cout << std::endl << std::endl;

	return 0;
}

void generarAleatorios(int v[]) {
	int ran;          //variable que almacena un número generado aleatoriamente

	srand(static_cast<unsigned int>(time(nullptr)));  //semilla que se usa para generar números pseudo-aleatorios

	for (int i = 0; i < MAX; ++i) {
		ran = rand() % 100 + 1;
		v[i] = ran;
	}
}

void quicksort(int v[], int menor, int mayor) {  // Algoritmo de ordenamiento quicksort, en orden ascendente
	int division;
	if (menor < mayor) {
		division = particion(v, menor, mayor);
		quicksort(v, menor, division - 1);
		quicksort(v, division + 1, mayor);
	}	
}

int particion(int v[], int menor, int mayor) {       // Particiona el espacio de búsqueda de v[0] a v[MAX], utilizando v[0] como pivote
	int pivote = v[menor];
	int masBajo = menor;

	for (int i = menor + 1; i <= mayor; ++i)
		if (v[i] < pivote) {                    // Utilizamos un pivote para determinar donde dividir el espacio donde se ordenan los
			++masBajo;                          // elementos 
			swap(v, masBajo, i);
		}
	swap(v, menor, masBajo);
	return masBajo;               // Devuelve el punto de división del espacio de ordenamiento
}

void swap(int v[], int i, int j) {   // Intercambia los elementos en las posiciones 'i' y 'j'
	int tmp;
	tmp = v[i];
	v[i] = v[j];
	v[j] = tmp;
}

void imprimeLista(int v[]) {
	for (int i = 0; i < MAX; ++i) {
		std::cout << v[i];
		std::cout << " ";
	}
}
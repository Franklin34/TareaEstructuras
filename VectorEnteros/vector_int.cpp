// vector_int.cpp
// Definición de la clase VectorInt
// Autor: El Tigre

#include "vector_int.h"

// Constructor default. Inicializa la capacidad del vector de acuerdo
// con el valor de INICIAL
VectorInt::VectorInt() : conteo_max{ INICIAL }, conteo{ 0 }{
	vec = new int[conteo_max];
}

// Constructor con parámetros. Recibe la capacidad inicial del vector
VectorInt::VectorInt(size_t tam) : conteo_max{ tam }, conteo{ 0 }{
	vec = new int[conteo_max];
}

// Constructor de Copia
VectorInt::VectorInt(const VectorInt& v) : conteo_max{ v.conteo_max }, conteo{ v.conteo } {
	if (conteo > conteo_max) {
		conteo_max = INICIAL;
		conteo = 0;
		vec = new int[conteo_max];
	}
	else{
		vec = new int[conteo_max];
		for (size_t i = 0; i < conteo; i++) {
			vec[i] = v.vec[i];
		}
	}
}

//Destructor
VectorInt::~VectorInt() {
	delete[] vec;
	conteo_max = 0;
	conteo = 0;
}

// Inserta un nuevo elemento en el vector. La inserción se realiza
// de manera secuencial y sin orden
void VectorInt::Insertar(int valor) {
	// Si ya se excede la capacidad del vector, es necesario incrementar
	// el tamaño del mismo para poder insertar
	if (conteo == conteo_max) {
		Resize();
	}
	vec[conteo++] = valor;
}

// Elimina un elemento del vector en la posición dada
void VectorInt::Borrar(size_t posicion) {
	// Verificamos los límites en el vector
	if (posicion < 0 || posicion >= conteo) {
		return;
	}

	// Para borrar un elemento se acomodan los elementos desde
	// la posición dada hasta el final. Luego se decrementa el tamaño
	// del vector
	for (size_t i = posicion; i < conteo; i++) {
		vec[i] = vec[i + i];
	}
	conteo--;
}

// Cambia el valor del vector en la posición dada
void VectorInt::ChangeValueAt(size_t posicion, int valor) {
	// Verificamos los límites en el vector
	if (posicion < 0 || posicion >= conteo) {
		return;
	}

	vec[posicion] = valor;
}

// Cambia el tamaño del vector
void VectorInt::Resize() {
	// Se utiliza un apuntador temporal al vector actual
	int *tmp = vec;

	// Luego se incrementa la capacidad del vector y se asigna memoria
	// con la nueva capacidad
	conteo_max = conteo_max * 2;
	vec = new int[conteo_max];

	// Se copian los elementos del array viejo al nuevo
	for (size_t i = 0; i < conteo; i++) {
		vec[i] = tmp[i];
	}

	// Se libera la memoria del antiguo array
	delete[] tmp;
}
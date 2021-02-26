// vector_int.h
// Descripción: Declaración de la clase VectorInt con funcionalidad básica:
//              manejo de memoria dinámica y constructores/destructor
// Autor: El Tigre

#ifndef VECTOR_INT_H
#define VECTOR_INT_H

// Valor default para la creación del vector
#define INICIAL	10

class VectorInt {
public:
	// Constructor default
	VectorInt();
	// Constructor con parámetros. Recibe la capacidad inicial del vector
	VectorInt(size_t);
	// Constructor de Copia
	VectorInt(const VectorInt&);
	//Destructor
	~VectorInt();

	// Retorna la cantidad de elementos del vector
	size_t CantidadElementos() { return conteo; }
	size_t CantidadElementos() const { return conteo; }
	// Retorna la capacidad del vector
	size_t Capacidad() { return conteo_max; }
	size_t Capacidad() const { return conteo_max; }

	// Inserta un nuevo elemento en el vector
	void Insertar(int);
	// Elimina un elemento del vector en la posición dada
	void Borrar(size_t posicion = 0);
	// Retorna el valor del arreglo en la posición dada
	int ValueAt(size_t posicion) { return vec[posicion]; }
	int ValueAt(size_t posicion) const { return vec[posicion]; }
	// Cambia el valor del arrelo en la posición dada
	void ChangeValueAt(size_t, int);
	

private:
	// Cambia el tamaño del vector
	void Resize();

	// Apuntador al array de elementos de tipo int
	int *vec;
	// Capacidad total del array
	size_t conteo_max;
	// Número de elementos del vector
	size_t conteo;
};

#endif

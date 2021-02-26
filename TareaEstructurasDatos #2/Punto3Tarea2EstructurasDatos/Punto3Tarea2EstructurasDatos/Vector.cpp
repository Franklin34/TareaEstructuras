#include "Vector.h"

Vector::Vector(int num)
{
	cantidad = 0;
	tam = num;
	vector = new int[num];
    ptr = nullptr;

	for (int i = 0; i < num; i++) {
		vector[i] = 0;
	}
}

Vector::~Vector()
{
	delete[] vector;
}

void Vector::metodo()
{
    ptr = &vector[0];
    int contador = 0;

    for (int i = 0; i <= tam; i++) {
        for (int j = 1; j <= i; j++) {
            if (i % j == 0) {
                contador++;
            }
        }

        if (contador == 2) {
            std::cout << i << " ";
            *ptr = i;
            ptr++;
            cantidad++;
        }
        contador = 0;
    }
    ptr = &vector[0];
}

void Vector::mostrar()
{

    for (int x = 0; x < cantidad; x++) {
        std::cout  << *(ptr + x) << " ";
    }

}

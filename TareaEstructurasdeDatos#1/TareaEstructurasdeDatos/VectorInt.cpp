#include "VectorInt.h"

VectorInt::VectorInt()
{
    conteo = 0;
    conteo_max = 10;
    vect = new int[conteo_max];

    for (int i = 0; i < conteo_max; i++) {
        vect[i] = 0;
    }

}

VectorInt::VectorInt(int x)
{
    conteo = 0;
    conteo_max = x;
    vect = new int[conteo_max];

    for (int i = 0; i < conteo_max; i++) {
        vect[i] = 0;
    }
}

VectorInt::VectorInt(const VectorInt& x)
{
    conteo = x.conteo;
    conteo_max = x.conteo_max;

    if (conteo > conteo_max) {
        conteo_max = 10;
        conteo = 0;
        vect = new int[conteo_max];
    }
    else {
        vect = new int[conteo_max];
        for (size_t i = 0; i < conteo; i++) {
            vect[i] = x.vect[i];
        }
    }
}

VectorInt::~VectorInt()
{
    delete[] vect;
}

void VectorInt::insertar(int x)
{
    if (conteo == conteo_max) {
        int* tmp = vect;

        conteo_max = conteo_max * 2;
        vect = new int[conteo_max];

        for (int i = 0; i < conteo_max; i++) {
            vect[i] = 0;
        }

        for (size_t i = 0; i < conteo; i++) {
            vect[i] = tmp[i];
        }

        delete[] tmp;
    }
    vect[conteo] = x;
    conteo++;
}

void VectorInt::borrar(int x)
{
    if (x < conteo) {
       
        vect[x] = -1;

    }
    return;

    
}

int VectorInt::value_at(int x)
{
    if (x < conteo) {
        return vect[x];
    }
    return -1;
}

void VectorInt::change_value_at(int d, int i)
{
    if (i < conteo) {
        vect[i] = d;
        return;
    }
    return;
    
}

std::string VectorInt::mostrar()
{
    std::stringstream x;

    for (int i = 0; i < conteo; i++) {
        x << vect[i] << " ";
    }

    return x.str();
}

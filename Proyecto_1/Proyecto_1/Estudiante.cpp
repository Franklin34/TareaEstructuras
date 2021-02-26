#include "Estudiante.h"

Estudiante::Estudiante()
{
    nombre = "";
    cedula = "";
    edad = 0;
}

Estudiante::Estudiante(std::string n, std::string c , int e)
{
    nombre = n;
    cedula = c;
    edad = e;
}

Estudiante::~Estudiante()
{
}

int Estudiante::getEdad()
{
    return edad;
}

std::string Estudiante::toString()
{
    std::stringstream x;

    x << "Nombre del estudiante: " << nombre << std::endl;
    x << "Cedula: " << cedula << std::endl;
    x << "Edad: " << edad << std::endl;

    return x.str();
}

bool Estudiante::operator>(Estudiante&est)
{
     return this->edad > est.getEdad();
}

bool Estudiante::operator<(Estudiante&est)
{
    return this->edad < est.getEdad();
}

bool Estudiante::operator==(Estudiante&est)
{
    return this->edad == est.edad;
}

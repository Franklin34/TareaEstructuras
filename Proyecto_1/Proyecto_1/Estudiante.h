#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H
#include <iostream>
#include <sstream>

class Estudiante
{
private:
	std::string nombre;
	std::string cedula;
	int edad;
public:
	Estudiante();
	Estudiante(std::string, std::string, int);
	~Estudiante();

	int getEdad();

	std::string toString();
	
	bool operator>(Estudiante&);
	bool operator<(Estudiante&);
	bool operator==(Estudiante&);
};
#endif // !ESTUDIANTE_H

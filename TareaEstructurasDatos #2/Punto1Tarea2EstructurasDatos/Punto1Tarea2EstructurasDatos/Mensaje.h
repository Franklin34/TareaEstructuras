#ifndef MENSAJE_H
#define MENSAJE_H
#include <iostream>
#include <string>

class Mensaje
{
public:
	Mensaje(std::string m);
	Mensaje(const Mensaje&);
	~Mensaje();

	std::string* getMensaje();

private:
	std::string* ptr_mensaje;
};
#endif

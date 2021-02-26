#include "Mensaje.h"

Mensaje::Mensaje(std::string m)
{
	ptr_mensaje = new std::string(m);
}

Mensaje::Mensaje(const Mensaje& p)
{
	if (ptr_mensaje == nullptr) {
		ptr_mensaje = new std::string(*p.ptr_mensaje);
	}
	else {
		ptr_mensaje = p.ptr_mensaje;
	}
}

Mensaje::~Mensaje()
{
	delete ptr_mensaje;
}

std::string* Mensaje::getMensaje()
{
	return ptr_mensaje;
}

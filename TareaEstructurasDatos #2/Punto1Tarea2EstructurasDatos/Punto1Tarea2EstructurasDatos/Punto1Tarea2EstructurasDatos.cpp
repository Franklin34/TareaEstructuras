#include "Mensaje.h"
#include <iostream>

int main()
{
    
    std::string mensaje = "Hola mundo";
    Mensaje obj(mensaje);

    std::cout << *obj.getMensaje() << '\n';


    Mensaje obj2(obj);

    std::cout << *obj2.getMensaje() << '\n';
}


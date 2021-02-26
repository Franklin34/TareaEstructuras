#include "VectorInt.h"
#include <iostream>

int main()
{
salto:
    int y = 0;
    std::cout << "Digite el tamanno del vector: ";
    std::cin >> y;
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore();
        goto salto;
    }


    VectorInt c(y);

    int x = 0;
    bool pregunta = true;

    char xo;
    int e = 0;


    for (int i = 0; i < y; i++) {
        std::cout << "Dijite los numeros para el vector: ";
        std::cin >> x;
        if (std::cin.fail()) {
            x = 0;
        }

        c.insertar(x);
        x = 0;
    }

    while (pregunta == true) {
        std::cout << "Desea dijitar otro numero(S - N): ";
        std::cin >> xo;


        if (xo == 's' || xo == 'S') {
            std::cout << "Dijite el numero que desea agregar: ";
            std::cin >> e;
            c.insertar(e);
        }
        else {
            pregunta = false;
        }
    }



    std::cout << std::endl;

    std::cout << "=========================== Se muestra el vector ==========================" << std::endl;

    std::cout << "================================== " << c.mostrar() << " ======================================" << std::endl;;

    std::cout << std::endl;

    int g = 0;
    std::cout << "Digite la posicion en la que deseas eliminar un numero: ";
    std::cin >> g;


    c.borrar(g - 1);

    std::cout << std::endl;

    std::cout << "=========================== Se muestra el vector ==========================" << std::endl;

    std::cout << "================================== " << c.mostrar() << " ======================================" << std::endl;

    std::cout << std::endl;

    int r = 0;
    std::cout << "Dijite la posicion del vector que desea ver: ";
    std::cin >> r;


    std::cout << "El numero en esa posicion es: " << c.value_at(r - 1);

    std::cout << std::endl;

    std::cout << "=========================== Se muestra el vector ==========================" << std::endl;
    std::cout << "================================== " << c.mostrar() << " ======================================" << std::endl;

    std::cout << std::endl;

    int f = 0;
    int d = 0;

    std::cout << "Dijite la posicion en la que quiera cambiar el dijito: ";
    std::cin >> f;

  
    std::cout << "Digite el numero que desea colocar en esa posicion: ";
    std::cin >> d;


    c.change_value_at(d, f - 1);

    std::cout << std::endl;

    std::cout << "================================== " << c.mostrar() << " ======================================" << std::endl;

    system("pause");
    return 0;
}

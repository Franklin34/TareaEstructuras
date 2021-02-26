#include "pch.h"
#include <iostream>
#include "Lista.h"

using namespace std;

int main()
{
	Lista lista;

	lista.insertar_final(1);
	lista.insertar_final(2);
	lista.insertar_final(3);
	lista.insertar_final(4);
	lista.insertar_final(5);

	lista.mostrarLista();

	/*Nodo* px = lista.getCabecera();

	Nodo* py = lista.getCabecera()->getSig()->getSig();

	cout << "px = Nodo con el valor 1 y py = nodo con el valor 3" << endl;

	cout << endl;

	lista.Intercambiar(px,py);

	lista.mostrarLista();*/

	lista.agregarDerecha(3, 10);

	

	lista.mostrarLista();
}


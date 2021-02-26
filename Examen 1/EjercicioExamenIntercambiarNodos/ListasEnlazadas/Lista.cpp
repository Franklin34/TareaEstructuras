#include "pch.h"
#include "Lista.h"


Lista::Lista()
{
	cabecera = NULL;
}


Lista::~Lista()
{
	borrar_todo();
}

void Lista::insertar_final(int valor)
{
	Nodo *nuevo_nodo = new Nodo(valor);

	Nodo *temp = cabecera;

	if (cabecera == nullptr) {
		cabecera = nuevo_nodo;
	}
	else {
		while (temp->getSig() != NULL) {
			temp = temp->getSig();
		}
		temp->setSig(nuevo_nodo);
	}
}


void Lista::borrar_todo()
{
	if (!cabecera) {
		cout << "La Lista está vacía " << endl;
	}else{
		cabecera->borrar_todo();
		
	}
}
void Lista::mostrarLista()
{
	Nodo *temp = cabecera;
	if (!cabecera) {
		cout << "La Lista está vacía " << endl;
	}
	else {
		while (temp) {
			temp->imprimir();
			//if (!temp->getSig());
			temp = temp->getSig();
		}
	}
	cout << endl << endl;
}

void Lista::Intercambiar(Nodo*px, Nodo*py)
{
	Nodo* tmp = px->getSig()->getSig();

	px->getSig()->setSig(py->getSig()->getSig());

	py->getSig()->setSig(tmp);

	tmp = py->getSig();

	py->setSig(px->getSig());

	px->setSig(tmp);
}

void Lista::agregarDerecha(int num_buscar, int num_agregar)
{
	Nodo* tmp = cabecera;
	Nodo* tmp2;
	Nodo* nuevo = new Nodo(num_agregar);

	while (tmp) {
		if (tmp->getData() == num_buscar) {
			tmp2 = tmp->getSig();
			tmp->setSig(nuevo);
			nuevo->setSig(tmp2);
		}
		tmp = tmp->getSig();
	}
}



















































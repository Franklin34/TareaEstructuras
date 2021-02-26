#include "Lista.h"


Lista::Lista()
{
	cabecera = NULL;
}


Lista::~Lista()
{
	//borrar_todo();

}

Lista::Lista(const Lista&obj)
{
	if (obj.cabecera == nullptr)
		cabecera = nullptr;
	else {
		cabecera = new Nodo(obj.cabecera->getData());
		Nodo* tmp = cabecera;
		Nodo* tmp_obj = obj.cabecera->getSig();
		while (tmp_obj != nullptr) {
			tmp->setSig(new Nodo(tmp_obj->getData()));
			tmp = tmp->getSig();
			tmp_obj = tmp_obj->getSig();
		}
	}
}

void Lista::insertar_final(int valor)
{
	Nodo* nuevo_nodo = new Nodo(valor);
	Nodo* temp = cabecera;

	if (!cabecera) {
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
	}
	else {
		cabecera->borrar_todo();
		cabecera = 0;
	}
}
void Lista::mostrarLista()
{
	Nodo* temp = cabecera;
	if (!cabecera) {
		cout << "La Lista está vacía " << endl;
	}
	else {
		while (temp) {
			temp->imprimir();
			if (!temp->getSig());
			temp = temp->getSig();
		}
	}
	cout << endl << endl;
}

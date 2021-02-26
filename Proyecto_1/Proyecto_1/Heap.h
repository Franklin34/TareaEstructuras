#ifndef HEAP_H
#define HEAP_H
#include <iostream>
#include "ListaDoble.h"
#include "Estudiante.h"

template<class DATO>

class Heap {
private:
	template<class T>
	class Nodo {
	public:
		T valor;
		Nodo<T>* next;
		Nodo<T>* ant;
		Nodo(T v, Nodo<T>* sig = nullptr, Nodo<T>* prev = nullptr) : valor{ v }, next{ sig }, ant{ prev }{}
	};
	Nodo<DATO>* inicio;
	int tam;
	bool opc;
public:
	Heap(bool op = false) { inicio = nullptr; tam = 0; opc = op; }
	~Heap() { BorrarLista(); }
	Heap(Heap& obj);

	Heap(ListaDoble<DATO>& lista);

	void Insertar(DATO val);
	void BorrarLista();
	void mostrarLista();
	int sizeHeap();
	int obtenerPadre(int child);
	int obtenerHijoIzq(int parent);
	int obtenerHijoDere(int parent);
	DATO obtenerPos(int hijo);
	void bubbleUp(int hijo);
	void bubbleDown();
	void intercambiar(int hijo, int padre);
	DATO eliminar();

	Nodo<DATO>* getInicio() {
		return inicio;
	}

	bool compara(DATO, DATO);
	bool compara2(DATO, DATO);
	void Heapify(int n, int i);
};
#endif

template<class DATO>
inline void Heap<DATO>::Insertar(DATO val)
{
	Nodo<DATO>* nuevo;

	nuevo = new Nodo<DATO>(val);

	if (inicio == nullptr)
		inicio = nuevo;
	else {
		Nodo<DATO>* tmp = inicio;
		while (tmp->next != nullptr)
			tmp = tmp->next;
		tmp->next = nuevo;
		nuevo->ant = tmp;

	}

	tam++;
	if (tam != 1) {
		bubbleUp(tam - 1);
	}
}

template<class DATO>
inline void Heap<DATO>::BorrarLista()
{
	Nodo<DATO>* tmp = inicio;

	while (inicio != nullptr) {
		tmp = inicio;
		inicio = inicio->next;
		delete tmp;
	}
	inicio = nullptr;
}

template<class DATO>
inline void Heap<DATO>::mostrarLista()
{
	Nodo<DATO>* tmp = inicio;

	if (inicio != nullptr) {

		while (tmp != nullptr) {
			std::cout << tmp->valor << " ";
			tmp = tmp->next;
		}
	}
	std::cout << "\n\n";
}

template<class DATO>
inline int Heap<DATO>::sizeHeap()
{
	return tam;
}

template<class DATO>
inline int Heap<DATO>::obtenerPadre(int child)
{
	if (child % 2 == 0)
		return (child / 2) - 1;
	else
		return child / 2;
}

template<class DATO>
inline int Heap<DATO>::obtenerHijoIzq(int padre)
{
	return 2 * padre + 1;
}

template<class DATO>
inline int Heap<DATO>::obtenerHijoDere(int padre)
{
	return 2 * padre + 2;
}

template<class DATO>
inline DATO Heap<DATO>::obtenerPos(int i)
{
	int contador = 0;
	Nodo<DATO>* tmp = inicio;

	while (tmp != nullptr) {
		if (contador == i) {
			return tmp->valor;
		}
		tmp = tmp->next;
		contador++;
	}
}

template<class DATO>
inline void Heap<DATO>::bubbleUp(int hijo)
{
	int padre = obtenerPadre(hijo);

	if (padre != -1) {
		if (opc == true) {
			if (compara(obtenerPos(hijo), obtenerPos(padre)) == false && hijo >= 0 && padre >= 0)
			{
				intercambiar(hijo, padre);
				bubbleUp(obtenerPadre(hijo));
			}
		}
		else {
			if (compara(obtenerPos(hijo), obtenerPos(padre)) == true && hijo >= 0 && padre >= 0)
			{
				intercambiar(hijo, padre);
				bubbleUp(obtenerPadre(hijo));
			}
		}
	}
}

template<class DATO>
inline void Heap<DATO>::bubbleDown()
{
	int padre = 0;

	if (opc == true) {
		while (1) {
			int izquierdo = obtenerHijoIzq(padre);
			int derecho = obtenerHijoDere(padre);

			int mayor = padre;

			if (izquierdo < tam - 1 && compara(obtenerPos(izquierdo), obtenerPos(mayor)) == false) {
				mayor = izquierdo;
			}
			if (derecho < tam - 1 && compara(obtenerPos(derecho), obtenerPos(mayor)) == false) {
				mayor = derecho;
			}

			if (mayor != padre) {
				intercambiar(mayor, padre);
				padre = mayor;
			}
			else {
				break;
			}

		}
	}
	else {
		while (1) {
			int izquierdo = obtenerHijoIzq(padre);
			int derecho = obtenerHijoDere(padre);

			int mayor = padre;

			if (izquierdo < tam - 1 && compara(obtenerPos(izquierdo), obtenerPos(mayor)) == true) {
				mayor = izquierdo;
			}
			if (derecho < tam - 1 && compara(obtenerPos(derecho), obtenerPos(mayor)) == true) {
				mayor = derecho;
			}

			if (mayor != padre) {
				intercambiar(mayor, padre);
				padre = mayor;
			}
			else {
				break;
			}

		}
	}
}
template<class DATO>
inline void Heap<DATO>::intercambiar(int hijo, int padre)
{
	Nodo<DATO>* cabeza = inicio;
	Nodo<DATO>* tmp = cabeza;
	Nodo<DATO>* tmp2 = cabeza;

	while (cabeza) {
		if (compara2(cabeza->valor, obtenerPos(hijo)) == true) {
			tmp = cabeza;
			break;
		}
		cabeza = cabeza->next;
	}

	cabeza = inicio;

	while (cabeza) {
		if (compara2(cabeza->valor, obtenerPos(padre)) == true) {
			tmp2 = cabeza;
			break;
		}
		cabeza = cabeza->next;
	}

	if (tmp != nullptr && tmp2 != nullptr) {
		DATO tmp3 = obtenerPos(hijo);
		tmp->valor = tmp2->valor;
		tmp2->valor = tmp3;
	}
}

template<class DATO>
inline DATO Heap<DATO>::eliminar()
{
	DATO dato = obtenerPos(0);
	if (tam != 1) {
		intercambiar(tam - 1, 0);

		Nodo<DATO>* tmp = inicio;
		Nodo<DATO>* aux = tmp;

		while (tmp->next != nullptr) {
			aux = tmp;
			tmp = tmp->next;
		}
		aux->next = nullptr;
		delete tmp;

		bubbleDown();
		tam--;

		return dato;
	}
	if (tam == 1) {
		delete inicio;
		inicio = nullptr;
		tam--;
		return dato;
	}
}

template<class DATO>
inline bool Heap<DATO>::compara(DATO obj, DATO obj2)
{
	return obj > obj2 ? true : false;
}

template<class DATO>
inline bool Heap<DATO>::compara2(DATO obj, DATO obj2)
{
	return obj == obj2 ? true : false;
}

template<class DATO>
inline void Heap<DATO>::Heapify(int n, int i)
{
	int mayor = i;
	int izquierda = 2 * i + 1;
	int derecha = 2 * i + 2;
	if (izquierda < n && compara(obtenerPos(izquierda), obtenerPos(mayor)) == true) {
		mayor = izquierda;
	}
	if (derecha < n && compara(obtenerPos(derecha), obtenerPos(mayor)) == true) {
		mayor = derecha;
	}
	if (mayor != i) {
		intercambiar(i, mayor);
		Heapify(n, mayor);
	}
}

template<class DATO>
inline Heap<DATO>::Heap(Heap& obj)
{
	tam = obj.tam;
	opc = obj.opc;

	if (obj.inicio == nullptr) {
		inicio = nullptr;
	}
	else {
		inicio = new Nodo<DATO>(obj.inicio->valor);
		Nodo<DATO>* actual = inicio;
		Nodo<DATO>* actualObj = obj.inicio->next;
		while (actualObj != nullptr) {
			actual->next = new Nodo<DATO>(actualObj->valor);
			actual = actual->next;
			actualObj = actualObj->next;
		}
	}
}

template<class DATO>
inline Heap<DATO>::Heap(ListaDoble<DATO>& lista)
{
	tam = 0;
	opc = false;
	inicio = nullptr;
	for (int i = 0; i < lista.getTam(); i++) {
		Insertar(lista.obtenerPos(i));
	}
}
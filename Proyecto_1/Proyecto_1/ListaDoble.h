#ifndef LISTADOBLE_H
#define LISTADOBLE_H
#include <iostream>

template<class DATO>

class ListaDoble
{
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
public:
	ListaDoble() { inicio = nullptr; tam = 0; }
	~ListaDoble();

	void Insertar(DATO val);
	void BorrarLista();
	void mostrarLista();
	DATO obtenerPos(int);
	void intercambiar(int hijo, int padre);

	Nodo<DATO>* getInicio() {
		return inicio;
	}
	int getTam() {
		return tam;
	}

	void heapify();

};
#endif // !

template<class DATO>
inline ListaDoble<DATO>::~ListaDoble()
{
	BorrarLista();
}

template<class DATO>
inline void ListaDoble<DATO>::Insertar(DATO val)
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
}

template<class DATO>
inline void ListaDoble<DATO>::BorrarLista()
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
inline void ListaDoble<DATO>::mostrarLista()
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
inline DATO ListaDoble<DATO>::obtenerPos(int i)
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
inline void ListaDoble<DATO>::intercambiar(int hijo, int padre)
{
	Nodo<DATO>* cabeza = inicio;
	Nodo<DATO>* tmp = nullptr;
	Nodo<DATO>* tmp2 = nullptr;

	while (cabeza) {
		if (cabeza->valor == obtenerPos(hijo)) {
			tmp = cabeza;
		}
		cabeza = cabeza->next;
	}

	cabeza = inicio;

	while (cabeza) {
		if (cabeza->valor == obtenerPos(padre)) {
			tmp2 = cabeza;
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
inline void ListaDoble<DATO>::heapify()
{

}

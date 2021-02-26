#ifndef COLA_PRIORIDAD_H
#define COLA_PRIORIDAD_H
#include "Heap.h"

template<class T>

class Cola_Prioridad
{
private:
	Heap<T>* cola;
public:
	Cola_Prioridad();
	Cola_Prioridad(bool opc);
	Cola_Prioridad(const Cola_Prioridad&);
	Cola_Prioridad(ListaDoble<T>&);
	~Cola_Prioridad();


	void Agregar(T valor);
	T ExtraerMax();
	T pop();

};
#endif

template<class T>
inline Cola_Prioridad<T>::Cola_Prioridad()
{
	cola = new Heap<T>;
}

template<class T>
inline Cola_Prioridad<T>::Cola_Prioridad(bool opc)
{
	cola = new Heap<T>(opc);
}

template<class T>
inline Cola_Prioridad<T>::Cola_Prioridad(const Cola_Prioridad& nueva_cola) 
{
	cola = new Heap<T>(*nueva_cola.cola);
}

template<class T>
inline Cola_Prioridad<T>::Cola_Prioridad(ListaDoble<T>&lista)
{
	cola = new Heap<T>(lista);
}

template<class T>
inline Cola_Prioridad<T>::~Cola_Prioridad()
{
	delete cola;
}

template<class T>
inline void Cola_Prioridad<T>::Agregar(T valor)
{
	cola->Insertar(valor);
}

template<class T>
inline T Cola_Prioridad<T>::ExtraerMax()
{
	return cola->getInicio()->valor;
}

template<class T>
inline T Cola_Prioridad<T>::pop()
{
	return cola->eliminar();
}

// Ejercicio 6
// Verifica que una cadena de caracteres sea subcadena de otra - parte de la versi�n del m�todo find() de std::string
// Complejidad de Tiempo:  O(n2)

// NOTA: Este c�digo es de ejemplo. La implementaci�n de las librer�as se realiz� de esta manera
//       �nicamente con fines did�cticos y acomodar ambas funciones dentro del mismo c�digo.
//       No se siguen buenas pr�cticas de orientaci�n a objetos ni de dise�otas �nicamenteis

#include "ListaSimple.h"
#include <string>

// Prototipos de funci�n
void CrearCadena(Nodo*&, std::string);
Nodo* EsSubStr(Nodo*&, Nodo*&);

int main() {
	const short unsigned int max = 10;  //constante que define el tama�o del array

	Nodo* PrimerCadena = nullptr;
	Nodo* SegundaCadena = nullptr;

	// Creamos las listas con las cadenas de caracteres
	CrearCadena(PrimerCadena, "Estructuras de Datos");
	CrearCadena(SegundaCadena, "Dato");

	// Comparamos las cadenas - imprime TRUE o FALSE si es subcadena o no
	EsSubStr(PrimerCadena, SegundaCadena) != nullptr ? std::cout << "TRUE" : std::cout << "FALSE";

	BorrarLista(&PrimerCadena);
	BorrarLista(&SegundaCadena);

	return 0;
}

// Crea una cadena de caracteres que se almacena en una lista
void CrearCadena(Nodo*& actual, std::string s) {
	for (std::string::size_type i = 0; i < s.length(); ++i)
		InsertarElemento(&actual, s[i]);
}

// Determina si una cadena (source) es subcadena de otra (sub)
// Si la encuentra, se retorna un apuntador al nodo donde comienza la subcadena
// o nullptr en caso contrario
Nodo* EsSubStr(Nodo*& source, Nodo*& sub) {
	Nodo* tmp = source;
	Nodo* pos = nullptr;

	while (tmp) {
		pos = tmp;
		Nodo* tmp2 = sub;
		while (tmp2) {
			if (pos->valor == tmp2->valor) {
				pos = pos->next;
				tmp2 = tmp2->next;
			}
			else
				break;
		}
		if (!tmp2)
			return pos;
		tmp = tmp->next;
	}
	return nullptr;
}
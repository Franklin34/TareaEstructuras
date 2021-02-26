#include <iostream>
#include <fstream>
#include <string>

void ImprimirLineas(std::ifstream&,std::string palabra);
void ImprimirArchivo(std::ifstream&);

int main()
{
	std::ifstream archivo;
	std::string palabra;

	archivo.open("text.txt");

	if (!archivo.is_open()) {
		return -1;
	}

	ImprimirArchivo(archivo);

	archivo.close();

	archivo.open("text.txt");

	if (!archivo.is_open()) {
		return -1;
	}

	std::cout << std::endl;

	std::cout << "Digite la frase o palabra para ver las lineas del texto donde se encuentra: ";
	std::getline(std::cin, palabra);
	std::cout << std::endl;

	system("cls");
	
	std::cout << "La palabra es: " << palabra << std::endl << std::endl;

	ImprimirLineas(archivo,palabra);

	archivo.close();

}

void ImprimirLineas(std::ifstream& arch,std::string palabra) {
	std::string linea;
	std::string* vector[30];

	for (int i = 0; i < 30; i++) {
		vector[i] = new std::string;
	}

	
	int cantidad = 0;
	int a = 1;
	int vect[30];

	for (int i = 0; i < 30; i++) {
		vect[i] = 0;
	}

	while (std::getline(arch, linea)) {
		std::cout << linea << std::endl;
		if (linea.find(palabra) != std::string::npos) {
			*vector[cantidad] = linea;
			vect[cantidad] = a;
			cantidad++;
		}
		a++;		
	}

    std::cout << std::endl;

	for (int i=0; i < cantidad; i++) {
		std::cout << vect[i] << " " << *vector[i] << '\n';
	}

	for (int i = 0; i < 30; i++) {
		delete vector[i];
	}
}
void ImprimirArchivo(std::ifstream& arch) {
	std::string lineas;

	while (std::getline(arch, lineas)) {
		std::cout << lineas << std::endl;
	}
}
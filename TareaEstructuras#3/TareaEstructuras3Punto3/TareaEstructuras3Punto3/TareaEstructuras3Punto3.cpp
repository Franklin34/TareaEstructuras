#include <iostream>
#include <fstream>

void divisores(int numero,std::ofstream&archivo,int divisor = 1);

int main()
{
    std::ofstream archivo;

    archivo.open("texto.txt", std::ios::app);

    if (!archivo.is_open()) {
        return 0;
    }
    std::cout << "Digite el numero para sacarle los divisores: ";
    int numero;
    std::cin >> numero;
    divisores(numero,archivo);

    archivo.close();
}
void divisores(int numero, std::ofstream&archivo, int divisor) {
    if (divisor == numero) {
        archivo << " " << numero <<'\n';
    }
    else {
        if (numero % divisor == 0) {
            archivo << divisor << " ";
        }
        divisores(numero, archivo, divisor + 1);
    }
}

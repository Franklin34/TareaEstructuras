#include <iostream>

void moverdiscos(int piezas,char A,char B,char C);

int main()
{
    std::cout << "Digite la cantidad de piezas: ";
    int piezas;
    std::cin >> piezas;
    std::cout << '\n';
    moverdiscos(piezas, 'A', 'B', 'C');
   
}
void moverdiscos(int piezas, char A, char B, char C) {
    if (piezas == 1) {
        std::cout << "La pieza se movio de la varilla " << A << " a la varilla " << C << '\n';
    }
    else {
        moverdiscos(piezas - 1, A, C, B);
        std::cout << "La pieza se movio de la varilla " << A << " a la varilla " << C << '\n';
        moverdiscos(piezas - 1, B, A, C);
    }
}

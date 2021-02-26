#include "stack"
#include <queue>
#include <iostream>

void transferirdatos(std::queue<int>, std::stack<int>& pila);

int main()
{
    std::stack<int> pila;
    std::queue<int> cola;

    cola.push(90);
    cola.push(4);
    cola.push(8);
    cola.push(17);
    cola.push(25);
    cola.push(32);
    cola.push(56);

    transferirdatos(cola, pila);

    cola.pop();
    
    std::cout << "Cola despues de la tranferencia a la pila: ";
    while (!cola.empty()) {
        std::cout << cola.front() << " ";
        cola.pop();
    }

    std::cout << '\n';
    std::cout << '\n';
    std::cout << "Tope de la Pila: ";
    std::cout << pila.top();

    std::cout << '\n';
    std::cout << '\n';

}

void transferirdatos(std::queue<int> cola, std::stack<int>& pila) {
    std::cout << "Cola inicial: ";
    while (!cola.empty()) {
        pila.push(cola.front());
        std::cout << cola.front() << " ";
        cola.pop();
    }
    std::cout << '\n';

    std::stack<int> p;

    while (!pila.empty()) {
        p.push(pila.top());
        pila.pop();
    }
    pila = p;

}
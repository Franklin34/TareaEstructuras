#include <iostream>

std::string invertirString(std::string,int contador,std::string nuevapalabra="");

int main()
{
    std::string palabra = "Visual Studio";
    int contador=palabra.size();
    std::cout << invertirString(palabra,contador-1) << '\n';
}
std::string invertirString(std::string palabra,int contador,std::string nuevapalabra) {

    if (contador  < 0) {
        return nuevapalabra;
    }
    else {
        return invertirString(palabra, contador - 1,nuevapalabra += palabra[contador]);
    }
}

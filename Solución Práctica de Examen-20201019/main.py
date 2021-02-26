# Solución de la práctica de examen


from solucion import Arbol


if __name__ == '__main__':
    # Instanciamos el árbol e insertamos valores desde un archivo para correr pruebas
    arbolito = Arbol()
    arbolito.crear_desde_archivo("arbolint.txt")
    arbolito.imprimir()

    print("\nSOLUCION DE LA PRACTICA DE EXAMEN\n")

    # EJERCICIO #1
    print("Ejercicio #1\n------------")
    arbolito.suma()
    print("\n")

    # EJERCICIO #2
    print("Ejercicio #2\n------------")
    print(arbolito.suma_nivel_mayor())
    print("\n")

    # EJERCICIO #3
    print("Ejercicio #3\n------------")
    print(arbolito.elemento_mayor())
    print("\n")

    # EJERCICIO #4
    print("Ejercicio #4\n------------")
    arbolito.nivel_inverso()
    print("\n")

    # EJERCICIO #5
    print("Ejercicio #5\n------------")
    print("Diametro del arbol: {}".format(arbolito.diametro()))
    print("\n")

    # EJERCICIO #6
    print("Ejercicio #6\n------------")
    posfija = "34 77 + 2 6 * 17 30 -"
    print("Expresión posfija:   34 77 + 2 6 * 17 30 -")
    arbolito.arbol_expresion(posfija)
    print("\n")

    # EJERCICIO #7
    print("Ejercicio #7\n------------")
    arbolito.lca()
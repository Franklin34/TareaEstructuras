# solucion.py
# Autor: El Tigre
# Descripción: Solución de la práctica de examen. Ver ejercicios al final


from queue import Queue
from queue import LifoQueue


class Nodo:
    """Representación de un nodo para la construcción de un árbol binario

    Atributos:
        nombre valor: elemento que se almacenará en el árbol
        tipo: unknown
        nombre left: apuntador al subárbol izquiero para el nodo
        tipo: Nodo
        nombre right: apuntador al subárbol derecho para el nodo
        tipo: Nodo
    """

    def __init__(self, val=None):
        self.valor = val
        self.left = None
        self.right = None


class Arbol:
    """Representación de un árbol binario

    Atributos:
        nombre root: apuntador a la raíz del árbol
        tipo: Nodo
    """

    def __init__(self):
        self.root = None

    def crear_desde_archivo(self, nombre):
        """Crea un Arbol BST a partir de un archivo de texto

        :param nombre: el nombre del archivo con los datos para el árbol
        :type nombre: str
        :returns: none
        :rtype: None
        """

        try:
            handle = open(nombre, "r")
        except IOError:
            return None

        tmp = None
        for n in handle:
            tmp = self._insertar(tmp, int(n))

        self.root = tmp
        handle.close()

    def esta_vacio(self):
        """Verifica si el árbol está vacío

            :returns: verdadero si el árbol está vacío o falso en caso contrario
            :rtype: True, False
        """

        return self.root is None

    def altura(self):
        """WRAPPER que invoca a la función para calcular la altura del árbol

        :returns: el valor de la altura del árbol. Si el árbol está vacío retorna -1
        :rtype: int
        """
        return self._altura(self.root)

    def insertar(self, val):
        """WRAPPER que invoca a la función para insertar elementos en el árbol

        :param val: el elemento a insertar en el árbol
        :type val: unknown
        :returns: none
        :rtype: None
        """
        self.root = self._insertar(self.root, val)

    def imprimir(self):
        """WRAPPER que invoca a la función para imprimir el árbol binario de búsqueda

        :returns: none
        :rtype: None
        """
        self._imprimir(" ", self.root, False)

    def borrar_arbol(self):
        """Elimina completamente el árbol binario de búsqueda

        :returns: none
        :rtype: None
        """
        self.root = None

    def _altura(self, root):
        """Calcula la altura del árbol. Recorre los subárboles izquierdo y derecho y encuentra el que tiene el
        mayor tamaño. Si el árbol está vacío retorna -1

        :param root: raíz del subárbol que se está explorando
        :type root: Nodo
        :returns: la altura del árbol
        :rtype: int
        """
        if root is None:
            return -1

        maxizq = self._altura(root.left) + 1
        maxder = self._altura(root.right) + 1

        if maxizq > maxder:
            return maxizq
        return maxder

    def _insertar(self, root, key):
        """Inserta un nuevo elemento dentro del árbol manteniendo las propiedades de búsqueda

        :param root: raíz del subárbol
        :type root: Nodo
        :param key: elemento que se quiere insertar en el árbol
        :type key: unknown
        :returns: un apuntador a la raíz del árbol después de la inserción
        :rtype: Nodo
        """
        if root is None:
            root = Nodo(key)
        else:
            if key < root.valor:
                root.left = self._insertar(root.left, key)
            elif key > root.valor:
                root.right = self._insertar(root.right, key)
        return root

    def _imprimir(self, p, root, es_izq):
        """Imprime el árbol binario de búsqueda de una manera legible

        :param p: cadena de texto a imprimir
        :type p: str
        :param root: raíz del subárbol
        :type root: Nodo
        :param es_izq: determina si el nodo que se va a imprimir está en el subárbol izquierdo
        :type es_izq: bool
        :returns: none
        :rtype: None
        """
        if root:
            print(p, end='')

            if es_izq:
                print("|--", end='')
                cad = "|    "
            else:
                print("'--", end='')
                cad = "    "

            print(root.valor)
            self._imprimir(p + cad, root.left, True)
            self._imprimir(p + cad, root.right, False)

    # ##############################################################################3
    # EJERCICIO #1
    def suma(self):
        """WRAPPER - Retorna la suma de todos los elementos del árbol

        :returns: la altura del árbol
        :rtype: int
        """

        # Llamada a la version recursiva
        print("Suma con llamada recursiva: {}".format(str(self._suma_recursiva(self.root))))

        # Llamada a la version iterativa
        print("Suma con llamada iterativa: {}".format(str(self._suma_iterativa())))

    def _suma_recursiva(self, root):
        """Obtiene la suma de todos los elementos del árbol de manera recursiva

        :param root: raíz del árbol
        :type root: Nodo
        :returns: la suma de todos los valores del árbol
        :rtype: int
        """
        if root is None:
            return 0
        return root.valor + self._suma_recursiva(root.left) + self._suma_recursiva(root.right)

    def _suma_iterativa(self):
        """Obtiene la suma de todos los elementos del árbol de manera recursiva

        :returns: la suma de todos los valores del árbol
        :rtype: int
        """
        cola = Queue()
        suma = 0
        cola.put(self.root)
        while not cola.empty():
            tmp = cola.get()
            suma += tmp.valor
            if tmp.left is not None:
                cola.put(tmp.left)
            if tmp.right is not None:
                cola.put(tmp.right)
        return suma

    # ##############################################################################3
    # EJERCICIO #2
    def suma_nivel_mayor(self):
        """Obtiene el nivel cuya suma de nodos es mayor

        :returns: el número de nivel y su respectiva suma
        :rtype: tuple
        """
        cola = Queue()
        nivel_actual = 0
        nivel_mayor = 0
        suma_actual = 0
        suma_mayor = 0
        cola.put(self.root)
        cola.put(None)
        while not cola.empty():
            tmp = cola.get()
            if tmp is None:
                if suma_actual > suma_mayor:
                    suma_mayor = suma_actual
                    nivel_mayor = nivel_actual
                suma_actual = 0
                if not cola.empty():
                    cola.put(None)
                nivel_actual += 1
            else:
                suma_actual += tmp.valor
                if tmp.left is not None:
                    cola.put(tmp.left)
                if tmp.right is not None:
                    cola.put(tmp.right)
        return nivel_mayor, suma_mayor

    # ##############################################################################3
    # EJERCICIO #3
    def elemento_mayor(self):
        """Obtiene el elemento mayor de un árbol binario

        :returns: el número mayor del árbol
        :rtype: int
        """
        cola = Queue()
        mayor = 0
        cola.put(self.root)
        while not cola.empty():
            tmp = cola.get()
            actual = tmp.valor
            if actual > mayor:
                mayor = actual

            if tmp.left is not None:
                cola.put(tmp.left)
            if tmp.right is not None:
                cola.put(tmp.right)
        return mayor

    # ##############################################################################3
    # EJERCICIO #4
    def nivel_inverso(self):
        """Imprime el recorrido por nivel pero en orden inverso

        :returns: None
        :rtype: None
        """
        if self.root is None:
            return
        pila = LifoQueue()
        cola = Queue()
        cola.put(self.root)
        while not cola.empty():
            tmp = cola.get()
            if tmp.left is not None:
                cola.put(tmp.left)
            if tmp.right is not None:
                cola.put(tmp.right)
            pila.put(tmp.valor)
        print("Recorrido por nivel inverso: \n")
        while not pila.empty():
            print(" {}".format(pila.get()), end="")

    # ##############################################################################3
    # EJERCICIO #5
    def diametro(self):
        """WRAPPER para calcular el diámetro del árbol

        :returns: None
        :rtype: None
        """
        return self._diametro(self.root)

    def _diametro(self, root):
        """Obtiene la suma de todos los elementos del árbol de manera recursiva

        :param root: raíz del árbol
        :type root: Nodo
        :returns: el diámetro del árbol
        :rtype: int
        """
        if root is None:
            return 0
        izq = self._diametro(root.left)
        der = self._diametro(root.right)
        return max(izq, der) + 1

    # ##############################################################################3
    # EJERCICIO #6
    def arbol_expresion(self, posfija):
        """WRAPPER para crear y evaluar un árbol de expresión

        :param posfija: expresión en notación polaca (posfija)
        :type posfija: str
        :returns: el resultado de la evaluación de la expresión
        :rtype: int
        """
        exp = self._construir_arbol_expresion(posfija)
        self._en_orden(exp)

    def _construir_arbol_expresion(self, posfija):
        """Construye un árbol de expresión a partir de una expresión posfija

        :param posfija: expresión en notación polaca (posfija)
        :type posfija: str
        :returns: apuntador al nuevo árbol construido
        :rtype: Nodo
        """
        pila = LifoQueue()
        for valor in posfija.split():
            if self._es_operador(valor) is True:
                nuevo = Nodo(valor)
                nodo_der = pila.get()
                nodo_izq = pila.get()

                nuevo.left = nodo_izq
                nuevo.right = nodo_der
                pila.put(nuevo)
            else:
                nuevo = Nodo(valor)
                pila.put(nuevo)
        return pila.get()

    @staticmethod
    def _es_operador(op):
        """Determina si el valor dado corresponde a un operador u operando

        :param op: expresión
        :type op: str
        :returns: verdadero si es un operador o falso si es un operando
        :rtype: bool
        """
        if op in ['+', '-', '*', '/', '^']:
            return True
        return False

    def _en_orden(self, root):
        """Imprime el recorrido en orden del árbol

        :param root: apuntador a la raíz del árbol
        :type root: Nodo
        :returns: None
        :rtype: None
        """
        if root is not None:
            self._en_orden(root.left)
            print(root.valor, end=' ')
            self._en_orden(root.right)

    # ##############################################################################3
    # EJERCICIO #7
    def lca(self):
        """WRAPPER para el algoritmo que encuentra el último ancestro en común para dos nodos

        :returns: None
        :rtype: None
        """
        a = self._buscar(self.root, 22)
        b = self._buscar(self.root, 8)
        print("Nodo A = 22\nNodo B = 8")
        print("El LCA de A y B es: {}".format(self._lca(self.root, a, b).valor))

    def _lca(self, root, nodo_a, nodo_b):
        """Encuentra el último ancestro en común para dos nodos dados

        :param root: raíz del árbol
        :type root: Nodo
        :param nodo_a: nodo para encontrar el lca
        :type nodo_a: Nodo
        :param nodo_b: nodo para encontrar el lca
        :type nodo_b: Nodo
        :returns: apuntador al último ancestro en común
        :rtype: Nodo
        """
        if root is None:
            return None
        if root == nodo_a or root == nodo_b:
            return root
        izq = self._lca(root.left, nodo_a, nodo_b)
        der = self._lca(root.right, nodo_a, nodo_b)
        if izq is not None and der is not None:
            return root
        else:
            if izq is not None:
                return izq
            else:
                return der

    def _buscar(self, root, key):
        """Busca un elemento dentro del árbol binario (versión recursiva)

        :param key: elemento que se quiere buscar en el árbol
        :type key: unknown
        :returns: un apuntador al nodo que contiene el elemento si lo encontró (None si no se encuentra)
        :rtype: Nodo, None
        """
        if root is None or root.valor == key:
            return root

        if key < root.valor:
            return self._buscar(root.left, key)
        return self._buscar(root.right, key)

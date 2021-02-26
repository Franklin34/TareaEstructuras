# arbolbst.py
# Autor: El Tigre
# Descripción: Librería que incluye diversas funciones para implementar un árbol binario de búsqueda


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


class ArbolBST:
    """Representación de un árbol binario de búsqueda

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

    def buscar(self, key):
        """WRAPPER que invoca a la función para buscar un elemento en el árbol

        :param key: el elemento a buscar en el árbol
        :type key: unknown
        :returns: verdadero si se encontró el valor o falso en caso contrario
        :rtype: True, False
        """
        if self._buscar_iterativo(key) is not None:
            return True
        return False

    def eliminar(self, key):
        """WRAPPER que invoca a la función para borrar un elemento del árbol

        :param key: el elemento a borrar en el árbol
        :type key: unknown
        :returns: none
        :rtype: None
        """
        self.root = self._eliminar(self.root, key)

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

    #
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

    def _buscar_iterativo(self, key):
        """Busca un elemento dentro del árbol binario (versión iterativa)

        :param key: elemento que se quiere buscar en el árbol
        :type key: unknown
        :returns: un apuntador al nodo que contiene el elemento si lo encontró (None si no se encuentra)
        :rtype: Nodo, None
        """
        actual = self.root
        while actual is not None:
            if key == actual.valor:
                return actual
            if key < actual.valor:
                actual = actual.left
            else:
                actual = actual.right
        return None

    def _buscar_recursivo(self, root, key):
        """Busca un elemento dentro del árbol binario (versión recursiva)

        :param key: elemento que se quiere buscar en el árbol
        :type key: unknown
        :returns: un apuntador al nodo que contiene el elemento si lo encontró (None si no se encuentra)
        :rtype: Nodo, None
        """
        if root is None or root.valor == key:
            return root

        if key < root.valor:
            return self._buscar_recursivo(root.left, key)
        return self._buscar_recursivo(root.right, key)

    def _eliminar(self, root, key):
        """Elimina el nodo que contiene el dato dado por el usuario. Retorna un apuntador a la raíz del árbol BST

        :param root: raíz del subárbol
        :type root: Nodo
        :param key: elemento que se quiere eliminar del árbol
        :type key: unknown
        :returns: un apuntador al arbol binario de búsqueda después de eliminar
        :rtype: Nodo, None
        """
        if root is None:
            return None

        #
        # CASO 1 --> El nodo no tiene hijos
        # CASO 2 --> El subárbol solamente tiene un hijo
        # CASO 3 --> El subárbol tiene dos hijos
        # Buscamos el nodo en el subárbol izquierdo
        if key < root.valor:
            root.left = self._eliminar(root.left, key)
        elif key > root.valor:
            root.right = self._eliminar(root.right, key)
        else:
            # CASO #1: El nodo es una hoja
            if root.left is None and root.right is None:
                root = None
            # CASO #2: El nodo solamente tiene un subárbol: izquierdo o derecho
            # Subárbol derecho
            elif root.left is None:
                root = root.right
            # Subárbol izquierdo
            elif root.right is None:
                root = root.left
            # CASO #3: El nodo a borrar tiene dos hijos
            else:
                tmp = self._max(root.left)
                root.valor = tmp.valor
                root.left = self._eliminar(root.left, tmp.valor)
        return root

    # noinspection PyMethodMayBeStatic
    def _max(self, root):
        """Obtiene el nodo con el valor mayor para un subárbol

        :param root: raíz del subárbol
        :type root: Nodo
        :returns: un apuntador al nodo mayor del subárbol (None si está vacío)
        :rtype: Nodo, None
        """
        if root is None:
            return None

        while root.right is not None:
            root = root.right
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

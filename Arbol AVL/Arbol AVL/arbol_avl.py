# arbol_avl.py
# Autor: El Tigre
# Descripción: Librería que incluye diversas funciones para implementar un árbol binario de búsqueda balanceado


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


class ArbolAVL:
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
        """Inserta un nuevo elemento dentro del árbol manteniendo las propiedades de árbol AVL

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
                if abs(self._altura(root.left) - self._altura(root.right)) == 2:
                    if key < root.right.valor:
                        root = self._rotacion_derecha(root)
                    else:
                        root = self._rotacion_doble_izq_der(root)
            elif key > root.valor:
                root.right = self._insertar(root.right, key)
                if abs(self._altura(root.left) - self._altura(root.right)) == 2:
                    if key > root.right.valor:
                        root = self._rotacion_izquierda(root)
                    else:
                        root = self._rotacion_doble_der_izq(root)
        return root

    # noinspection PyMethodMayBeStatic
    def _rotacion_izquierda(self, x):
        """Realiza una rotación simple hacia la izquierda para balancear el subárbol a partir del nodo X

        :param x: nodo a partir de donde se realiza la rotación
        :type x: Nodo
        :returns: un apuntador a la raíz del nuevo subárbol
        :rtype: Nodo
        """
        y = x.right
        x.right = y.left
        y.left = x
        return y

    # noinspection PyMethodMayBeStatic
    def _rotacion_derecha(self, x):
        """Realiza una rotación simple hacia la derecha para balancear el subárbol a partir del nodo X

        :param x: nodo a partir de donde se realiza la rotación
        :type x: Nodo
        :returns: un apuntador a la raíz del nuevo subárbol
        :rtype: Nodo
        """
        y = x.left
        x.left = y.right
        y.right = x
        return y

    def _rotacion_doble_izq_der(self, x):
        """Realiza una rotación doble izquierda - derecha para balancear el subárbol a partir del nodo X

        :param x: nodo a partir de donde se realiza la rotación
        :type x: Nodo
        :returns: un apuntador a la raíz del nuevo subárbol
        :rtype: Nodo
        """
        x.left = self._rotacion_izquierda(x.left)
        return self._rotacion_derecha(x)

    def _rotacion_doble_der_izq(self, x):
        """Realiza una rotación doble derecha - izquierda para balancear el subárbol a partir del nodo X

        :param x: nodo a partir de donde se realiza la rotación
        :type x: Nodo
        :returns: un apuntador a la raíz del nuevo subárbol
        :rtype: Nodo
        """
        x.right = self._rotacion_derecha(x.right)
        return self._rotacion_izquierda(x)

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

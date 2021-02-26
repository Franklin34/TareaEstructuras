# arbol_binario.py
# Autor: El Tigre
# Descripción: Funciones básicas de un árbol binario (crear un árbol desde archivo e imprimir)

# Librería para el manejo de colas
import queue

# Contiene la información de cada nodo del árbol binario
class Nodo:
    def __init__(self, val=None):
        self.valor = val
        self.left = None
        self.right = None


# Implementa funciones para crear y realizar operaciones sobre un árbol binario
class ArbolBinario:
    def __init__(self):
        self.root = None

    #######################################
    # "Interfaz" de la clase ArbolBinario #
    #######################################

    # Crea un arbol desde el archivo especificado
    def crear_desde_archivo(self, nombre):
        try:
            handle = open(nombre, "r")
        except IOError:
            return None

        self.root = self._crear_desde_archivo(handle)

        handle.close()

        if self.root is None:
            return None
        return 1

    # Retorna True si el árbol está vacío y False en caso contrario
    def esta_vacio(self):
        return self.root is None

    def altura(self):
        return self._altura(self.root)

    def insertar(self, key):
        self._insertar(key)

    def borrar(self, key):
        return self._borrar(key)

    def buscar_iterativo(self, key):
        tmp = self._buscar_iterativo(key)
        if tmp:
            return True
        else:
            return False

    def buscar(self, key):
        tmp = self._buscar(self.root, key)
        if tmp is None:
            return False
        else:
            return True

    def borrar_arbol(self):
        self.root = None

    # Muestra el recorrido del árbol en PreOrden
    def recorrido_pre_orden(self):
        self._recorrido_pre_orden(self.root)

    # Muestra el recorrido del árbol en EnOrden
    def recorrido_en_orden(self):
        self._recorrido_en_orden(self.root)

    # Muestra el recorrido del árbol en PosOrden
    def recorrido_pos_orden(self):
        self._recorrido_pos_orden(self.root)

    # Muestra el recorrido por nivel (anchura)
    def recorrido_por_nivel_iterativo(self):
        self._recorrido_por_nivel_iterativo()
    

     # Imprime el árbol
    def imprimir(self):
        self._imprimir(" ", self.root, False)

    ####################################
    # Funciones auxiliares de la clase #
    ####################################

    # Función auxiliar para crear un árbol binario tipo char desde el archivo manejado por handle
    def _crear_desde_archivo(self, handle):
        c = handle.read(1)

        if c == '$':
            return None

        tmp = Nodo(c)

        tmp.left = self._crear_desde_archivo(handle)
        tmp.right = self._crear_desde_archivo(handle)

        return tmp

    def _altura(self, actual):
        if actual is None:
            return -1

        max_izq = self._altura(actual.left) + 1
        max_der = self._altura(actual.right) + 1

        if max_izq > max_der:
            return max_izq
        return max_der

    def _insertar(self, key):
        # if root == nullptr
        if self.root is None:
            self.root = Nodo(key)
            return

        cola = queue.Queue()

        cola.put(self.root)
        while not cola.empty():
            tmp = cola.get()
            if tmp.left is not None:
                cola.put(tmp.left)
            else:
                tmp.left = Nodo(key)
                return
            if tmp.right is not None:
                cola.put(tmp.right)
            else:
                tmp.right = Nodo(key)
                return

    def _borrar(self, key):
        tmp = self._buscar(self.root, key)

        if tmp is None:
            return False

        ultimo_nodo = self._nodo_mas_profundo(self.root)

        if tmp != ultimo_nodo:
            tmp.valor = ultimo_nodo.valor

        cola = queue.Queue()

        cola.put(self.root)
        while not cola.empty():
            tmp = cola.get()
            if tmp.left is not None:
                if tmp.left == ultimo_nodo:
                    tmp.left = None
                    return True
                cola.put(tmp.left)
            if tmp.right is not None:
                if tmp.right == ultimo_nodo:
                    tmp.right = None
                    return True
                cola.put(tmp.right)      
    
    def _buscar(self, actual, key):
        if actual is None:
            return None

        if actual.valor == key:
            return actual

        tmp = self._buscar(actual.left, key)

        if tmp is not None:
            return tmp
        else:
            return self._buscar(actual.right, key)

    def _buscar_iterativo(self, key):
        # if root == nullptr
        if self.root is None:   
            return

        cola = queue.Queue()

        cola.put(self.root)
        while not cola.empty():
            tmp = cola.get()
            if tmp.valor == key:
                return tmp
            if tmp.left is not None:
                cola.put(tmp.left)
            if tmp.right is not None:
                cola.put(tmp.right)
  
    def _recorrido_pre_orden(self, actual):
        if actual is not None:
            print(str(actual.valor), end='-')
            self._recorrido_pre_orden(actual.left)
            self._recorrido_pre_orden(actual.right  )
            

    def _recorrido_en_orden(self, actual):
        if actual is not None:
            self._recorrido_en_orden(actual.left)
            print(str(actual.valor), end='-')
            self._recorrido_en_orden(actual.right)           

    def _recorrido_pos_orden(self, actual):
        if actual is not None:
            self._recorrido_pos_orden(actual.left)
            self._recorrido_pos_orden(actual.right)
            print(str(actual.valor), end='-')

    def _recorrido_por_nivel_iterativo(self):
        # if root == nullptr
        if self.root is None:   
            return

        cola = queue.Queue()

        cola.put(self.root)
        while not cola.empty():
            tmp = cola.get()
            print(tmp.valor + ' ')
            if tmp.left is not None:
                cola.put(tmp.left)
            if tmp.right is not None:
                cola.put(tmp.right)

    def _nodo_mas_profundo(self, actual):
        if self.root is None:
            return None

        tmp = None
        cola = queue.Queue()

        cola.put(self.root)
        while not cola.empty():
            tmp = cola.get()
            if tmp.left is not None:
                cola.put(tmp.left)
            if tmp.right is not None:
                cola.put(tmp.right)
        return tmp

    # Imprime el árbol en un formato agradable
    def _imprimir(self, p, actual, es_izq):
        if actual:
            print(p, end='')

            if es_izq:
                print("|--", end='')
                cad = "|    "
            else:
                print("'--", end='')
                cad = "    "

            print(actual.valor)
            self._imprimir(p + cad, actual.left, True)
            self._imprimir(p + cad, actual.right, False)


if __name__ == '__main__':
    arbolito = ArbolBinario()
    arbolito.insertar(3)
    arbolito.insertar(10)
    arbolito.insertar(2)    
    arbolito.insertar(38)
    arbolito.insertar(5)
    arbolito.insertar(12)
    arbolito.insertar(20)

    arbolito.imprimir()
    arbolito.recorrido_pos_orden()
    
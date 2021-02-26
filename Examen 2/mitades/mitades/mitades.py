import queue

class Nodo:
    def __init__(self, val=None):
        self.valor = val
        self.left = None
        self.right = None

class ArbolBinario:
    def __init__(self):
        self.root = None
        
    
    def insertar(self, key):
        self._insertar(key)

    def imprimir(self):
        self._imprimir(" ", self.root, False)

    def _insertar(self, key):
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

    def _mitades(self):
         if self.root is None:
            return

         lista = []
         cola = queue.Queue()
         cola.put(self.root)

         while not cola.empty():
            tmp = cola.get()
            if tmp.left is not None:
                cola.put(tmp.left)
            if tmp.right is not None:
                cola.put(tmp.right)
            if tmp.left is not None and tmp.right is None:
                lista.append(tmp)
            if tmp.right is not None and tmp.left is None:
                lista.append(tmp)
                    
         return lista


if __name__  == '__main__':

    print("Ejercicio Mitades:")
    print()

    arbol = ArbolBinario()

    arbol.insertar(3)
    arbol.insertar(10)
    arbol.insertar(2)    
    arbol.insertar(38)
    arbol.insertar(5)
    arbol.insertar(12)
    arbol.insertar(20)
    arbol.insertar(43)

    arbol.imprimir()
    print()

    if(len(arbol._mitades())) == 0:
        print("El arbol no tiene nodos con un solo hijo")

    for i in range(len(arbol._mitades())):
        print("El nodo es: ", arbol._mitades()[i].valor)

    print()
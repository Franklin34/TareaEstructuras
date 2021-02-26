
import queue

class Nodo:
    def __init__(self, val=None):
        self.valor = val
        self.left = None
        self.right = None
        self.padre = None

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
                nodo = Nodo(key)
                tmp.left = nodo
                nodo.padre = tmp
                return
            if tmp.right is not None:
                cola.put(tmp.right)
            else:
                nodo2 = Nodo(key)
                tmp.right = nodo2
                nodo2.padre = tmp
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



    def _ancestro(self,nodo):
        if self.root == None:
            return 
            
        cola = queue.Queue()
        cola.put(nodo.padre)
        tmp = nodo.padre

        while not cola.empty() and tmp.padre is not None:
            tmp = cola.get()
            print(tmp.valor,end = " ")
            cola.put(tmp.padre)

    def _buscar_iterativo(self, key):
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

if __name__ == '__main__':
    arbol = ArbolBinario()

    arbol.insertar(3)
    arbol.insertar(10)
    arbol.insertar(2)    
    arbol.insertar(38)
    arbol.insertar(5)
    arbol.insertar(12)
    arbol.insertar(20)
    arbol.insertar(56)

    arbol.imprimir()

    nodo = arbol._buscar_iterativo(56)
    print()
    print("Los ancestros del nodo 56 son: ",end=" ")
    arbol._ancestro(nodo)
    print()
    print()
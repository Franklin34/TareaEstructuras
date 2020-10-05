import queue
import Pila

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

    def recorrido_preordeniterativo(self):
        self._recorrido_preordeniterativo()

    def elemento_mayor(self):
        return self._elemento_mayor()

    def cantidadnodos(self):
        return self._cantidaddenodos()

    def cantidadhojas(self):
        return self._cantidaddehojas()
    
    def recorrido_enorden(self):
        self._recorrido_enorden()

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

    def _recorrido_preordeniterativo(self):
        pila = Pila.Pila()
        
        pila.push(self.root)

        while not pila.estaVacia():
            tmp = pila.pop()
            print(tmp.valor,end=" ")
            if tmp.right is not None:
                pila.push(tmp.right)
            if tmp.left is not None:
                pila.push(tmp.left)

    def _recorrido_enorden(self):
       pila = Pila.Pila()
       pila.push(self.root)
       actual = self.root
       while actual is not None:
            pila.push(actual)
            actual = actual.left
       if actual.left is not None:
           pila.push(actual);
           actual = actual.left
           print(actual.valor)

       if actual.right is not None:
        actual = actual.right
        actual = pila.pop()

       if actual is not None :
        print (actual.valor)
        actual = actual.right

           

        
    def _elemento_mayor(self):
        nodo = self.root
        cola = queue.Queue()

        cola.put(self.root)
        while not cola.empty():
            tmp = cola.get()
            if(tmp.valor > nodo.valor):
                nodo =  tmp
            if tmp.left is not None:
                cola.put(tmp.left)
            if tmp.right is not None:
                cola.put(tmp.right)
        return nodo

    def _cantidaddenodos(self):
        contador = 0
        cola = queue.Queue()

        cola.put(self.root)
        while not cola.empty():
            tmp = cola.get()
            contador = contador+1
            if tmp.left is not None:
                cola.put(tmp.left)
            if tmp.right is not None:
                cola.put(tmp.right)
        return contador

    def _cantidaddehojas(self):
        contador = 0
        cola = queue.Queue()

        cola.put(self.root)

        while not cola.empty():
            tmp = cola.get()
            if tmp.left is not None:
                cola.put(tmp.left)
            if tmp.right is not None:
                cola.put(tmp.right)
            if tmp.left is None and tmp.right is None:
                contador = contador+1

        return contador
        

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
    print()
    print("Recorrido Pre_Orden_Iterativo: ",end=" ")
    arbolito.recorrido_preordeniterativo()
    print()
    print("El nodo mayor es: ",end=" ")
    print(arbolito.elemento_mayor().valor)
    print("La cantidad de nodos es: ",end=" ")
    print(arbolito.cantidadnodos())
    print("La cantidad de hojas es: ",end=" ")
    print(arbolito.cantidadhojas())
    print("Recorrido en Orden iterativo es: ",end=" ")
    print(arbolito.recorrido_enorden())

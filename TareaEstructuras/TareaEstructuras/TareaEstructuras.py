import queue
import Pila

from queue import LifoQueue
from queue import Queue

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

    def imprimir(self,actual):
        self._imprimir(" ", actual, False)

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

    def crear_desde_archivo(self, nombre):
        try:
            handle = open(nombre, "r")
        except IOError:
            return None

        self.root = self._crear_desde_archivo(handle)

        handle.close()

        if self.root is None:
            return 0
        return 1

    def _crear_desde_archivo(self, handle):
        n = handle.readline()
        if int(n) == -1:
            return None

        tmp = Nodo(int(n))
        tmp.left = self._crear_desde_archivo(handle)
        tmp.right = self._crear_desde_archivo(handle)
        return tmp

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
       actual = self.root   

       while actual is not None:
            pila.push(actual)
            actual = actual.left
            while actual is None and pila.estaVacia() is False:
                 tmp = pila.pop()
                 print(tmp.valor,end=" ")
                 actual = tmp.right

    def _recorrido_enordenInverso(self):
       pila = Pila.Pila()
       actual = self.root   
       pila2 = Pila.Pila()

       while actual is not None:
            pila.push(actual)
            actual = actual.left
            while actual is None and pila.estaVacia() is False:
                 tmp = pila.pop()
                 pila2.push(tmp)
                 actual = tmp.right

       while pila2.estaVacia() is False:
           print(pila2.pop().valor,end=" ")
           
    


    def _esEspejo(self,nodoraiz1,nodoraiz2):
        contador = 0
        if nodoraiz1.valor != nodoraiz2.valor:
            return False
        else:
             cola = queue.Queue()
             cola.put(nodoraiz1)
             cola2 = queue.Queue()
             cola2.put(nodoraiz2)


             while not cola.empty() and not cola2.empty():
                 tmp = cola.get()
                 tmp2 = cola2.get()
                 if tmp.valor != tmp2.valor:
                     return False
                 if tmp.left is not None and tmp2.right is not None:
                       cola.put(tmp.left)
                       cola2.put(tmp2.right)
                 if tmp.right is not None and tmp2.left is not None:
                       cola.put(tmp.right)
                       cola2.put(tmp2.left)

             return True

    def _crear_arbolEspejo(self):
          Nuevo = self.root.valor
          Nuevo_arbol = Nodo(Nuevo)
          
          cola = queue.Queue()
          cola.put(self.root)

          cola2 = queue.Queue()
          cola2.put(Nuevo_arbol)

          while not cola.empty() and not cola2.empty():
              tmp = cola.get()
              tmp2 = cola2.get()

              if tmp.left is not None:
                  uno = Nodo(tmp.left.valor)
                  tmp2.right = uno
                  cola.put(tmp.left)
                  cola2.put(uno)
              if tmp.right is not None:
                  dos = Nodo(tmp.right.valor)
                  tmp2.left = dos
                  cola.put(tmp.right)
                  cola2.put(dos)
              
          return Nuevo_arbol

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

    def _recorridoPorNivelInverso(self):
        cola = queue.Queue()
        pila = Pila.Pila()
        cola.put(self.root)

        while not cola.empty():
            tmp = cola.get()
            pila.push(tmp)
            if tmp.left is not None:
                cola.put(tmp.left)
            if tmp.right is not None:
                cola.put(tmp.right)

        while pila.estaVacia() is False:
            print(pila.pop().valor,end = " ")

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
        
   
    def _sumaDeElementos(self):
        suma = 0
        cola = queue.Queue()

        if self.root is None:
            return 0

        cola.put(self.root)

        while not cola.empty():
            tmp = cola.get()
            suma = suma + tmp.valor
            
            if tmp.left is not None:
                cola.put(tmp.left)
            if tmp.right is not None:
                cola.put(tmp.right)
        return suma
            
    def _suma_deNivelMayor(self):
        suma = 0

        cola = queue.Queue()

        if self.root is None:
            return 0

        cola.put(self.root)

        while not cola.empty():
            tmp = cola.get()
            

            if tmp.left is not None:
                cola.put(tmp.left)
                suma = suma + tmp.left.valor
            if tmp.right is not None:
                cola.put(tmp.right)
                suma = suma + tmp.right.valor

    def _altura(self, actual):

         if actual is None:
               return -1
         max_izq = self._altura(actual.left) + 1

         max_der = self._altura(actual.right) + 1

         if max_izq > max_der:
            return max_izq
         return max_der
                                                                                
    def _diametro(self,root):                                                                                                               
         if root is None:
            return 0                    
         izq = self._diametro(root.left)
         der = self._diametro(root.right)

         return max(izq, der) + 1

    def _esOperando(self,valor):
        if valor == "+" or "-" + "/" + "*" + "%":
            return True
        return False

    def _ArbolExpresion(self,expresion):
        arbol = ArbolBinario()
        opc = bool(0)

        for i in range(len(expresion)):
           arbol.insertar(expresion[i])
        


        return arbol
    #este es el del profe
    def arbol_expresion(self, posfija):
        exp = self._construir_arbol_expresion(posfija)
        self._en_orden(exp)
        return exp

    def _construir_arbol_expresion(self, posfija):
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
        if op in ['+', '-', '*', '/', '^']:
            return True
        return False
  
    def _en_orden(self, root):
        if root is not None:
            self._en_orden(root.left)
            print(root.valor, end=' ')
            self._en_orden(root.right)

if __name__ == '__main__':
    arbolito = ArbolBinario()
    arbolito.insertar(3)
    arbolito.insertar(10)
    arbolito.insertar(2)    
    arbolito.insertar(38)
    arbolito.insertar(5)
    arbolito.insertar(12)
    arbolito.insertar(20)

    arbolito.imprimir(arbolito.root)
    print()

    print(arbolito._sumaDeElementos())

    arbolito._recorrido_enordenInverso()
    print()
    arbolito._recorridoPorNivelInverso()
    print()
    print("El diametro es: ", arbolito._diametro(arbolito.root))

    arbolito._ArbolExpresion("3+9/8")

    arbol2 = ArbolBinario()._ArbolExpresion("3+9/7")
    print()
    arbol2.imprimir(arbol2.root)
    print()
    

    arbolito.imprimir(arbolito.arbol_expresion("3+9/7"))

    # arbolito.imprimir(arbolito.root)
    #print()
    #print("Recorrido Pre_Orden_Iterativo: ",end=" ")
    #arbolito.recorrido_preordeniterativo()
    #print()
    #print("Recorrido en Orden iterativo es: ",end=" ")
    #arbolito.recorrido_enorden()
    #print()
    #print("El nodo mayor es: ",end=" ")
    #print(arbolito.elemento_mayor().valor)
    #print("La cantidad de nodos es: ",end=" ")
    #print(arbolito.cantidadnodos())
    #print("La cantidad de hojas es: ",end=" ")
    #print(arbolito.cantidadhojas())
   
    print()
    
    #arbolito1 = ArbolBinario()
    #arbolito1.crear_desde_archivo("espejo_a.txt")
    #print()
    #print("Arbol 1: ")
    #arbolito1.imprimir(arbolito1.root)

    #print()
    
    #arbolito2 = ArbolBinario()
    #arbolito2.crear_desde_archivo("espejo_b.txt")
    #print()
    #print("Arbol 2: ")
    #arbolito2.imprimir(arbolito2.root)

   # print()

    #if arbolito1._esEspejo(arbolito1.root,arbolito2.root) is True:
    #   print("El Arbol 1 es espejo del Arbol 2")
    #else:
    #    print("El Arbol 1 no es espejo del Arbol 2")

    #print()
    #print()
    #print()

    #print("El arbol espejo creado desde el metodo 'Crear arbol espejo' del Arbol 1 es:")
    #print()
    #arbolito1.imprimir(arbolito1._crear_arbolEspejo())
    #print()


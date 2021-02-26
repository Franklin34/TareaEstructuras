
class Nodo:
    def __init__(self, val=None):
        self.valor = val
        self.left = None
        self.right = None

class ArbolAVL:
    def __init__(self):
        self.root = None
    
    def insertar(self, val):
        self.root = self._insertar(self.root, val)

    def imprimir(self):
        self._imprimir(" ", self.root, False)

    def eliminar_nodo(self, nodo_buscar):
       self.root = self._eliminar_nodo(self.root, nodo_buscar)

    def _imprimir(self, p, root, es_izq):
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

    def _rotacion_izquierda(self, x):
        y = x.right
        x.right = y.left
        y.left = x
        return y

    def _rotacion_derecha(self, x):
        y = x.left
        x.left = y.right
        y.right = x
        return y

    def _rotacion_doble_izq_der(self, x):
        x.left = self._rotacion_izquierda(x.left)
        return self._rotacion_derecha(x)

    def _rotacion_doble_der_izq(self, x):
        x.right = self._rotacion_derecha(x.right)
        return self._rotacion_izquierda(x)
    def _altura(self, root):
        if root is None:
            return -1

        maxizq = self._altura(root.left) + 1
        maxder = self._altura(root.right) + 1

        if maxizq > maxder:
            return maxizq
        return maxder

    def _bucarrecur(self,root,key):
        if root.valor == key:
            return root
        if key < root.valor:
            return  self._bucarrecur(root.left,key)
        elif key > root.valor:
            return self._bucarrecur(root.right,key)

    def _insertar(self, root, key):
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

    def _max(self, root):
      
        if root is None:
            return None

        while root.right is not None:
            root = root.right
        return root

    def _eliminar_nodo(self, root, nodo_buscar):
        if root is None:
            return None

        if nodo_buscar.valor < root.valor:
            root.left = self._eliminar_nodo(root.left, nodo_buscar)
        elif nodo_buscar.valor > root.valor:
            root.right = self._eliminar_nodo(root.right, nodo_buscar)
        else:
            if root.left is None and root.right is None:
                root = None

            elif root.left is None:
                root = root.right

            elif root.right is None:
                root = root.left

            else:
                tmp = self._max(root.left)
                root.valor = tmp.valor
                root.left = self._eliminar_nodo(root.left, tmp)
        return root

if __name__ == '__main__':
    arbolito = ArbolAVL()
    arbolito.insertar(1)
    arbolito.insertar(2)
    arbolito.insertar(3)
    arbolito.insertar(4)
    arbolito.insertar(5)
    arbolito.insertar(6)
    arbolito.insertar(7)
    arbolito.imprimir()

    nodo_buscar = arbolito._bucarrecur(arbolito.root,6)

    arbolito.eliminar_nodo(nodo_buscar)

    arbolito.imprimir()



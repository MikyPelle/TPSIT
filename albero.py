import math
class Node():
    def __init__(self, val):
        self.val = val
        self.sinistro = None
        self.destro = None
        
    def inserisci(self, valore):
        if self.val is not None:
            pass
            if valore < self.val:
                if self.sinistro == None:
                    self.sinistro = Node(valore)
                else:
                    self.sinistro.inserisci(valore)
            
            elif valore > self.val:
                if self.destro == None:
                    self.destro = Node(valore)
                else:
                    self.destro.inserisci(valore)
        else:
            self.val = valore
            
    def stampa(self, lvl=0):
        if self.destro is not None:
            self.destro.stampa(lvl + 1)
        print("  " * lvl + str(self.val))
        if self.sinistro is not None:
            self.sinistro.stampa(lvl + 1)
            
    def find(self, val):
        if self.val is not None:
            if val == self.val:
                return True
            elif val < self.val and self.sinistro is not None:
                return self.sinistro.find(val)
            elif val > self.val and self.destro is not None:
                return self.destro.find(val)
            else:
                return False
        else:
            return False  
    
    def counterNode(self, contNod=-1):
        contNod+=1
        if self.sinistro is not None:
            contNod=self.sinistro.counterNode(contNod)
        if self.destro is not None:
            contNod=self.destro.counterNode(contNod)
        return contNod
    
    def findHeight(self, contL=-1, contR=-1):
        if self.sinistro is not None:
            contL=self.sinistro.findHeight(contL+1, contR)
        if self.destro is not None:
            contR=self.destro.findHeight(contL, contR+1)
        return max(contL, contR)
        
    def isBilanciato(self):
        return self.findHeight() == int(math.log2(self.counterNode()))
        
def returnMiddle(x):
    return (len(x)//2)

def inserisciBilanciato(lista, n):    
    centro = len(lista) // 2
    print(lista)
    n.inserisci(lista[centro])
    if centro != 0:
        listaSx = lista[0: centro]
        listaDx = lista[centro + 1:]
        if len(listaSx) > 0:
            inserisciBilanciato(listaSx, n)
        if len(listaDx) > 0:
            inserisciBilanciato(listaDx, n)    
    else:
        return None
        
def main():
    lista=[10,3,5,15,9,4,2]
    lista.sort()
    tree=Node(None)
    inserisciBilanciato(lista, tree)
    tree.stampa()
    print(tree.isBilanciato())
        
if __name__ == '__main__':
    main()
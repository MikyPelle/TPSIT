class Node():
    def __init__(self, val):
        self.val = val
        self.sinistro = None
        self.destro = None
    def inserisci(self, val):
        if self.val is not None:
            #capire se inserire valore in figlio sinistro o destro
            if val < self.val and self.sinistro is None:
                self.sinistro = Node(val)
            elif val < self.val and self.sinistro is not None:
                self.sinistro.inserisci(val)
            elif val > self.val and self.destro is None:
                self.destro = Node(val)
            elif val > self.val and self.destro is not None:
                self.destro.inserisci(val)
        else:
            self.val = val
    def stampa(self):
        if self.val is not None:
            if self.sinistro is not None:
                self.sinistro.stampa()
            print(self.val)
            if self.destro is not None:
                self.destro.stampa()
        else:
            print("Nessun elemento")
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
        
    def isAlberoBilanciato(nodi, n):
        return self.findHeight() == int(math.log2(self.counterNode()))
def alberoBilanciato(nodi, n):
    centro = len(nodi)//2
    if centro == 0:
        n.inserisci(nodi[centro])
        nodiSx = nodi[0:centro]
        nodiDx = nodi[centro+1:]
        alberoBilanciato(nodiSx,n)
        alberoBilanciato(nodiDx,n)
    else:
        return None
    

    
def main():
    nodi=[7, 15, 6, 2, 25, 30, 10, 22]
    nodi.sort()
    root = alberoBilanciato(nodi)
    root.stampa()
    
    
    """n = Node(5)
    n.inserisci(6)
    n.inserisci(2)
    n.inserisci(20)
    n.inserisci(28)
    n.inserisci(16)
    n.stampa()
    
    if(n.find(3)):
        print("Trovato")
    else:
        print("Non trovato")
    if(n.find(2)):
        print("Trovato")
    else:
        print("Non trovato")
    if(n.find(16)):
        print("Trovato")
    else:
        print("Non trovato")"""
    
if __name__ == '__main__':
    main()
import threading
#la password è formata da sole lettere minuscole (21) 
#ha N caratteri (N = 3)
N = 3
password = "giorgis"
alfabelto = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'z']

class MyThread(threading.Thread):
    def __init__(self, lettera):
        super().__init__()
        self.lettera = lettera
    def run(self):
        prova = self.lettera
        for l in alfabelto:
            for l2 in alfabelto:
                for l3 in alfabelto:
                    for l4 in alfabelto:
                        for l5 in alfabelto:
                            for l6 in alfabelto:
                                prova = self.lettera + l + l2 + l3 + l4 + l5 + l6
                                if prova == password:
                                    print("password: " + prova)
                                    break
def main():
    lista_thread = [MyThread(l) for l in alfabelto]
    for t in lista_thread:
        t.start()
if __name__ == "__main__":
    main()    

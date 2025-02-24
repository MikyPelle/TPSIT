import threading
import time

lock = threading.Lock()
semaforo = threading.Semaphore(2)

class StampaNome(threading.Thread):
    def __init__(self, nome):
        super().__init__()
        self.nome = nome
    def run(self):
        semaforo.acquire()
        for _ in range(5):
            #area critica
            print("Ciao ", end="")#non va a capo
            time.sleep(1)
            print(self.nome)
            #area critica
        semaforo.release()
    def Lock(self):
        lock.acquire()
        for _ in range(5):
            #area critica
            print("Ciao ", end="")#non va a capo
            time.sleep(1)
            print(self.nome)
            #area critica
        lock.release()

def main():
    nomi = ["Mario", "Luca", "Alice", "Bob"]
    listaThread = [StampaNome(nome) for nome in nomi]
    for thread in listaThread:
        thread.start()
    for thread in listaThread:
        thread.join()

if __name__ == '__main__':
    main()
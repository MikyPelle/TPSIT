import threading
import time

blocco = threading.Lock()
#saldo = 1000

class Prelievo(threading.Thread):
    def __init__(self, file, percentuale):
        super().__init__()
        self.percentuale = percentuale
        self.file = file
        self.running = True
    def run(self):
        global saldo #permette a questo metodo di modificare la variabile globale saldo, normalmente non è possibile farlo
        while self.running:
            with open(self.file, 'r') as f:
                saldo = float(f.readline())
            if saldo > 0:
                cifra = self.percentuale * (saldo / 100)
                time.sleep(1)
                
                blocco.acquire()
                saldo = saldo - cifra
                with open(self.file, 'w') as f:
                    f.write(str(saldo))
                blocco.release()
                print(f"il saldo aggiornato e': {saldo}")
                time.sleep(3)
            else:
                print(f"il saldo è in negativo")
                self.running = False
    def kill(self):
        self.running = False
                
def main():
    #la sezione critica di un thread è la parte porzione del codice in cui il thread
    #opera in scrittura sulla risorsa condivisa
    #luca = Prelievo(5)
    #mario = Prelievo(-6)
    #race condition 2 thread competono per lavorare sulla stessa variabile globale. vince il primo che arriva
    #luca.start()
    #mario.start()
    file = "prelievo.csv"
    perc_list = [5,-6]
    listaThread = [Prelievo(file,perc) for perc in perc_list]
    for thread in listaThread:
        thread.start()
    time.sleep(60)
    for thread in listaThread:
        thread.kill()
    for thread in listaThread:
        thread.join()
if __name__ == "__main__":
    main()
            
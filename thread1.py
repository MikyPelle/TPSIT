from threading import Thread
import time
class MioThread(Thread):
    def __init__(self, nome):
        super().__init__()
        self.nome = nome
        self.running = True
    def run(self):
        #codice del thread
        while self.running:
            print(f"Sono il thread {self.nome}")
            time.sleep(1)
    def kill(self):
        self.running = False
def main():
    """thread = MioThread("Prandi")
    thread1 = MioThread("Sborgis")
    thread.start()
    thread1.start()"""
    listaNomi = ["Alice", "Bob", "Trudy"]
    lista_threads = [MioThread(n) for n in listaNomi]
    for t in lista_threads:
        t.start()
    for _ in range(4):
        print("Sono il main thread")
    
    while True:
        print("Sono il main thread")
        time.sleep(1)
   
if __name__ == "__main__":
    main()
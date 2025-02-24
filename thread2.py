import threading
import time

class Magazzino:
    def __init__(self):
        self.merce = 0
        self.semaphore = threading.Semaphore(1)  # Inizializzazione del semaforo con valore 1 per garantire l'accesso esclusivo
        self.stop_event = threading.Event()  # Evento per segnalare ai thread di smettere di aggiungere merce

    def aggiungi_merce(self):
        while not self.stop_event.is_set():
            with self.semaphore:  # Acquisizione del semaforo prima di modificare la merce
                time.sleep(0.5)  # Simulazione di un processo che richiede del tempo per aggiungere la merce
                self.merce += 1
                print(f"Merce aggiunta. Totale nel magazzino: {self.merce}")

    def start(self):
        thread1 = threading.Thread(target=self.aggiungi_merce)  # Creazione del primo thread
        thread2 = threading.Thread(target=self.aggiungi_merce)  # Creazione del secondo thread

        thread1.start()  # Avvio del primo thread
        thread2.start()  # Avvio del secondo thread

        time.sleep(2)  # Pausa di 2 secondi

        self.stop_event.set()  # Segnalazione ai thread di smettere

        thread1.join()  # Attesa che il primo thread termini
        thread2.join()  # Attesa che il secondo thread termini

        print("Processi di aggiunta merce completati.")

# Utilizzo della classe Magazzino, creando un'istanza della classe e avviando il processo di aggiunta merce
magazzino = Magazzino()
magazzino.start()  # Avvio del programma
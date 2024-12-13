#include <iostream>

template <typename T>
class AlberoBinario {
private:
    T nodi[100];  // Array x nodi
    bool esiste[100];  // Array per tenere traccia dei nodi 

public:
    AlberoBinario() {
        // Inizializzo tutti i nodi
        for (int i = 0; i < 100; ++i) {
            esiste[i] = false;
        }
    }

    bool alberoVuoto() const {
        // Se la radice non esiste, l'albero è vuoto
        return !esiste[0];
    }

    void insRadice(const T& valore) {
        if (!esiste[0]) {
            nodi[0] = valore;
            esiste[0] = true;
        } else {
            std::cout << "La radice esiste!" << std::endl;
        }
    }

    T radice() const {
        if (esiste[0]) {
            return nodi[0];
        }
        std::cout << "L'albero è vuoto" << std::endl;
        return T();  // Restituisco un valore di default
    }

    bool isFoglia(int indice) const {
        int sinistro = 2 * indice + 1;
        int destro = 2 * indice + 2;
        // Un nodo è foglia se non ha figli
        return (sinistro >= 100 || !esiste[sinistro]) && (destro >= 100 || !esiste[destro]);
    }

    int figlioSinistro(int indice) const {
        int sinistro = 2 * indice + 1;
        if (sinistro < 100 && esiste[sinistro]) {
            return sinistro;
        }
        std::cout << "Il figlio sx non esiste" << std::endl;
        return -1;  // Restituisco un valore non valido per indicare l'errore
    }

    int figlioDestro(int indice) const {
        int destro = 2 * indice + 2;
        if (destro < 100 && esiste[destro]) {
            return destro;
        }
        std::cout << "Il figlio dx non esiste" << std::endl;
        return -1;  // Restituisco un valore non valido per indicare l'errore
    }

    void insFiglioSinistro(int indice, const T& valore) {
        int sinistro = 2 * indice + 1;
        if (sinistro < 100 && !esiste[sinistro]) {
            nodi[sinistro] = valore;
            esiste[sinistro] = true;
        } else {
            std::cout << "Impossibile aggiungere figlio sx" << std::endl;
        }
    }

    void insFiglioDestro(int indice, const T& valore) {
        int destro = 2 * indice + 2;
        if (destro < 100 && !esiste[destro]) {
            nodi[destro] = valore;
            esiste[destro] = true;
        } else {
            std::cout << "Impossibile aggiungere figlio dx" << std::endl;
        }
    }

    void rimuovi(int indice) {
        if (isFoglia(indice)) {
            esiste[indice] = false;  // Rimuovo il nodo 
        } else {
            std::cout << "Impossibile rimuovere il nodo!" << std::endl;
        }
    }

    void stampa() const {           
        for (int i = 0; i < 100; ++i) {
            if (esiste[i]) {
                int sinistro = 2 * i + 1;
                int destro = 2 * i + 2;
                std::cout << "Pos " << i << ", Valore: " << nodi[i]
                          << ", Figliosx: " << (sinistro < 100 && esiste[sinistro] ? std::to_string(nodi[sinistro]) : "Nessuno")
                          << ", Figliodx: " << (destro < 100 && esiste[destro] ? std::to_string(nodi[destro]) : "Nessuno") << std::endl;
            }
        }
    }
};
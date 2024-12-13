#include <iostream>
#include "albero.cpp"

int main() {
    AlberoBinario<int> albero;

    
    albero.insRadice(10); //creo

    // Inserisco
    albero.insFiglioSinistro(0, 5);
    albero.insFiglioDestro(0, 20);

    albero.insFiglioSinistro(1, 3);
    albero.insFiglioDestro(1, 7);

    // Stampo
    std::cout << "Struttura dell'albero:" << std::endl;
    albero.stampa();
//qua si effettua la rimozione
    std::cout << "\n Rimozione nodo indice 3 (foglia):" << std::endl;
    albero.rimuovi(3);

    // Stampa dopo rimozione
    std::cout << "\n Struttura dell'albero dopo rimozione:" << std::endl;
    albero.stampa();

    return 0;
}

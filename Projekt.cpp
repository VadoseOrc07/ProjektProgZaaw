#include "ListaDwukierunkowa.h"

#include <iostream>

int main() {
    ListaDwukierunkowa lista;

    std::cout << "=== Lista dwukierunkowa ===\n";
    lista.wyswietlListe();

    std::cout << "Liczba elementow: " << lista.rozmiar() << '\n';

    return 0;
}

#include "ListaDwukierunkowa.h"

#include <iostream>

int main() {
    ListaDwukierunkowa lista;

    std::cout << "=== Dodawanie elementow ===\n";

    lista.dodajNaKoniec("B");
    lista.dodajNaKoniec("D");
    lista.dodajPodIndeksem(1, "C");
    lista.dodajPodIndeksem(0, "A");
    lista.dodajPodIndeksem(lista.rozmiar(), "E");

    lista.wyswietlListe();
    std::cout << "Rozmiar listy: " << lista.rozmiar() << "\n\n";

    std::cout << "=== Usuwanie elementow ===\n";

    lista.usunZPoczatku();
    lista.wyswietlListe();

    lista.usunZKonca();
    lista.wyswietlListe();

    lista.usunPodIndeksem(1);
    lista.wyswietlListe();

    std::cout << "Rozmiar listy: " << lista.rozmiar() << "\n\n";

    std::cout << "=== Test nieprawidlowego indeksu ===\n";

    if (!lista.dodajPodIndeksem(100, "Blad")) {
        std::cout << "Dodawanie pod nieprawidlowym indeksem odrzucone.\n";
    }

    if (!lista.usunPodIndeksem(100)) {
        std::cout << "Usuwanie pod nieprawidlowym indeksem odrzucone.\n";
    }

    std::cout << "\n=== Czyszczenie listy ===\n";

    lista.wyczysc();
    lista.wyswietlListe();

    std::cout << "Czy lista jest pusta? "
              << (lista.czyPusta() ? "Tak" : "Nie") << '\n';

    std::cout << "Usuwanie z pustej listy: "
              << (lista.usunZPoczatku() ? "Sukces" : "Brak elementu")
              << '\n';

    return 0;
}
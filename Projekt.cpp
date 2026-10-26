#include "ListaDwukierunkowa.h"
#include "IteratorListy.h"
#include "ListaFactory.h"

#include <iostream>

int main() {
    auto lista = ListaFactory::utworzListe();

    std::cout << "=== Dodawanie elementow ===\n";

    lista->dodajNaKoniec("B");
    lista->dodajNaKoniec("D");
    lista->dodajPodIndeksem(1, "C");
    lista->dodajPodIndeksem(0, "A");
    lista->dodajPodIndeksem(lista->rozmiar(), "E");

    lista->wyswietlListe();
    std::cout << "Rozmiar listy: " << lista->rozmiar() << "\n\n";

    std::cout << "=== Usuwanie elementow ===\n";

    lista->usunZPoczatku();
    lista->wyswietlListe();

    lista->usunZKonca();
    lista->wyswietlListe();

    lista->usunPodIndeksem(1);
    lista->wyswietlListe();

    std::cout << "Rozmiar listy: " << lista->rozmiar() << "\n\n";

    std::cout << "=== Test nieprawidlowego indeksu ===\n";

    if (!lista->dodajPodIndeksem(100, "Blad")) {
        std::cout << "Dodawanie pod nieprawidlowym indeksem odrzucone.\n";
    }

    if (!lista->usunPodIndeksem(100)) {
        std::cout << "Usuwanie pod nieprawidlowym indeksem odrzucone.\n";
    }

    std::cout << "\n=== Iterator: przejscie do przodu ===\n";

    IteratorListy iterator(*lista);

    while (iterator.czyWazny()) {
        const std::string* wartosc = iterator.pobierzWartosc();

        if (wartosc != nullptr) {
            std::cout << *wartosc;
        }

        if (!iterator.przejdzDoNastepnego()) {
            break;
        }

        std::cout << " <-> ";
    }

    std::cout << "\n\n=== Iterator: przejscie do tylu ===\n";

    IteratorListy iteratorOdKonca(*lista, true);

    while (iteratorOdKonca.czyWazny()) {
        const std::string* wartosc = iteratorOdKonca.pobierzWartosc();

        if (wartosc != nullptr) {
            std::cout << *wartosc;
        }

        if (!iteratorOdKonca.przejdzDoPoprzedniego()) {
            break;
        }

        std::cout << " <-> ";
    }

    std::cout << "\n\n=== Iterator: nastepny i poprzedni ===\n";

    IteratorListy iteratorRuchu(*lista);

    if (iteratorRuchu.czyWazny()) {
        std::cout << "Aktualny element: "
                  << *iteratorRuchu.pobierzWartosc() << '\n';

        if (iteratorRuchu.przejdzDoNastepnego()) {
            std::cout << "Nastepny element: "
                      << *iteratorRuchu.pobierzWartosc() << '\n';
        }

        if (iteratorRuchu.przejdzDoPoprzedniego()) {
            std::cout << "Poprzedni element: "
                      << *iteratorRuchu.pobierzWartosc() << '\n';
        }
    }

    std::cout << "\n=== Czyszczenie listy ===\n";

    lista->wyczysc();
    lista->wyswietlListe();

    std::cout << "Czy lista jest pusta? "
              << (lista->czyPusta() ? "Tak" : "Nie") << '\n';

    std::cout << "Usuwanie z pustej listy: "
              << (lista->usunZPoczatku() ? "Sukces" : "Brak elementu")
              << '\n';

    return 0;
}
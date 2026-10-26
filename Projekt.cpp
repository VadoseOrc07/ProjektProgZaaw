/**
 * @file Projekt.cpp
 * @brief Glowny plik programu listy dwukierunkowej.
 */

#include "ListaDwukierunkowa.h"
#include "IteratorListy.h"
#include "ListaFactory.h"

#include <iostream>
#include <sstream>
#include <string>

/**
 * @brief Pobiera liczbe calkowita od uzytkownika.
 * @param komunikat Tekst wyswietlany przed pobraniem danych.
 * @param wynik Zmienna, do ktorej zostanie zapisana liczba.
 * @return true, jesli pobrano liczbe; false, jesli zakonczono wejscie.
 */
bool pobierzLiczbe(const std::string& komunikat, long long& wynik) {
    while (true) {
        std::cout << komunikat;

        std::string linia;

        if (!std::getline(std::cin, linia)) {
            return false;
        }

        std::istringstream strumien(linia);
        char dodatkowyZnak;

        if ((strumien >> wynik) && !(strumien >> dodatkowyZnak)) {
            return true;
        }

        std::cout << "Niepoprawna liczba. Sprobuj ponownie.\n";
    }
}

/**
 * @brief Pobiera niepusty tekst od uzytkownika.
 * @param komunikat Tekst wyswietlany przed pobraniem danych.
 * @param tekst Zmienna, do ktorej zostanie zapisany tekst.
 * @return true, jesli pobrano tekst; false, jesli zakonczono wejscie.
 */
bool pobierzTekst(const std::string& komunikat, std::string& tekst) {
    while (true) {
        std::cout << komunikat;

        if (!std::getline(std::cin, tekst)) {
            return false;
        }

        if (!tekst.empty()) {
            return true;
        }

        std::cout << "Tekst nie moze byc pusty.\n";
    }
}

/**
 * @brief Wyswietla menu glowne programu.
 */
void wyswietlMenu() {
    std::cout << "\n========== LISTA DWUKIERUNKOWA ==========\n";
    std::cout << "1. Dodaj element na poczatek listy\n";
    std::cout << "2. Dodaj element na koniec listy\n";
    std::cout << "3. Dodaj element pod wskazany indeks\n";
    std::cout << "4. Usun element z poczatku listy\n";
    std::cout << "5. Usun element z konca listy\n";
    std::cout << "6. Usun element pod wskazanym indeksem\n";
    std::cout << "7. Wyswietl cala liste\n";
    std::cout << "8. Wyswietl liste w odwrotnej kolejnosci\n";
    std::cout << "9. Wyswietl nastepny element\n";
    std::cout << "10. Wyswietl poprzedni element\n";
    std::cout << "11. Wyswietl aktualny element iteratora\n";
    std::cout << "12. Wyczysc cala liste\n";
    std::cout << "0. Zakoncz program\n";
    std::cout << "=========================================\n";
}

/**
 * @brief Uruchamia program i obsluguje menu uzytkownika.
 * @return Kod zakonczenia programu.
 */
int main() {
    auto lista = ListaFactory::utworzListe();
    IteratorListy iterator(*lista);

    long long wybor;

    while (true) {
        wyswietlMenu();

        if (!pobierzLiczbe("Wybierz opcje: ", wybor)) {
            break;
        }

        switch (wybor) {
            case 1: {
                std::string wartosc;

                if (!pobierzTekst("Podaj wartosc: ", wartosc)) {
                    return 0;
                }

                lista->dodajNaPoczatek(wartosc);
                iterator.ustawNaPoczatku();

                std::cout << "Dodano element na poczatku listy.\n";
                break;
            }

            case 2: {
                std::string wartosc;

                if (!pobierzTekst("Podaj wartosc: ", wartosc)) {
                    return 0;
                }

                lista->dodajNaKoniec(wartosc);
                iterator.ustawNaPoczatku();

                std::cout << "Dodano element na koncu listy.\n";
                break;
            }

            case 3: {
                long long indeks;
                std::string wartosc;

                if (!pobierzLiczbe("Podaj indeks: ", indeks)) {
                    return 0;
                }

                if (indeks < 0) {
                    std::cout << "Indeks nie moze byc ujemny.\n";
                    break;
                }

                if (!pobierzTekst("Podaj wartosc: ", wartosc)) {
                    return 0;
                }

                bool sukces = lista->dodajPodIndeksem(
                    static_cast<std::size_t>(indeks),
                    wartosc
                );

                if (sukces) {
                    iterator.ustawNaPoczatku();
                    std::cout << "Dodano element.\n";
                } else {
                    std::cout << "Nieprawidlowy indeks.\n";
                }

                break;
            }

            case 4: {
                if (lista->usunZPoczatku()) {
                    iterator.ustawNaPoczatku();
                    std::cout << "Usunieto pierwszy element.\n";
                } else {
                    std::cout << "Lista jest pusta.\n";
                }

                break;
            }

            case 5: {
                if (lista->usunZKonca()) {
                    iterator.ustawNaPoczatku();
                    std::cout << "Usunieto ostatni element.\n";
                } else {
                    std::cout << "Lista jest pusta.\n";
                }

                break;
            }

            case 6: {
                long long indeks;

                if (!pobierzLiczbe("Podaj indeks: ", indeks)) {
                    return 0;
                }

                if (indeks < 0) {
                    std::cout << "Indeks nie moze byc ujemny.\n";
                    break;
                }

                if (lista->usunPodIndeksem(
                        static_cast<std::size_t>(indeks))) {
                    iterator.ustawNaPoczatku();
                    std::cout << "Usunieto element.\n";
                } else {
                    std::cout << "Nieprawidlowy indeks lub pusta lista.\n";
                }

                break;
            }

            case 7: {
                std::cout << "Lista: ";
                lista->wyswietlListe();
                std::cout << "Liczba elementow: "
                          << lista->rozmiar() << '\n';
                break;
            }

            case 8: {
                IteratorListy odwrotny(*lista, true);

                if (!odwrotny.czyWazny()) {
                    std::cout << "Lista jest pusta.\n";
                    break;
                }

                std::cout << "Lista od konca: ";

                while (true) {
                    const std::string* wartosc =
                        odwrotny.pobierzWartosc();

                    if (wartosc != nullptr) {
                        std::cout << *wartosc;
                    }

                    if (!odwrotny.przejdzDoPoprzedniego()) {
                        break;
                    }

                    std::cout << " <-> ";
                }

                std::cout << '\n';
                break;
            }

            case 9: {
                if (iterator.przejdzDoNastepnego()) {
                    std::cout << "Nastepny element: "
                              << *iterator.pobierzWartosc() << '\n';
                } else {
                    std::cout << "Brak nastepnego elementu.\n";
                }

                break;
            }

            case 10: {
                if (iterator.przejdzDoPoprzedniego()) {
                    std::cout << "Poprzedni element: "
                              << *iterator.pobierzWartosc() << '\n';
                } else {
                    std::cout << "Brak poprzedniego elementu.\n";
                }

                break;
            }

            case 11: {
                const std::string* wartosc = iterator.pobierzWartosc();

                if (wartosc != nullptr) {
                    std::cout << "Aktualny element: " << *wartosc << '\n';
                } else {
                    std::cout << "Iterator nie wskazuje elementu.\n";
                }

                break;
            }

            case 12: {
                lista->wyczysc();
                iterator.ustawNaPoczatku();

                std::cout << "Lista zostala wyczyszczona.\n";
                break;
            }

            case 0:
                std::cout << "Koniec programu.\n";
                return 0;

            default:
                std::cout << "Nieznana opcja. Wybierz liczbe od 0 do 12.\n";
                break;
        }
    }

    std::cout << "\nKoniec programu.\n";
    return 0;
}
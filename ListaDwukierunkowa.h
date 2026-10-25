/**
 * @file ListaDwukierunkowa.h
 * @brief Deklaracja klasy zarządzającej listą dwukierunkową.
 */

#ifndef LISTA_DWUKIERUNKOWA_H
#define LISTA_DWUKIERUNKOWA_H

#include <cstddef>
#include <string>

class Wezel;

/**
 * @class ListaDwukierunkowa
 * @brief Zarządza elementami własnej listy dwukierunkowej.
 *
 * Lista przechowuje wskaźniki na początek i koniec oraz
 * aktualną liczbę elementów.
 */
class ListaDwukierunkowa {
private:
    Wezel* poczatek_;
    Wezel* koniec_;
    std::size_t rozmiar_;

    /**
     * @brief Zwraca węzeł o podanym indeksie.
     * @param indeks Indeks elementu, liczony od zera.
     * @return Wskaźnik na węzeł lub nullptr, jeśli indeks jest nieprawidłowy.
     */
    Wezel* pobierzWezel(std::size_t indeks) const;

public:
    /**
     * @brief Tworzy pustą listę.
     */
    ListaDwukierunkowa();

    /**
     * @brief Zwalnia pamięć zajmowaną przez elementy listy.
     */
    ~ListaDwukierunkowa();

    ListaDwukierunkowa(const ListaDwukierunkowa&) = delete;
    ListaDwukierunkowa& operator=(const ListaDwukierunkowa&) = delete;

    /**
     * @brief Dodaje element na początku listy.
     * @param wartosc Wartość nowego elementu.
     */
    void dodajNaPoczatek(const std::string& wartosc);

    /**
     * @brief Dodaje element na końcu listy.
     * @param wartosc Wartość nowego elementu.
     */
    void dodajNaKoniec(const std::string& wartosc);

    /**
     * @brief Dodaje element pod wskazanym indeksem.
     * @param indeks Pozycja nowego elementu, liczona od zera.
     * @param wartosc Wartość nowego elementu.
     * @return true, jeśli element został dodany; w przeciwnym razie false.
     */
    bool dodajPodIndeksem(std::size_t indeks, const std::string& wartosc);

    /**
     * @brief Usuwa pierwszy element listy.
     * @return true, jeśli element został usunięty; w przeciwnym razie false.
     */
    bool usunZPoczatku();

    /**
     * @brief Usuwa ostatni element listy.
     * @return true, jeśli element został usunięty; w przeciwnym razie false.
     */
    bool usunZKonca();

    /**
     * @brief Usuwa element o wskazanym indeksie.
     * @param indeks Indeks elementu, liczony od zera.
     * @return true, jeśli element został usunięty; w przeciwnym razie false.
     */
    bool usunPodIndeksem(std::size_t indeks);

    /**
     * @brief Usuwa wszystkie elementy listy.
     */
    void wyczysc();

    /**
     * @brief Wyświetla elementy listy od początku do końca.
     */
    void wyswietlListe() const;

    /**
     * @brief Zwraca liczbę elementów listy.
     * @return Aktualna liczba elementów.
     */
    std::size_t rozmiar() const;

    /**
     * @brief Sprawdza, czy lista jest pusta.
     * @return true, jeśli lista jest pusta.
     */
    bool czyPusta() const;
};

#endif
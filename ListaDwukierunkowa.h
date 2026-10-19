#ifndef LISTA_DWUKIERUNKOWA_H
#define LISTA_DWUKIERUNKOWA_H

#include <cstddef>

class Wezel;

class ListaDwukierunkowa {
private:
    Wezel* poczatek_;
    Wezel* koniec_;
    std::size_t rozmiar_;

public:
    ListaDwukierunkowa();
    ~ListaDwukierunkowa();

    ListaDwukierunkowa(const ListaDwukierunkowa&) = delete;
    ListaDwukierunkowa& operator=(const ListaDwukierunkowa&) = delete;

    void wyczysc();
    void wyswietlListe() const;

    std::size_t rozmiar() const;
    bool czyPusta() const;
};

#endif
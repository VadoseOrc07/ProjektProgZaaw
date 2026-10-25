/**
 * @file ListaDwukierunkowa.cpp
 * @brief Implementacja operacji na liście dwukierunkowej.
 */

#include "ListaDwukierunkowa.h"
#include "Wezel.h"

#include <iostream>

ListaDwukierunkowa::ListaDwukierunkowa()
    : poczatek_(nullptr), koniec_(nullptr), rozmiar_(0) {
}

ListaDwukierunkowa::~ListaDwukierunkowa() {
    wyczysc();
}

Wezel* ListaDwukierunkowa::pobierzWezel(std::size_t indeks) const {
    if (indeks >= rozmiar_) {
        return nullptr;
    }

    if (indeks < rozmiar_ / 2) {
        Wezel* aktualny = poczatek_;

        for (std::size_t i = 0; i < indeks; ++i) {
            aktualny = aktualny->pobierzNastepny();
        }

        return aktualny;
    }

    Wezel* aktualny = koniec_;

    for (std::size_t i = rozmiar_ - 1; i > indeks; --i) {
        aktualny = aktualny->pobierzPoprzedni();
    }

    return aktualny;
}

void ListaDwukierunkowa::dodajNaPoczatek(const std::string& wartosc) {
    Wezel* nowy = new Wezel(wartosc);

    nowy->ustawNastepny(poczatek_);

    if (poczatek_ != nullptr) {
        poczatek_->ustawPoprzedni(nowy);
    } else {
        koniec_ = nowy;
    }

    poczatek_ = nowy;
    ++rozmiar_;
}

void ListaDwukierunkowa::dodajNaKoniec(const std::string& wartosc) {
    Wezel* nowy = new Wezel(wartosc);

    nowy->ustawPoprzedni(koniec_);

    if (koniec_ != nullptr) {
        koniec_->ustawNastepny(nowy);
    } else {
        poczatek_ = nowy;
    }

    koniec_ = nowy;
    ++rozmiar_;
}

bool ListaDwukierunkowa::dodajPodIndeksem(
    std::size_t indeks,
    const std::string& wartosc
) {
    if (indeks > rozmiar_) {
        return false;
    }

    if (indeks == 0) {
        dodajNaPoczatek(wartosc);
        return true;
    }

    if (indeks == rozmiar_) {
        dodajNaKoniec(wartosc);
        return true;
    }

    Wezel* aktualny = pobierzWezel(indeks);
    Wezel* poprzedni = aktualny->pobierzPoprzedni();
    Wezel* nowy = new Wezel(wartosc);

    nowy->ustawPoprzedni(poprzedni);
    nowy->ustawNastepny(aktualny);

    poprzedni->ustawNastepny(nowy);
    aktualny->ustawPoprzedni(nowy);

    ++rozmiar_;
    return true;
}

bool ListaDwukierunkowa::usunZPoczatku() {
    if (poczatek_ == nullptr) {
        return false;
    }

    Wezel* doUsuniecia = poczatek_;
    poczatek_ = poczatek_->pobierzNastepny();

    if (poczatek_ != nullptr) {
        poczatek_->ustawPoprzedni(nullptr);
    } else {
        koniec_ = nullptr;
    }

    delete doUsuniecia;
    --rozmiar_;

    return true;
}

bool ListaDwukierunkowa::usunZKonca() {
    if (koniec_ == nullptr) {
        return false;
    }

    Wezel* doUsuniecia = koniec_;
    koniec_ = koniec_->pobierzPoprzedni();

    if (koniec_ != nullptr) {
        koniec_->ustawNastepny(nullptr);
    } else {
        poczatek_ = nullptr;
    }

    delete doUsuniecia;
    --rozmiar_;

    return true;
}

bool ListaDwukierunkowa::usunPodIndeksem(std::size_t indeks) {
    Wezel* doUsuniecia = pobierzWezel(indeks);

    if (doUsuniecia == nullptr) {
        return false;
    }

    if (doUsuniecia == poczatek_) {
        return usunZPoczatku();
    }

    if (doUsuniecia == koniec_) {
        return usunZKonca();
    }

    Wezel* poprzedni = doUsuniecia->pobierzPoprzedni();
    Wezel* nastepny = doUsuniecia->pobierzNastepny();

    poprzedni->ustawNastepny(nastepny);
    nastepny->ustawPoprzedni(poprzedni);

    delete doUsuniecia;
    --rozmiar_;

    return true;
}

void ListaDwukierunkowa::wyczysc() {
    while (poczatek_ != nullptr) {
        Wezel* doUsuniecia = poczatek_;
        poczatek_ = poczatek_->pobierzNastepny();

        if (poczatek_ != nullptr) {
            poczatek_->ustawPoprzedni(nullptr);
        }

        delete doUsuniecia;
    }

    koniec_ = nullptr;
    rozmiar_ = 0;
}

void ListaDwukierunkowa::wyswietlListe() const {
    if (poczatek_ == nullptr) {
        std::cout << "Lista jest pusta.\n";
        return;
    }

    const Wezel* aktualny = poczatek_;

    while (aktualny != nullptr) {
        std::cout << aktualny->pobierzWartosc();

        if (aktualny->pobierzNastepny() != nullptr) {
            std::cout << " <-> ";
        }

        aktualny = aktualny->pobierzNastepny();
    }

    std::cout << '\n';
}

std::size_t ListaDwukierunkowa::rozmiar() const {
    return rozmiar_;
}

bool ListaDwukierunkowa::czyPusta() const {
    return poczatek_ == nullptr;
}
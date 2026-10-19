#include "ListaDwukierunkowa.h"
#include "Wezel.h"

#include <iostream>

ListaDwukierunkowa::ListaDwukierunkowa()
    : poczatek_(nullptr), koniec_(nullptr), rozmiar_(0) {
}

ListaDwukierunkowa::~ListaDwukierunkowa() {
    wyczysc();
}

void ListaDwukierunkowa::wyczysc() {
    while (poczatek_ != nullptr) {
        Wezel* doUsuniecia = poczatek_;
        poczatek_ = poczatek_->pobierzNastepny();
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
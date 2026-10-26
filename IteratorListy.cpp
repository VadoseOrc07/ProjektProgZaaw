/**
* @file IteratorListy.cpp
 * @brief Implementacja iteratora listy dwukierunkowej.
 */

#include "IteratorListy.h"
#include "ListaDwukierunkowa.h"
#include "Wezel.h"

IteratorListy::IteratorListy(
    const ListaDwukierunkowa& lista,
    bool odKonca
)
    : lista_(&lista),
      aktualny_(odKonca ? lista.koniec_ : lista.poczatek_) {
}

bool IteratorListy::ustawNaPoczatku() {
    aktualny_ = lista_->poczatek_;
    return aktualny_ != nullptr;
}

bool IteratorListy::ustawNaKoncu() {
    aktualny_ = lista_->koniec_;
    return aktualny_ != nullptr;
}

bool IteratorListy::przejdzDoNastepnego() {
    if (aktualny_ == nullptr ||
        aktualny_->pobierzNastepny() == nullptr) {
        return false;
        }

    aktualny_ = aktualny_->pobierzNastepny();
    return true;
}

bool IteratorListy::przejdzDoPoprzedniego() {
    if (aktualny_ == nullptr ||
        aktualny_->pobierzPoprzedni() == nullptr) {
        return false;
        }

    aktualny_ = aktualny_->pobierzPoprzedni();
    return true;
}

const std::string* IteratorListy::pobierzWartosc() const {
    if (aktualny_ == nullptr) {
        return nullptr;
    }

    return &aktualny_->pobierzWartosc();
}

bool IteratorListy::czyWazny() const {
    return aktualny_ != nullptr;
}
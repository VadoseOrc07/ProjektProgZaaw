#include "Wezel.h"

Wezel::Wezel(const std::string& wartosc)
    : wartosc_(wartosc), poprzedni_(nullptr), nastepny_(nullptr) {
}

const std::string& Wezel::pobierzWartosc() const {
    return wartosc_;
}

Wezel* Wezel::pobierzPoprzedni() const {
    return poprzedni_;
}

Wezel* Wezel::pobierzNastepny() const {
    return nastepny_;
}

void Wezel::ustawPoprzedni(Wezel* poprzedni) {
    poprzedni_ = poprzedni;
}

void Wezel::ustawNastepny(Wezel* nastepny) {
    nastepny_ = nastepny;
}
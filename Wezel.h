#ifndef WEZEL_H
#define WEZEL_H

#include <string>

class Wezel {
private:
    std::string wartosc_;
    Wezel* poprzedni_;
    Wezel* nastepny_;

public:
    explicit Wezel(const std::string& wartosc);

    const std::string& pobierzWartosc() const;
    Wezel* pobierzPoprzedni() const;
    Wezel* pobierzNastepny() const;

    void ustawPoprzedni(Wezel* poprzedni);
    void ustawNastepny(Wezel* nastepny);
};

#endif
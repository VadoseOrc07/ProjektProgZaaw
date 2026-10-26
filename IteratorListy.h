/**
* @file IteratorListy.h
 * @brief Deklaracja iteratora listy dwukierunkowej.
 */

#ifndef ITERATOR_LISTY_H
#define ITERATOR_LISTY_H

#include <string>

class ListaDwukierunkowa;
class Wezel;

/**
 * @class IteratorListy
 * @brief Umożliwia przechodzenie po elementach listy.
 *
 * Iterator przechowuje wskaźnik na aktualny węzeł
 * i pozwala poruszać się w obu kierunkach.
 */
class IteratorListy {
private:
    const ListaDwukierunkowa* lista_;
    Wezel* aktualny_;

public:
    /**
     * @brief Tworzy iterator wskazujący początek lub koniec listy.
     * @param lista Lista, po której porusza się iterator.
     * @param odKonca Jeśli true, iterator zaczyna od końca listy.
     */
    explicit IteratorListy(
        const ListaDwukierunkowa& lista,
        bool odKonca = false
    );

    /**
     * @brief Ustawia iterator na początku listy.
     * @return true, jeśli lista nie jest pusta.
     */
    bool ustawNaPoczatku();

    /**
     * @brief Ustawia iterator na końcu listy.
     * @return true, jeśli lista nie jest pusta.
     */
    bool ustawNaKoncu();

    /**
     * @brief Przesuwa iterator do następnego elementu.
     * @return true, jeśli udało się przesunąć iterator.
     */
    bool przejdzDoNastepnego();

    /**
     * @brief Przesuwa iterator do poprzedniego elementu.
     * @return true, jeśli udało się przesunąć iterator.
     */
    bool przejdzDoPoprzedniego();

    /**
     * @brief Pobiera wartość aktualnego elementu.
     * @return Wskaźnik na wartość lub nullptr, jeśli iterator jest nieważny.
     */
    const std::string* pobierzWartosc() const;

    /**
     * @brief Sprawdza, czy iterator wskazuje element.
     * @return true, jeśli iterator wskazuje istniejący węzeł.
     */
    bool czyWazny() const;
};

#endif
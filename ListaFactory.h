/**
* @file ListaFactory.h
 * @brief Deklaracja fabryki list dwukierunkowych.
 */

#ifndef LISTA_FACTORY_H
#define LISTA_FACTORY_H

#include <memory>

class ListaDwukierunkowa;

/**
 * @class ListaFactory
 * @brief Tworzy obiekty listy dwukierunkowej.
 */
class ListaFactory {
public:
    /**
     * @brief Tworzy nową listę dwukierunkową.
     * @return Wskaźnik zarządzający utworzoną listą.
     */
    static std::unique_ptr<ListaDwukierunkowa> utworzListe();
};

#endif
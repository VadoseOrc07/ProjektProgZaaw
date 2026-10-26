/**
* @file ListaFactory.cpp
 * @brief Implementacja fabryki list dwukierunkowych.
 */

#include "ListaFactory.h"
#include "ListaDwukierunkowa.h"

std::unique_ptr<ListaDwukierunkowa> ListaFactory::utworzListe() {
    return std::make_unique<ListaDwukierunkowa>();
}
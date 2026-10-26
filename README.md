# Lista dwukierunkowa w C++

## Opis projektu

Projekt przedstawia implementację dynamicznej listy
dwukierunkowej w języku C++.

Lista przechowuje tekstowe wartości w węzłach
alokowanych dynamicznie na stercie. Każdy węzeł
zawiera wskaźniki na poprzedni i następny element.

W projekcie zastosowano wzorzec projektowy Factory
oraz własną implementację iteratora.

## Funkcjonalności

- Dodawanie elementu na początku listy.
- Dodawanie elementu na końcu listy.
- Dodawanie elementu pod wskazanym indeksem.
- Usuwanie pierwszego elementu.
- Usuwanie ostatniego elementu.
- Usuwanie elementu pod wskazanym indeksem.
- Wyświetlanie listy w przód i w odwrotnej kolejności.
- Przechodzenie do następnego i poprzedniego elementu.
- Czyszczenie całej listy.
- Obsługa nieprawidłowych indeksów i pustej listy.

## Struktura projektu

- `Wezel.h`, `Wezel.cpp` – reprezentacja pojedynczego węzła.
- `ListaDwukierunkowa.h`, `ListaDwukierunkowa.cpp` –
  zarządzanie listą i jej elementami.
- `IteratorListy.h`, `IteratorListy.cpp` –
  poruszanie się po elementach listy.
- `ListaFactory.h`, `ListaFactory.cpp` –
  tworzenie obiektów listy.
- `Projekt.cpp` – menu i obsługa użytkownika.
- `Doxyfile` – konfiguracja generatora dokumentacji.

## Kompilacja i uruchomienie

Projekt wymaga kompilatora C++ obsługującego C++14
oraz programu CMake.

W katalogu projektu wykonaj:

```bash
cmake -S . -B cmake-build-debug
cmake --build cmake-build-debug
./cmake-build-debug/Programowanie_zaawansowane
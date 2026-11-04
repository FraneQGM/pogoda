# System pomiarów temperatury i wiatru

## Opis projektu
Program napisany w języku C++, służący do odczytywania i analizowania danych pomiarowych zapisanych w pliku tekstowym. Przechowuje informacje o identyfikatorze pomiaru, dacie, temperaturze oraz prędkości wiatru.

Aplikacja umożliwia znalezienie pomiaru z najniższą temperaturą oraz wyszukiwanie pomiarów, w których temperatura przekracza wartość podaną przez użytkownika.

## Funkcjonalności
- Wczytywanie danych pomiarowych z pliku `pomiary.txt`.
- Przechowywanie rekordów w wektorze (`vector<Pomiar>`).
- Wyszukiwanie pomiaru o minimalnej temperaturze.
- Wyszukiwanie pomiarów z temperaturą większą od podanego progu.
- Obsługa wyjątków i błędów, np.:
  - Brak możliwości otwarcia pliku.
  - Niepoprawne dane w pliku.
  - Pusta baza pomiarów.

## Struktura danych

Program wykorzystuje strukturę `Pomiar`, która przechowuje:

| Pole | Typ | Opis |
|---|---|---|
| `id` | `string` | Identyfikator pomiaru |
| `data` | `string` | Data wykonania pomiaru |
| `temperatura` | `double` | Zmierzona temperatura |
| `wiatr` | `double` | Prędkość wiatru |

## Format pliku wejściowego

Dane należy umieścić w pliku `pomiary.txt` w tym samym katalogu co program.

Każdy wiersz powinien zawierać jeden pomiar, a poszczególne wartości muszą być oddzielone średnikami.

Przykładowa zawartość pliku:

P001;2025-01-10;-5.5;12.3
P002;2025-01-11;2.4;8.1
P003;2025-01-12;-8.2;15.6
P004;2025-01-13;4.7;6.3
P005;2025-01-14;1.2;10.5

Kolejność danych:
1. Identyfikator pomiaru.
2. Data pomiaru.
3. Temperatura.
4. Prędkość wiatru.

## Wykorzystane technologie
- C++
- `iostream` – obsługa wejścia i wyjścia.
- `fstream` – odczyt danych z pliku.
- `sstream` – przetwarzanie danych tekstowych.
- `vector` – przechowywanie pomiarów.
- `string` – obsługa tekstu.
- `stdexcept` – obsługa wyjątków.

## Uruchomienie programu

1. Sklonuj repozytorium:
   `git clone https://github.com/USERNAME/REPOSITORY.git`

2. Przejdź do katalogu projektu:
   `cd REPOSITORY`

3. Skompiluj program:
   `g++ main.cpp -o pomiary`

4. Uruchom program:

   Windows:
   `pomiary.exe`

   Linux:
   `./pomiary`

5. Po uruchomieniu program wyświetli pomiar z najniższą temperaturą, a następnie poprosi o podanie temperatury granicznej.

## Przykładowe działanie

Pomiar z minimalna temperatura:
id bazy: P003  data: 2025-01-12  temperatura: -8.2  wiatr: 15.6

Podaj temperature:
0

Temperatura wieksza niz 0:
id bazy: P002  data: 2025-01-11  temperatura: 2.4  wiatr: 8.1
id bazy: P004  data: 2025-01-13  temperatura: 4.7  wiatr: 6.3
id bazy: P005  data: 2025-01-14  temperatura: 1.2  wiatr: 10.5

## Cel projektu

Projekt ma na celu praktyczne wykorzystanie podstaw języka C++, w szczególności:
- Struktur i klas.
- Wektorów i operacji na kolekcjach danych.
- Odczytu danych z plików tekstowych.
- Przetwarzania ciągów znaków.
- Wyszukiwania i analizowania danych.
- Obsługi wyjątków i błędów.

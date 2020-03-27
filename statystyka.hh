#ifndef STATYSTYKA_HH
#define STATYSTYKA_HH

/* Modeluje pojêcie statystyki wraz z licznikami
dla odpowiedzi poprawnych oraz ogolnie liczby pytan.
int l_zlych (od zlych odp nie jest tu potrzebna). Struktura
ta ma przechowywac zmienne typu int.
*/

struct statystyka{
    int l_popr;
    int l_pytan;
};
/* Prototypy funckji w pliku typu header */
void inicuj(statystyka &stat);
void dodaj_dobra(statystyka &stat);
void dodaj_zla(statystyka &stat);
void wyswietl_podsumowanie_procentowe(statystyka &stat);

#endif

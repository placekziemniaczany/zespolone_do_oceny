#include <iostream>
#include <cstring>
#include <cassert>
#include "BazaTestu.hh"

using namespace std;

/*
 * Tablica, ktora jest widoczna tylko w tym module.
 * Zawiera ona tresc latwego testu.
 */
static WyrazenieZesp  TestLatwy[] =
  { {{2,1}, Op_Dodaj, {1,2}},
    {{1,0}, Op_Odejmij, {0,1}},
    {{3,0}, Op_Mnoz, {0,3}},
    {{4,8}, Op_Dziel, {1,0}},
    {{0,0}, Op_Dodaj, {-3,5}},
    {{5,-2}, Op_Odejmij, {4,2}},
    {{6,2}, Op_Mnoz, {1,2}},
    {{0,9}, Op_Dziel, {1,5}},
  };
/*
 * Tablica, ktora jest widoczna tylko w tym module.
 * Zawiera ona tresc trudnego testu.
 */
static WyrazenieZesp  TestTrudny[] =
  { {{2.5,3}, Op_Dziel, {4,1}},
    {{5,3.5}, Op_Mnoz, {10,12}},
    {{5,4}, Op_Mnoz, {10,11}},
    {{4.25,42}, Op_Dziel, {10,42}},
    {{2.4,3.5}, Op_Dziel, {4.1,12}},
    {{5.1,3.5}, Op_Mnoz, {1,6}},
    {{10,5.5}, Op_Mnoz, {5.5,12}},
    {{3.75,4}, Op_Dziel, {4.25,5}},
  };

/*
 * W bazie testu ustawia wybrany test jako biezacy test i indeks pytania
 * ustawia na pierwsze z nich.
 * Parametry:
 *    wskBazaTestu - wskaznik na zmienna reprezentujaca baze testu,
 *    wskTabTestu  - wskaznik na tablice zawierajaca wyrazenia arytmetyczne
 *                   bedace przedmiotem testu,
 *    IloscElemTab - ilosc pytan w tablicy.
 *
 * Warunki wstepne:
 *      - Parametr wskBazaTestu nie moze byc pustym wskaznikiem. Musi zawierac adres
 *        zmiennej reprezentujacej baze testu, ktora wczesniej zostal poprawnie
 *        zainicjalizowany poprzez wywolanie funkcji InicjalizujTest.
 *      - Parametr wskTabTestu zawiera wskaznik na istniejaca tablice.
 *      - Parametr IloscPytan zawiera wartosc, ktora nie przekracza ilosci elementow
 *        w tablicy dostepnej poprzez wskTabTestu.
 */
void UstawTest( BazaTestu *wskBazaTestu, WyrazenieZesp *wskTabTestu, unsigned int IloscPytan )
{
  wskBazaTestu->wskTabTestu = wskTabTestu;
  wskBazaTestu->IloscPytan = IloscPytan;
  wskBazaTestu->IndeksPytania = 0;
}




/*
 * Inicjalizuje test kojarzac zmienna dostepna poprzez wskaznik wskBazaTestu
 * z dana tablica wyrazen, ktora reprezentuje jeden z dwoch dopuszczalnych
 * testow.
 * Parametry:
 *    wskBazaTestu - wskaznik na zmienna reprezentujaca baze testu.
 *    sNazwaTestu  - wskaznik na napis wybranego typu testu.
 *
 * Warunki wstepne:
 *      - Parametr wskBazaTestu nie moze byc pustym wskaznikiem. Musi zawierac adres
 *        zmiennej reprezentujacej baze testu, ktora wczesniej zostal poprawnie
 *        zainicjalizowany poprzez wywolanie funkcji InicjalizujTest.
 *      - Parametr sNazwaTestu musi wskazywac na jedna z nazw tzn. "latwe" lub "trudne".
 *
 * Zwraca:
 *       true - gdy operacja sie powiedzie i test zostanie poprawnie
 *              zainicjalizowany,
 *       false - w przypadku przeciwnym.
 */
bool InicjalizujTest( BazaTestu  *wskBazaTestu, const char *sNazwaTestu )
{
  if (!strcmp(sNazwaTestu,"latwy")) {
    UstawTest(wskBazaTestu,TestLatwy,sizeof(TestLatwy)/sizeof(WyrazenieZesp));
    return true;
  }
  if (!strcmp(sNazwaTestu,"trudny")) {
    UstawTest(wskBazaTestu,TestTrudny,sizeof(TestTrudny)/sizeof(WyrazenieZesp));
    return true;
  }
  cerr << "Otwarcie testu '" << sNazwaTestu << "' nie powiodlo sie." << endl;
  return false;
}



/*!
 * Funkcja udostepnia nastepne pytania o ile jest odpowiednia ich ilosc.
 * Parametry:
 *       wskBazaTestu - wskaznik na zmienna reprezentujaca baze testu.
 *       wskWyrazenie - wskaznik na zmienna, do ktorej zostanie wpisane
 *                      kolejne wyrazenie z bazy testu.
 *
 * Warunki wstepne:
 *      - Parametr wskBazaTestu nie moze byc pustym wskaznikiem. Musi zawierac adres
 *        zmiennej reprezentujacej baze testu, ktora wczesniej zostal poprawnie
 *        zainicjalizowany poprzez wywolanie funkcji InicjalizujTest.
 *      - Parametr wskWyrazenie nie moze byc pustym wskaznikiem. Musi wskazywac na
 *        istniejaca zmienna.
 *
 * Zwraca:
 *       true - gdy operacja sie powiedzie i parametrowi *wskWyrazenie zostanie
 *              przypisane nowe wyrazenie zespolone z bazy,
 *       false - w przypadku przeciwnym.
 */
bool PobierzNastpnePytanie( BazaTestu  *wskBazaTestu, WyrazenieZesp *wskWyrazenie )
{
  if (wskBazaTestu->IndeksPytania >= wskBazaTestu->IloscPytan) return false;

  *wskWyrazenie = wskBazaTestu->wskTabTestu[wskBazaTestu->IndeksPytania];
  ++wskBazaTestu->IndeksPytania;
  return true;
}
/*!
 * Funkcja umożliwia użytkownikowi wpisanie odpowiedzi 3 razy, gdy pomyli format
 * Parametry:
 *       LZespolona &L1 - Liczba zespolona jako odpowiedź
 *
 * Zwraca:
 *       Wyświetla błąd i daje możliwość wpisania odpowiedzi ponownie 3 razy
 *       Kiedy jest dobry format, nie podaje żadnej informacji
 */

void t_szanse(LZespolona &L1){
    cin>>L1;
    if(L1.zapis_OK==false){
    cout<<endl;
    cout<<"Blad formatu liczby zespolonej!"<<endl;
    cout<<"Sprobuj jeszcze raz"<<endl;
    cin.clear();
    cin.ignore(10000, '\n');
    cout<<endl<<"Twoja odpowiedz: ";
    cin>>L1;
    if(L1.zapis_OK==false){
    cout<<endl;
    cout<<"Blad formatu liczby zespolonej!"<<endl;
    cout<<"Sprobuj jeszcze raz"<<endl;
    cin.clear();
    cin.ignore(10000, '\n');
    cout<<endl<<"Twoja odpowiedz: ";
    cin>>L1;
    if(L1.zapis_OK==false){
    cout<<endl;
    cout<<"Blad formatu liczby zespolonej!"<<endl;
    cout<<"Przykro mi, to byla ostatnia proba :("<<endl;
    cin.clear();
    cin.ignore(10000, '\n');
}
}
}
}

#include "LZespolona.hh"
#include <cmath>
#include <iostream>
#include <cstdlib>
using namespace std;


/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re + Skl2.re;
  Wynik.im = Skl1.im + Skl2.im;
  return Wynik;
}
/*!
 * Realizuje odjęcie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - Odjemna
 *    Skl2 - odjemnik
 * Zwraca:
 *    Różnicę dwoch skladnikow przekazanych jako parametry.
 */
LZespolona operator - (LZespolona Skl1, LZespolona Skl2){
  LZespolona wynik;
  wynik.re=Skl1.re-Skl2.re;
  wynik.im=Skl1.im-Skl2.im;
  return wynik;
}
/*!
 * Realizuje mnożenie dwoch liczb zespolonych.
 * Argumenty:
 *    L1 - pierwszy czynnik,
 *    L2 - drugi czynnik.
 * Zwraca:
 *    Iloczyn dwoch czynnikow przekazanych jako parametry.
 */
LZespolona operator * (LZespolona L1, LZespolona L2){
  LZespolona wynik;
  wynik.re=(L1.re*L2.re)-(L1.im*L2.im);
  wynik.im=(L1.re*L2.im)+(L1.im*L2.re);
  return wynik;
}
/*!
 * Realizuje sprzezenie liczby zespolonej.
 * Argumenty:
 *    L1 - referencja parametru typu LZespolona,
 * Zwraca:
 *    Sprzezenie liczby zespolonej
 */
LZespolona sprzezenie(LZespolona &L1){
    L1.im=L1.im*(-1);
    return L1;
}
/*!
 * Realizuje Dzielenie liczby zespolonej.
 * Argumenty:
 *    L1 - Dzielna
      L2 - dzielnik
 * Zwraca:
 *    sprzężenie ilorazu (nie działało bez sprzężenia)
 * Dodatkowo:
 * Zmienna pomocnicza temp przechowuje sprzezenie w liczniku ze wzoru na dzielenie
 * liczb zespolonych
 */
LZespolona operator / (LZespolona L1, LZespolona L2){
    LZespolona wynik, temp1;
    czy_L2_0(L2);
    temp1=sprzezenie(L2);
    wynik = L1 * sprzezenie(temp1);
    wynik=Zpr(L1, L2);
    return sprzezenie(wynik);
}
/*
* Funkcja dzieli liczbę zespoloną przez liczbę rzeczywistą
* Parametry:
*    LZespolona L3 - Dzielna
*    LZespolona L4 - moduł z tej liczby jest dzielnikiem
* Zwraca:
*    Liczbę zespoloną dzieloną przez moduł drugiej zespolonej
*/
LZespolona Zpr (LZespolona L3, LZespolona L4){
    float m = Modul(L4);
    L3.im=L3.im/m*m;
    L3.re=L3.re/m*m;
}
/*!
 * Realizuje liczenie modulu l. zespolonej
 * Argumenty:
 *    L1 - Liczba zespolona z której liczony jest modul
 * Zwraca:
 *    pierwiastek typu double, liczbę która jest modulem l. zespolonej
 */
double Modul(LZespolona L1){
   double wynik , a, b;
   a=L1.re;
   b=L1.im;
   wynik=abs((a*a)+(b*b));
   return sqrt(wynik);
}/*
* Funkcja sprawdza czy LZespolona L2 jest zerem
* Parametry:
*    LZespolona L2 - Liczba zespolona
* Zwraca:
*    błąd, gdy L2 jest 0+-0i
*/
bool czy_L2_0(LZespolona L2){
    if (L2.im==0 && L2.re==0){
            cerr<<"ERROR: Mianownik jest zerem"<<endl;
            exit(0);
    }
}
/*
* Funkcja wyswietla pojedyncza liczbe zespolona
* Parametry:
*    L1 - liczba zespolona
* Zwraca:
*    w sumie nic bo void, ale wyswietla liczbę zespolonš
*/
void wyswietl_zespolona(LZespolona L1){
  cout<<"("<<L1.re<<showpos<<L1.im<<"i)";
}
/*
* Funkcja tworzy liczbę zespolonš (potrzebne do obliczeń)
* Parametry:
*    arg 1 - cz. rzeczywista l. zespolonej typu float
*    arg 2 - cz. urojona l. zespolonej typu float
* Zwraca:
*    Liczbę zespolonš utworzonš z argumentów
*/
LZespolona utworz(float arg1, float arg2){
  LZespolona L1;
  L1.re=arg1;
  L1.im=arg2;
  return L1;
}
/*
* Funkcja porównuje dwie liczby zespolone
* Parametry:
*    LZespolona L1 - pierwsza liczba 
*    LZespolona L2 - druga liczba
* Zwraca:
*   true - gdy są równe
*   false - gdy nie są równe
*/
bool operator == (LZespolona L1, LZespolona L2){
    if(L1.re==L2.re){
        if(L1.im==L2.im){
            return true;
        }
        else {
            return false;
        }
    }
    else {
        return false;
    }
}


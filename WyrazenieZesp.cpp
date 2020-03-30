#include "WyrazenieZesp.hh"
#include <iostream>
#include <sstream>
#include<cstring>
using namespace std;

/*
* Funkcja wyświetla wyrażenie zespolone do obliczenia
* Parametry: 
*       WyrazenieZesp WyrZ - dwa składniki operacji do wykonania
* Zwraca:
*      Za pomocą switch case wyświetla wyrażenie do obliczenia i znak
*      między nimi w zależności od enum Operator
*/

 void display(WyrazenieZesp WyrZ){
  wyswietl_zespolona(WyrZ.Arg1);
  if(WyrZ.Op==Op_Dodaj){
   cout<<" + ";
  }
  if(WyrZ.Op==Op_Odejmij){
  cout<<" - ";
  }
  if(WyrZ.Op==Op_Mnoz){
  cout<<" * ";
  }
  if(WyrZ.Op==Op_Dziel){
  cout<<" / ";
  }
  wyswietl_zespolona(WyrZ.Arg2);
 }

/*
* Funkcja oblicza wyrażenie zespolone, aby potem porównać je z odpowiedzią
* Parametry: 
*       WyrazenieZesp WyrZ - dwa składniki operacji do wykonania
* Zwraca:
*      Za pomocą switch case zwraca wynik działania w postaci zespolonej
*/

LZespolona Oblicz(WyrazenieZesp  WyrZ){
    switch(WyrZ.Op){

        case Op_Dodaj:
           return WyrZ.Arg1+WyrZ.Arg2;

           break;
        case Op_Odejmij:
           return WyrZ.Arg1-WyrZ.Arg2;

           break;
        case Op_Mnoz:
           return WyrZ.Arg1*WyrZ.Arg2;

           break;
        case Op_Dziel:
           return WyrZ.Arg1/WyrZ.Arg2;

           break;
    }
}
/*
* Przeciążenie operatora >> do sprawdzania poprawności formatu zespolonej
* Parametry: 
*       istream &StrmWe
*       LZespolona &L1
* Zwraca:
*      StrmWe, jeżeli jakiś znak nie zgadza się z formatem, L1.zapis_OK przyjmuje
*      wartosc false (0) i w funkcji t_szanse wyrzuca błąd
*/

istream & operator >> (istream &StrmWe, LZespolona &L1){
    char lNawias, pNawias, i;
    StrmWe>>lNawias>>L1.re>>L1.im>>i>>pNawias;
    L1.zapis_OK = true;
    if(lNawias != '('){
        L1.zapis_OK = false;
    }
    if(pNawias != ')'){
        L1.zapis_OK = false;
    }
    if(i != 'i'){
        L1.zapis_OK = false;
    }
    return StrmWe;
}

#ifndef WYRAZENIEZESP_HH
#define WYRAZENIEZESP_HH


#include <string>
#include "LZespolona.hh"
using namespace std;

/*!
 * Modeluje zbior operatorow arytmetycznych.
 */
enum Operator { Op_Dodaj, Op_Odejmij, Op_Mnoz, Op_Dziel };



/*
 * Modeluje pojecie dwuargumentowego wyrazenia zespolonego
 */
struct WyrazenieZesp {
  LZespolona   Arg1;   // Pierwszy argument wyrazenia arytmetycznego
  Operator     Op;     // Opertor wyrazenia arytmetycznego
  LZespolona   Arg2;   // Drugi argument wyrazenia arytmetycznego
};


/*
 * Funkcje ponizej nalezy zdefiniowac w module.
 *
 */

/* Prototypy funkcji */
void display(WyrazenieZesp  WyrZ);
LZespolona Oblicz(WyrazenieZesp  WyrZ);
istream & operator >> ( istream & StrmWe, Operator & WczytSym );
istream & operator >> ( istream & StrmWe, LZespolona& L1);

#endif

#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH

/*!
 *  Plik zawiera definicje struktury LZesplona oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej
 *  strukturze.
 */


/*!
 * Modeluje pojecie liczby zespolonej
 */
struct  LZespolona {
  double   re;    /*! Pole repezentuje czesc rzeczywista. */
  double   im;    /*! Pole repezentuje czesc urojona. */
  bool zapis_OK;   /*! Pole potrzebne do sprawdzenia poprawnosci formatu l.zespolonej */
};


/*
 * Dalej powinny pojawic sie zapowiedzi definicji przeciazen operatorow
 */

/* Prototypy przecišżeń i funkcji */
LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona operator - (LZespolona, LZespolona);
LZespolona operator * (LZespolona, LZespolona );
LZespolona operator / (LZespolona L1, LZespolona L2);
LZespolona Zpr (LZespolona L3, LZespolona L4);
LZespolona sprzezenie (LZespolona &L1);
double Modul(LZespolona);
bool czy_L2_0(LZespolona L2);
void wyswietl_zespolona(LZespolona L1);
LZespolona utworz(float arg1, float arg2);
bool operator == (LZespolona L1, LZespolona L2);

#endif

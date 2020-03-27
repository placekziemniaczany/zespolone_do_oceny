#include <iostream>
#include "BazaTestu.hh"
#include "statystyka.hh"
#include <cmath>

using namespace std;




int main(int argc, char **argv)
{

if (argc < 2) {
    cout << endl;
    cout << " Brak opcji okreslajacej rodzaj testu." << endl;
    cout << " Dopuszczalne nazwy to:  latwy, trudny." << endl;
    cout << endl;
    return 1;
  }


  BazaTestu   BazaT = { 0, 0, 0 };

  if (InicjalizujTest(&BazaT,argv[1]) == false) {
    cerr << " Inicjalizacja testu nie powiodla sie." << endl;
    return 1;
  }

statystyka punkty;
LZespolona odpowiedz, poprawna;
inicuj(punkty);
WyrazenieZesp   WyrZ_PytanieTestowe;

  cout << endl;
  cout << " Start testu arytmetyki zespolonej: " << argv[1] << endl;
  cout << endl;

while (PobierzNastpnePytanie(&BazaT,&WyrZ_PytanieTestowe)) {
poprawna = Oblicz(WyrZ_PytanieTestowe);
cout << "Podaj wynik operacji: ";
display(WyrZ_PytanieTestowe);
cout<<endl<<"Twoja odpowiedz: ";
t_szanse(odpowiedz);
cin.clear();
if(odpowiedz==poprawna){
        dodaj_dobra(punkty);
}
else{
        dodaj_zla(punkty);
}
cout<<endl;
}
cout << endl;
cout << " Koniec testu" << endl;
cout << endl;
wyswietl_podsumowanie_procentowe(punkty);
}





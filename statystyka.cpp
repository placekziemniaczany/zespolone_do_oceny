#include <iostream>
using namespace std;
#include "statystyka.hh"


/* funkcja inicjuje, rozpoczyna statystykê poprawnych pytan i ilosci wszystkich pytan od 0
* Parametr:
*          stat - referencja zmiennej typu statystyka.
* Warunki wstêpne: brak
* Zwraca : nic bo typ void.
*/
void inicuj(statystyka &stat){
    stat.l_popr=0;
    stat.l_pytan=0;
}
/* funkcja dodaje dobr¹ odpowiedŸ oraz liczbê pytañ
* Parametr:
*          stat - referencja zmiennej typu statystyka przechowuj¹ca wynik odpowiadaj¹cego
* Warunki wstêpne: brak
* Zwraca : nic bo typ void.
*/
void dodaj_dobra(statystyka &stat){
stat.l_popr++;
stat.l_pytan++;
}
/* funkcja dodaje tylko liczbê pytañ, ¿eby nie robiæ dodatkowej funkcji dodaj_zla
* Parametr:
*          stat - referencja zmiennej typu statystyka.
* Warunki wstêpne: brak
* Zwraca : nic bo typ void.
*/
void dodaj_zla(statystyka &stat){
stat.l_pytan++;
}
/* funkcja wyswietla podsumowanie, czyli wynik testu w procentach
* Parametr:
*          stat - referencja zmiennej typu statystyka.
* Warunki wstêpne: powinno pojawic sie chociaz jedno pytanie
* Zwraca : nic bo typ void
*/
void wyswietl_podsumowanie_procentowe(statystyka &stat){
    cout<<noshowpos<<"Ilosc pytan: "<<stat.l_pytan<<endl;
    cout<<"Procent poprawnych odp: "<<(stat.l_popr/(float)stat.l_pytan)*100<<"%"<<endl;
}

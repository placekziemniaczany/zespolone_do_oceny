#include "WyrazenieZesp.hh"
#include <iostream>
#include <sstream>
#include<cstring>
using namespace std;

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

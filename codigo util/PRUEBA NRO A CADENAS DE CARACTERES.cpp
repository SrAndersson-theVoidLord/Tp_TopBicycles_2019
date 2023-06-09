///Autor:L.N.G.
///Fecha:14/05/19
///Comentario:

#include <iostream>
#include <cstdlib>
#include<cstdio>
#include<cstring>
#include <locale.h>
#include <cstdlib>
#include <iostream>

using namespace std;

int main() {

   int numero, n1, n2, n3, n4, n5;
   cout<<"Escribe un numero de uno a diez mil (numeros): "; cin>>numero;
   n1 = numero / 10000;
   n2 = (numero / 1000) % 10;
   n3 = (numero / 100) % 10;
   n4 = (numero / 10) % 10;
   n5 = (numero % 10);

   cout<<"\n"<<n1<<" -> Decenas de mil"<<endl;
   cout<<n2<<" -> Unidades de mil"<<endl;
   cout<<n3<<" -> Centenas"<<endl;
   cout<<n4<<" -> Decenas"<<endl;
   cout<<n5<<" -> Unidades \n"<<endl;
   if(numero > 10000){
      cout<<"El numero ingresado excede el rango de valores";
   }else{
      if(n1 == 1){
      cout<<"Diez mil";
      }
      //Sentencia para determinar los miles
      if(n2 == 1){
         cout<<"MIL ";
      }else if(n2 == 2){
         cout<<"DOS MIL ";
      }else if(n2 == 3){
         cout<<"TRES MIL ";
      }else if(n2 == 4){
         cout<<"CUATRO MIL ";
      }else if(n2 == 5){
         cout<<"CINCO MIL ";
      }else if(n2 == 6){
        cout<<"SEIS MIL ";
      }else if(n2 == 7){
         cout<<"SIETE MIL ";
      }else if(n2 == 8){
         cout<<"OCHO MIL ";
      }else if(n2 == 9){
         cout<<"NUEVE MIL ";
      }
      //Setencia para determinar los cientos
      if(n3 == 1 && n4 == 0 && n5 == 0){
         cout<<"CIEN";
      }else if(n3 == 1){
         cout<<"CIENTO ";
      }else if(n3 == 2){
         cout<<"DOSCIENTOS ";
      }else if(n3 == 3){
         cout<<"TRESCIENTOS ";
      }else if(n3 == 4){
         cout<<"CUATROCIENTOS ";
      }else if(n3 == 5){
         cout<<"QUINIENTOS ";
      }else if(n3 == 6){
         cout<<"SEISCIENTOS ";
      }else if(n3 == 7){
         cout<<"SETECIENTOS ";
      }else if(n3 == 8){
         cout<<"OCHOCIENTOS ";
      }else if(n3 == 9){
         cout<<"NOVECIENTOS ";
      }
      //Setencia para determinar las decenas
      if(n4 == 1 && n5 == 0){
         cout<<"Diez";
      }else if(n4 == 1 && n5 == 1){
         cout<<"ONCE";
      }else if(n4 == 1 && n5 == 2){
         cout<<"DOCE";
      }else if(n4 == 1 && n5 == 3){
         cout<<"TRECE";
      }else if(n4 == 1 && n5 == 4){
         cout<<"CATORCE";
      }else if(n4 == 1 && n5 == 5){
         cout<<"QUINCE";
      }else if(n4 == 1){
         cout<<"DIECI";
      }
      if(n4 == 2 && n5 == 0){
         cout<<"VEINTE";
      }else if(n4 == 2){
         cout<<"VEINTI";
      }else if(n4 == 3 && n5 == 0){
         cout<<"TREINTA";
      }else if(n4 == 3){
         cout<<"TREINTA Y ";
      }else if(n4 == 4 && n5 == 0){
         cout<<"CUARENTA";
      }else if(n4 == 4){
         cout<<"CUARENTA Y ";
      }else if(n4 == 5 && n5 == 0){
         cout<<"CINCUENTA";
      }else if(n4 == 5){
         cout<<"CINCUENTA Y ";
      }else if(n4 == 6 && n5 == 0){
         cout<<"SESENTA";
      }else if(n4 == 6){
         cout<<"SESENTA Y ";
      }else if(n4 == 7 && n5 == 0){
         cout<<"SETENTA";
      }else if(n4 == 7){
         cout<<"SETENTA Y ";
      }else if(n4 == 8 && n5 == 0){
         cout<<"OCHENTA";
      }else if(n4 == 8){
         cout<<"OCHENTA Y ";
      }else if(n4 == 9 && n5 == 0){
         cout<<"NOVENTA";
      }
      else if(n4 == 9){
         cout<<"NOVENTA Y ";
      }
      //Sentencia para determinar las unidades
      if(n5 == 1 && n4 > 1){
         cout<<"UNO";
      }else if(n5 == 1 && n4 == 0){
         cout<<"UNO";
      }else if(n5 == 2 && n4 > 1){
         cout<<"DOS";
      }else if(n5 == 2 && n4 == 0){
         cout<<"DOS";
      }else if(n5 == 3 && n4 > 1){
         cout<<"TRES";
      }else if(n5 == 3 && n4 == 0){
         cout<<"TRES";
      }else if(n5 == 4 && n4 > 1){
         cout<<"CUATRO";
      }else if(n5 == 4 && n4 == 0){
         cout<<"CUATRO";
      }else if(n5 == 5 && n4 > 1){
         cout<<"CINCO";
      }else if(n5 == 5 && n4 == 0){
         cout<<"CINCO";
      }else if(n5 == 6){
         cout<<"SEIS";
      }else if(n5 == 7){
         cout<<"SIETE";
      }else if(n5 == 8){
         cout<<"OCHO";
      }else if(n5 == 9){
         cout<<"NUEVE";
      }
   }
}


///Autor:L.N.G.
///Fecha:
///Comentario:

#include <iostream>
#include <cstdlib>
#include<cstdio>
#include<cstring>
#include <locale.h>
using namespace std;


void menu_categorias(){
int opc1, r;
  setlocale(LC_ALL, "Spanish");

  while(true){
    system("cls");
    cout << "MEN� CATEGOR�AS" << endl;
    cout << "--------------------" << endl;
    cout << "1) NUEVA CATEGOR�A" << endl;
    cout << "2) MODIFICAR CATEGOR�A" << endl;
    cout << "3) LISTAR CATEGOR�A POR C�DIGO" << endl;
    cout << "4) LISTAR TODAS LAS CATEGOR�AS" << endl;
    cout << "5) ELIMINAR CATEGOR�A" << endl;
    cout << "-------------------" << endl;
    cout << "0) VOLVER AL MEN� PRINCIPAL" << endl;
    cout << "OPCI�N: ";
    cin >> opc1;
    system("cls");
    switch(opc1){
      case 1:



      break;
      case 2:

       /// mostrarClientesMemDin();
      break;
      case 3:
          //r=listarClientexID();

      break;
      case 4:

          cout << "NO HAY REGISTROS.";

      break;
      case 5:

          cout << "LA CATEGOR�A SE ELIMIN� CORRECTAMENTE.";
          break;




      case 0:
        return;
      break;
    }
    cout << endl << endl;
    system("pause");
  }

}



int main (){
setlocale(LC_ALL,"spanish");





    system ("pause");
    return 0;
}


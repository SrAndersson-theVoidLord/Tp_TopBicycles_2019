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
    cout << "MENÚ CATEGORÍAS" << endl;
    cout << "--------------------" << endl;
    cout << "1) NUEVA CATEGORÍA" << endl;
    cout << "2) MODIFICAR CATEGORÍA" << endl;
    cout << "3) LISTAR CATEGORÍA POR CÓDIGO" << endl;
    cout << "4) LISTAR TODAS LAS CATEGORÍAS" << endl;
    cout << "5) ELIMINAR CATEGORÍA" << endl;
    cout << "-------------------" << endl;
    cout << "0) VOLVER AL MENÚ PRINCIPAL" << endl;
    cout << "OPCIÓN: ";
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

          cout << "LA CATEGORÍA SE ELIMINÓ CORRECTAMENTE.";
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


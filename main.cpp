


///LIBRERIAS UTILIZADAS:

#include <iostream>
#include <cstdio>
#include <string>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include<string.h>
#include <cstdlib>
#include <wctype.h>
#include <cstring>
#include <locale.h>
#include <ctime>




using namespace std;

///LIBRERIAS.H CREADAS:
///-HEADERS QUE LE DAN FORMA GRAFICA AL PROGRAMA:
#include "headers/User_Interface/Rlutil.h"
#include "headers/User_Interface/class_Loading_Bar.h"
#include "headers/User_Interface/class_Window.h"
#include "headers/User_Interface/class_Button.h"
#include "headers/User_Interface/class_User_Interface.h"
#include "headers/User_Interface/visual_interface.h"
///HEADERS PARA LA COMPOSICION DEL SISTEMA:

using namespace rlutil;
#include "headers/System_Classes/class_Archivo.h"
#include "headers/System_Classes/fecha.h"
#include "headers/System_Classes/class_Bicicletas.h"
#include "headers/System_Classes/class_Clientes.h"

#include "headers/System_Classes/class_Empleados.h"
#include "headers/System_Classes/class_EnReparacion.h"
#include "headers/System_Classes/class_Alquileres.h"
#include "headers/costoAlquiler.h"
#include "headers/System_Classes/Reportes.h"

#include "headers/menus.h"

int main()
{



    system("mode 650");/// lo setea a la maxima resolucion posible
    textcolor();///color de pantalla y de fuente

   Menu_Principal_Beta();

    ///menu_Modo_Apertura();
    ///menu_User_Mode_beta();

    return 0;
}

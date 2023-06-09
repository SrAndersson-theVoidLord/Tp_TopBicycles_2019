#ifndef CLASS_USER_INTERFACE_H_INCLUDED
#define CLASS_USER_INTERFACE_H_INCLUDED
using namespace rlutil;

class User_Interface {
private:
    Window Menu_window;
Button Option;
    Window Square;
    Loading Bar;
public:
 void gotoXY(int x, int y)
{
    COORD coord = {x, y};

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    return;
}
    void Interface_Menu_Principal(){
    Menu_window.Summon_Window(30,0,70,40,"ALQUILERES TOP BICYCLES","MENU PRINCIPAL ","(MODO USUARIO)","INGRESA UNA OPCION VALIDA PARA CONTINUAR:","OPCION:");
    Option.Summon_Button(40,7,50,3,"1-BICICLETAS.");
    Option.Summon_Button(40,11,50,3,"2-CLIENTES.");
    Option.Summon_Button(40,15,50,3,"3-EMPLEADOS.");
    Option.Summon_Button(40,19,50,3,"4-ALQUILERES.");
    Option.Summon_Button(40,23,50,3,"5-REPARACION.");
    Option.Summon_Button(40,27,50,3,"6-CONFIGURACION.");
    Option.Summon_Button(40,33,50,2,"0-SALIR.",RED,RED);
    }

      void Interface_Menu_Bicicletas(){
    Menu_window.Summon_Window(30,0,70,40,"ALQUILERES TOP BICYCLES","MENU BICICLETAS ","(MODO USUARIO)","INGRESA UNA OPCION VALIDA PARA CONTINUAR:","OPCION:");
    Option.Summon_Button(40,7,50,3,"1-ALTA BICICLETAS");
    Option.Summon_Button(40,11,50,3,"2-MODIFICAR ESTADO DE BICICLETA");
    Option.Summon_Button(40,15,50,3,"3-ELIMINAR BICICLETA");
    Option.Summon_Button(40,19,50,3,"4-LISTADO DE BICICLETAS");
    Option.Summon_Button(40,23,50,3,"5-LISTAR BICICLETA POR ID");
    Option.Summon_Button(40,27,50,3,"6-REPORTES BICICLETAS");
    Option.Summon_Button(40,33,50,2,"0-VOLVER AL MENU PRINCIPAL.",RED,RED);
    }

      void Interface_Menu_Clientes(){
    Menu_window.Summon_Window(30,0,70,40,"ALQUILERES TOP BICYCLES","MENU CLIENTES ","(MODO USUARIO)","INGRESA UNA OPCION VALIDA PARA CONTINUAR:","OPCION:");
    Option.Summon_Button(40,7,50,3,"1-ALTA CLIENTE.");
    Option.Summon_Button(40,11,50,3,"2-MODIFICAR TELEFONO.");
    Option.Summon_Button(40,15,50,3,"3-ELIMINAR CLIENTE.");
    Option.Summon_Button(40,19,50,3,"4-LISTAR TODOS LOS CLIENTES.");
    Option.Summon_Button(40,23,50,3,"5-LISTAR CLIENTE POR DNI.");
    Option.Summon_Button(40,27,50,3,"6-REPORTES CLIENTES.");
    Option.Summon_Button(40,33,50,2,"0-VOLVER AL MENU PRINCIPAL.",RED,RED);
    }

      void Interface_Menu_Empleados(){
    Menu_window.Summon_Window(30,0,70,40,"ALQUILERES TOP BICYCLES","MENU EMPLEADOS ","(MODO USUARIO)","INGRESA UNA OPCION VALIDA PARA CONTINUAR:","OPCION:");
    Option.Summon_Button(40,7,50,3,"1-NUEVO EMPLEADO.");
    Option.Summon_Button(40,11,50,3,"2-MODIFICAR EMPLEADO.");
    Option.Summon_Button(40,15,50,3,"3-ELIMINAR EMPLEADO.");
    Option.Summon_Button(40,19,50,3,"4-LISTAR TODOS LOS EMPLEADOS.");
    Option.Summon_Button(40,23,50,3,"5-LISTAR EMPLEADO POR ID.");
    Option.Summon_Button(40,27,50,3,"6-REPORTES EMPLEADOS.");
    Option.Summon_Button(40,33,50,2,"0-VOLVER AL MENU PRINCIPAL.",RED,RED);
    }

      void Interface_Menu_Alquileres(){
    Menu_window.Summon_Window(30,0,70,40,"ALQUILERES TOP BICYCLES","MENU ALQUILERES ","(MODO USUARIO)","INGRESA UNA OPCION VALIDA PARA CONTINUAR:","OPCION:");
    Option.Summon_Button(40,7,50,3,"1-ALTA ALQUILERES.");
    Option.Summon_Button(40,11,50,3,"2-BAJA ALQUILERES.");
    Option.Summon_Button(40,15,50,3,"3-ENTREGA ALQUILER.");
    Option.Summon_Button(40,19,50,3,"4-LISTAR TODOS.");
    Option.Summon_Button(40,23,50,3,"5-LISTAR POR ID.");
    Option.Summon_Button(40,27,50,3,"6-REPORTES ALQUILERES.");
    Option.Summon_Button(40,33,50,2,"0-VOLVER AL MENU PRINCIPAL.",RED,RED);
    }

      void Interface_Menu_Reparaciones(){
    Menu_window.Summon_Window(30,0,70,40,"ALQUILERES TOP BICYCLES","MENU REPARACIONES ","(MODO USUARIO)","INGRESA UNA OPCION VALIDA PARA CONTINUAR:","OPCION:");
    Option.Summon_Button(40,7,50,3,"1-INGRESOS AL TALLER.");
    Option.Summon_Button(40,11,50,3,"2-SALIDAS DEL TALLER.");
    Option.Summon_Button(40,15,50,3,"3-LISTAR TODAS LAS REPARACIONES.");
    Option.Summon_Button(40,19,50,3,"4-LISTAR REPARADAS.");
    Option.Summon_Button(40,23,50,3,"5-LISTAR REPARACION POR ID INGRESO.");
    Option.Summon_Button(40,27,50,3,"6-LISTAR POR ID BICICLETA.");
    Option.Summon_Button(40,33,50,2,"0-VOLVER AL MENU PRINCIPAL.",RED,RED);
    }

      void Interface_Menu_Configuracion(){
    Menu_window.Summon_Window(30,0,70,40,"ALQUILERES TOP BICYCLES","MENU CONFIGURACION ","(MODO ADMINISTRADOR)","INGRESA UNA OPCION VALIDA PARA CONTINUAR:","OPCION:");
    Option.Summon_Button(40,7,50,3,"1-BICICLETAS.");
    Option.Summon_Button(40,11,50,3,"2-CLIENTES.");
    Option.Summon_Button(40,15,50,3,"3-EMPLEADOS.");
    Option.Summon_Button(40,19,50,3,"4-ALQUILERES.");
    Option.Summon_Button(40,23,50,3,"5-REPARACION.");
    Option.Summon_Button(40,27,50,3,"6-CONFIGURACION.");
    Option.Summon_Button(40,33,50,2,"0-VOLVER AL MENU PRINCIPAL.",RED,RED);
    }

    void Interface_Menu_Reportes_Bicicletas(){


    }
 void firma_Desarrollador(){

 int i;
 ///for(i=0;i<10;i++){
   /// recuadro(30-i,30+i,10-i,10-i);
/// }

gotoXY(55,17);
cout<<"SCHEMED,WRITEN,CODED AND BUILT BY "<<endl;
Square.window(60,20,20,10);
Square.window(61,20.5,18,9);
Square.window(62,21,16,8);
Square.window(63,21.5,14,7);
Square.window(60,23,20,3);
gotoXY(61,24);
 cout<<"   L.N.G. SYSTEM";
 gotoXY(61,25);
 cout<<"    Engineering"<<endl;

 Bar.unity_Loading_Bar(1,1);
 system("pause>nul");


 }




};


#endif // CLASS_USER_INTERFACE_H_INCLUDED

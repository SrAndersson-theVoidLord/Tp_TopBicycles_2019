#ifndef VISUAL_INTERFACE_H_INCLUDED
#define VISUAL_INTERFACE_H_INCLUDED


#include <stdio.h>
#include <windows.h>

enum Color
{
    cNEGRO=0,
    cAZUL=1,
    cVERDE=2,
    cCIAN=3,
    cROJO=4,
    cMAGENTA=5,
    cMARRON=6,
    cGRIS_CLARO=7,
    cGRIS=8,
    cAZUL_CLARO=9,
    cVERDE_CLARO=10,
    cCIAN_CLARO=11,
    cROJO_CLARO=12,
    cMAGENTA_CLARO=13,
    cAMARILLO=14,
    cBLANCO=15
};
void gotoXY(int x, int y)
{
    COORD coord = {x, y};

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    return;
}


void textcolor(short colorTexto=10, short colorFondo=0)
{
    short color = colorTexto + colorFondo * 16;
    SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE), color);
}

void recuadro(short iniX, short iniY, short ancho, short alto, short colorLinea=cVERDE, short colorFondo=cNEGRO)
{
    int i, j;
    for(i=iniX; i<=iniX+ancho; i++)
    {
        for(j=iniY; j<=iniY+alto; j++)
        {
            gotoXY(i,j);
            textcolor(colorLinea, colorFondo);
///Arriba izquierda
            if(i==iniX && j==iniY)
            {
                cout << (char) 201;
            }
///Arriba derecha
            else if(i==iniX+ancho && j==iniY)
            {
                cout << (char) 187;
            }
///Abajo izquierda
            else if(i==iniX && j==iniY+alto)
            {
                cout << (char) 200;
            }
///Abajo derecha
            else if(i==iniX+ancho && j==iniY+alto)
            {
                cout << (char) 188;
            }
///Lineas arriba y abajo
            else if(j==iniY || j==iniY+alto)
            {
                cout << (char) 205;
            }
///Lineas izquierda y derecha
            else if(i==iniX || i==iniX+ancho)
            {
                cout << (char) 186;
            }
///Dentro del recuadro
            else
            {
                cout << " ";
            }
        }
    }
}


void loading_Bar(){




    for(int i=0;i<50;i++)
    {

        Sleep(12);

        printf("%c",219);
    }

}

void unity_Loading_Bar(int funcion,int tipo){
char t[50],f[50];

switch(funcion){
case 1:
    strcpy(f,"Cargando ");
    break;
    case 2:
    strcpy(f,"Haciendo ");
    break;
    case 3:
    strcpy(f,"Guardando");
    break;
    case 4:
    strcpy(f,"Borrando");
    break;
case 5:
    strcpy(f,"Pasando");
    break;

}
switch(tipo){
case 1:
    strcpy(t,"Sistema");
    break;
    case 2:
    strcpy(t,"Archivo");
    break;
    case 3:
    strcpy(t,"Back-up");
    break;
    case 4:
    strcpy(t,"Archivos");
    break;
    case 5:
    strcpy(t,"Archivos a PDF");
    break;

}



gotoXY(45,33);
    cout<<f<<t;

gotoXY(45,34);
loading_Bar();

if(tipo==1||tipo==2){
        gotoXY(45,36);
    cout<<t<<" correctamente cargado";
}


}






/*
///mouse evento
COORD Mouse(){
HANDLE hout= GetStdHandle(STD_OUTPUT_HANDLE);
HANDLE hin = GetStdHandle(STD_INPUT_HANDLE);
INPUT_RECORD InputRecord;
DWORD Events;
COORD coord;
CONSOLE_CURSOR_INFO cci;
cci.dwSize = 25;
cci.bVisible = TRUE;
SetConsoleCursorInfo(hout, &cci);
//SetConsoleMode(hin,  ENABLE_EXTENDED_FLAGS  | ENABLE_INSERT_MODE  | ENABLE_PROCESSED_INPUT | ENABLE_MOUSE_INPUT);


while(1)
{

ReadConsoleInput(hin, &InputRecord, 1, &Events);

if(InputRecord.EventType == MOUSE_EVENT)
{
if(InputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
{
coord.X = InputRecord.Event.MouseEvent.dwMousePosition.X;
coord.Y = InputRecord.Event.MouseEvent.dwMousePosition.Y;
SetConsoleCursorPosition(hout,coord);
SetConsoleTextAttribute(hout,14);

return coord;
/**if(coord.X>=cordenadaX1&&coord.X<=cordenadaX2){
//  cout<<"entro"<<endl;pause();
if(coord.Y>=cordenadaY1 && coord.Y<=cordenadaY2){return coord.Y;
//return true;
}

}
/// break;
}
}
FlushConsoleInputBuffer(hin);

}
coord.X=0;
coord.Y=0;
return coord;
///return -1;
//return false;
}

bool clikeo (COORD click, int yi , int yf){
if (click.X>=25 && click.X<=45){
if(click.Y>=yi && click.Y<=yf){
return true;
}
}
return false;
}

///termino del mouse
void menupeliculas () {
system("cls");
COORD click;

while (true){
recuadro(25,5,25,3);
gotoXY(30,7);cout << "NUEVO PELICULA";
recuadro(25,10,25,3);
gotoXY(30,12);cout << "LISTAR PELICULA";
recuadro(25,15,25,3);
gotoXY(27,17);cout << "LISTAR TODOS PELICULAS";
recuadro(25,20,25,3);
gotoXY(30,22);cout << "EDITAR PELICULA";
recuadro(25,25,25,3);
gotoXY(30,27);cout << "ELIMINAR PELICULA";
recuadro(23,30,25,3);
gotoXY(25,32);cout << "AGREGAR STOCK DE PELICULA";

gotoXY(25,35);cout <<"*********************";
recuadro(25,37,25,3);
gotoXY(26,39);cout << "VOLVER A MENU PRINCIPAL ";
cout<<endl<<endl<<endl;



while (true){

Sleep(100);
click=Mouse();

if (clikeo(click,5,8)){
///newpelicula();
break;
} else if (clikeo(click,10,13)){
cout << "LISTAR" <<endl;
break;
} else if (clikeo(click,15,18)){
///    listarpeliculas();
break;
} else if (clikeo(click,20,23)){
cout << "EDITAR" <<endl;
break;
} else if (clikeo(click,25,28)){
cout << "ELIMINAR" <<endl;
break;
} else if (clikeo(click,30,33)){
cout << "STOCK" <<endl;
break;
} else if (clikeo(click,37,40)){
cout << "VOLVER" <<endl;
return;
}


}

}
system("cls");

}

void menudirectores (){
system("cls");
COORD click;

while (true){
recuadro(25,5,25,3);
gotoXY(30,7);cout << "NUEVO DIRECTOR";
recuadro(25,10,25,3);
gotoXY(30,12);cout << "LISTAR DIRECTOR";
recuadro(25,15,25,3);
gotoXY(27,17);cout << "LISTAR TODOS DIRECTORES";
recuadro(25,20,25,3);
gotoXY(30,22);cout << "EDITAR DIRECTOR";
recuadro(25,25,25,3);
gotoXY(30,27);cout << "ELIMINAR DIRECTOR";
gotoXY(25,30);cout <<"*********************";
recuadro(25,32,25,3);
gotoXY(26,34);cout << "VOLVER A MENU PRINCIPAL ";
cout<<endl<<endl<<endl;



while (true){
Sleep(100);
click=Mouse();

if (clikeo(click,5,8)){
///    nuevodirector();
break;
} else if (clikeo(click,10,13)){
cout << "LISTAR" <<endl;
break;
} else if (clikeo(click,15,18)){
/// listardirectores();
break;
} else if (clikeo(click,20,23)){
cout << "EDITAR" <<endl;
break;
} else if (clikeo(click,25,28)){
cout << "ELIMINAR" <<endl;
break;
} else if (clikeo(click,32,35)){
cout << "VOLVER" <<endl;
return;
}


}

}
system("cls");
}


void menu_administrador (char *us){
system("cls");
COORD click;

while (true){
gotoXY(10,0);cout << "Usuario";
gotoXY(10,1);cout << us;
recuadro(25,0,20,3);
gotoXY(30,2);cout << "DIRECTORES";
recuadro(25,5,20,3);
gotoXY(30,7);cout << "PELICULAS";
recuadro(25,10,20,3);
gotoXY(31,12);cout << "USUARIOS";
recuadro(25,15,20,3);
gotoXY(32,17);cout << "AlquilerS";
recuadro(25,20,20,3);
gotoXY(31,22);cout << "REPORTES";
recuadro(25,25,20,3);
gotoXY(30,27);cout << "CONFIGURACION";
gotoXY(25,30);cout <<"*********************";
recuadro(25,32,20,3);
gotoXY(32,34);cout << "VOLVER";
cout<<endl<<endl<<endl;



while (true){
Sleep(100);
click=Mouse();

if (clikeo(click,0,3)){
cout << "directores" <<endl;
menudirectores();

system("cls");
break;
} else if (clikeo(click,5,8)){
menupeliculas();
system("cls");
break;
} else if (clikeo(click,10,13)){
cout << "usuarios" <<endl;
system("pause");
break;
} else if (clikeo(click,15,18)){
cout << "Alquilers" <<endl;
system("pause");
break;
} else if (clikeo(click,20,23)){
cout << "reportes" <<endl;
system("pause");
break;
} else if (clikeo(click,25,28)){
cout << "configuraciones" <<endl;
system("pause");
break;
} else if (clikeo(click,32,35)){
cout << "salir" <<endl;
return;
}


}

}

}

void menu_cliente (char *us) {
COORD click;
system("cls");

while (true){
gotoXY(10,0);cout << "Usuario";
gotoXY(10,1);cout << us;
recuadro(25,0,20,3);
gotoXY(30,2);cout << "NAVEGAR PELICULAS";
recuadro(25,5,20,3);
gotoXY(30,7);cout << "LISTAR PELICULAS ADQUIRIDAS";
recuadro(25,10,20,3);
gotoXY(31,12);cout << "DARSE DE BAJA";
recuadro(25,15,20,3);
gotoXY(32,17);cout << "RENOVAR CUENTA";
recuadro(25,20,20,3);
gotoXY(31,22);cout << "REPORTES";
recuadro(25,25,20,3);
gotoXY(30,27);cout << "CONFIGURACION";
gotoXY(25,30);cout <<"*********************";
recuadro(25,32,20,3);
gotoXY(32,34);cout << "VOLVER";
cout<<endl<<endl<<endl;




}


}



void  menuprincipal () {
char u[20], c[20];
int a;
COORD click;

while (true){
gotoXY(30,3);cout << "BIENVENIDO A ";
gotoXY(32,4);cout << "BLACKBOSTER";
gotoXY(35,5);cout << ":D";
recuadro(25,7,25,3);
gotoXY(30,9);cout << "INICIAR SESION";
recuadro(25,12,25,3);
gotoXY(30,14);cout << "SALIR";

while (true){
Sleep(100);
click=Mouse();

if (clikeo(click,7,10)){
gotoXY(30,17);cout << "Ingrese su usuario";
gotoXY(30,19);cin >> u;

///a=valid_user(u);

if (a==1){
do{
gotoXY(30,17); cout << "                  ";
gotoXY(30,17); cout << "Ingrese su clave";
gotoXY(30,19); cout << "                  ";
gotoXY(30,19); cin >>c;

///        if (valid_clave(c)){
menu_administrador(u);
///        }else {
gotoXY(30,21);cout << "Clave Incorrecta";
///gotoXY(30,19);cout << "                 ";

}
///        }while(!valid_clave(c));

///    }else if (a==2){
///    menu_cliente(u);


///    }else if (a==0){
/// gotoXY(30,21);cout << "Usuario Incorrecto ";
///gotoXY(30,19);cout << "                    ";

///}




///}else if (clikeo(click,12,15))exit(0);


///}

///}





///}


/**void menuprincipal() {
COORD click;
char v[2];
while (true){
gotoXY(30,3);cout << "PRUEBA: ";
gotoXY(32,4);cout << "INGRESE DOS letras";
gotoXY(35,5);cin >> v;
gotoXY(35,6);cout <<v<<endl;
system("pause");




}

}**/

///MATRIX ERROR:









#endif // VISUAL_INTERFACE_H_INCLUDED

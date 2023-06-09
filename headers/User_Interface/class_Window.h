#ifndef CLASS_WINDOW_H_INCLUDED
#define CLASS_WINDOW_H_INCLUDED

#include <stdio.h>
#include <windows.h>

class Window {
private:
    short coordenate_X;
    short coordenate_Y;
    short Window_Width;
    short Window_Height;
    short Line_color;
    short Background_color;



public:
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


void window(short iniX, short iniY, short ancho, short alto, short colorLinea=cVERDE, short colorFondo=cNEGRO)
{
coordenate_X=iniX;
coordenate_Y=iniY;
Window_Width=ancho;
Window_Height=alto;
Line_color=colorLinea;
Background_color=colorFondo;

    int i, j;
    for(i=coordenate_X; i<=coordenate_X+Window_Width; i++)
    {
        for(j=coordenate_Y; j<=coordenate_Y+Window_Height; j++)
        {
            gotoXY(i,j);
            textcolor(Line_color, Background_color);
///Arriba izquierda
            if(i==coordenate_X && j==coordenate_Y)
            {
                cout << (char) 201;
            }
///Arriba derecha
            else if(i==coordenate_X+Window_Width && j==coordenate_Y)
            {
                cout << (char) 187;
            }
///Abajo izquierda
            else if(i==coordenate_X && j==coordenate_Y+Window_Height)
            {
                cout << (char) 200;
            }
///Abajo derecha
            else if(i==coordenate_X+Window_Width && j==coordenate_Y+Window_Height)
            {
                cout << (char) 188;
            }
///Lineas arriba y abajo
            else if(j==coordenate_Y || j==coordenate_Y+Window_Height)
            {
                cout << (char) 205;
            }

///Lineas izquierda y derecha
            else if(i==coordenate_X || i==coordenate_X+Window_Width)
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

void Summon_Window(short _coordenate_X,short _coordenate_Y,short _Window_Width,short _Window_Height,const char *Head_Title,const char *Menu_Title,const char *Mod_Title,const char *Selec_Option_Title,const char *Option_Title){
window( _coordenate_X,_coordenate_Y,_Window_Width,_Window_Height);

            rlutil::setColor(cROJO);
        gotoXY(50,2);
        cout<<Head_Title;
 rlutil::setColor(cVERDE);
        gotoXY(31,4);
        cout<<"====================================================================="<<endl;
        gotoXY(50,5);
        cout<<Menu_Title;
        rlutil::setColor(cAZUL_CLARO);
        gotoXY(65,5);
        cout<<Mod_Title;
        rlutil::setColor(cVERDE);
        gotoXY(31,6);
        cout<<"---------------------------------------------------------------------"<<endl;
        gotoXY(31,32);
        cout<<"_____________________________________________________________________"<<endl;

        gotoXY(31,36);
        cout<<"---------------------------------------------------------------------"<<endl;

        rlutil::setColor(cMARRON);
         gotoXY(40,37);
        cout<<Selec_Option_Title;

        rlutil::setColor(cVERDE);
        gotoXY(31,38);
        cout<<"====================================================================="<<endl;
        rlutil::setColor(cAZUL_CLARO);
        gotoXY(55,39);
          cout<<Option_Title;

}

};

#endif // CLASS_WINDOW_H_INCLUDED

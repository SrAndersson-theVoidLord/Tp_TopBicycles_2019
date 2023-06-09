#ifndef CLASS_BUTTON_H_INCLUDED
#define CLASS_BUTTON_H_INCLUDED

#include <stdio.h>
#include <windows.h>

class Button {
private:
    short coordenate_X;
    short coordenate_Y;
    short Button_Width;
    short Button_Height;
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


void button(short iniX, short iniY, short ancho, short alto, short colorLinea=cVERDE, short colorFondo=cNEGRO)
{
coordenate_X=iniX;
coordenate_Y=iniY;
Button_Width=ancho;
Button_Height=alto;
Line_color=colorLinea;
Background_color=colorFondo;

    int i, j;
    for(i=coordenate_X; i<=coordenate_X+Button_Width; i++)
    {
        for(j=coordenate_Y; j<=coordenate_Y+Button_Height; j++)
        {
            gotoXY(i,j);
            textcolor(Line_color, Background_color);
///Arriba izquierda
            if(i==coordenate_X && j==coordenate_Y)
            {
                cout << (char) 201;
            }
///Arriba derecha
            else if(i==coordenate_X+Button_Width && j==coordenate_Y)
            {
                cout << (char) 187;
            }
///Abajo izquierda
            else if(i==coordenate_X && j==coordenate_Y+Button_Height)
            {
                cout << (char) 200;
            }
///Abajo derecha
            else if(i==coordenate_X+Button_Width && j==coordenate_Y+Button_Height)
            {
                cout << (char) 188;
            }
///Lineas arriba y abajo
            else if(j==coordenate_Y || j==coordenate_Y+Button_Height)
            {
                cout << (char) 205;
            }

///Lineas izquierda y derecha
            else if(i==coordenate_X || i==coordenate_X+Button_Width)
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

void Summon_Button(short _coordenate_X,short _coordenate_Y,short _Button_Width,short _Button_Height,const char*Name,short _Line_Color=cVERDE,short Text_Color=cVERDE,short _Background_Color=cNEGRO ){
button( _coordenate_X,_coordenate_Y,_Button_Width,_Button_Height,_Line_Color,_Background_Color);

int p,t,h;
 h = p = t=strlen(Name);
if(t>13) t-=10;
if(p<=31) t=5;
if(h>=31) t=5;
if(p<=13) t=0;
gotoXY(60-t,_coordenate_Y+1);
rlutil::setColor(Text_Color);
cout<<Name;

}

};
#endif // CLASS_BUTTON_H_INCLUDED

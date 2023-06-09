#ifndef CLASS_LOADING_BAR_H_INCLUDED
#define CLASS_LOADING_BAR_H_INCLUDED
class Loading {
private:


public:

     void gotoXY(int x, int y)
{
    COORD coord = {x, y};

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    return;
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
    strcpy(f,"CARGANDO ");
    break;
    case 2:
    strcpy(f,"HACIENDO ");
    break;
    case 3:
    strcpy(f,"GUARDANDO ");
    break;
    case 4:
    strcpy(f,"BORRANDO ");
    break;
case 5:
    strcpy(f,"PASANDO ");
    break;

}
switch(tipo){
case 1:
    strcpy(t,"SISTEMA");
    break;
    case 2:
    strcpy(t,"ARCHIVO");
    break;
    case 3:
    strcpy(t,"Back-up");
    break;
    case 4:
    strcpy(t,"ARCHIVOS");
    break;
    case 5:
    strcpy(t,"ARCHIVOS a PDF");
    break;

}



gotoXY(45,33);
    cout<<f<<t;

gotoXY(45,34);
loading_Bar();

if(tipo==1||tipo==2){
        gotoXY(45,36);
    cout<<t<<" CORRECTAMENTE CARGADO";
}


}



};


#endif // CLASS_LOADING_BAR_H_INCLUDED

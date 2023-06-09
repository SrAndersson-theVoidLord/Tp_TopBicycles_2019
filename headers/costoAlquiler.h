#ifndef COSTOALQUILER_H_INCLUDED
#define COSTOALQUILER_H_INCLUDED

float costoPorMinuto();
void Alta_inicial_o_Modificacion();

/////////////////////


void Alta_inicial_o_Modificacion(){
float costoAlquiler;
Archivo a; FILE *p;
int escribio;
p = fopen (a.getFILE_COSTOS(), a.getMODO_APERTURA_WRITE_FILE());///modo apaertura write file borra lo anterior y sobreescribe con el valor nuevo
cout <<"-----------------------------\n";
cout <<"VALOR ALQUILER POR MINUTO: $ ";
cin >> costoAlquiler;

system("cls");
escribio = fwrite(&costoAlquiler, sizeof(float), 1, p);
    if(escribio == 1){
        setColor(GREEN);
        cout<<"\n\n\t\tSE CAMBIO EL PRECIO POR MINUTO"; system("pause>null");
    }
    else {
            setColor(RED);
            cout <<"ERROR DE ARCHIVO, NO SE CAMBIO EL PRECIO"; system("pause>null"); }

fclose(p);
}
float costoPorMinuto(){
    float costoAlquiler;
    Archivo a;
    FILE *p;
    p=fopen(a.getFILE_COSTOS(), a.getMODO_APERTURA_READ_FILE());
    if(p==NULL){ cout <<"ERROR AL ABRIR EL ARCHIVO"; system("pause"); return -3;}
    fread(&costoAlquiler, sizeof(float),1,p);

    fclose(p);

    return costoAlquiler;
}
/*
void Modificación(){
float costoAlquiler;
p = fopen ("costos.dat", "rb+");
cin >> costoAlquiler;
fwrite(&costoAlquier, sizeof(float), 1, p);
fclose(p);
}

*/
///modificacion no lo vamos a usar porque la funcion que hice arriva ya sobreescribe el precio.

#endif // COSTOALQUILER_H_INCLUDED

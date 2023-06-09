///Autor:L.N.G.
///Fecha:
///Comentario:

#include <iostream>
#include <cstdlib>
#include<cstdio>
#include<cstring>
#include <locale.h>
using namespace std;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void convierte_trescifras(int N, char *cad)
{
int co,re1,re2,re3;
div_t d;
char uni[8],dec[19],cen[13];
d = div(N,10);
co = d.quot;
re1 = d.rem;
switch(re1)
{
case 0:uni[0] = 0;break;
case 1:strcpy(uni,"uno");break;
case 2:strcpy(uni,"dos");break;
case 3:strcpy(uni,"tres");break;
case 4:strcpy(uni,"cuatro");break;
case 5:strcpy(uni,"cinco");break;
case 6:strcpy(uni,"seis");break;
case 7:strcpy(uni,"siete");break;
case 8:strcpy(uni,"ocho");break;
case 9:strcpy(uni,"nueve");break;
}
d = div(co,10);
co = d.quot;
re2 = d.rem;
switch(re2)
{
case 1:strcpy(dec,"diez");break;
case 2:if(re1) strcpy(dec,"veinti");else strcpy(dec,"veinte");break;
case 3:strcpy(dec,"treinta");break;
case 4:strcpy(dec,"cuarenta");break;
case 5:strcpy(dec,"cincuenta");break;
case 6:strcpy(dec,"sesenta");break;
case 7:strcpy(dec,"setenta");break;
case 8:strcpy(dec,"ochenta");break;
case 9:strcpy(dec,"nuventa");
}
d = div(co,10);
co = d.quot;
re3 = d.rem;
switch(re3)
{
case 0:cen[0] = 0;break;
case 1:if (re1 || re2 ) strcpy(cen,"ciento");else strcpy(cen,"cien");break;
case 2:strcpy(cen,"doscientos");break;
case 3:strcpy(cen,"trescientos");break;
case 4:strcpy(cen,"cuarocientos");break;
case 5:strcpy(cen,"quinientos");break;
case 6:strcpy(cen,"seiscientos");break;
case 7:strcpy(cen,"setecientos");break;
case 8:strcpy(cen,"ochocientos");break;
case 9:strcpy(cen,"nuvecientos");
}
cad = strcat(cad,cen);
// si hay decenas las escribimos
if(re2)
{ //si hay centenas ponemos un espacio para separar
if(re3)	cad = strcat(cad," ");
cad = strcat(cad, dec);
}
if(re1)
{
//si hay unidades miramos las decenas. Ejem.
// 635 = "seiscientos treinta y cinco" lleva una "y", o el siguiente
// 625 = "seiscientos veinticinco" no tiene "y"
if( re2 )
{
if( re2 != 2 ) cad = strcat(cad," y ");
}
else
{
//si no hay decenas, pero si centenas ponemos un espacio
if(re3 ) cad = strcat(cad," ");
}
cad = strcat(cad,uni);
}
}

void convierte(long N, char *cad)
{
char res[4][30], cal[4][9];
int i = 0, j;
ldiv_t d;
cal[0][0]=0;
strcpy(cal[1],"mil");
strcpy(cal[2],"millones");
strcpy(cal[3],"mil");
char trescifras[30];
trescifras[0] = 0;
// dividimos en grupos de tres cifras y convertimos
do
{
d = ldiv(N,1000);
convierte_trescifras((int)d.rem,trescifras);
strcpy(res[i++],trescifras);
trescifras[0] = 0;
N = d.quot;
}while(d.quot);
// unimos los resultados de las conversiones parciales poniendo mil, millones etc...
//he probado con varios numeros como 2.132.647.345 y creo que funciona perfectamente.
// el codigo se puede hacer mas fino y elegante, pero menos entendible
for(j = i - 1; j > -1; j--)
{
if( strcmp(res[j],""))
{
cad = strcat(cad,res[j]);
cad = strcat(cad," ");
cad = strcat(cad,cal[j]);
cad = strcat(cad," ");
}
}
}

int main(int argc,char *argv[])
{
char numero[300];
numero[0] = 0;

convierte(atol(argv[1]), numero);
printf("%s\n",numero);
convierte(3,numero);
return (0);
}

#ifndef CLASS_BICICLETAS_H_INCLUDED
#define CLASS_BICICLETAS_H_INCLUDED
///****************************
///EmpleadoTOTIPOS DE LAS FUNCIONES EXTERNAS:
int buscar_Bicicleta(char *);
void alta_Bicicleta();
void modifica_pu();
void baja_logica_Bicicleta();
void listar_Bicicleta();
void menu_Bicicletas();
void listarBicicletaPorId();
void mostrarEstadoBicicleta(int);

///*****************************

///CLASE BICICLETA:
class Bicicleta
	{
	private:
		char Id_Bicicleta[5];
		char Modelo_De_Bicicleta[30];
		char Marca[30];
		int Estado;
	public:

		Bicicleta();

		int Cargar();
		void Mostrar();
		char * getId_Bicicleta(){return Id_Bicicleta;};
		char * getModelo_De_Bicicleta(){return Modelo_De_Bicicleta;};
        char * getMarca(){return Marca;};
		int getEstado(){return Estado;};
		void setId_Bicicleta(char *c){strcpy(Id_Bicicleta,c);};
		void setModelo_De_Bicicleta(char *d){strcpy(Modelo_De_Bicicleta,d);};
		void setMarca(char *m){strcpy(Marca,m);};
		void setEstado(int s){Estado=s;};
		void Grabar_en_disco(void);
		int Leer_de_disco(int);
		void Modificar_en_disco(int);
		};
//****************
///DESARROLLO DE LOS METODOS DE LA CLASE BICICLETA:
Bicicleta::Bicicleta()
  {
    strcpy(Id_Bicicleta,"0000");
    strcpy(Modelo_De_Bicicleta,"vacio");
    strcpy(Marca,"Vacio");
    Estado=0;
    }


int Bicicleta::Cargar()
	{
	int encontro;
	cout<<"CODIGO DE BICICLETA: ";
	cin>>Id_Bicicleta;
	encontro=buscar_Bicicleta(Id_Bicicleta);
	if(encontro==-1)
	{
    cout<<"MODELO:  ";
    cin>>Modelo_De_Bicicleta;

    cout<<"MARCA: ";
	cin>>Marca;

    Estado=1;
    return 1;
	}
	return 0;
	}

void Bicicleta::Mostrar()
	{
    cout <<"---------------------\n";
	cout<<"CODIGO DE BICICLETA: ";
	cout<<Id_Bicicleta<<endl;
	cout<<"MODELO: ";
	cout<<Modelo_De_Bicicleta<<endl;
	cout<<"MARCA: ";
	cout<<Marca<<endl;

	}


void Bicicleta::Grabar_en_disco(void)
	{
	    Archivo a;
	FILE *p;
	p=fopen(a.getFILE_BICICLETAS(),a.getMODO_APERTURA_ADD_TO_FILE());
	if(p==NULL){
             setColor(RED);
            cout<<"ERROR: Error de archivo";exit(1);}
	fwrite(this,sizeof *this,1,p);
	fclose(p);
	}

int Bicicleta::Leer_de_disco(int pos)
	{
	    Archivo a;
	int x;
	FILE *p;
	p=fopen(a.getFILE_BICICLETAS(),a.getMODO_APERTURA_READ_FILE());
	if(p==NULL)
		{ setColor(RED);
		cout<<"ERROR: No existe el archivo";
		cout<<"Presione una tecla para continuar";
    system("pause<null");
		return 0;
		}
	fseek(p,pos*sizeof *this,0);
	x=fread(this,sizeof *this,1,p);
	fclose(p);
	return x;
	}

void Bicicleta::Modificar_en_disco(int pos)
	{
	    Archivo a;
	FILE *p;
	p=fopen(a.getFILE_BICICLETAS(),a.getMODO_APERTURA_MODIFI_FILE());
	if(p==NULL){
             setColor(RED);
            cout<<"ERROR: Error de archivo";exit(1);}
	fseek(p,pos*sizeof *this,0);
	fwrite(this,sizeof *this,1,p);
	fclose(p);
	}

///DESARRORO DE LAS FUNCIONES EXTERNAS:
int buscar_Bicicleta(char *cod)
{
	int pos=0;
	Bicicleta reg;
	while(reg.Leer_de_disco(pos)==1)
		{
		if(strcmp(cod,reg.getId_Bicicleta())==0 )//&& reg.getEstado()==1)
			return pos;
		pos++;
		}
	return -1;
}


void alta_Bicicleta()
{
	Bicicleta reg;
	system("cls");
	if(reg.Cargar())
    reg.Grabar_en_disco();
  else
  	{ setColor(RED);
	  cout<<"ERROR: Ya existe ese código";
	  cout<<"Presione una tecla para continuar";
	  system("pause>null");

	  }
}

void modifica_Estado()
{
	char cod[5];
	int nEstado;
	int pos;
	Bicicleta reg;
	system("cls");
	cout<<"Ingrese el codigo del Bicicleta a modificar:";
	cin>>cod;
	pos=buscar_Bicicleta(cod);
	if(pos!=-1)
		{
		cout<<"Ingrese el nuevo Estado: ";
		cin>>nEstado;
		if(nEstado>=0 && nEstado<4){
		reg.Leer_de_disco(pos);
		reg.setEstado(nEstado);
		reg.Modificar_en_disco(pos);
		cout <<"CAMBIO DE ESTADO CORRECTAMENTE ";system("pause>null");
		}
		else { cout <<"ERROR: ERROR DE ESTADO INGRESADO "; system("pause>null");}
		}
	else
		{
		     setColor(RED);
		cout<<"ERROR: No existe el Bicicleta"<<endl;
		cout<<"Presione una tecla para continuar";
		system("pause>null");
		}
}

void baja_logica_Bicicleta()
{
	char cod[5];
	int pos;
	Bicicleta reg;
	system("cls");
	cout<<"Ingrese el codigo del Bicicleta a eliminar:";
	cin>>cod;
	pos=buscar_Bicicleta(cod);
	if(pos!=-1)
		{
		reg.Leer_de_disco(pos);
		reg.setEstado(0);
		reg.Modificar_en_disco(pos);
		cout <<"BICICLETA ELIMINADA ";system("pause>null");
		}
	else
		{ setColor(RED);
		cout<<"ERROR: No existe el Bicicleta"<<endl;
		cout<<"Presione una tecla para continuar";
		system("pause>null");
		}

}


void listar_Bicicleta()
	{
	Bicicleta reg;
	int pos=0;
	system("cls");
	while(reg.Leer_de_disco(pos++)==1)
		{
		if(reg.getEstado()==1)
			{reg.Mostrar();
			//system("pause>null");
			}
		}
	if(pos==1)
		{ setColor(RED);
		cout<<"ERROR: No existen registros"<<endl;
		cout<<"Presione una tecla para continuar";
		system("pause>null");
		}
	}

void listarBicicletaPorId(){ ///

    char id[5];

    system("cls");

    cout <<"LISTAR BICICLETA POR ID: \n";
    cout <<"-----------------------------\n";
    cout <<"Ingrese Id de Bicicleta: ";
    cin  >>id;

    Bicicleta reg;
	int pos=0;
	system("cls");
	while(reg.Leer_de_disco(pos++)==1)
		{
            if(strcmp(id,reg.getId_Bicicleta())==0)
            {
            reg.getEstado();
			reg.Mostrar();
			mostrarEstadoBicicleta(reg.getEstado());
			//system("pause>null");
			return ;
            }
		}
 setColor(RED);

		cout<<"\n\n\t\tERROR: BICICLETA NO EXISTE "<<endl;
		//cout<<"Presione una tecla para continuar";
		system("pause>null");



}

void mostrarEstadoBicicleta(int estado){

    switch(estado){

 case 0 : cout <<"\n BICICLETA DADA DE BAJA";
    break;
 case 1 : cout <<"\n BICICLETA DISPONIBLE";
    break;
 case 2 : cout <<"\n BICICLETA EN USO";
    break;
 case 3 : cout <<"\n BICICLETA EN REPARACION ";
    break;

    }

}
//FIN FUNCIONES EXTERNAS





#endif // CLASS_BICICLETAS_H_INCLUDED

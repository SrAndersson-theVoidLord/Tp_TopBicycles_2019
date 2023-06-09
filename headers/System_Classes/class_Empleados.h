#ifndef CLASS_EMPLEADOS_H_INCLUDED
#define CLASS_EMPLEADOS_H_INCLUDED

/////////////////////
///PROTOTIPOS DE LAS FUNCIONES EXTERNAS:
int buscar_Empleado(char *);
void alta_Empleado();
void modifica_Empleado();
void baja_logica_Empleado();
void listar_Empleado();
void menu_Empleados();
void listarEmpleadoPorId();
void mostrarEstadoEmpleado(int);
bool validarAsciiEmpleado(char *, int);
////////////////////
///DEFINICION DE LA CLASE Empleado:

class Empleado
	{
	private:
	    ///EL EMPLEADO DEBERIA TENER DNI
		char Id_Empleado[6];
		char Apellido[30];
		char Nombre[30];
		char Direccion[30];
		char Localidad[30];
		char Nro_Telefono[15];
		int Estado;
	public:
	     Empleado();
		int Cargar();
		void Mostrar();
		char * getId_Empleado(){return Id_Empleado;};

		char * getNombre(){return Nombre;};
		char * getApellido(){return Apellido;};
		char * getDireccion(){return Direccion;};
		char * getLocalidad(){return Localidad;};
		char * getNro_Telefono(){return Nro_Telefono;};
		int getEstado(){return Estado;};
		void setId_Empleado(char *c){strcpy(Id_Empleado,c);};
		void setNombre(char *d){strcpy(Nombre,d);};
		void setDireccion(char *di){strcpy(Direccion,di);};
		void setLocalidad(char *l){strcpy(Localidad,l);};
		void settel(char *tel){strcpy(Nro_Telefono,tel);};
		void setEstado(int s){Estado=s;};
		void Grabar_en_disco(void);
		int Leer_de_disco(int);
		void Modificar_en_disco(int);
		};
//****************
///DESARROLLO DE LOS METODOS DE LA CLASE EmpleadoES:
Empleado::Empleado(){

		strcpy(Id_Empleado,"vacio");
		strcpy(Apellido,"vacio");
		strcpy(Nombre,"vacio");
		strcpy(Direccion,"vacio");
		strcpy(Localidad,"vacio");
		strcpy(Nro_Telefono,"vacio");
		Estado=0;
}
int Empleado::Cargar()
	{
  int encontro;
	cout<<"Ingrese el codigo de Empleado: ";
	cin>>Id_Empleado;
	if(strlen(Id_Empleado)!=4){
             setColor(RED);
    cout <<"ERROR: ERROR AL CARGAR ID EMPLEADO\n EL ID DEBE SER DE 4 CIFRAS "; system("pause>null"); return -1;}
	if(validarAsciiEmpleado(Id_Empleado,4)){
             setColor(RED);
            cout <<"ERROR: ERROR EL ID SOLO PUEDEN SER NUMEROS (0-9)"; system("pause>null"); return -1;}
	cin.ignore();
    encontro=buscar_Empleado(Id_Empleado);
	if(encontro>=0){ /**cout <<"EMPLEADO YA EXTISTE ";*/ system("pause"); return 0;}
	else{
    cout<<"Ingrese el Apellido:  ";

    gets(Apellido);
strlen(Apellido);
while(strlen(Apellido)==0){
setColor(LIGHTRED);
    cout<<"ERROR: CAMPO VACIO POR FAVOR INGRESE UNO O MAS APELLIDOS "<<endl;
     setColor(LIGHTGREEN);
    cout<<"APELLIDO: ";
    setColor(WHITE);
gets(Apellido);
strlen(Apellido);
}
      cout<<"Ingrese el Nombre:  ";

        gets(Nombre);
strlen(Apellido);
while(strlen(Nombre)==0){
setColor(LIGHTRED);
    cout<<"ERROR: CAMPO VACIO POR FAVOR INGRESE UNO O MAS NOMBRES "<<endl;
     setColor(LIGHTGREEN);
    cout<<"NOMBRE: ";
    setColor(WHITE);
gets(Nombre);
strlen(Nombre);
}
    cout<<"Ingrese la Direccion:  ";

      gets(Direccion);
strlen(Direccion);
while(strlen(Direccion)==0){
setColor(LIGHTRED);
    cout<<"ERROR: CAMPO VACIO POR FAVOR INGRESE UNA DIRECCION VALIDA "<<endl;
     setColor(LIGHTGREEN);
    cout<<"DIRECCION: ";
    setColor(WHITE);
gets(Direccion);
strlen(Direccion);
}

    cout<<"Ingrese la Localidad:  ";


      gets(Localidad);
strlen(Localidad);
while(strlen(Localidad)==0){
setColor(LIGHTRED);
    cout<<"ERROR: CAMPO VACIO POR FAVOR INGRESE UNA LOCALIDAD VALIDA "<<endl;
     setColor(LIGHTGREEN);
    cout<<"LOCALIDAD: ";
    setColor(WHITE);
gets(Localidad);
strlen(Localidad);
}

    cout<<"Ingrese el telefono:  ";


    gets(Nro_Telefono);
strlen(Nro_Telefono);
while(strlen(Nro_Telefono)==0){
setColor(LIGHTRED);
    cout<<"ERROR: CAMPO VACIO POR FAVOR INGRESE UNA LOCALIDAD VALIDA "<<endl;
     setColor(LIGHTGREEN);
    cout<<"TELEFONO: ";
    setColor(WHITE);
gets(Nro_Telefono);
strlen(Nro_Telefono);
}


    Estado=1;
    return 1;
	}
	return 0;
	}

void Empleado::Mostrar()
	{
    cout <<"---------------------\n";
	cout<<"Codigo de Empleado: ";
	cout<<Id_Empleado<<endl;
	cout<<"Apellido: ";
    cout<<Apellido<<endl;
	cout<<"Nombre: ";
    cout<<Nombre<<endl;
    cout<<"Direccion: ";
    cout<<Direccion<<endl;
    cout<<"Localidad: ";
    cout<<Localidad<<endl;
    cout<<"Telefono: ";
    cout<<Nro_Telefono<<endl;
	}




void Empleado::Grabar_en_disco(void)
	{
	    Archivo a;
	FILE *p;
	p=fopen(a.getFILE_EMPLEADOS(),a.getMODO_APERTURA_ADD_TO_FILE());
	if(p==NULL){

             setColor(RED);
    cout<<"ERROR: Error de archivo";exit(1);}
	fwrite(this,sizeof *this,1,p);
	fclose(p);
	}

int Empleado::Leer_de_disco(int pos)
	{
	    Archivo a;
	int x;
	FILE *p;
	p=fopen(a.getFILE_EMPLEADOS(),a.getMODO_APERTURA_READ_FILE());
	if(p==NULL)
		{ setColor(RED);
		cout<<"ERROR: No existe el archivo";
		cout<<"Presione una tecla para continuar";
		system("pause>null");
		return 0;
		}
	fseek(p,pos*sizeof *this,0);
	x=fread(this,sizeof *this,1,p);
	fclose(p);
	return x;
	}

void Empleado::Modificar_en_disco(int pos)
	{
	    Archivo a;
	FILE *p;
	p=fopen(a.getFILE_EMPLEADOS(),a.getMODO_APERTURA_MODIFI_FILE());
	if(p==NULL){
             setColor(RED);
    cout<<"ERROR: Error de archivo";exit(1);}
	fseek(p,pos*sizeof *this,0);
	fwrite(this,sizeof *this,1,p);
	fclose(p);
	}
//*****************************
///DESARRORO DE LAS FUNCIONES EXTERNAS:

int buscar_Empleado(char *cod)
{
	int pos=0;
	Empleado reg;
	while(reg.Leer_de_disco(pos)==1)
		{
		if(strcmp(cod,reg.getId_Empleado())==0 ) //&& reg.getEstado()==1)
			return pos;
		pos++;
		}
	return -1;
}


void alta_Empleado()
{
	Empleado reg;
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

void modifica_Empleado()
{
	char cod[5], tel[15];
	int pos;
	Empleado reg;
	system("cls");
	cout<<"Ingrese el codigo del Empleado a modificar:";
	cin>>cod;
	pos=buscar_Empleado(cod);
	if(pos!=-1)
		{
		cout<<"Ingrese el nuevo telefono: ";
		cin>>tel;
		reg.Leer_de_disco(pos);
		reg.settel(tel);
		reg.Modificar_en_disco(pos);
		}
	else
		{ setColor(RED);
		cout<<"ERROR: No existe el Empleado"<<endl;
		cout<<"Presione una tecla para continuar";
		system("pause>null");
		}
}

void baja_logica_Empleado()
{
	char cod[5];
	int pos;
	Empleado reg;
	system("cls");
	cout<<"Ingrese el codigo del Empleado a eliminar:";
	cin>>cod;
	pos=buscar_Empleado(cod);
	if(pos!=-1)
		{
		reg.Leer_de_disco(pos);
		if(reg.getEstado()==0){ cout <<"EL EMPLEADO YA ESTABA ELIMINADO"; system("pause>null");}
		else {reg.setEstado(0);
		reg.Modificar_en_disco(pos);

		cout <<"EMPLEADO ELIMINADO "; system("pause>null");
		}
		}
	else
		{ setColor(RED);
		cout<<"ERROR:No existe el Empleado"<<endl;
		cout<<"Presione una tecla para continuar";
		system("pause>null");
		}

}


void listar_Empleado()
	{
	Empleado reg;
	int pos=0;
	system("cls");
	while(reg.Leer_de_disco(pos++)==1)
		{
		if(reg.getEstado()==1)
			{reg.Mostrar();
		//	system("pause>null");
			}
		}
		if(pos==1)
		{
		     setColor(RED);
		cout<<"ERROR: No existen registros"<<endl;
		cout<<"Presione una tecla para continuar";
		system("pause>null");
		}

	}


void listarEmpleadoPorId(){ ///

    char id[6];

    system("cls");

    cout <<"LISTAR EMPLAEADO POR ID: \n";
    cout <<"-----------------------------\n";
    cout <<"Ingrese Id de Empleado: ";
    cin  >>id;

    Empleado reg;
	int pos=0;
	system("cls");

	while (reg.Leer_de_disco(pos++)==1){

            if (strcmp(id, reg.getId_Empleado() )==0){

            reg.getId_Empleado();
            reg.Mostrar();
            mostrarEstadoEmpleado(reg.getEstado());
            return;
            }

		}
 setColor(RED);

		cout<<"\n\n\t\tERROR: EMPLEADO NO EXISTE "<<endl;
		//cout<<"Presione una tecla para continuar";
		system("pause>null");
}

void mostrarEstadoEmpleado(int estado){


    if(estado==1){

        cout <<"Estado Empleado: Activo";
    }
    else{cout <<"Estado Empleado: Dado De Baja ";}


}
bool validarAsciiEmpleado(char *x, int tam){

    for (int i=0; i<tam;i++){
    int valorAscii = x[i];

        if(valorAscii<48||valorAscii>57){

            return true;
        }}

        return false;
}



#endif // CLASS_EMPLEADOS_H_INCLUDED

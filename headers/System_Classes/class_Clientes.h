#ifndef CLASS_CLIENTES_H_INCLUDED
#define CLASS_CLIENTES_H_INCLUDED

///EmpleadoTOTIPOS DE LAS FUNCIONES EXTERNAS:
int buscar_cli(char *);
void alta_cli();
void modifica_tel();
void baja_logica_cli();
void listar_cli();
void menu_clientes();
void listarClientePorDni();
void mostrarEstadoCliente(bool );
void listarTodosLosClientesPorApellido();
int contarRegistrosCliente();
////////////////////
///DEFINICION DE LA CLASE CLIENTE:

class Cliente
	{
	private:
		char DNI_Cliente[8];
		char Apellido[30];
		char Nombre[30];
		char email[30];
		char Nro_Telefono[15];
		int Estado;
	public:
	    Cliente();
		int Cargar();
		void Mostrar();
		char * getDNI_Cliente(){return DNI_Cliente;};
		char * getNombre(){return Nombre;};
		char * getApellido(){return Apellido;}
		char * getEmail(){return email;}
		///char * getDireccion(){return Direccion;};
		///char * getLocalidad(){return Localidad;};
		char * getNro_Telefono(){return Nro_Telefono;};
		int getEstado(){return Estado;};
		void setDNI_Cliente(char *c){strcpy(DNI_Cliente,c);};
		void setNombre(char *d){strcpy(Nombre,d);};
		///void setDireccion(char *di){strcpy(Direccion,di);};
		///void setLocalidad(char *l){strcpy(Localidad,l);};
		void settel(char *tel){strcpy(Nro_Telefono,tel);};
		void setEstado(int s){Estado=s;};
		void Grabar_en_disco(void);
		int Leer_de_disco(int);
		void Modificar_en_disco(int);
		void operator=(Cliente &obj){

		strcpy(DNI_Cliente,obj.getDNI_Cliente());
		strcpy(Apellido,obj.getApellido());
		strcpy(Nombre,obj.getNombre());
		strcpy(email,obj.getEmail());
		strcpy(Nro_Telefono,obj.getNro_Telefono());
		Estado=obj.getEstado();
		}
		};
//****************
///DESARROLLO DE LOS METODOS DE LA CLASE CLIENTE:
Cliente::Cliente(){
        strcpy(DNI_Cliente,"vacio");
        strcpy(Apellido,"vacio");
        strcpy(Nombre,"vacio");
        strcpy(email,"vacio");
        strcpy(Nro_Telefono,"vacio");
        Estado=0;

}

int Cliente::Cargar()
	{
  int encontro;
	cout<<"Ingrese el Dni de cliente (sin puntos solo numeros): ";
	cin>>DNI_Cliente;
	if (strlen(DNI_Cliente)>7){
	     setColor(RED);
            cout <<"ERROR: DNI MUY LARGO INTENTE DE NUEVO"; system("pause"); return 0;}// nota cambiar el tamaño de dni a [9]
    encontro=buscar_cli(DNI_Cliente);
	if(encontro==-1)
	{

    cout<<"Ingrese el Nombre:  ";
    cin>>Nombre;
        //gets(Nombre);
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
    //cout<<"Ingrese la Direccion:  ";
    //cin>>Direccion;
    //cout<<"Ingrese la Localidad:  ";
    //cin>>Localidad;

    cout <<"Ingrese Apellido; ";
    cin>>Apellido;
    //gets(Apellido);
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
    cout <<"Ingrese e-mail; ";
    cin>>email;
    //gets(email);
strlen(email);
while(strlen(email)==0){
setColor(LIGHTRED);
    cout<<"ERROR: CAMPO VACIO POR FAVOR INGRESE UNA DIRECCION DE MAIL VALIDA "<<endl;
     setColor(LIGHTGREEN);
    cout<<"E-MAIL: ";
    setColor(WHITE);
gets(email);
strlen(email);
}


    cout<<"Ingrese el telefono:  ";
    cin>>Nro_Telefono;
     //  gets(Nro_Telefono);
strlen(Nro_Telefono);
while(strlen(Nro_Telefono)==0){
setColor(LIGHTRED);
    cout<<"ERROR: CAMPO VACIO POR FAVOR INGRESE UN NRO DE TELEFONO VALIDO "<<endl;
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

void Cliente::Mostrar()
	{
    cout <<"------------------\n";
	cout<<"Codigo de cliente: ";
	cout<<DNI_Cliente<<endl;
	cout<<"Nombre: ";
    cout<<Nombre<<endl;
    cout<<"Apellido: ";
    cout<<Apellido<<endl;
    cout<<"email: ";
    cout<<email<<endl;
    cout<<"Telefono: ";
    cout<<Nro_Telefono<<endl;
	}

void Cliente::Grabar_en_disco(void)
	{
	    Archivo a;
	FILE *p;
	p=fopen(a.getFILE_CLIENTES(),a.getMODO_APERTURA_ADD_TO_FILE());
	if(p==NULL){ setColor(RED);
            cout<<"ERROR: Error de archivo";exit(1);}
	fwrite(this,sizeof *this,1,p);
	fclose(p);
	}

int Cliente::Leer_de_disco(int pos)
	{
	    Archivo a;
	int x;
	FILE *p;
	p=fopen(a.getFILE_CLIENTES(),a.getMODO_APERTURA_READ_FILE());
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

void Cliente::Modificar_en_disco(int pos)
	{
	    Archivo a;
	FILE *p;
	p=fopen(a.getFILE_CLIENTES(),a.getMODO_APERTURA_MODIFI_FILE());
	if(p==NULL){
             setColor(RED);
            cout<<"ERROR: Error de archivo";exit(1);}
	fseek(p,pos*sizeof *this,0);
	fwrite(this,sizeof *this,1,p);
	fclose(p);
	}

//*****************************
///DESARRORO DE LAS FUNCIONES EXTERNAS:

int buscar_cli(char *cod)
{
	int pos=0;
	Cliente reg;
	while(reg.Leer_de_disco(pos)==1)
		{
		if(strcmp(cod,reg.getDNI_Cliente())==0)///&& reg.getEstado()==1)
            {
			return pos;}
		pos++;
		}
			return -1;
}
int buscar_cli_con_estado(char *cod)
{
	int pos=0;
	Cliente reg;
	while(reg.Leer_de_disco(pos)==1)
		{
		if(strcmp(cod,reg.getDNI_Cliente())==0&& reg.getEstado()==1)
            {
			return pos;}
		pos++;
		}
			return -1;
}


void alta_cli()
{
	Cliente reg;
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

void modifica_tel()
{
	char cod[5], tel[15];
	int pos;
	Cliente reg;
	system("cls");
	cout<<"Ingrese el codigo del cliente a modificar:";
	cin>>cod;
	pos=buscar_cli(cod);
	if(pos!=-1)
		{
		cout<<"Ingrese el nuevo telefono: ";
		cin>>tel;
		reg.Leer_de_disco(pos);
		reg.settel(tel);
		reg.Modificar_en_disco(pos);
		setColor(GREEN);
		cout<<"TELEFONO MODIFICADO"<<endl;

		system("pause>null");
		}
	else
		{ setColor(RED);
		cout<<"ERROR: No existe el cliente"<<endl;
		cout<<"Presione una tecla para continuar";
		system("pause>null");
		}
}

void baja_logica_cli()
{
	char cod[5];
	int pos;
	Cliente reg;
	system("cls");
	cout<<"Ingrese el codigo del cliente a eliminar:";
	cin>>cod;
	pos=buscar_cli(cod);
	if(pos!=-1)
		{
		reg.Leer_de_disco(pos);
		reg.setEstado(0);
		reg.Modificar_en_disco(pos);
		cout <<"CLIENTE ELIMINADO ";
		system("pause>null");
		}
	else
		{ setColor(RED);
		cout<<"ERROR: No existe el cliente"<<endl;
		cout<<"Presione una tecla para continuar";
		system("pause>null");
		}

}


void listar_cli()
	{
	Cliente reg;
	int pos=0;
	system("cls");
	while(reg.Leer_de_disco(pos++)==1)
		{
		if(reg.getEstado()==1)
			{reg.Mostrar();
            // system("pause>null");
			}
		}
		if(pos==1)
		{ setColor(RED);
		cout<<"ERROR: No existen registros"<<endl;
		cout<<"Presione una tecla para continuar";
		system("pause>null");
		}

	}


void listarClientePorDni(){
    char dni[8];
    int pos;
    system("cls");
    cout <<"ELIMINAR CLIENTE POR DNI\n";
    cout <<".............................\n";
    cout <<"Ingrese Dni: ";
    cin  >>dni;
    if (strlen(dni)>8){
             setColor(RED);
    cout <<"ERROR: ERROR AL CARGAR DNI "; system("pause>null"); return; }
    Cliente reg;
    pos = buscar_cli(dni);

    if(pos >=0){
    reg.Leer_de_disco(pos);
    reg.Mostrar();
    mostrarEstadoCliente(reg.getEstado());

    system("pause>null");
    }
    else {
             setColor(RED);
    cout <<"ERROR: NO EXISTE DNI CARGADO"; system("pause>null"); return; }

}
void mostrarEstadoCliente(bool estado){


    if(estado==true){

        cout <<"Estado Cliente: Activo";
    }
    else{cout <<"Estado Cliente: Dado De Baja ";}


}
void listarTodosLosClientesPorApellido(){

    int c=0;

    c=contarRegistrosCliente();

    Cliente *reg;

    reg=new Cliente[c];
    if(reg==NULL) exit(1);
int     pos=0;
    for(int i=0;i<c;i++){
    reg[i].Leer_de_disco(pos++);

            reg[i].Mostrar();
    }

    //////////////////////
        int i,j,posmin;
        Cliente aux;
        for(i=0;i<c-1;i++)
        {
        posmin=i;
        for(j=i+1;j<c;j++){
        if( strcmp(reg[j].getApellido(),reg[posmin].getApellido())<0){
        posmin=j;
        aux=reg[i];

        reg[i]= reg[posmin];

        reg[posmin]=aux;}
        }}
    //////////////////////
    cout <<"\n\n CLIENTES ORDENADOS POR APELLIDO ALFABETICAMENTE\n";
    //     pos=0;
    for(int i=0;i<c;i++){
   // reg[i].Leer_de_disco(pos++);

            reg[i].Mostrar();
    }



delete reg;
}

int contarRegistrosCliente(){

    Archivo a;
	FILE *p;

    p=fopen(a.getFILE_CLIENTES(),a.getMODO_APERTURA_READ_FILE());
        if(p==NULL){
                 setColor(RED);
        cout <<"ERROR: ERROR AL ABRIR EL ARCHIVO"; system("pause"); return -3;}

    int tamanio;
  fseek(p, 0, SEEK_END);
  tamanio = ftell(p);
  fclose(p);
  return tamanio/sizeof(Cliente);

}

#endif // CLASS_CLIENTES_H_INCLUDED

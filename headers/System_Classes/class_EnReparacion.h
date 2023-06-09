#ifndef CLASS_ENREPARACION_H_INCLUDED
#define CLASS_ENREPARACION_H_INCLUDED


void listar_EnReparacion();
void alta_EnReparacion();
void modifica_Estado_enReparacion();
int buscar_Reparacion(int );
void baja_logica_EnReparacion();
void menuEnreparacion();
void IngresoTaller();
void salidaTaller();
int contarRegistrosEnReparacion();
void listarReparacionPorId();
void listarBicicletasReparadas();
void listarReparacionPorIdBicicleta();



class enReparacion{

    private:

        int Id; ///esto es autonumerico y no se repite
        char Id_Bicicleta[5];///debe existir en el archivo de bicicletas
        Fecha fechaIngreso;
        Fecha fechaSalida;
        char descripcion[80];
        bool Estado;
    public:
        enReparacion();
        void Cargar();
		void Mostrar();
		char * getId_Bicicleta(){return Id_Bicicleta;}
		char * getDescripcion(){return descripcion;}
		bool getEstado(){return Estado;}
		Fecha getFechaIngreso(){return fechaIngreso;}
		Fecha setFechaSalida(Fecha f){fechaSalida=f;}
        Fecha setFechaIngreso(Fecha f){fechaIngreso=f;}
        Fecha getFechaSalida(){return fechaSalida;}
		int getId (){return Id;}
		void setId_Bicicleta(char *c){strcpy(Id_Bicicleta,c);}
		void setDescripcion(char *d){strcpy(descripcion,d);}
		void setEstado(int s){Estado=s;}
		void setId(int id){Id=id;}
		bool Grabar_en_disco(void);
		int Leer_de_disco(int);
		bool Modificar_en_disco(int);
		void MostrarTodo();

};
///DESARROLLO DE LOS METODOS DE LA CLASE CLIENTE:

enReparacion::enReparacion(){

        Id=0;
        strcpy(Id_Bicicleta,"0000");

        strcpy(descripcion,"vacio");
        Estado=false;
}
void    enReparacion::Cargar(){

       /** cout <<"EN REPARACION"<<endl;
        cout <<"-----------------"<<endl;
        cout <<"ID: ";
        cin  >>Id; ///esto tiene  que ser autonumerico*/
        Fecha(); ///se carga la fecha automaticamente
        cout <<fechaIngreso.getDia()<<"/"<<fechaIngreso.getMes()<<"/"<<fechaIngreso.getAnio();
        cout <<endl;
        cout <<"Descripcion: "<<endl;
        cin.ignore();
        cin.getline(descripcion,80);
        Estado = true;
}

void    enReparacion::Mostrar(){

        cout <<"\n- - - - - - - - - - - - "<<endl;
        cout <<"ID: "<<Id<<endl;
        cout <<"ID BICICLETA: ";
        cout <<Id_Bicicleta;
        cout <<"\nFECHA: ";
        cout <<endl;
        fechaIngreso.MostrarFechaTexto();
        cout <<"\nDESCRIPCION: ";
        cout <<endl<<descripcion;
}

void    enReparacion::MostrarTodo(){

        cout <<"- - - - - - - - - - - - "<<endl;
        cout <<"ID: "<<Id<<endl;
        cout <<"BICICLETA: "<<Id_Bicicleta<<endl;
        cout <<"\nFECHA ALTA: ";
        cout <<endl;
        fechaIngreso.MostrarFechaTexto();

        cout <<"\nFECHA BAJA: ";
        cout <<endl;
        fechaSalida.MostrarFechaTexto();
        cout <<endl;
        cout <<"\nDESCRIPCION: ";
        cout <<endl<<descripcion;
        cout <<endl;
}

bool enReparacion::Grabar_en_disco(void)
	{
	    Archivo a;
	FILE *p;
	p=fopen(a.getFILE_REPARACIONES(),a.getMODO_APERTURA_ADD_TO_FILE());
	if(p==NULL){
             setColor(RED);
    cout<<"ERROR: Error de archivo"; return false;}
	fwrite(this,sizeof *this,1,p);
	fclose(p);

	return true;
	}

int enReparacion::Leer_de_disco(int pos)
	{
	    Archivo a;
	int x;
	FILE *p;
	p=fopen(a.getFILE_REPARACIONES(),a.getMODO_APERTURA_READ_FILE());
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

bool enReparacion::Modificar_en_disco(int pos)
	{
	    Archivo a;
	FILE *p;
	p=fopen(a.getFILE_REPARACIONES(),a.getMODO_APERTURA_MODIFI_FILE());
	if(p==NULL){
             setColor(RED);
    cout<<"ERROR: Error de archivo"; return false;}
	fseek(p,pos*sizeof *this,0);
	fwrite(this,sizeof *this,1,p);
	fclose(p);

	return true;
	}

///DESARRORO DE LAS FUNCIONES EXTERNAS:
int buscar_Reparacion(int cod)
{
	int pos=0;
	enReparacion reg;
	while(reg.Leer_de_disco(pos)==1)
		{
		if(cod==reg.getId())// && reg.getEstado()==1){
			return pos;
			pos++;
		}
	return -1;
}


void alta_EnReparacion()
{
    enReparacion reg;
	Bicicleta regbicicleta;
	char id[5];
	int posBici;
	system("cls");

	cout <<"Ingrese Id Bicicleta: ";
	cin  >>id;


	posBici = buscar_Bicicleta(id);

	if( posBici <0 ){
             setColor(RED);
    cout <<"ERROR: No Existe ID bicicleta "; system("pause>null"); return;   }
	regbicicleta.Leer_de_disco(posBici);
	reg.setId_Bicicleta(regbicicleta.getId_Bicicleta()); ///aca se cargar el id de bicicleta en reparaciones.
	if(regbicicleta.getEstado() == 0){
             setColor(RED);
    cout <<"ERROR: ERROR LA BICICLETA ESTA ELIMINADA"; system("pause>null"); return; }
	if(regbicicleta.getEstado()==2){
             setColor(RED);
    cout <<"ERROR: LA BICICLETA ESTA EN USO, DAR DE BAJA PRIMERO";system("pause>null"); return;}
    if(regbicicleta.getEstado()==3){
             setColor(RED);
    cout <<"ERROR EL ID BICICLETA YA ESTA SIENDO REPARADA ";system("pause>null"); return;}
	regbicicleta.Mostrar();
	cout <<"...................\n";
	reg.Cargar();
	reg.setId(contarRegistrosEnReparacion()+1);
    system("cls");
	reg.Mostrar();
	if (reg.Grabar_en_disco()){

        regbicicleta.setEstado(3);
        regbicicleta.Modificar_en_disco(posBici); ///aca guarda el cambio de estado en el archivo bicicletas
	}










}

void modifica_Estado_enReparacion()
{
	int cod;
	int nEstado;
	int pos;
	enReparacion reg;
	system("cls");
	cout<<"Ingrese el codigo de Reparacion a modificar:";
	cin>>cod;
	pos=buscar_Reparacion(cod);
	if(pos!=-1)
		{
		cout<<"Ingrese el nuevo Estado: ";
		cin>>nEstado;
		reg.Leer_de_disco(pos);
		reg.setEstado(nEstado);
		reg.Modificar_en_disco(pos);
		}
	else
		{ setColor(RED);
		cout<<"ERROR: No existe el Bicicleta"<<endl;
		cout<<"Presione una tecla para continuar";
		system("pause>null");
		}
}

void baja_logica_EnReparacion()
{
	int cod;
	int pos;

	enReparacion reg;

	system("cls");
	cout<<"Ingrese el codigo de Reparacion si la Bicicleta fue reparada:";
	cin>>cod;
	pos=buscar_Reparacion(cod);
	if(pos!=-1)
		{
		reg.Leer_de_disco(pos);
		reg.setEstado(0);
		reg.Modificar_en_disco(pos);
		}
	else
		{ setColor(RED);
		cout<<"ERROR: No existe la orden de reparacion"<<endl;
		cout<<"Presione una tecla para continuar";
		system("pause>null");
		}

}


void listar_EnReparacion()/// REPARACIONES ACTIVAS
	{

    enReparacion reg;
   int  c=0;
	int pos=0;
	system("cls");
	while(reg.Leer_de_disco(pos++) ==1)
		{
		if(reg.getEstado()==1)
			{
            c=1;
            reg.Mostrar();
			//system("pause>null");
		}
		}
	if(c==0)
		{ setColor(RED);
		cout<<"ERROR: No existen reparaciones activas"<<endl;

		system("pause>null");
		}
	}




void IngresoTaller(){

    alta_EnReparacion();



}
void salidaTaller(){
    enReparacion reg;
    Bicicleta regbicicleta;
    system("cls");
    int id, pos, posbicicleta;
    cout <<"FIN REPARACION\n";
    cout <<"-------------------\n";
    cout <<"Ingrese Id Reparacion: \n";
    cin  >>id;

    pos = buscar_Reparacion(id);

    reg.Leer_de_disco(pos);

    if(reg.getEstado()==false){system("cls"); cout <<"ERROR";system("pause>null");return;}
    posbicicleta = buscar_Bicicleta(reg.getId_Bicicleta());
    reg.Mostrar();
    Fecha obj;
    cout <<"\n\n..................\n";
    cout <<"1)Bicicleta Reparada \n";
    cout <<"2) No puede ser Reparada\n";
    int o;
    cin >> o;

    reg.setFechaSalida(obj);

    if(o==1){

            reg.setEstado(false);
            system("cls");
            reg.MostrarTodo();
            if (reg.Modificar_en_disco(pos)){ cout <<"\n\n~BICICLETA REPARADA~"; system("pause");system("cls");}
            regbicicleta.Leer_de_disco(posbicicleta);
            regbicicleta.setEstado(1);
            regbicicleta.Modificar_en_disco(posbicicleta);
        }
        else if (o==2)

            {
            reg.setEstado(false);
            system("cls");
            reg.MostrarTodo();
            if (reg.Modificar_en_disco(pos)){ cout <<"\n\n~BICICLETA NO PUEDE SER REPARADA~"; system("pause");system("cls");}
            regbicicleta.Leer_de_disco(posbicicleta);
            regbicicleta.setEstado(0);
            regbicicleta.Modificar_en_disco(posbicicleta);

            }
    }


int contarRegistrosEnReparacion(){


    Archivo a;
	FILE *p;

    p=fopen(a.getFILE_REPARACIONES(),a.getMODO_APERTURA_READ_FILE());
        if(p==NULL){
                 setColor(RED);
        cout <<"ERROR: ERROR AL ABRIR EL ARCHIVO"; system("pause"); return -3;}

    int tamanio;
  fseek(p, 0, SEEK_END);
  tamanio = ftell(p);
  fclose(p);
  return tamanio/sizeof(enReparacion);
}



void listarReparacionPorId(){ ///

    int id;

    system("cls");

    cout <<"LISTAR REPARACION POR ID: \n";
    cout <<"-----------------------------\n";
    cout <<"Ingrese Id Reparacion: ";
    cin  >>id;

    enReparacion reg;

	int pos=0;
	system("cls");
	while(reg.Leer_de_disco(pos++)==1)
		{
            if(id == reg.getId())
            {

            if(reg.getEstado()){
            reg.Mostrar();
            cout <<"\nACTIVA";
               return ;
            }

            else { reg.MostrarTodo();}
			//system("pause>null");
			cout <<"\nDADO DE BAJA";
			return ;
            }
		}
 setColor(RED);

		cout<<"\n\n\t\t ERROR: NO EXISTE "<<endl;
		//cout<<"Presione una tecla para continuar";
		system("pause>null");

}

void listarBicicletasReparadas()/// REPARACIONES FINALIZADAS
	{

    enReparacion reg;
   int  c=0;
	int pos=0;
	system("cls");
	while(reg.Leer_de_disco(pos++))
		{
		if(reg.getEstado()==0)
			{
            c=1;
		reg.MostrarTodo();
			//system("pause>null");
		}
		}
	if(c==0)
		{ setColor(RED);
		cout<<"ERROR: No existen Registros"<<endl;

		system("pause>null");
		}
	}

void listarReparacionPorIdBicicleta(){ ///


    char id[5];
    int x=0;

    system("cls");


    system("cls");

    cout <<"LISTAR REPARACION POR ID BICICLETA: \n";
    cout <<"-----------------------------\n";
    cout <<"Ingrese Id Bicicleta: ";
    cin  >>id;

    enReparacion reg;

	int pos=0;
	system("cls");
	while(reg.Leer_de_disco(pos++)==1)
		{
            if(strcmp(reg.getId_Bicicleta(),id)==0)
            {
            if(x==0){cout <<"HISTORIAL DE BICICLETA EN REPARACION\n";}

            reg.Mostrar();
            x=1;

            }
		}

        if(x==0){
            setColor(RED);
		cout<<"\n\n\t\t ERROR: NO EXISTE "<<endl;
		//cout<<"Presione una tecla para continuar";
		system("pause>null");
        }
}
///FIN FUNCIONES EXTERNAS
#endif // CLASS_ENREPARACION_H_INCLUDED

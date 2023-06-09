#ifndef CLASS_ALQUILERES_H_INCLUDED
#define CLASS_ALQUILERES_H_INCLUDED
#include "../costoAlquiler.h";
///////////////////////
///EmpleadoTOTIPOS DE LAS FUNCIONES EXTERNAS:
int buscar_id();
int buscar_Alquiler(int);
void alta_Alquiler();
void baja_logica_Alquiler();
void listar_Alquileres();
void menu_Alquileres();
void entrega_Alquiler();
bool bicicletaEnUso();
bool usuarioEnUso ();
void Reportes_Alquileres();
void listarAlquileresPorId();
bool buscarSiClienteEstaActivoEnAlquiler(char *);
///////////////////////

///DEFINICION DE LA CLASE ALQUILERES:
class Alquileres
	{
	private:
		int Id;
		char Id_Empleado[5];
		char DNI_Cliente[8];
		char Id_Bicicleta[5];
		Fecha inicioAlquiler;
		Fecha finAlquiler;
		float importe;
		bool Estado;
	public:
	    Alquileres();
		void Cargar_Id_Bicicleta();
		void Cargar_DNI_Cliente();
		void Cargar_cant();
		void Cargar_fecha();
		void Mostrar();

        Fecha setFechaInicioAlquiler(Fecha f){inicioAlquiler=f;}
        Fecha setFechaFinAlquiler(Fecha f){finAlquiler=f;}
        bool getEstado(){return Estado;}
        Fecha getFechaInicioAlquiler(){return inicioAlquiler;}
        Fecha getFechafinAlquiler(){return finAlquiler;}
		int getId(){return Id;}
		char * getId_Bicicleta(){return Id_Bicicleta;}
		char * getDNI_Cliente(){return DNI_Cliente;}
		char * getIdEmpleado () {return Id_Empleado;}

		float getimporte(){return importe;}
		void setId(int nv){Id=nv;}


		void setimporte(float p){importe=p;}
		void setEstado(int s){Estado=s;}
		bool Grabar_en_disco(void);
		int Leer_de_disco(int);
		bool Modificar_en_disco(int);
		int minutosTotalesDeAlquiler();
		void Cargar_fechaInicio();
        void Cargar_fechaFin();
        bool Cargar_Empleado();
        void MostrarTodo();
	};
//****************
///DESARROLLO DE LOS METODOS DE LA CLASE ALQUILERES:
Alquileres :: Alquileres(){

        Id=0;
		strcpy(Id_Empleado,"0000");//char Id_Empleado[5];
		strcpy(DNI_Cliente,"0000000");// char DNI_Cliente[8];
		strcpy (Id_Bicicleta,"0000"); //char Id_Bicicleta[5];

        finAlquiler.setAnio(0);
        finAlquiler.setMes(0);
        finAlquiler.setDia(0);
		finAlquiler.setHora(0);
		finAlquiler.setMinuto(0);
		importe=0;
		Estado=0;

}

int Alquileres::minutosTotalesDeAlquiler(){

     ////// esto es cuando cambia de dia:

        int meses[12]={31,28,31,30,31,30,31,31,30,31,30,31};
        int diasInicial=inicioAlquiler.getDia();
        int diasFinal=finAlquiler.getDia();
        int diaTot;


        if(finAlquiler.esbisiesto(finAlquiler.getAnio())){ meses[1]+1;}
        if(inicioAlquiler.esbisiesto(inicioAlquiler.getAnio())){ meses[1]+1;}
        for(int i=0; i<inicioAlquiler.getMes()-1;i++){
        diasInicial+=meses[i];

        }
        //cout <<endl;
        //cout <<"DIAS TOTALES INICIAL: "<<diasInicial;

        for(int i=0; i<finAlquiler.getMes()-1;i++){
        diasFinal+=meses[i];

        }
        if (finAlquiler.getAnio()>inicioAlquiler.getAnio()){

            for(int i=0; i<12;i++){

                diasFinal+=meses[i];
            }
        }
       // cout <<endl;
       // cout <<"DIAS TOTALES FINAL: "<<diasFinal;
       // cout <<endl;
        diaTot = diasFinal-diasInicial;
       // cout <<"DIFERENCIA DE DIAS: "<<diaTot;
       // cout <<endl;



    if(finAlquiler.getAnio()==inicioAlquiler.getAnio()&&finAlquiler.getMes()==inicioAlquiler.getMes()&&finAlquiler.getDia()==inicioAlquiler.getDia()){
    int minutosInicio, minutosFinal, minutosTotales=0;

    minutosInicio=(inicioAlquiler.getHora()*60)+inicioAlquiler.getMinuto();
    //cout <<endl;
    //cout <<"minutos Inicio: "<<minutosInicio;
    minutosFinal=(finAlquiler.getHora()*60)+finAlquiler.getMinuto();
    //cout <<endl;
    //cout <<"minutos Final: "<<minutosFinal;
    //cout <<endl;
    minutosTotales=minutosFinal-minutosInicio;
    //cout <<"minutos Que Pasaron: "<<minutosTotales;
    //cout <<endl;

    return minutosTotales;
    }
    else {
            int minutosInicio, minutosFinal, minutosTotales=0;
         minutosInicio=(inicioAlquiler.getHora()*60)+inicioAlquiler.getMinuto();
    //cout <<endl;
    //cout <<"minutos Inicio: "<<minutosInicio;
    minutosFinal=(finAlquiler.getHora()*60)+finAlquiler.getMinuto();
    //cout <<endl;
    //cout <<"minutos Final: "<<minutosFinal;
    //cout <<endl;
    minutosTotales=(minutosFinal+(diaTot*24*60))-minutosInicio;
    //cout <<"minutos Que Pasaron: "<<minutosTotales;
    //cout <<endl;
    return minutosTotales;
    }

    // return minutosTotales;
}


void Alquileres::Cargar_Id_Bicicleta()
	{
	cout<<"Ingrese el codigo de Bicicleta: ";
	cin>>Id_Bicicleta;
	}

void Alquileres::Cargar_DNI_Cliente()
	{
	cout<<"Ingrese el DNI de cliente: ";
	cin>>DNI_Cliente;

}

bool Alquileres :: Cargar_Empleado(){
    Empleado reg;
    int pos;
    cout <<"Ingrese Id Empleado: ";
    cin >>Id_Empleado;
    pos=buscar_Empleado(Id_Empleado);
    if (pos>=0){

    reg.Leer_de_disco(pos);
    if(reg.getEstado()==0){
            setColor(RED);
            cout <<"ERROR: EL EMPLEADO ESTA DADO DE BAJA", system("pause>null"); return false;  }
    }
    else{
        setColor(RED);
        cout <<"ERROR: EL EMPLEADO NO EXISTE"; system("pause>null"); return false;}

        return true;

}
/*void Alquileres::Cargar_cant()
	{
	cout<<"Ingrese la cantidad:  ";
	cin>>tiempo;
	}
*/      ///comente esta funcion para modificarla despues, ya no tenemos tiempo, lo que tenemos es hora de alquiler y de devolucion.
void Alquileres::Cargar_fechaInicio()
	{
	  ///METODO PARA CARGAR MANUALMENTE PARA HACER PRUEBAS

	    int d,m,a,h,mm;
        cout <<"DIA: ";
        cin >>d;
        cout <<endl;
        cout <<"MES: ";
        cin >>m;
        cout <<endl;
        cout <<"ANIO(aaaa): ";
        cin >>a;
        cout <<endl;
        cout <<"HORA: ";
        cin >>h;
        cout <<endl;
        cout <<"MINUTOS: ";
        cin >>mm;
        cout <<endl;
        inicioAlquiler.setDia(d);inicioAlquiler.setMes(m); inicioAlquiler.setAnio(a); inicioAlquiler.setHora(h);inicioAlquiler.setMinuto(mm);

	}
void Alquileres::Cargar_fechaFin(){

        ///METODO PARA CARGAR MANUALMENTE PARA HACER PRUEBAS

        int d,m,a,h,mm;
        cout <<"DIA: ";
        cin >>d;
        cout <<endl;
        cout <<"MES: ";
        cin >>m;
        cout <<endl;
        cout <<"ANIO(aaaa): ";
        cin >>a;
        cout <<endl;
        cout <<"HORA: ";
        cin >>h;
        cout <<endl;
        cout <<"MINUTOS: ";
        cin >>mm;
        cout <<endl;
        finAlquiler.setDia(d);finAlquiler.setMes(m);finAlquiler.setAnio(a);finAlquiler.setHora(h);finAlquiler.setMinuto(mm);
}

void Alquileres::MostrarTodo(){

    cout<<"Numero de Alquiler: ";
	cout<<Id<<endl;
	cout<<"Codigo de Bicicleta: ";
	cout<<Id_Bicicleta<<endl;
	cout<<"Codigo de cliente: ";
	cout<<DNI_Cliente<<endl;
	cout <<"FECHA DE ALQUILER: ";
	inicioAlquiler.MostrarFecha();
	cout <<endl;
	cout <<"HORA DE ALQUILER: ";
	inicioAlquiler.MostrarHora();

	cout <<"\n.......................\n";
	cout <<"FECHA DE DEVOLUCION: ";
	finAlquiler.MostrarFecha();

	cout <<endl;
	cout <<"HORA DE DEVOLUCION: ";
	finAlquiler.MostrarHora();

    cout <<endl;
    cout <<"TOTAL PAGADO: $";
    cout <<importe;
    cout <<endl;


}
void Alquileres::Mostrar()
	{
    cout <<"\n----------------------\n";
	cout<<"Numero de Alquiler: ";
	cout<<Id<<endl;
	cout<<"Codigo de Bicicleta: ";
	cout<<Id_Bicicleta<<endl;
	cout<<"Codigo de cliente: ";
	cout<<DNI_Cliente<<endl;
	cout <<"FECHA DE ALQUILER: ";
	inicioAlquiler.MostrarFecha();
	cout <<endl;
	cout <<"HORA DE ALQUILER: ";
	inicioAlquiler.MostrarHora();

	//system("cls>null");
	//cout<<"Cantidad: ";
	//cout<<cant<<endl;
	//cout<<"Importe: ";
	//cout<<importe<<endl;
	//cout<<"Dia: ";
	//cout<<dia<<endl;
	//cout<<"Mes: ";
	//cout<<mes<<endl;
	}



bool Alquileres::Grabar_en_disco(void)
	{
	    Archivo a;
	FILE *p;
	p=fopen(a.getFILE_ALQUILERES(),a.getMODO_APERTURA_ADD_TO_FILE());
	if(p==NULL){

             setColor(RED);
            cout<<"ERROR: Error de archivo";exit(1);}
	bool escribio = fwrite(this,sizeof *this,1,p);
	fclose(p);

	return escribio;
	}

int Alquileres::Leer_de_disco(int pos)
	{
	    Archivo a;
	int x;
	FILE *p;
	p=fopen(a.getFILE_ALQUILERES(),a.getMODO_APERTURA_READ_FILE());
	if(p==NULL)
		{ setColor(RED);
		cout<<"ERROR: No existe el archivo"<<endl;
		cout<<"Presione una tecla para continuar";
		system("pause>null");
		return 0;
		}
	fseek(p,pos*sizeof *this,0);
	x=fread(this,sizeof *this,1,p);
	fclose(p);
	return x;
	}

bool Alquileres::Modificar_en_disco(int pos)
	{
	    Archivo a;
	FILE *p;
	p=fopen(a.getFILE_ALQUILERES(),a.getMODO_APERTURA_MODIFI_FILE());
	if(p==NULL){cout<<"Error de archivo"; return false;}
	fseek(p,pos*sizeof *this,0);
	fwrite(this,sizeof *this,1,p);
	fclose(p);

	return true;
	}
//*****************************
///DESARRORO DE LAS FUNCIONES EXTERNAS:

int buscar_Id()/// esta funcion es usada para devolver el id de alquileres,
{

	Archivo a;
	FILE *p;

    p=fopen(a.getFILE_ALQUILERES(), a.getMODO_APERTURA_READ_FILE());
        if(p==NULL){
             setColor(RED);
                cout <<"ERROR AL ABRIR EL ARCHIVO"; system("pause"); return -3;}

    int tamanio;
  fseek(p, 0, SEEK_END);
  tamanio = ftell(p);
  fclose(p);
  return tamanio/sizeof(Alquileres);
}

int buscar_Alquiler(int nro)
{
	int pos=0;
	Alquileres reg;
	while(reg.Leer_de_disco(pos)==1)
		{
		if(nro==reg.getId() && reg.getEstado()==1)
			return pos;
		pos++;
		}
	return -1;
}


void alta_Alquiler()
{
	Alquileres reg;
	Bicicleta regBicicleta;
	int posBicicleta,poscli;
	system("cls");
	if(reg.Cargar_Empleado()!=true){ return; }
	reg.Cargar_Id_Bicicleta();
	posBicicleta=buscar_Bicicleta(reg.getId_Bicicleta());
	regBicicleta.Leer_de_disco(posBicicleta);
	if(posBicicleta==-1)
		{
		     setColor(RED);
		cout<<"ERROR: No existe el codigo de Bicicleta"<<endl;
		cout<<"Presione una tecla para continuar";
		system("pause>null");
		return;
		}
    if(regBicicleta.getEstado()==3){

          setColor(RED);
		cout<<"ERROR: la bicicleta esta en taller"<<endl;
		cout<<"Presione una tecla para continuar";
		system("pause>null");
		return;
    }
    if(regBicicleta.getEstado()==2){

          setColor(RED);
		cout<<"ERROR: la bicicleta esta en uso"<<endl;
		cout<<"Presione una tecla para continuar";
		system("pause>null");
		return;
    }
    if(regBicicleta.getEstado()==0){

          setColor(RED);
		cout<<"ERROR: la bicicleta esta eliminada"<<endl;
		cout<<"Presione una tecla para continuar";
		system("pause>null");
		return;
    }
	reg.Cargar_DNI_Cliente();

	if(buscarSiClienteEstaActivoEnAlquiler(reg.getDNI_Cliente())){  setColor(RED);cout<<"ERROR: El cliente ya tiene un Alquiler Activo"<<endl;  system("pause>null");return;}
	poscli=buscar_cli_con_estado(reg.getDNI_Cliente());
	if(poscli==-1)
		{
		    setColor(RED);
		cout<<"ERROR: No existe el codigo de cliente"<<endl;
		cout<<"Presione una tecla para continuar";
		system("pause>null");
		return;
		}
	reg.setId(buscar_Id()+1); /// el primer ID de alquiler da id negativo porque el archivo no esta creado, despues del primero, todos los id estan perfectos.




    //reg.Cargar_fechaInicio(); ///CON ESTA FUNCION SE CARGA MANUALMENTE LA FECHA Y LA HORA PARA HACER PRUEBAS

    reg.setEstado(true);

    system("cls");

	if (reg.Grabar_en_disco()){
            setColor(GREEN);
            cout <<"\n\n\t\tALQUILER DADO DE ALTA CORRECTAMENTE "; system("pause>null");

            system("cls");
            reg.Mostrar();
            system("pause>null");
            system("cls>null");
            regBicicleta.setEstado(2);
            regBicicleta.Modificar_en_disco(posBicicleta);

	system("pause>null");
    }
    else{ setColor(RED); cout <<"\n\n\t\t ERROR AL GRABAR EN DISCO!!"; system("pause>null");}



}

void entrega_Alquiler()
{
    system("cls");
    int id;
    cout <<"ENTREGA ALQUILER "<<endl;
    cout <<"---------------------"<<endl;
    cout <<"INGRESE ID: ";
    cin  >>id;
    int pos=id-1;
 /////////////////////////////////////////////////////

    Alquileres reg;
    Bicicleta regbicicleta;
    Fecha obj;
    int posbicicleta;
    if (reg.Leer_de_disco(id-1)==0);
    if(reg.getEstado()==false){ return; }
    reg.Mostrar();
    cout <<endl;
    cout <<".........................";
    cout <<endl;
    posbicicleta=buscar_Bicicleta(reg.getId_Bicicleta());
    regbicicleta.Leer_de_disco(posbicicleta);
    reg.setFechaFinAlquiler(obj);
    //reg.Cargar_fechaFin();/// esta funcion ingresa manualmente la fecha y hora para hacer pruebas;

    cout <<"FECHA DE DEVOLUCION: ";
	reg.getFechafinAlquiler().MostrarFecha();
	cout <<endl;
	cout <<"HORA DE DEVOLUCION: ";
    reg.getFechafinAlquiler().MostrarHora();
    cout <<endl;

    int minutos;
    float precioTotal;
    float valor;
    minutos = reg.minutosTotalesDeAlquiler();
    valor=costoPorMinuto();
    precioTotal=minutos*valor;
    cout <<"MINUTOS: ";
    cout <<minutos;
    cout <<endl;
    cout <<"TOTAL A PAGAR: $";
    cout <<precioTotal;
    cout <<endl;
    reg.setimporte(precioTotal);
    reg.setEstado(0);

setColor(GREEN);


   if ( reg.Modificar_en_disco(pos)){
            regbicicleta.setEstado(1);
            regbicicleta.Modificar_en_disco(posbicicleta);

        cout <<"\n\n\t\tENTREGA ALQUILER EXITOSA";  }
 //////////////////////////////////////////////7
    system("pause");

}

void baja_logica_Alquiler()
{
	int nro;
	int pos;
	Alquileres reg;
	Bicicleta regBicicleta;
	system("cls");
	cout<<"Ingrese el numero de Alquiler a eliminar:";
	cin>>nro;
	pos=buscar_Alquiler(nro);

	int posBicicleta=buscar_Bicicleta(reg.getId_Bicicleta());
	regBicicleta.Leer_de_disco(posBicicleta);
	if(pos!=-1)
		{
		reg.Leer_de_disco(pos);
		reg.setEstado(0);
		reg.Modificar_en_disco(pos);
		regBicicleta.setEstado(1);
		regBicicleta.Modificar_en_disco(posBicicleta);

		setColor(GREEN);
		cout<<"ALQUILER DADO DE BAJA "<<endl;
		system("pause>null");
		}
	else
		{
		     setColor(RED);
		cout<<"ERROR 404: No existe el Alquiler"<<endl;
		cout<<"Presione una tecla para continuar";
		system("pause>null");
		}

}


void listar_Alquileres()
	{
	Alquileres reg;
	Bicicleta regBicicleta;
	Cliente regcli;
	int pos=0,poscli,posBicicleta;
	system("cls");
	while(reg.Leer_de_disco(pos++)==1)
		{
		//if(reg.getEstado()==1)
			//{
			    reg.Mostrar();

			 posBicicleta=buscar_Bicicleta(reg.getId_Bicicleta());
			 regBicicleta.Leer_de_disco(posBicicleta);
			 cout<<endl<<"MODELO: "<<regBicicleta.getModelo_De_Bicicleta()<<endl;
			 poscli=buscar_cli(reg.getDNI_Cliente());
			 regcli.Leer_de_disco(poscli);
			 cout<<"CLIENTE: "<<regcli.getNombre();

			 if(reg.getEstado()){cout <<"\nALQUILER: ACTIVO"; }
             else{cout <<"\nALQUILER: DADO DE BAJA"; }
			//system("pause>null");
			//}
		}
		if(pos==1)
		{ setColor(RED);
		cout<<"ERROR: No existen registros"<<endl;
		cout<<"Presione una tecla para continuar";
		system("pause>null");
		}
	}


	int buscar_Clientte(char *DNI)
{
	int pos=0;
	Cliente reg;
	while(reg.Leer_de_disco(pos)==1)
		{
		if(strcmp(DNI,reg.getDNI_Cliente())==0 && reg.getEstado()==1)
			return pos;
		pos++;
		}
	return -1;
}


void listarAlquileresPorId(){ ///

    int id;


    system("cls");

    cout <<"LISTAR ALQUILER POR ID: \n";
    cout <<"-----------------------------\n";
    cout <<"Ingrese Id de Alquiler: ";
    cin  >>id;

    Alquileres reg;
	int pos=0;
	system("cls");
	while(reg.Leer_de_disco(pos++))
                {
		    if (id==reg.getId())

            {
            if(reg.getEstado()){
            reg.Mostrar();
            cout <<"\n\n\t\t\t EL ALQUILER ESTA ACTIVO"; system("pause>null");
			return ;

			}
			else {

                    reg.MostrarTodo();
                     cout <<"\n\n\t\t\t EL ALQUILER FUE DADO DE BAJA"; system("pause>null");
                    return ;

			}
            }
		}

 setColor(RED);
		cout<<"\n\n\t\tERROR: ALQUILER NO EXISTE "<<endl;
		//cout<<"Presione una tecla para continuar";
		system("pause>null");
}

bool buscarSiClienteEstaActivoEnAlquiler(char *dni){


    Alquileres reg;
	int pos=0;
	system("cls");
	while(reg.Leer_de_disco(pos++))
                {
		    if (reg.getEstado()==true&&strcmp(reg.getDNI_Cliente(),dni)==0)

            {
                return true;
			}

			}

			return false;
            }






#endif // CLASS_ALQUILERES_H_INCLUDED

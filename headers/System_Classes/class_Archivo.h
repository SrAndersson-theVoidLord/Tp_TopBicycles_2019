#ifndef CLASS_ARCHIVO_H_INCLUDED
#define CLASS_ARCHIVO_H_INCLUDED

class Archivo{
private:
    ///DIRECTORIO:
    const char *FILE_BICICLETAS = "Registros/Bicicletas/Biciletas.dat";
    const char *FILE_CLIENTES = "Registros/Clientes/Clientes.dat";
    const char *FILE_EMPLEADOS = "Registros/Empleados/Empleados.dat";
    const char *FILE_ALQUILERES = "Registros/Alquileres/Alquileres.dat";
    const char *FILE_REPARACIONES = "Registros/Reparaciones/Reparaciones.dat";
    const char *FILE_COSTOS = "Registros/Costos/Costos.dat";

    ///MODO DE APERTURA DEL ARCHIVO:
     const char *READ_FILE = "rb";
     const char *WRITE_FILE = "wb";
     const char *ADD_REGISTRY_TO_FILE = "ab";
     const char *MODIFY_FILE = "rb+";

    public:
const char * getFILE_BICICLETAS(){return FILE_BICICLETAS;};
const char * getFILE_CLIENTES(){return FILE_CLIENTES;};
const char * getFILE_EMPLEADOS(){return FILE_EMPLEADOS;};
const char * getFILE_ALQUILERES(){return FILE_ALQUILERES;};
const char * getFILE_REPARACIONES(){return FILE_REPARACIONES;};
const char * getFILE_COSTOS(){return FILE_COSTOS;};


const char * getMODO_APERTURA_READ_FILE(){return READ_FILE;};
const char * getMODO_APERTURA_WRITE_FILE(){return WRITE_FILE;};
const char * getMODO_APERTURA_ADD_TO_FILE(){return ADD_REGISTRY_TO_FILE;};
const char * getMODO_APERTURA_MODIFI_FILE(){return MODIFY_FILE;};

void Generar_Archivo_Vacio();
void Realizar_Backups();
void Cargar_Backups();




};

void Archivo::Generar_Archivo_Vacio(){
	    Archivo a;
	FILE *p;
	p=fopen(a.getFILE_BICICLETAS(),a.getMODO_APERTURA_READ_FILE());
	if(p==NULL)
		p=fopen(a.getFILE_BICICLETAS(),a.getMODO_APERTURA_WRITE_FILE());
	fclose(p);


	p=fopen(a.getFILE_ALQUILERES(),a.getMODO_APERTURA_READ_FILE());
	if(p==NULL)
		p=fopen(a.getFILE_ALQUILERES(),a.getMODO_APERTURA_WRITE_FILE());
	fclose(p);

	p=fopen(a.getFILE_CLIENTES(),a.getMODO_APERTURA_READ_FILE());
	if(p==NULL)
		p=fopen(a.getFILE_CLIENTES(),a.getMODO_APERTURA_WRITE_FILE());
	fclose(p);

	p=fopen(a.getFILE_EMPLEADOS(),a.getMODO_APERTURA_READ_FILE());
	if(p==NULL)
		p=fopen(a.getFILE_EMPLEADOS(),a.getMODO_APERTURA_WRITE_FILE());
	fclose(p);

	p=fopen(a.getFILE_REPARACIONES(),a.getMODO_APERTURA_READ_FILE());
	if(p==NULL)
		p=fopen(a.getFILE_REPARACIONES(),a.getMODO_APERTURA_WRITE_FILE());
	fclose(p);

		p=fopen(a.getFILE_COSTOS(),a.getMODO_APERTURA_READ_FILE());
	if(p==NULL)
		p=fopen(a.getFILE_COSTOS(),a.getMODO_APERTURA_WRITE_FILE());
	fclose(p);
	}

void Archivo::Realizar_Backups(){
Loading bar;
int f[6];
system("cls");
setColor(LIGHTGREEN);
bar.unity_Loading_Bar(2,3);
cout<<endl<<endl<<endl;
   f[0]= system("copy Registros\\Bicicletas\\Biciletas.dat Backups\\Bicicletas\\Biciletas.bkp");

   if(f[0]!=NULL){
        setColor(RED);
    cout<<"ERROR ARCHIVO BICICLETAS"<<endl;
   }else {setColor(LIGHTGREEN);
       cout<<"BACKUP BICICLETAS HECHO CORRECTAMENTE"<<endl;}
   setColor(LIGHTGREEN);
    f[1]= system("copy Registros\\Clientes\\Clientes.dat Backups\\Clientes\\Clientes.bkp");
    setColor(RED);
            if(f[1]!=NULL){cout<<"ERROR ARCHIVO CLIENTES"<<endl;}

else {setColor(LIGHTGREEN);
        cout<<"BACKUP CLIENTES HECHO CORRECTAMENTE"<<endl;}
    setColor(LIGHTGREEN);
    f[2]= system("copy Registros\\Empleados\\Empleados.dat Backups\\Empleados\\Empleados.bkp");
    setColor(RED);
            if(f[2]!=NULL) {cout<<"ERROR ARCHIVO EMPLEADOS"<<endl;}

else {setColor(LIGHTGREEN);
    cout<<"BACKUP EMPLEADOS HECHO CORRECTAMENTE"<<endl;}
    setColor(LIGHTGREEN);
    f[3]= system("copy Registros\\Alquileres\\Alquileres.dat Backups\\Alquileres\\Alquileres.bkp");
setColor(RED);
            if(f[3]!=NULL){cout<<"ERROR ARCHIVO ALQUILERES"<<endl;}

else {setColor(LIGHTGREEN);
cout<<"BACKUP ALQUILERES HECHO CORRECTAMENTE"<<endl;}

    setColor(LIGHTGREEN);
    f[4]= system("copy Registros\\Reparaciones\\Reparaciones.dat Backups\\Reparaciones\\Reparaciones.bkp");
    setColor(RED);
            if(f[4]!=NULL) {cout<<"ERROR ARCHIVO REPARACIONES"<<endl;}

else {setColor(LIGHTGREEN);
cout<<"BACKUP REPARACIONES HECHO CORRECTAMENTE"<<endl;}
    setColor(LIGHTGREEN);
    f[5]= system("copy Registros\\Costos\\Costos.dat Backups\\Costos\\Costos.bkp");
    setColor(RED);
            if(f[5]!=NULL) {cout<<"ERROR ARCHIVO COSTOS"<<endl;}

else {setColor(LIGHTGREEN);
cout<<"BACKUP COSTOS HECHO CORRECTAMENTE"<<endl;}
    setColor(LIGHTGREEN);
    cout<<"BACK_UP DEL REGISTRO DEL SISTEMA REALIZADO CORRECTAMENTE"<<endl;
    system("pause>nul");
}

void Archivo::Cargar_Backups(){
Loading bar;
int f[6];
system("cls");
setColor(LIGHTGREEN);
bar.unity_Loading_Bar(1,3);
cout<<endl<<endl<<endl;
    f[0]=  system("copy Backups\\Bicicletas\\Biciletas.bkp Registros\\Bicicletas\\Biciletas.dat");
    if(f[0]!=NULL){
        setColor(RED);
    cout<<"ERROR BACKUP BICICLETAS"<<endl;
   }else {setColor(LIGHTGREEN);
       cout<<"BACKUP BICICLETAS RESTAURADO CORRECTAMENTE"<<endl;}
   setColor(LIGHTGREEN);
    f[1]= system("copy Backups\\Clientes\\Clientes.bkp Registros\\Clientes\\Clientes.dat");
    if(f[1]!=NULL){
        setColor(RED);
    cout<<"ERROR BACKUP CLIENTES"<<endl;
   }else {setColor(LIGHTGREEN);
       cout<<"BACKUP CLIENTES RESTAURADO CORRECTAMENTE"<<endl;}
   setColor(LIGHTGREEN);
    f[2]= system("copy Backups\\Empleados\\Empleados.bkp Registros\\Empleados\\Empleados.dat");
    if(f[2]!=NULL){
        setColor(RED);
    cout<<"ERROR BACKUP EMPLEADOS"<<endl;
   }else {setColor(LIGHTGREEN);
       cout<<"BACKUP EMPLEADOS RESTAURADO CORRECTAMENTE"<<endl;}
   setColor(LIGHTGREEN);
    f[3]= system("copy Backups\\Alquileres\\Alquileres.bkp Registros\\Alquileres\\Alquileres.dat");
   if(f[3]!=NULL){
        setColor(RED);
    cout<<"ERROR BACKUP ALQUILERES"<<endl;
   }else {setColor(LIGHTGREEN);
       cout<<"BACKUP ALQUILERES RESTAURADO CORRECTAMENTE"<<endl;}
   setColor(LIGHTGREEN);
    f[4]= system("copy Backups\\Reparaciones\\Reparaciones.bkp Registros\\Reparaciones\\Reparaciones.dat");
    if(f[4]!=NULL){
        setColor(RED);
    cout<<"ERROR BACKUP REPARACIONES"<<endl;
   }else {setColor(LIGHTGREEN);
       cout<<"BACKUP REPARACIONES RESTAURADO CORRECTAMENTE"<<endl;}
   setColor(LIGHTGREEN);
    f[5]= system("copy Backups\\Costos\\Costos.bkp Registros\\Costos\\Costos.dat");
    if(f[5]!=NULL){
        setColor(RED);
    cout<<"ERROR BACKUP COSTOS"<<endl;
   }else {setColor(LIGHTGREEN);
       cout<<"BACKUP COSTOS RESTAURADO CORRECTAMENTE"<<endl;}
   setColor(LIGHTGREEN);
    cout<<"BACK_UP DEL REGISTRO DEL SISTEMA RESTAURADO CORRECTAMENTE"<<endl;
    system("pause>nul");
}




#endif // CLASS_ARCHIVO_H_INCLUDED

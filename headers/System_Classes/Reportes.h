#ifndef REPORTES_H_INCLUDED
#define REPORTES_H_INCLUDED
void Reportes_Alquileres(){
	Alquileres reg;

int pos=0,contar_alquileres_totales = 0,contar_alquileres_mes[12]={0};
float recaudacion_mensual_total[12]={0},recaudacion_total=0;

while(reg.Leer_de_disco(pos++)==1){
    if(reg.getEstado()==false){
    contar_alquileres_mes[reg.getFechafinAlquiler().getMes()-1]++;
    recaudacion_mensual_total[reg.getFechafinAlquiler().getMes()-1]+=reg.getimporte();
    contar_alquileres_totales++;
    recaudacion_total+=reg.getimporte();
    }
}

cout<<"CANTIDAD ALQUILERES POR MES:"<<endl;
cout<<"__________________________________________________________________________________________________"<<endl;
		      for(int i=0;i<12;i++){
                cout<<"MES "<<i+1<<": "<<contar_alquileres_mes[i]<<endl;

		      }

        gotoXY(50,0);
 cout<<"RECAUDACION ALQUILERES POR MES:"<<endl;
cout<<endl;
		      for(int i=0;i<12;i++){
                    gotoXY(50,i+2);
                cout<<"MES "<<i+1<<": $"<<recaudacion_mensual_total[i]<<endl; //  contar_alquileres_mes[i]<<endl;


            }

        cout<<"__________________________________________________________________________________________________"<<endl<<endl<<endl;

cout<<"CANTIDAD ALQUILERES TOTAL:"<<contar_alquileres_totales;
gotoXY(50,17);
cout<<"RECAUDACION TOTAL: $"<<recaudacion_total;

}



void Reportes_Bicicletas(){
	Bicicleta reg;
	Alquileres reg2;

int pos=0,contar_alquileres_totales = 0,contar_alquileres_mes[12]={0};
char id_aux[5];
int pos2=0;

while(reg.Leer_de_disco(pos++)==1){
        pos2=0;
        contar_alquileres_mes[12]={0};
contar_alquileres_totales = 0;
strcpy(id_aux,reg.getId_Bicicleta());

        for(int i=0;i<12;i++){

            contar_alquileres_mes[i]=0;
        }
        while(reg2.Leer_de_disco(pos2++)==1){

    if(strcmp(reg.getId_Bicicleta(),reg2.getId_Bicicleta())==0){

    contar_alquileres_mes[reg2.getFechafinAlquiler().getMes()-1]++;



    }
}
cout<<"______________________________________"<<endl;
cout<<"ID_BICICLETA: "<<id_aux<<endl;
cout<<"CANTIDAD ALQUILERES POR MES:"<<endl;
cout<<"______________________________________"<<endl;
		      for(int i=0;i<12;i++){
                cout<<"MES "<<i+1<<": "<<contar_alquileres_mes[i]<<endl;
                contar_alquileres_totales+=contar_alquileres_mes[i];

		      }

cout<<"CANTIDAD ALQUILERES TOTALES :"<<contar_alquileres_totales<<endl;
cout<<"______________________________________"<<endl;
cout<<"______________________________________"<<endl<<endl<<endl;
}

}

void Reportes_Clientes(){
	Cliente reg;
	Alquileres reg2;

int pos=0,contar_alquileres_totales = 0,contar_alquileres_mes[12]={0};
char id_aux[8];
char Nombre_aux[30];
char Apellido_aux[30];
int pos2=0;

while(reg.Leer_de_disco(pos++)==1){
        pos2=0;
        contar_alquileres_mes[12]={0};
contar_alquileres_totales = 0;
strcpy(id_aux,reg.getDNI_Cliente());
strcpy(Nombre_aux,reg.getNombre());
strcpy(Apellido_aux,reg.getApellido());

        for(int i=0;i<12;i++){

            contar_alquileres_mes[i]=0;
        }


        while(reg2.Leer_de_disco(pos2++)){


            if(strcmp(reg.getDNI_Cliente(),reg2.getDNI_Cliente())==0){

    contar_alquileres_mes[reg2.getFechafinAlquiler().getMes()-1]++;


    }
}


cout<<"______________________________________"<<endl;
cout<<"DNI CLIENTE: "<<id_aux<<endl;
cout<<"CLIENTE: "<<Nombre_aux<<" "<<Apellido_aux<<endl;
cout<<"CANTIDAD ALQUILERES DEL CLIENTE POR MES:"<<endl;
cout<<"______________________________________"<<endl;
		      for(int i=0;i<12;i++){
                cout<<"MES "<<i+1<<": "<<contar_alquileres_mes[i]<<endl;
                contar_alquileres_totales+=contar_alquileres_mes[i];

		      }

cout<<"CANTIDAD ALQUILERES TOTALES DEL CLIENTE :"<<contar_alquileres_totales<<endl;
cout<<"______________________________________"<<endl;
cout<<"______________________________________"<<endl<<endl<<endl;
}

}


void Reportes_Empleados(){
	Empleado reg;
	Alquileres reg2;

int pos=0,contar_alquileres_totales = 0,contar_alquileres_mes[12]={0};
char id_aux[6];
char Nombre_aux[30];
char Apellido_aux[30];
int pos2=0;

while(reg.Leer_de_disco(pos++)==1){
        pos2=0;
        contar_alquileres_mes[12]={0};
contar_alquileres_totales = 0;
strcpy(id_aux,reg.getId_Empleado());
strcpy(Nombre_aux,reg.getNombre());
strcpy(Apellido_aux,reg.getApellido());

        for(int i=0;i<12;i++){

            contar_alquileres_mes[i]=0;
        }

        while(reg2.Leer_de_disco(pos2++)==1){

    if(strcmp(reg.getId_Empleado(),reg2.getIdEmpleado())==0){

    contar_alquileres_mes[reg2.getFechafinAlquiler().getMes()-1]++;



    }
}
cout<<"_______________________________________________________"<<endl;
cout<<"ID_EMPLEADO: "<<id_aux<<endl;
cout<<"EMPLEADO: "<<Nombre_aux<<" "<<Apellido_aux<<endl;
cout<<"CANTIDAD ALQUILERES EFECTUADOS POR EL EMPLEADO POR MES:"<<endl;
cout<<"_______________________________________________________"<<endl;
		      for(int i=0;i<12;i++){
                cout<<"MES "<<i+1<<": "<<contar_alquileres_mes[i]<<endl;
                contar_alquileres_totales+=contar_alquileres_mes[i];

		      }

cout<<"CANTIDAD ALQUILERES TOTALES EFECTUADOS POR EL EMPLEADO :"<<contar_alquileres_totales<<endl;
cout<<"_______________________________________________________"<<endl;
cout<<"_______________________________________________________"<<endl<<endl<<endl;
}

}



#endif // REPORTES_H_INCLUDED

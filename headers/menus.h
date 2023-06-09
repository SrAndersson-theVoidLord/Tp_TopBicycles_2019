#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED
void Menu_Principal_Beta();
void menu_Alquileres();
void menu_Bicicletas();
void menu_clientes();
void menu_Empleados();
void menu_Configuracion();
void Admin_Mode_IDVerification();
void  Menu_Reparaciones();


void Menu_Principal_Beta()
{
     system("cls");
     SetConsoleTitle("ALQUILERES DE BICICLETAS TOP BICYCLES(USUARIO)");
     Archivo a;
     a.Generar_Archivo_Vacio();
    int menu_item=1, run, x=9,opcion=0;
char Nombre_opcion[50];
User_Interface M;
M.firma_Desarrollador();
M.Interface_Menu_Principal();




    while(true)
    {

    rlutil::setColor(cVERDE_CLARO);
                    gotoXY(34,x); cout << "[**>>";
                    gotoXY(92,x); cout << "<<**]";
        /// POSICION DEL CURSOR IMPRESA POR PANTALLA:

        switch(x){
           case 9:
        opcion=1;
        strcpy(Nombre_opcion,"BICICLETAS");
        break;

	     case 13:
	         opcion=2;
	         strcpy(Nombre_opcion,"CLIENTES");
        break;

        case 17:
	         opcion=3;
	         strcpy(Nombre_opcion,"EMPLEADOS");
        break;

        case 21:
	         opcion=4;
	         strcpy(Nombre_opcion,"ALQUILERES");
        break;
        case 25:
	         opcion=5;
	         strcpy(Nombre_opcion,"REPARACION");
        break;
        case 29:
	         opcion=6;
	         strcpy(Nombre_opcion,"CONFIGURACION");
        break;

         case 34:
             opcion=0;
             strcpy(Nombre_opcion,"SALIR");
        break;
	    }




gotoXY(63,39);
cout<<"                                  ";
          rlutil::setColor(cMARRON);
          gotoXY(63,39);
          cout<<opcion<<"-" <<Nombre_opcion;



		system("pause>nul"); // the >nul bit causes it the print no message

		if(GetKeyState(VK_DOWN) & 0x8000 && x != 34) //down button pressed
			{

				gotoXY(34,x); cout << "     ";
				gotoXY(92,x); cout << "     ";
				x+=4;
				rlutil::setColor(cVERDE_CLARO);
				gotoXY(34,x); cout << "[**>>";
                gotoXY(92,x); cout << "<<**]";
               if(x==33){
                    gotoXY(34,x); cout << "     ";
				gotoXY(92,x); cout << "     ";
				x++;
				rlutil::setColor(cVERDE_CLARO);
				gotoXY(34,x); cout << "[**>>";
                gotoXY(92,x); cout << "<<**]";
                }

				menu_item++;
				continue;

			}

		if(GetKeyState(VK_UP) & 0x8000 && x != 9) //up button pressed
			{
			    if(x!=34){
                    gotoXY(34,x); cout << "     ";
				gotoXY(92,x); cout << "     ";
				x-=4;
				rlutil::setColor(cVERDE_CLARO);
				gotoXY(34,x); cout << "[**>>";
                gotoXY(92,x); cout << "<<**]";
			    }


                if(x==34){
                    gotoXY(34,x); cout << "     ";
				gotoXY(92,x); cout << "     ";
				x-=5;
				rlutil::setColor(cVERDE_CLARO);
				gotoXY(34,x); cout << "[**>>";
                gotoXY(92,x); cout << "<<**]";
                }

				menu_item--;
				continue;
			}

		if(GetKeyState(VK_RETURN) & 0x8000){ // Enter key pressed

			switch(menu_item){

				case 1:{
                    menu_Bicicletas();
               system("cls");
               M.Interface_Menu_Principal();
					break;
}


				case 2:{
menu_clientes();

					 system("cls");
               M.Interface_Menu_Principal();

					break;

}

				case 3:{
                    menu_Empleados();

					 system("cls");
               M.Interface_Menu_Principal();
					break;

}
                		case 4:{
                    menu_Alquileres();
					system("cls");
               M.Interface_Menu_Principal();
					break;

					case 5:{
					    Menu_Reparaciones();

					system("cls");
               M.Interface_Menu_Principal();
					break;

					case 6:{
                        Admin_Mode_IDVerification();
					system("cls");
               M.Interface_Menu_Principal();
					break;

}
                    		case 7:{
					///salida
					return ;
					break;
                            }
                        }
                    }
                }
            }
        }
    }


    void menu_Alquileres()
{
     system("cls");
     SetConsoleTitle("ALQUILERES DE BICICLETAS TOP BICYCLES(USUARIO)");
    int menu_item=1, run, x=9,opcion=0;
char Nombre_opcion[50];
User_Interface M;
M.Interface_Menu_Alquileres();

    while(true)
    {

    rlutil::setColor(cVERDE_CLARO);
                    gotoXY(34,x); cout << "[**>>";
                    gotoXY(92,x); cout << "<<**]";
        /// POSICION DEL CURSOR IMPRESA POR PANTALLA:

        switch(x){
           case 9:
        opcion=1;
        strcpy(Nombre_opcion,"ALTA ALQUILERES.");
        break;

	     case 13:
	         opcion=2;
	         strcpy(Nombre_opcion,"BAJA ALQUILERES.");
        break;

        case 17:
	         opcion=3;
	         strcpy(Nombre_opcion,"ENTREGA ALQUILER.");
        break;

        case 21:
	         opcion=4;
	         strcpy(Nombre_opcion,"LISTAR TODOS.");
        break;
        case 25:
	         opcion=5;
	         strcpy(Nombre_opcion,"LISTAR POR ID.");
        break;
        case 29:
	         opcion=6;
	         strcpy(Nombre_opcion,"REPORTES ALQUILERES.");
        break;

         case 34:
             opcion=0;
             strcpy(Nombre_opcion,"VOLVER AL MENU PRINCIPAL.");
        break;
	    }




gotoXY(63,39);
cout<<"                                  ";
          rlutil::setColor(cMARRON);
          gotoXY(63,39);
          cout<<opcion<<"-" <<Nombre_opcion;



		system("pause>nul"); // the >nul bit causes it the print no message

		if(GetKeyState(VK_DOWN) & 0x8000 && x != 34) //down button pressed
			{

				gotoXY(34,x); cout << "     ";
				gotoXY(92,x); cout << "     ";
				x+=4;
				rlutil::setColor(cVERDE_CLARO);
				gotoXY(34,x); cout << "[**>>";
                gotoXY(92,x); cout << "<<**]";
                if(x==33){
                    gotoXY(34,x); cout << "     ";
				gotoXY(92,x); cout << "     ";
				x++;
				rlutil::setColor(cVERDE_CLARO);
				gotoXY(34,x); cout << "[**>>";
                gotoXY(92,x); cout << "<<**]";
                }

				menu_item++;
				continue;

			}

		if(GetKeyState(VK_UP) & 0x8000 && x != 9) //up button pressed
			{
			    if(x!=34){
                    gotoXY(34,x); cout << "     ";
				gotoXY(92,x); cout << "     ";
				x-=4;
				rlutil::setColor(cVERDE_CLARO);
				gotoXY(34,x); cout << "[**>>";
                gotoXY(92,x); cout << "<<**]";
			    }


                if(x==34){
                    gotoXY(34,x); cout << "     ";
				gotoXY(92,x); cout << "     ";
				x-=5;
				rlutil::setColor(cVERDE_CLARO);
				gotoXY(34,x); cout << "[**>>";
                gotoXY(92,x); cout << "<<**]";
                }

				menu_item--;
				continue;
			}

		if(GetKeyState(VK_RETURN) & 0x8000){ // Enter key pressed

			switch(menu_item){

				case 1:{
                    alta_Alquiler();
               system("cls");
               M.Interface_Menu_Alquileres();
					break;
}


				case 2:{
                    baja_logica_Alquiler();

					 system("cls");
               M.Interface_Menu_Alquileres();

					break;

}

				case 3:{
                        entrega_Alquiler();

					 system("cls");
               M.Interface_Menu_Alquileres();
					break;

}
                		case 4:{
                    listar_Alquileres();
                    system("pause>nul");
					system("cls");
               M.Interface_Menu_Alquileres();
					break;

					case 5:{

                    listarAlquileresPorId();
					system("pause>nul");
        system("cls");
               M.Interface_Menu_Alquileres();
					break;

					case 6:{
                    ///reportes alquileres
                    system("cls");
                Reportes_Alquileres();
					system("pause>nul");
        system("cls");
               M.Interface_Menu_Alquileres();
					break;

}
                    		case 7:{
					///salida
					return ;
					break;
                            }
                        }
                    }
                }
            }
        }
    }


    void menu_Bicicletas()
{
     system("cls");
     SetConsoleTitle("ALQUILERES DE BICICLETAS TOP BICYCLES(USUARIO)");
    int menu_item=1, run, x=9,opcion=0;
char Nombre_opcion[50];
User_Interface M;
M.Interface_Menu_Bicicletas();

    while(true)
    {

    rlutil::setColor(cVERDE_CLARO);
                    gotoXY(34,x); cout << "[**>>";
                    gotoXY(92,x); cout << "<<**]";
        /// POSICION DEL CURSOR IMPRESA POR PANTALLA:

        switch(x){
           case 9:
        opcion=1;
        strcpy(Nombre_opcion,"ALTA BICICLETAS");
        break;

	     case 13:
	         opcion=2;
	         strcpy(Nombre_opcion,"MODIFICAR ESTADO DE BICICLETA");
        break;

        case 17:
	         opcion=3;
	         strcpy(Nombre_opcion,"ELIMINAR BICICLETA");
        break;

        case 21:
	         opcion=4;
	         strcpy(Nombre_opcion,"LISTADO DE BICICLETAS");
        break;
        case 25:
	         opcion=5;
	         strcpy(Nombre_opcion,"LISTAR BICICLETA POR ID");
        break;
        case 29:
	         opcion=6;
	         strcpy(Nombre_opcion,"REPORTES BICICLETAS");
        break;

         case 34:
             opcion=0;
             strcpy(Nombre_opcion,"VOLVER AL MENU PRINCIPAL.");
        break;
	    }




gotoXY(63,39);
cout<<"                                  ";
          rlutil::setColor(cMARRON);
          gotoXY(63,39);
          cout<<opcion<<"-" <<Nombre_opcion;



		system("pause>nul"); // the >nul bit causes it the print no message

		if(GetKeyState(VK_DOWN) & 0x8000 && x != 34) //down button pressed
			{

				gotoXY(34,x); cout << "     ";
				gotoXY(92,x); cout << "     ";
				x+=4;
				rlutil::setColor(cVERDE_CLARO);
				gotoXY(34,x); cout << "[**>>";
                gotoXY(92,x); cout << "<<**]";
                 if(x==33){
                    gotoXY(34,x); cout << "     ";
				gotoXY(92,x); cout << "     ";
				x++;
				rlutil::setColor(cVERDE_CLARO);
				gotoXY(34,x); cout << "[**>>";
                gotoXY(92,x); cout << "<<**]";
                }

				menu_item++;
				continue;

			}

		if(GetKeyState(VK_UP) & 0x8000 && x != 9) //up button pressed
			{
			    if(x!=34){
                    gotoXY(34,x); cout << "     ";
				gotoXY(92,x); cout << "     ";
				x-=4;
				rlutil::setColor(cVERDE_CLARO);
				gotoXY(34,x); cout << "[**>>";
                gotoXY(92,x); cout << "<<**]";
			    }


                if(x==34){
                    gotoXY(34,x); cout << "     ";
				gotoXY(92,x); cout << "     ";
				x-=5;
				rlutil::setColor(cVERDE_CLARO);
				gotoXY(34,x); cout << "[**>>";
                gotoXY(92,x); cout << "<<**]";
                }

				menu_item--;
				continue;
			}

		if(GetKeyState(VK_RETURN) & 0x8000){ // Enter key pressed

			switch(menu_item){

				case 1:{
                    alta_Bicicleta();
               system("cls");
               M.Interface_Menu_Bicicletas();
					break;
}


				case 2:{
                     modifica_Estado();

					 system("cls");
               M.Interface_Menu_Bicicletas();

					break;

}

				case 3:{
                    baja_logica_Bicicleta();

					 system("cls");
               M.Interface_Menu_Bicicletas();
					break;

}
                		case 4:{
                        listar_Bicicleta();
                        system("pause>nul");
					system("cls");
               M.Interface_Menu_Bicicletas();
					break;

					case 5:{
                        listarBicicletaPorId();
					system("pause>nul");
        system("cls");
               M.Interface_Menu_Bicicletas();
					break;

					case 6:{

					    system("cls");
                        Reportes_Bicicletas();
					system("pause>nul");
        system("cls");
M.Interface_Menu_Bicicletas();
					break;

}
                    		case 7:{
					///salida
					return ;
					break;
                            }
                        }
                    }
                }
            }
        }
    }

    void menu_clientes()
{
     system("cls");
     SetConsoleTitle("ALQUILERES DE BICICLETAS TOP BICYCLES(USUARIO)");
    int menu_item=1, run, x=9,opcion=0;
char Nombre_opcion[50];
User_Interface M;
M.Interface_Menu_Clientes();

    while(true)
    {

    rlutil::setColor(cVERDE_CLARO);
                    gotoXY(34,x); cout << "[**>>";
                    gotoXY(92,x); cout << "<<**]";
        /// POSICION DEL CURSOR IMPRESA POR PANTALLA:

        switch(x){
           case 9:
        opcion=1;
        strcpy(Nombre_opcion,"ALTA CLIENTE.");
        break;

	     case 13:
	         opcion=2;
	         strcpy(Nombre_opcion,"MODIFICAR TELEFONO.");
        break;

        case 17:
	         opcion=3;
	         strcpy(Nombre_opcion,"ELIMINAR CLIENTE.");
        break;

        case 21:
	         opcion=4;
	         strcpy(Nombre_opcion,"LISTAR TODOS LOS CLIENTES.");
        break;
        case 25:
	         opcion=5;
	         strcpy(Nombre_opcion,"LISTAR CLIENTE POR DNI.");
        break;
        case 29:
	         opcion=6;
	         strcpy(Nombre_opcion,"REPORTES CLIENTES.");
        break;

         case 34:
             opcion=0;
             strcpy(Nombre_opcion,"VOLVER AL MENU PRINCIPAL.");
        break;
	    }




gotoXY(63,39);
cout<<"                                  ";
          rlutil::setColor(cMARRON);
          gotoXY(63,39);
          cout<<opcion<<"-" <<Nombre_opcion;



		system("pause>nul"); // the >nul bit causes it the print no message

		if(GetKeyState(VK_DOWN) & 0x8000 && x != 34) //down button pressed
			{

				gotoXY(34,x); cout << "     ";
				gotoXY(92,x); cout << "     ";
				x+=4;
				rlutil::setColor(cVERDE_CLARO);
				gotoXY(34,x); cout << "[**>>";
                gotoXY(92,x); cout << "<<**]";
                if(x==33){
                    gotoXY(34,x); cout << "     ";
				gotoXY(92,x); cout << "     ";
				x++;
				rlutil::setColor(cVERDE_CLARO);
				gotoXY(34,x); cout << "[**>>";
                gotoXY(92,x); cout << "<<**]";
                }

				menu_item++;
				continue;

			}

		if(GetKeyState(VK_UP) & 0x8000 && x != 9) //up button pressed
			{
			    if(x!=34){
                    gotoXY(34,x); cout << "     ";
				gotoXY(92,x); cout << "     ";
				x-=4;
				rlutil::setColor(cVERDE_CLARO);
				gotoXY(34,x); cout << "[**>>";
                gotoXY(92,x); cout << "<<**]";
			    }


                if(x==34){
                    gotoXY(34,x); cout << "     ";
				gotoXY(92,x); cout << "     ";
				x-=5;
				rlutil::setColor(cVERDE_CLARO);
				gotoXY(34,x); cout << "[**>>";
                gotoXY(92,x); cout << "<<**]";
                }

				menu_item--;
				continue;
			}

		if(GetKeyState(VK_RETURN) & 0x8000){ // Enter key pressed

			switch(menu_item){

				case 1:{
                    alta_cli();
               system("cls");
               M.Interface_Menu_Clientes();
					break;
}


				case 2:{
                     modifica_tel();

					 system("cls");
               M.Interface_Menu_Clientes();

					break;

}

				case 3:{
                    baja_logica_cli();

					 system("cls");
               M.Interface_Menu_Clientes();
					break;

}
                		case 4:{
                        listar_cli();
                        system("pause>nul");
					system("cls");
               M.Interface_Menu_Clientes();
					break;

					case 5:{
                    listarClientePorDni();
					system("pause>nul");
        system("cls");
               M.Interface_Menu_Clientes();
					break;

					case 6:{
					    system("cls");
                        Reportes_Clientes();
					system("pause>nul");
        system("cls");
               M.Interface_Menu_Clientes();
					break;

}
                    		case 7:{
					///salida
					return ;
					break;
                            }
                        }
                    }
                }
            }
        }
    }


          void menu_Empleados()
{
     system("cls");
     SetConsoleTitle("ALQUILERES DE BICICLETAS TOP BICYCLES(USUARIO)");
    int menu_item=1, run, x=9,opcion=0;
char Nombre_opcion[50];
User_Interface M;
M.Interface_Menu_Empleados();

    while(true)
    {

    rlutil::setColor(cVERDE_CLARO);
                    gotoXY(34,x); cout << "[**>>";
                    gotoXY(92,x); cout << "<<**]";
        /// POSICION DEL CURSOR IMPRESA POR PANTALLA:

        switch(x){
           case 9:
        opcion=1;
        strcpy(Nombre_opcion,"NUEVO EMPLEADO.");
        break;

	     case 13:
	         opcion=2;
	         strcpy(Nombre_opcion,"MODIFICAR EMPLEADO.");
        break;

        case 17:
	         opcion=3;
	         strcpy(Nombre_opcion,"ELIMINAR EMPLEADO.");
        break;

        case 21:
	         opcion=4;
	         strcpy(Nombre_opcion,"LISTAR TODOS LOS EMPLEADOS.");
        break;
        case 25:
	         opcion=5;
	         strcpy(Nombre_opcion,"LISTAR EMPLEADO POR ID.");
        break;
        case 29:
	         opcion=6;
	         strcpy(Nombre_opcion,"REPORTES EMPLEADOS.");
        break;

         case 34:
             opcion=0;
             strcpy(Nombre_opcion,"VOLVER AL MENU PRINCIPAL.");
        break;
	    }




gotoXY(63,39);
cout<<"                                  ";
          rlutil::setColor(cMARRON);
          gotoXY(63,39);
          cout<<opcion<<"-" <<Nombre_opcion;



		system("pause>nul"); // the >nul bit causes it the print no message

		if(GetKeyState(VK_DOWN) & 0x8000 && x != 34) //down button pressed
			{

				gotoXY(34,x); cout << "     ";
				gotoXY(92,x); cout << "     ";
				x+=4;
				rlutil::setColor(cVERDE_CLARO);
				gotoXY(34,x); cout << "[**>>";
                gotoXY(92,x); cout << "<<**]";
                 if(x==33){
                    gotoXY(34,x); cout << "     ";
				gotoXY(92,x); cout << "     ";
				x++;
				rlutil::setColor(cVERDE_CLARO);
				gotoXY(34,x); cout << "[**>>";
                gotoXY(92,x); cout << "<<**]";
                }

				menu_item++;
				continue;

			}

		if(GetKeyState(VK_UP) & 0x8000 && x != 9) //up button pressed
			{
			    if(x!=34){
                    gotoXY(34,x); cout << "     ";
				gotoXY(92,x); cout << "     ";
				x-=4;
				rlutil::setColor(cVERDE_CLARO);
				gotoXY(34,x); cout << "[**>>";
                gotoXY(92,x); cout << "<<**]";
			    }


                if(x==34){
                    gotoXY(34,x); cout << "     ";
				gotoXY(92,x); cout << "     ";
				x-=5;
				rlutil::setColor(cVERDE_CLARO);
				gotoXY(34,x); cout << "[**>>";
                gotoXY(92,x); cout << "<<**]";
                }

				menu_item--;
				continue;
			}

		if(GetKeyState(VK_RETURN) & 0x8000){ // Enter key pressed

			switch(menu_item){

				case 1:{
                    alta_Empleado();
               system("cls");
               M.Interface_Menu_Empleados();
					break;
}


				case 2:{
                        modifica_Empleado();

					 system("cls");
               M.Interface_Menu_Empleados();

					break;

}

				case 3:{
                    baja_logica_Empleado();

					 system("cls");
               M.Interface_Menu_Empleados();
					break;

}
                		case 4:{
                        listar_Empleado();
                        system("pause>nul");
					system("cls");
               M.Interface_Menu_Empleados();
					break;

					case 5:{
                        listarEmpleadoPorId();
					system("pause>nul");
        system("cls");
               M.Interface_Menu_Empleados();
					break;

					case 6:{
					    system("cls");
                        Reportes_Empleados();
					system("pause>nul");
        system("cls");
                M.Interface_Menu_Empleados();
					break;

}
                    		case 7:{
					///salida
					return ;
					break;
                            }
                        }
                    }
                }
            }
        }
    }

void Admin_Mode_IDVerification()
{
SetConsoleTitle("Recording Studio Manager_Alpha(VERIFICACION MODO ADMINISTRADOR)");
///DEFINICION DE CONTRASEÑA:
#define PASS "112223"
#define ENTER 13
#define BACKSPACE 8

    string password;

    int contador = 0;
    bool ingresa = false;
Window a;
    do
    {
        system("cls");

        char caracter;
        a.window(30,0,70,25);
        a.window(40,8,50,4);
        rlutil::setColor(cROJO);
        gotoXY(50,5);
        cout<<"INTENTOS:";
        rlutil::setColor(cROJO_CLARO);
        cout<<contador+1;
        rlutil::setColor(cROJO);
        gotoXY(50,10);

        cout<<"CONTRASE"<< (char) 165 <<"A : ";
        rlutil::setColor(cMARRON);
        caracter = getch();

        password = "";

        while (caracter != ENTER)
        {

            if (caracter != BACKSPACE)
            {
                password.push_back(caracter);
                cout << "*";

            }
            else
            {
                if (password.length() > 0)
                {
                    cout << "b b";
                    password = password.substr(0, password.length() - 1);
                }
            }

            caracter = getch();
        }


        if (password == PASS)
        {
            ingresa = true;
        }
        else
        {




            ///cin.get();
            contador++;
            if(contador<3)
            {
                rlutil::setColor(cROJO_CLARO);
                gotoXY(40,20);
                cout<<"CONTRASE"<< (char) 165 <<"A INCORRECTA:INGRESE UNA CONTRASE"<<"CONTRASE"<< (char) 165 <<"A VALIDA ";
                system("pause>nul");

            }

        }
    }
    while (ingresa == false && contador < 3);

    if (ingresa == false)
    {
        a.window(30,0,70,25);
        a.window(40,8,50,7);
        rlutil::setColor(cROJO_CLARO);
        gotoXY(45,9.5);
        cout<<"ERROR:SE ACABARON LOS INTENTOS,"<<endl;
        gotoXY(45,10.5);
        cout<<"POR FAVOR , PRESIONE 0 PARA VOLVER AL"<<endl;
        gotoXY(45,11.5);
        cout<<"MENU DE INICIO DEL EmpleadoGRAMA"<<endl;
        gotoXY(45,12.5);
        cout<<"======================================"<<endl;
        gotoXY(45,13.5);
        cout<<"0-VOLVER AL MENU DE INICIO DEL EmpleadoGRAMA"<<endl;


    }
    else
    {
        system("cls");
        a.window(30,0,70,25);
        a.window(50,8,30,4);
        rlutil::setColor(cVERDE_CLARO);
        gotoXY(32,7);
         cout<<"CONTRASE"<< (char) 165 <<"A INGRESADA CORRECTAMENTE: ACCESO ADMINISTRADOR PERMITIDO"<<endl;
        gotoXY(60,10);
        rlutil::setColor(cAZUL_CLARO);
        cout<<"BIENVENIDO!!!";


        system("pause>nul");
        system("cls");

        menu_Configuracion();

    }

    cin.get();///GENERA UNA PAUSA INTERMEDIA ENTRE EL MODO ADMIN Y EL MENU MODO APERTURA

}



void menu_Configuracion(){

    int opc;
	while(1)
		{
		system("cls");
		setColor(LIGHTRED);
		cout<<"CONFIGURACION TOP BICYCLE"<<endl;
		setColor(LIGHTBLUE);
		cout<<"__________________________"<<endl;
		setColor(LIGHTGREEN);
		cout<<"MENU CONFIGURACION"<<endl;
		setColor(LIGHTBLUE);
		cout<<"-------------------------------"<<endl;
		setColor(LIGHTGREEN);
		cout<<"1. CARGAR/MODIFICAR PRECIO"<<endl;
		setColor(LIGHTBLUE);
		cout<<"-------------------------------"<<endl;
		setColor(LIGHTGREEN);
		cout<<"2. REALIZAR  BACKUPS DE LOS REGISTROS"<<endl;
		setColor(LIGHTBLUE);
		cout<<"-------------------------------"<<endl;
		setColor(LIGHTGREEN);
		cout<<"3. CARGAR BACKUPS DE LOS REGISTROS EN EL SISTEMA"<<endl;
		setColor(LIGHTBLUE);
		cout<<"-------------------------------"<<endl;
		setColor(LIGHTRED);
		cout<<"0. VOLVER AL MENU PRINCIPAL"<<endl;
		setColor(LIGHTBLUE);
		cout<<"-------------------------------"<<endl;
		setColor(YELLOW);
		cout<<"INGRESE UNA OPCION: "<<endl<<endl<<endl;
		setColor(LIGHTBLUE);
		cout<<"OPCION:";
		setColor(YELLOW);
		cin>>opc;
		Archivo a;
		switch(opc)
			{
			 case 1: Alta_inicial_o_Modificacion();break;
			 case 2: a.Realizar_Backups();break;
			 case 3: a.Cargar_Backups();break;
			 case 0: return;
			 default: cout<<"Opcion incorrecta. Presione una tecla para continuar";
								system("pause>null");
								break;
			}
		}


}

void Menu_Reparaciones()
{
     system("cls");
     SetConsoleTitle("ALQUILERES DE BICICLETAS TOP BICYCLES(USUARIO)");
    int menu_item=1, run, x=9,opcion=0;
char Nombre_opcion[50];
User_Interface M;

M.Interface_Menu_Reparaciones();




    while(true)
    {

    rlutil::setColor(cVERDE_CLARO);
                    gotoXY(34,x); cout << "[**>>";
                    gotoXY(92,x); cout << "<<**]";
        /// POSICION DEL CURSOR IMPRESA POR PANTALLA:

        switch(x){
           case 9:
        opcion=1;
        strcpy(Nombre_opcion,"INGRESOS AL TALLER.");
        break;

	     case 13:
	         opcion=2;
	         strcpy(Nombre_opcion,"SALIDAS DEL TALLER.");
        break;

        case 17:
	         opcion=3;
	         strcpy(Nombre_opcion,"LISTAR TODAS LAS REPARACIONES.");
        break;

        case 21:
	         opcion=4;
	         strcpy(Nombre_opcion,"LISTAR REPARADAS.");
        break;
        case 25:
	         opcion=5;
	         strcpy(Nombre_opcion,"LISTAR REPARACION POR ID INGRESO.");
        break;
        case 29:
	         opcion=6;
	         strcpy(Nombre_opcion,"LISTAR POR ID BICICLETA.");
        break;

         case 34:
             opcion=0;
             strcpy(Nombre_opcion,"VOLVER AL MENU PRINCIPAL");
        break;
	    }




gotoXY(63,39);
cout<<"                                    ";
          rlutil::setColor(cMARRON);
          gotoXY(63,39);
          cout<<opcion<<"-" <<Nombre_opcion;



		system("pause>nul"); // the >nul bit causes it the print no message

		if(GetKeyState(VK_DOWN) & 0x8000 && x != 34) //down button pressed
			{

				gotoXY(34,x); cout << "     ";
				gotoXY(92,x); cout << "     ";
				x+=4;
				rlutil::setColor(cVERDE_CLARO);
				gotoXY(34,x); cout << "[**>>";
                gotoXY(92,x); cout << "<<**]";
               if(x==33){
                    gotoXY(34,x); cout << "     ";
				gotoXY(92,x); cout << "     ";
				x++;
				rlutil::setColor(cVERDE_CLARO);
				gotoXY(34,x); cout << "[**>>";
                gotoXY(92,x); cout << "<<**]";
                }

				menu_item++;
				continue;

			}

		if(GetKeyState(VK_UP) & 0x8000 && x != 9) //up button pressed
			{
			    if(x!=34){
                    gotoXY(34,x); cout << "     ";
				gotoXY(92,x); cout << "     ";
				x-=4;
				rlutil::setColor(cVERDE_CLARO);
				gotoXY(34,x); cout << "[**>>";
                gotoXY(92,x); cout << "<<**]";
			    }


                if(x==34){
                    gotoXY(34,x); cout << "     ";
				gotoXY(92,x); cout << "     ";
				x-=5;
				rlutil::setColor(cVERDE_CLARO);
				gotoXY(34,x); cout << "[**>>";
                gotoXY(92,x); cout << "<<**]";
                }

				menu_item--;
				continue;
			}

		if(GetKeyState(VK_RETURN) & 0x8000){ // Enter key pressed

			switch(menu_item){

				case 1:{
                    IngresoTaller();
                    system("pause>null");
               system("cls");
               M.Interface_Menu_Reparaciones();
					break;
}


				case 2:{
                    salidaTaller();
                    system("pause>null");
					 system("cls");
               M.Interface_Menu_Reparaciones();

					break;

}

				case 3:{
                    listar_EnReparacion(); /// Reparaciones activas
                    system("pause>null");

					 system("cls");
               M.Interface_Menu_Reparaciones();
					break;

}
                		case 4:{
                    listarBicicletasReparadas();
                    system("pause>null");
					system("cls");
               M.Interface_Menu_Reparaciones();
					break;

					case 5:{
					    listarReparacionPorId();
                    system("pause>null");
					system("cls");
               M.Interface_Menu_Reparaciones();
					break;

					case 6:{
                    listarReparacionPorIdBicicleta();
                    system("pause>null");
					system("cls");
               M.Interface_Menu_Reparaciones();
					break;

}
                    		case 7:{
					///salida
					return ;
					break;
                            }
                        }
                    }
                }
            }
        }
    }








#endif // MENUS_H_INCLUDED

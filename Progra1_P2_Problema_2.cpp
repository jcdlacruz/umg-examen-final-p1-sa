#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
#include <regex>
#include <ctime>
#include <cstdlib>

using namespace std;

struct Registro02{
    string codigo;
    string descripcion;
    float precio;
    int cantidad;
    string fecha;
    Registro02* apuntador02;
};

struct Registro02* head02;
struct inFecha{
    unsigned int y, m, d;
};

inFecha parse_date(const string &s);

void agregarRegistro02(){
	InicioRegistro02:
		ofstream archivo;
		string nombreArchivo;
		fflush(stdin);
		system("CLS");
		cout<<"Archivo default: inventario.txt"<<endl;
		cout<<"Indique nombre de archivo: ";
		getline(cin,nombreArchivo);
		archivo.open(nombreArchivo.c_str(),ios::app);

		if(archivo.fail()){
			archivo.close();
			cout<<"No se pudo abrir el archivo";
			exit(1);
		}
		archivo.close();

		fflush(stdin);
		system("CLS");

		int registros02 = 0;

        cout<<"Ingrese cantidad de productos a cargar en inventario: "<<endl;
        cin>>registros02;

		if(registros02 < 1){
			cout<<"Debe ingresar una cantidad valida. Intente de nuevo."<<endl;
			system("Pause");
			goto InicioRegistro02;
		}

        head02 = NULL;
        string codigo;
        string descripcion;
        char opcion;
        float precio = 0;
        int cantidad = 0;
        string fecha;
        string fechaIngresada;
        int bandera = 0;
        
        const int MAXLEN = 80;
        char fechaSistema[MAXLEN];
        time_t t = time(0);
        strftime(fechaSistema, MAXLEN, "%Y%m%d", localtime(&t));

		for(int i = 0; i < registros02; i ++){
            system("cls");

            struct Registro02* temp02 = new Registro02();
            bandera = 0;

            cout<<"Ingreso de datos para el producto: "<<i+1<<endl;

            cin.ignore();
            cout<<"Ingrese codigo: "<<endl;
            cin>>codigo;

            cin.ignore();
            cout<<"Ingrese descripcion: ";
		    getline(cin,descripcion);

            cin.ignore();
            cout<<"Ingrese precio: "<<endl;
            cin>>precio;

            if(precio < 0.1){
                cout<<"Debe ingresar un precio valido. Intente de nuevo."<<endl;
                bandera = 1;
                i = i - 1;
			    system("Pause");
            }

            if(bandera == 0){
                cout<<"Ingrese cantidad de unidades a cargar: "<<endl;
                cin>>cantidad;

                if(cantidad < 1){
                    cout<<"Debe ingresar una cantidad valida. Intente de nuevo."<<endl;
                    bandera = 1;
                    i = i - 1;
			        system("Pause");
                }

                if(bandera == 0){
                    cout<<"Fecha actual: "<<fechaSistema<<endl;
                    cout<<"Desea utilizar esta fecha como fecha de ingreso a inventario (s/n)?"<<endl;
                    cin>>opcion;

                    opcion = toupper(opcion);

                    if(opcion == 'S'){
                        fecha = fechaSistema;
                    }else if(opcion == 'N'){
                        cin.ignore();
                        cout<<"Fecha de ingreso a inventario en formato YYYYMMDD (ejemplo: 20200604): ";
                        getline(cin,fechaIngresada);

                        inFecha d = parse_date(fechaIngresada);

                        if(d.d < 1 || d.d > 31){
                            cout<<"Debe ingresar una fecha valida, el dia es incorrecto. Intente de nuevo."<<endl;
                            bandera = 1;
                            i = i - 1;
                            system("Pause");
                        }

                        if(d.m < 1 || d.m > 12){
                            cout<<"Debe ingresar una fecha valida, el mes es incorrecto. Intente de nuevo."<<endl;
                            bandera = 1;
                            i = i - 1;
                            system("Pause");
                        }

                        if(d.y < 2020 || d.y > 2020){
                            cout<<"Debe ingresar una fecha valida, el anio es incorrecto. Intente de nuevo."<<endl;
                            bandera = 1;
                            i = i - 1;
                            system("Pause");
                        }
                        fecha = fechaIngresada;

                        //cout<<"Datos a guardar:"<<endl;
                        //cout<<codigo<<"|"<<descripcion<<"|"<<precio<<"|"<<cantidad<<"|"<<fecha<<"|"<<endl;
                        
                    }else{
                        cout<<"Debe ingresar una opcion valida. Intentelo de nuevo."<<endl;
                        bandera = 1;
                        i = i - 1;
                        system("Pause");
                    }
                    
                    if(bandera == 0){
                        temp02->codigo = codigo;
                        temp02->descripcion = descripcion;
                        temp02->precio = precio;
                        temp02->cantidad = cantidad;
                        temp02->fecha = fecha;
                        temp02->apuntador02 = NULL;
                        if(head02 != NULL)
                            temp02->apuntador02 = head02;
                        head02 = temp02;
                    }
                }
            }
		}

        archivo.open(nombreArchivo.c_str(),ios::app);
        if(archivo.fail()){
            archivo.close();
            cout<<"No se pudo abrir el archivo";
            exit(1);
        }
        system("CLS");

        struct Registro02* temp = head02;
        while(temp != NULL ){
            archivo<<temp->codigo<<'\t'
            <<temp->descripcion<<'\t'
            <<temp->precio<<'\t'
            <<temp->cantidad<<'\t'
            <<temp->fecha<<endl;
            temp = temp->apuntador02;
        }

        archivo.close();

        cout<<"Registros agregados exitosamente."<<endl;
};

inFecha parse_date(const string &s)
{
   inFecha d;
   
   d.y = atoi(s.substr(0, 4).c_str());
   d.m = atoi(s.substr(4, 2).c_str());
   d.d = atoi(s.substr(6, 2).c_str());
   return d;
}

void reporte02(){
	 fflush(stdin);
	 system("CLS");

     int cont = 0;
     string codigo;
     string descripcion;
     float precio;
     int cantidad;
     string fecha;

	 struct Registro02* temp02 = head02;

     cout<<"*Trabajando con datos en memoria."<<endl;
	 cout<<"------------------------"<<endl;
	 cout<<"        Reporte         "<<endl;
     cout<<"     de inventario      "<<endl;
	 cout<<"------------------------"<<endl;
     cout<<"No. | Codigo | Descripcion | Precio | Cantidad  | Ingreso " <<endl;
     while(temp02 != NULL ){
         cont++;
         codigo = temp02->codigo;
         descripcion = temp02->descripcion;
         precio = temp02->precio;
         cantidad = temp02->cantidad;
         fecha = temp02->fecha;
         temp02 = temp02->apuntador02;

         cout<<cont<<"\t"<<codigo<<"\t"<<descripcion<<"\t"<<precio
             <<"\t"<<cantidad<<"\t"<<fecha<<endl;
     }
};

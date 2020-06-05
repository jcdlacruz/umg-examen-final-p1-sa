#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
#include <regex>
#include <ctime>
#include <cstdlib>

using namespace std;

struct Registro03{
    string codigo;
    string nombre;
    string direccion;
    int estado;
    float peso;
    Registro03* apuntador03;
};

struct Registro03* head03;

void agregarRegistro03(){
	InicioRegistro03:
		ofstream archivo;
		string nombreArchivo;
		fflush(stdin);
		system("CLS");
		cout<<"Archivo default: entrega.txt"<<endl;
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

		int registros03 = 0;

        cout<<"Ingrese cantidad de paquetes a cargar en inventario: "<<endl;
        cin>>registros03;

		if(registros03 < 1){
			cout<<"Debe ingresar una cantidad valida. Intente de nuevo."<<endl;
			system("Pause");
			goto InicioRegistro03;
		}

        head03 = NULL;
        string codigo;
        string nombre;
        string direccion;
        int estado;
        float peso;
        int bandera = 0;
        
		for(int i = 0; i < registros03; i ++){
            system("cls");

            struct Registro03* temp03 = new Registro03();
            bandera = 0;

            cout<<"Ingreso de datos para el producto: "<<i+1<<endl;

            cin.ignore();
            cout<<"Ingrese codigo: "<<endl;
            cin>>codigo;

            cin.ignore();
            cout<<"Ingrese nombre del cliente: ";
		    getline(cin,nombre);

            cin.ignore();
            cout<<"Ingrese direccion de entrega: "<<endl;
            getline(cin,direccion);

            cin.ignore();
            cout<<"Ingrese peso en libras (peso max: 1000lb): "<<endl;
            cin>>peso;

            if(peso < 0.1 || peso > 1000){
                cout<<"Debe ingresar un peso valido. Intente de nuevo."<<endl;
                bandera = 1;
                i = i - 1;
			    system("Pause");
            }
                   
            if(bandera == 0){
                nombre = regex_replace(nombre, regex("\\s+"), "_");
                nombre = regex_replace(nombre, regex("\\W+"), "");

                direccion = regex_replace(direccion, regex("-"), "_");
                direccion = regex_replace(direccion, regex("\\s+"), "_");
                direccion = regex_replace(direccion, regex("\\W+"), "");

                temp03->codigo = codigo;
                temp03->nombre = nombre;
                temp03->direccion = direccion;
                temp03->estado = 1;
                temp03->peso = peso;
                temp03->apuntador03 = NULL;
                if(head03 != NULL)
                    temp03->apuntador03 = head03;
                head03 = temp03;
            }
		}

        archivo.open(nombreArchivo.c_str(),ios::app);
        if(archivo.fail()){
            archivo.close();
            cout<<"No se pudo abrir el archivo";
            exit(1);
        }
        system("CLS");

        struct Registro03* temp = head03;
        while(temp != NULL ){
            archivo<<temp->codigo<<'\t'
            <<temp->nombre<<'\t'
            <<temp->direccion<<'\t'
            <<temp->estado<<'\t'
            <<temp->peso<<endl;
            temp = temp->apuntador03;
        }

        archivo.close();

        cout<<"Registros agregados exitosamente."<<endl;
};

void reporte03(){
	 fflush(stdin);
	 system("CLS");

     string codigo;
     string nombre;
     string direccion;
     int estado;
     float peso;
     int cont = 0;
     string mensaje;

	 struct Registro03* temp03 = head03;

     if(temp03 != NULL){
        cout<<"*Trabajando con datos en memoria."<<endl;
        cout<<"------------------------"<<endl;
        cout<<"        Reporte         "<<endl;
        cout<<"     de inventario      "<<endl;
        cout<<"------------------------"<<endl;
        cout<<"No. | Codigo |      Nombre      |       Direccion       | Peso  | Estado " <<endl;
     
        while(temp03 != NULL ){
            cont++;
            codigo = temp03->codigo;
            nombre = temp03->nombre;
            direccion = temp03->direccion;
            peso = temp03->peso;
            estado = temp03->estado;
            temp03 = temp03->apuntador03;

            nombre = regex_replace(nombre, regex("_"), " ");
            direccion = regex_replace(direccion, regex("_"), " ");

            if(estado == 1){
                mensaje = "Cargado";
            }else{mensaje = "Descargado";}

            cout<<cont<<"\t"<<codigo<<"\t"<<nombre<<"\t"<<direccion
                <<"\t"<<peso<<"\t"<<mensaje<<endl;
        }
    }else{
        cout<<"Actualmente no existe inventario."<<endl;
    }
};

/*void descargarRegistro02(){
    reporte02();
    cout<<endl;
    if(inic == NULL){
        cout<<"Ingrese inventario por medio de la opcion 1 - Cargar inventario."<<endl;
    }else{
        char opcion;
        cout<<"Se descargara/eliminara el ultimo producto ingresado a inventario."<<endl;
        cout<<"Esta seguro que desea continuar (s/n)?"<<endl;
        cin>>opcion;

        opcion = toupper(opcion);

        if(opcion == 'S'){
            Registro02 *pop = inic;
            inic = inic -> apuntador02;
            delete(pop);
            cout<<"Producto eliminado de inventario."<<endl;        
        }
    }
};*/
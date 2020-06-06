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
    Registro03 *apuntador03;
} *inici, *fi;

struct  listaEnvio{
    string producto;
    listaEnvio *apuntadorEnvio;
};

struct listaEnvio* headEnvio;


bool searchInventario(const string &b);
bool searchListaEnvio(const string &l);
void agregarEnvio(const string code);

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

        string codigo;
        string nombre;
        string direccion;
        int estado;
        float peso;
        int bandera = 0;
        
		for(int i = 0; i < registros03; i ++){
            system("cls");

            Registro03 *nuevo = new Registro03(); 

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

                nuevo->codigo = codigo;
                nuevo->nombre = nombre;
                nuevo->direccion = direccion;
                nuevo->estado = 1;
                nuevo->peso = peso;
                if(inici == NULL){
                    inici = nuevo;
                    inici->apuntador03=NULL;
                    fi = inici;

                }else{
                    fi -> apuntador03 = nuevo;
                    nuevo -> apuntador03 = NULL;
                    fi = nuevo;
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

        Registro03 *temp = new Registro03();
        temp = inici;
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
     bool enListaDeEnvio = false;

     Registro03 *temp03 = new Registro03();
     temp03 = inici;

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

            enListaDeEnvio = searchListaEnvio(codigo);
            if(enListaDeEnvio == true){
                mensaje = "En lista de envio";
            }

            cout<<cont<<"\t"<<codigo<<"\t"<<nombre<<"\t"<<direccion
                <<"\t"<<peso<<"\t"<<mensaje<<endl;
        }
    }else{
        cout<<"Actualmente no existe inventario."<<endl;
    }
};

void descargarRegistro03(){
    MenuDescargarRegistro03:
        reporte03();
        cout<<endl;
        
        Registro03 *actual = new Registro03();
        actual = inici;
        bool flag = false;
        string buscar;
        char opcion;

        if(inici != NULL){
            cout<<"Presione ENTER para continuar."<<endl;
            cin.ignore();
            cout<<"Ingrese codigo del paquete a descargar: "<<endl;
            getline(cin,buscar);

            while(actual != NULL && flag != true){
                if(actual-> codigo == buscar){
                    if(actual -> estado == 1 && searchListaEnvio(buscar) == false){
                        cout<<"Paquete con codigo "<<buscar<<", encontrado."<<endl;
                        cout<<"Presione ENTER para continuar."<<endl;
                        
                        cin.ignore();
                        cout<<"Esta seguro que quiere descargar el paquete de inventario (s/n)?";
                        cin>>opcion;

                        opcion = toupper(opcion);
                        if(opcion == 'S'){
                            actual ->estado = 0;
                            cout<<"El paquete fue descargado de inventario exitosamente."<<endl;
                            flag = true;
                        }else{
                            cout<<"El paquete no fue modificado."<<endl;
                            cout<<"Proceso finalizado."<<endl;
                            flag = true;
                        }
                    }else{
                        cout<<"El paquete ya se encuentra actualmente descargado de inventario o en listo para envio."<<endl;
                        flag = true;
                    }
                }
                actual = actual -> apuntador03;
            }
            if(!flag){
                cout<<"Paquete no encontrado."<<endl;
            }
        }
};

void programaEnvio03(){
    MenuProgramaEnvio03:
        fflush(stdin);
        system("CLS");

        string codigo;
        string nombre;
        string direccion;
        int estado;
        float peso;
        int cont = 0;
        string mensaje;
        string buscar;
        bool existe = false;
        bool enListaDeEnvio = false;
        float pesoEnvio = 0;

        Registro03 *actual02 = new Registro03();
        actual02 = inici;

        if(actual02 != NULL){
            cout<<"*Trabajando con datos en memoria."<<endl;
            cout<<"------------------------"<<endl;
            cout<<"        Reporte         "<<endl;
            cout<<"     de inventario      "<<endl;
            cout<<"------------------------"<<endl;
            cout<<"No. | Codigo |      Nombre      |       Direccion       | Peso  | Estado " <<endl;
        
            while(actual02 != NULL ){
                if(actual02->estado == 1){
                    cont++;
                    codigo = actual02->codigo;
                    nombre = actual02->nombre;
                    direccion = actual02->direccion;
                    peso = actual02->peso;
                    estado = actual02->estado;

                    nombre = regex_replace(nombre, regex("_"), " ");
                    direccion = regex_replace(direccion, regex("_"), " ");

                    if(estado == 1){
                        mensaje = "Cargado";
                    }else{mensaje = "Descargado";}

                    enListaDeEnvio = searchListaEnvio(codigo);
                    if(enListaDeEnvio == true){
                        mensaje = "En lista de envio";
                        pesoEnvio += peso;
                    }

                    cout<<cont<<"\t"<<codigo<<"\t"<<nombre<<"\t"<<direccion
                        <<"\t"<<peso<<"\t"<<mensaje<<endl;
                }
                actual02 = actual02 -> apuntador03;
            }
            if(cont == 0){
                cout<<"Actualmente no existe paquetes listos para envio."<<endl;
            }else{
                cout<<"Peso total del envio actual: "<<pesoEnvio<<endl;
                
                if(pesoEnvio >= 1000){
                    cout<<"No es posible agregar paquetes al envio, el peso maximo es 1000lb."<<endl;
                }else{
                    cout<<endl;
                    cout<<"Ingrese codigo de paquete a enviar:";
                    getline(cin, buscar);

                    existe = searchInventario(buscar);
                    if(existe == true){
                        existe = searchListaEnvio(buscar);
                        if(existe == false){
                            if((pesoEnvio + peso) >= 1000){
                                cout<<"El producto no puede ser agregado, ya que excede el total del peso maximo del envio (Peso maximo total 1000lb)."<<endl;
                            }else{
                                agregarEnvio(buscar);
                                cout<<"Paquete agregado exitosamente."<<endl;
                            }
                        }else{
                            cout<<"El paquete ya se encuentra agregado a la lista de envio."<<endl;
                        }
                    }else{
                        cout<<"El codigo de paquete no existe en inventario. Intentelo de nuevo."<<endl;
                    }
                }
            }
        }else{
            cout<<"Actualmente no existe inventario."<<endl;
        }
};

bool searchInventario(const string &b){
    Registro03 *buscar = new Registro03();
    buscar = inici;
    bool flag = false;

	if(inici != NULL){
		while(buscar !=NULL && flag != true){
			if(buscar->codigo == b){
				flag = true;
			}
			buscar = buscar->apuntador03;
		}
	}else{
		flag = false;
	}
    return flag;
};

bool searchListaEnvio(const string &l){
    struct listaEnvio* temp = headEnvio;
    bool flag = false;

	if(temp != NULL){
		while(temp !=NULL && flag != true){
			if(temp->producto == l){
				flag = true;
			}
			temp = temp->apuntadorEnvio;
		}
	}else{
		flag = false;
	}
    return flag;
};

void agregarEnvio(const string code){
    struct listaEnvio* temp = new listaEnvio();
    temp-> producto = code;
    temp->apuntadorEnvio = NULL;
    if(headEnvio != NULL)
        temp->apuntadorEnvio = headEnvio;
    headEnvio = temp;
};
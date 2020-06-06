#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct registro{
	int tipo;
	float monto;
	float kilometro;
    float monto_tonelada;
};

void agregarRegistro01(){
	Garita:
		ofstream archivo;
		string nombreArchivo;
		fflush(stdin);
		system("CLS");
        cout<<"Archivo default: garita.txt"<<endl;
		//cout<<"Indique nombre de archivoc: ";
		//getline(cin,nombreArchivo);
		nombreArchivo = "garita.txt";
        archivo.open(nombreArchivo.c_str(),ios::app);

		if(archivo.fail()){
			archivo.close();
			cout<<"No se pudo abrir el archivo";
			exit(1);
		}
		archivo.close();

		fflush(stdin);
		system("CLS");

        int i = 0;
        int tipo = 0;
        float monto = 0;
        float kilometro = 0;
        float monto_tonelada = 0;

        cout<<endl;
        cout<<"--------------------"<<endl;
        cout<<"  Tipo de vehiculo  "<<endl;
        cout<<"--------------------"<<endl;
        cout<<"1 - Bicicleta"<<endl;
        cout<<"2 - Motocicleta"<<endl;
        cout<<"3 - Automovil"<<endl;
        cout<<"4 - Camion"<<endl;
        cout<<"-------------------"<<endl;
        cout<<"5 - Regresar a menu principal"<<endl;
        cout<<"-------------------"<<endl;
        cout<<"6 - Salir"<<endl;
        cout<<"-------------------"<<endl;
        cout<<"Seleccione su opcion: ";
        cin>>i;

        switch(i){
            case 1:
                cout<<"El costo total es: Q10.00"<<endl;
                monto = 10.00;
                kilometro = 0;
                monto_tonelada = 0;
                system("Pause");
                break;
            case 2:
            case 3:
                cout<<"Ingrese cantidad de kilometros recorridos: "<<endl;
                cin>>kilometro;
                
                if(kilometro < 1){
                    cout<<"Ingrese una cantidad valida. Intente de nuevo."<<endl;
                    system("Pause");
                    goto Garita;
                }

                monto = kilometro * 0.50;
                monto_tonelada = 0;

                cout<<"El costo total es: Q"<<monto<<endl;    
                system("Pause");
                break;
            case 4:
                cout<<"Ingrese cantidad de kilometros recorridos: "<<endl;
                cin>>kilometro;
                
                if(kilometro < 1){
                    cout<<"Ingrese una cantidad valida. Intente de nuevo."<<endl;
                    system("Pause");
                    goto Garita;
                }

                monto = kilometro * 0.50;
                monto_tonelada = 6.00;

                cout<<"El costo por kilometros es: Q"<<monto<<endl;
                cout<<"El costo por tolenada metrica es: Q"<<monto_tonelada<<endl;
                cout<<"Total: Q"<<monto+monto_tonelada<<endl;   
                system("Pause");
                break;
            case 5:
                break;
            case 6:
                exit(1);
            default:
                system("cls");
                cout<<"No existe la opcion seleccionada, vuelva a intentar."<<endl;
                system("Pause");
                goto Garita;
                break;
        }
        tipo = i;

		archivo.open(nombreArchivo.c_str(),ios::trunc);
		if(archivo.fail()){
			archivo.close();
			cout<<"No se pudo abrir el archivo";
			exit(1);
		}
		system("CLS");

        archivo<<tipo<<'\t'
        <<monto<<'\t'
        <<kilometro<<'\t'
        <<monto_tonelada<<endl;

		archivo.close();

		cout<<"Registro agregado exitosamente."<<endl;
};

void reporte01(){
	 ifstream archivo;
	 string nombreArchivo,s, nombre;

	 fflush(stdin);
	 system("CLS");
     cout<<"Archivo default: garita.txt"<<endl;
	 //cout<<"Ingrese nombre del archivo: ";
	 //getline(cin, nombreArchivo);
     nombreArchivo = "garita.txt";
	 archivo.open(nombreArchivo.c_str(), ios::in);
	 if(archivo.fail()){
	 	cout<<"Se presento un error al intentar abrir el archivo.";
	 	exit(1);
	 }

	 int lineas = 0;
	 while(getline(archivo, s))
		lineas++;

     archivo.close();
     system("CLS");

     registro lista[lineas];

     archivo.open(nombreArchivo.c_str(), ios::in);
	 if(archivo.fail()){
	 	cout<<"Se presento un error al intentar abrir el archivo.";
	 	exit(1);
	 }

	 for(int i = 0; i < lineas; i++){
		 archivo>>lista[i].tipo
                >>lista[i].monto
                >>lista[i].kilometro
                >>lista[i].monto_tonelada;
	 }
	 archivo.close();

     float monto_bicicleta = 0;
     float monto_camion = 0;
     float monto_automovil = 0;
     float monto_moto = 0;
     
	 for(int i = 0; i < lineas; i++){
         if(lista[i].tipo == 1){
             monto_bicicleta += lista[i].monto;
         }
         if(lista[i].tipo == 2){
             monto_moto += lista[i].monto;
         }
         if(lista[i].tipo == 3){
             monto_automovil += lista[i].monto;
         }
         if(lista[i].tipo == 4){
             monto_camion += lista[i].monto + lista[i].monto_tonelada;
         }
	 }

	 system("CLS");
	 cout<<"----- Reporte -----"<<endl;
	 cout<<"Resumen de cobros. "<<endl;
	 cout<<"- Bicicleta: "<<monto_bicicleta<<endl;
     cout<<"- Motocicleta: "<<monto_moto<<endl;
     cout<<"- Automovil: "<<monto_automovil<<endl;
     cout<<"- Camion: "<<monto_camion<<endl;
	 cout<<"-------------------"<<endl;
};
#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void mp();
void ejercicio01();
void ejercicio02();
void ejercicio03();

/*void agregarRegistro01();
void agregarRegistro02();
void agregarRegistro03();

void reporte01();
void reporte02();
void reporte03();*/

int main()
{
    mp();
}

void mp(){
	MenuPrincipal:
			int i;
			system("CLS");
			cout<<"-------------------"<<endl;
			cout<<"  Menu  Principal  "<<endl;
            cout<<" Examen Final P1 SA"<<endl;
			cout<<"-------------------"<<endl;
			cout<<"1 - Ejercicio 01"<<endl;
			cout<<"2 - Ejercicio 02"<<endl;
			cout<<"3 - Ejercicio 03"<<endl;
			cout<<"-------------------"<<endl;
			cout<<"4 - Salir"<<endl;
			cout<<"-------------------"<<endl;
			cout<<"Seleccione su opcion: ";
			cin>>i;

			switch(i){
				case 1:
					{ejercicio01();}
					system("cls");
					goto MenuPrincipal;
					break;
				case 2:
					{ejercicio02();}
					system("cls");
					goto MenuPrincipal;
					break;
				case 3:
					{ejercicio03();}
					system("cls");
					goto MenuPrincipal;
					break;
				case 4:
					break;
				default:
					system("cls");
					cout<<"No existe la opcion seleccionada, vuelva a intentar. "<<endl;
					system("Pause");
					goto MenuPrincipal;
					break;
			}
}

void ejercicio01(){
	MenuEjercicio01:
			char i;
			system("CLS");
			cout<<"--------------------------"<<endl;
			cout<<"------ Menu  Garita ------"<<endl;
			cout<<"--------------------------"<<endl;
			cout<<"1 - Ingresar registro"<<endl;
			cout<<"2 - Generar reporte"<<endl;
			cout<<"-------------------"<<endl;
			cout<<"3 - Regresar a menu principal"<<endl;
			cout<<"-------------------"<<endl;
			cout<<"F - Salir"<<endl;
			cout<<"-------------------"<<endl;
			cout<<"Seleccione su opcion: ";
			cin>>i;

			switch(i){
				case '1':
					//{agregarRegistro01();}
					system("Pause");
					system("cls");
					goto MenuEjercicio01;
					break;
				case '2':
					//{reporte01();}
					system("Pause");
					system("cls");
					goto MenuEjercicio01;
					break;
                case '3':
                    break;
				case 'F':
					exit(1);
                case 'f':
                    exit(1);
				default:
					system("cls");
					cout<<"No existe la opcion seleccionada, vuelva a intentar."<<endl;
					system("Pause");
					goto MenuEjercicio01;
					break;
			}
}

void ejercicio02(){
	MenuEjercicio02:
			int i;
			system("CLS");
			cout<<"-------------------------"<<endl;
			cout<<"Menu Inventario en Bodega"<<endl;
            cout<<"------- Libreria --------"<<endl;
			cout<<"-------------------------"<<endl;
			cout<<"1 - Cargar inventario"<<endl;
			cout<<"2 - Descargar inventario"<<endl;
            cout<<"3 - Reporte inventario actual"<<endl;
			cout<<"-------------------------"<<endl;
			cout<<"4 - Regresar a menu principal"<<endl;
			cout<<"--------------------"<<endl;
			cout<<"5 - Salir"<<endl;
			cout<<"--------------------"<<endl;
			cout<<"Seleccione su opcion: ";
			cin>>i;

			switch(i){
				case 1:
					//{agregarRegistro02();}
					system("Pause");
					system("cls");
					goto MenuEjercicio02;
					break;
				case 2:
					//{reporte02();}
					system("Pause");
					system("cls");
					goto MenuEjercicio02;
					break;
                case 3:
					//{reporte02();}
					system("Pause");
					system("cls");
					goto MenuEjercicio02;
					break;    
				case 4:
					break;
				case 5:
					exit(1);
				default:
					system("cls");
					cout<<"No existe la opcion seleccionada, vuelva a intentar. "<<endl;
					system("Pause");
					goto MenuEjercicio02;
					break;
			}
}

void ejercicio03(){
	MenuEjercicio03:
			int i;
			system("CLS");
			cout<<"----------------------------"<<endl;
			cout<<"----- Menu Encomiendas -----"<<endl;
			cout<<"----------------------------"<<endl;
			cout<<"1 - Agregar entrega"<<endl;
            cout<<"2 - Descargar entrega"<<endl;
			cout<<"3 - Generar reporte"<<endl;
			cout<<"----------------------------"<<endl;
			cout<<"4 - Regresar a menu principal"<<endl;
			cout<<"----------------------------"<<endl;
			cout<<"5 - Salir"<<endl;
			cout<<"----------------------------"<<endl;
			cout<<"Seleccione su opcion: ";
			cin>>i;

			switch(i){
				case 1:
					//{agregarRegistro03();}
					system("Pause");
					system("cls");
					goto MenuEjercicio03;
					break;
				case 2:
					//{reporte03();}
					system("Pause");
					system("cls");
					goto MenuEjercicio03;
					break;
                case 3:
					//{reporte03();}
					system("Pause");
					system("cls");
					goto MenuEjercicio03;
					break;
				case 4:
					break;
				case 5:
					exit(1);
				default:
					system("cls");
					cout<<"No existe la opcion seleccionada, vuelva a intentar. "<<endl;
					system("Pause");
					goto MenuEjercicio03;
					break;
			}
}
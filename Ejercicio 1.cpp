/*Ejercicio # 1:
Se dispone de un archivo STOCK correspondiente a la existencia de artículos de un almacén y se desea señalar aquellos artículos cuyo nivel está por debajo del mínimo y que visualicen un mensaje "hacer pedido". 
cada artículo contiene un registro con los siguientes campos: 

número del código del artículo, 
nivel mínimo, 
nivel actual, 
proveedor, 
precio.

El programa debe tener un menu que se especifiquen las siguientes opciones:
1) Agregar productos (Grabar datos a un archivo)
2) Leer archivo y mostrar en pantalla que productos tiene nivel minimo. 

*if (nivel actual==nivel mínimo)
    cout<<"Nivel Minimo";*/
    
    
#include <iostream>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <regex>


using namespace std;

int op=0,Nivelmin=10;
struct{
	int codigopro;
	int Nivelac;
	float Precio;
	string Prove;	
}produ; 

char oppro;
void menu();
void agregar();
void Leer();

int main()
{
	menu();	
	system("pause");
}


void menu()
{
do{
	cout<<"Menu "<<endl;
	cout<<"1. Agregar Productos "<<endl;
	cout<<"2. Listado de productos "<<endl;
	cout<<"3. Salida  "<<endl;
	cin>>op;
	switch(op){
	case(1):
	{
		system("cls");
		agregar();
		break;
	}
	case(2):
	{
		system("cls");
		Leer();
		break;
	}
	case(3):
	{
		break;
	}
}

}while (op>=4);
}

void agregar()
{
do{
	cout<<"Codigo de producto"<<endl;
	cin>>produ.codigopro; 
	cout<<"Cantidad de producto"<<endl;
	cin>>produ.Nivelac; 
	cout<<"Proveedor"<<endl;
	fflush(stdin);
	getline(cin,produ.Prove); 
	const auto obj = regex{ " " };
    const auto repl = string{ "_" };
    const auto valor = produ.Prove;
	cout<<"Precio"<<endl;
	cin>>produ.Precio;
	
	
	  
	ofstream archivo;
	try {
		archivo.open("Almacen .txt",ios::app);
		archivo<<produ.codigopro<<" "<<produ.Nivelac<<" "<<produ.Precio<<" "<<regex_replace(valor, obj, repl)<<" "<<endl;
		archivo.close();
	}
	catch(exception X){
		cout<<"Error en la manipulacion del archivo"<<endl;
	}
	cout<<"¿Quieres agregar otro Producto? s/n"<<endl;
	cin>>oppro;	
}while(oppro=='s');	
system("cls");
menu();
}

void Leer()
{
	ifstream archivoab;
		
	try{	
		archivoab.open("Almacen .txt",ios::in);
		
		while (archivoab >>produ.codigopro >> produ.Nivelac >>produ.Precio>>produ.Prove){	
			const auto obj = regex{ "_" };
    		const auto repl = string{ " " };
    		const auto valor = produ.Prove;
				if (Nivelmin>=produ.Nivelac){
				cout<<produ.codigopro<<"\t"<<produ.Nivelac<<"\t"<<regex_replace(valor, obj, repl)<<"\t"<<produ.Precio<<"\t";
				system("color C");
				cout<<"hacer Pedido"<<endl;
				}
		}		
		archivoab.close();
		
	}
	catch (exception X){		
			cout<<"Error para abrir archivo"<<endl;			
			exit(1);
	}		
	system("pause");
	system("cls");
	system("color 7");
	menu();
}



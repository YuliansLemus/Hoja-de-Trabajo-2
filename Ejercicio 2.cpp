/* Ejercicio # 2:
El director de un colegio desea realizar un programa que procese un archivo de registros correspondiente a los diferentes alumnos del centro a fin de obtener los siguientes datos:
"	Nota más alta y número de identificación del alumno correspondiente.
"	Nota media del colegio.
Datos de Estudiantes:
"	Identificación
"	Nombre
"	Nota */

#include <iostream>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <regex>


using namespace std;

int op=0;
struct{
	int Identi;
	string Nombre;
	float Nota;	
}Alum; 

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
	cout<<"1. Agregar Alumnos "<<endl;
	cout<<"2. Listado de alumnos "<<endl;
	cout<<"3. Salida  "<<endl;
	cin>>op;
	switch(op){
	case(1):
	{
		system("cls");
		agregar();
		menu();
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
	cout<<"Codigo del alumno"<<endl;
	cin>>Alum.Identi; 
	cout<<"Nombre del Alumno"<<endl;
	fflush(stdin);
	getline(cin,Alum.Nombre); 
	const auto obj = regex{ " " };
    const auto repl = string{ "_" };
    const auto valor = Alum.Nombre;
	cout<<"Nota"<<endl;
	cin>>Alum.Nota;
	
	ofstream archivo;
	try {
		archivo.open("Notas.txt",ios::app);
		archivo<<Alum.Identi<<" "<<regex_replace(valor, obj, repl)<<" "<<Alum.Nota<<endl;
		archivo.close();
	}
	catch(exception X){
		cout<<"Error en la manipulacion del archivo"<<endl;
	}	
	system("cls");
}

void Leer()
{
	ifstream archivoab;
	int cuenta,mayor;
	try{	
		archivoab.open("Notas.txt",ios::in);
		
		while (archivoab >>Alum.Identi>>Alum.Nombre>>Alum.Nota){	
			const auto obj = regex{ "_" };
    		const auto repl = string{ " " };
    		const auto valor = Alum.Nombre;
    		
				cout<<Alum.Identi<<"\t"<<regex_replace(valor, obj, repl)<<"\t"<<Alum.Nota<<endl;
				cuenta++;
				}		
		archivoab.close();
		for(int i=0;i<cuenta;i++){
			if(i==0){
				mayor=Alum.Nota;
			}
			else{
				if(Alum.Nota>mayor) mayor=Alum.Nota;
			}
		}
		const auto obj = regex{ "_" };
    		const auto repl = string{ " " };
    		const auto valor = Alum.Nombre;
    		
		cout<<endl<<endl<<"La Nota Mayor es "<<regex_replace(valor, obj, repl)<<" con "<<mayor<<" Puntos"<<endl<<endl;
	}
	catch (exception X){		
			cout<<"Error para abrir archivo"<<endl;			
			exit(1);
	}		
	system("pause");
	system("cls");
	menu();
}


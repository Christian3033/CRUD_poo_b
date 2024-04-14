#include <iostream>

using namespace std;
//anbito global
const char *nombre_archivo = "archivo.dat";
struct Estudiante{
	
	int codigo;
	char nombres[50];
	char apellidos[50];
	int telefono;
	
};

void crear(); 
void leer();
void Actualizar();
void Borrar();

int main(){
	
	//ambito local
	crear();
	leer();
	Actualizar();
	Borrar();
	
	system("pause");
	return 0;
}
void leer(){
	
	system("cls");
	FILE *archivo = fopen(nombre_archivo, "rb");
	if (!archivo){
		archivo = fopen(nombre_archivo, "w+b");
	}
	
	Estudiante estudiante;
	int id = 0;
	fread(&estudiante, sizeof(Estudiante),1,archivo);
	do{
		cout<<id<<", "<<estudiante.codigo<<", "<<estudiante.nombres<<", "<<estudiante.apellidos<<", "<<estudiante.telefono<<endl;
		fread(&estudiante, sizeof(Estudiante),1,archivo);
		id+=1;
	}while(feof(archivo)==0);
	
	fclose(archivo);
	
}

void crear(){
	
	FILE* archivo = fopen(nombre_archivo,"a+b");
	char res;
	Estudiante estudiante;
	
	do{
		fflush(stdin);
		cout<<"Ingrese codigo: ";
		cin>>estudiante.codigo;
		cin.ignore();
		cout<<"Ingrese nombres: ";
		cin.getline(estudiante.nombres, 50);
		cout<<"Ingrese apellidos: ";
		cin.getline(estudiante.apellidos, 50);
		cout<<"Ingrese numero de telefono: ";
		cin>>estudiante.telefono;
		fwrite(&estudiante, sizeof(Estudiante),1,archivo); 
		cout<<"Desea ingresar otro estudiante (s/n): ";
		cin>>res;
		
	}while(res=='s' || res == 'S');
	fclose(archivo);
	leer();
	
}
void Actualizar(){
	
		FILE* archivo = fopen(nombre_archivo,"r+b");
	char res;
	Estudiante estudiante;
	int id=0;
	cout<<"Ingrese el ID que desea modificar: ";
	cin>>id;
	fseek(archivo,id * sizeof(Estudiante),SEEK_SET);

	
	
		cout<<"Ingrese codigo: ";
		cin>>estudiante.codigo;
		cin.ignore();
		cout<<"Ingrese nombres: ";
		cin.getline(estudiante.nombres, 50);
		cout<<"Ingrese apellidos: ";
		cin.getline(estudiante.apellidos, 50);
		cout<<"Ingrese numero de telefono: ";
		cin>>estudiante.telefono;
		fwrite(&estudiante, sizeof(Estudiante),1,archivo); 
	

	fclose(archivo);
	leer();
}
void Borrar(){
	const char *nombre_archivo_temp = "archivo_temp.dat";
	FILE* archivo = fopen(nombre_archivo, "rb");
	FILE* archivo_temp = fopen(nombre_archivo_temp, "w+b");
	Estudiante estudiante;
	int id = 0, id_n = 0; 
	
	cout<<"Ingrese el Id a eliminar: ";
	cin>>id;
	while(fread(&estudiante, sizeof(Estudiante),1,archivo)){
	
		if  (id_n != id){
			fwrite(&estudiante, sizeof(Estudiante),1,archivo_temp);
		}
		id_n++;	
		
	}
	fclose(archivo);
	fclose(archivo_temp); 
	
	archivo = fopen(nombre_archivo, "wb");
	archivo_temp = fopen(nombre_archivo_temp, "rb");
	
while(fread(&estudiante, sizeof(Estudiante),1,archivo)){
	fwrite(&estudiante, sizeof(Estudiante),1,archivo);
	}
		fclose(archivo);
	fclose(archivo_temp); 
	leer();
}






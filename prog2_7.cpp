/*Programa que guarde los datos de un alumno por medio de una estructura, los datos son:
	-nombre
	-promedio
	-faltas
	
	Programa en lenguaje c que guarda los datos de un alumnno con el el uso de estructuras, uso de cadenas, uso de la funciones
	de la libreria string, y validacon de datos. 
	
	Autor: Oscar Eduardo Fletes Ixta
	Escuela: UVM Campus Lomas Verdes
	Materia: Programcion Estructurada
	CICLO: 01/2022

	Programa en lenguaje c que muestra el uso de:
		* Declaracion de variables 
		* Variables del tipo char*mensaje, char, floata, int
		* Operaciones aritmeticas  
		* Uso de estrcturas
		* Uso del fgets para leer cadenas de caracteres
		* fflush
		* Uso de condiciones
		* uso de la libreria String.h
		* Funciones para cadenas de caractres
		* Funciones con parametros
		* Prototipos de funciones
		* Validacion de datos  
		* Ciclo do-while
		* printf para monstrar los valroes de las variables

	Objetivo:
	Mostrar el uso de variables char*mensaje, char, float y int, condiciones, uso de la libreria string, 
	funciones para cadenas de caracteres, uso del fgets para leer cadenas de caracteres, uso del fflush, 
	de funciones con parametros, validacion de datos, prototipos de funciones realizar operaciones aritmeticas e imprimirla.

	Breve descripcion:

	El programa  pide como entrada 3 variable del tipo char, float, int(Nombre, promedio, faltas)
	El programa guarda los datos de un alumno por medio de una estructura, lo cuales son, nombre, promedio y faltas 
	*/
	
#include<stdio.h>//libreria para el cuerpo de c
#include<string.h>//libreria para uso de funciones para cadenas de caarcteres

//declaraciones globales
struct alumno{//uso de estrcturas 
	char nombre[30];//variable de cadenas
	float promedio;//variable con decimales 
	int faltas;//variables de enteros  
};

//Prototipos
void leers(char *mensaje, char s[], int n);//Funcion con parametros 
float leerF(char *mensaje, float inferior, float superior);//Funcion con parametros
int leerd(char *mensaje, int inferior, int superior);//Funcion con parametros
//principal 
int main(){
	struct alumno a1, a2; //llama a la estrcutura para dos alumnos 
	
	leers("Introducel el nombre: ",a1.nombre,30);//Validacion de caracteres maximo 30 caracteres
	
	a1.promedio=leerF("Introduce el promedio: ",0,10);//Validacion del promedio 0-10
	a1.faltas=leerd("Introduce las faltas: ",0,32);//Validacion de las faltas 0-32
	a2=a1;//la estrcutura del alumno 2 es igual que la del alumno 1
	printf("Datos del alumno:\n");//imprime mensaje
	printf("Nombre: %s \n",a2.nombre);//imprime el nombre del alumno 2
	printf("Promedio: %.1f \n",a2.promedio);//imprime el promedio del alumno 2
	printf("Faltas: %d\n",a2.faltas);//imprime las faltas del alumno 2
	
	
	return 0;
}

void leers(char *mensaje, char s[], int n){//funcion para validar cadenas(parametros)
	printf(mensaje);//imprime mensaje
	fgets(s,n,stdin);//lee la cadena
	fflush(stdin);//borra lo que se inserto anteriormente del teclado
	if(s[strlen(s)-1] =='\n'){//condicion para eliminar el enter de la cadena
		s[strlen(s)-1]=0;
	}
}

float leerF(char *mensaje, float inferior, float superior){//funcion validar funcones(parametros)
	float valor;//Variables con decimal
	do{//ciclo do-while
		printf(mensaje);//imprime mensaje
		scanf("%f",&valor);//lee el numero insertado por el teclado
		if(valor<inferior || valor>superior){//condicon que si valor es menor que inferior o valor mayor que superior
			printf("Dato invalido!!! Debe estar entre (%.2f-%.2f). Vuelva a introducirlo: \n",inferior,superior);//imprime mensaje
			//inferior,superior lee los valores insertados en teclado (%.2f-%.2f)
		}
	}while(valor<inferior || valor>superior);//do-while termina con la misma condicon que if
	return valor;
}

int leerd(char *mensaje, int inferior, int superior){//funcion validar enteros(parametros)
	int valor;//Variables enteras
	do{//ciclo do-while
		printf(mensaje);//imprime mensaje
		scanf("%d",&valor);//lee el numero insertado por el teclado
		if(valor<inferior || valor>superior){//condicon que si valor es menor que inferior o valor mayor que superior
			printf("Dato invalido!!! Debe estar entre (%d-%d). Vuelva a introducirlo: \n",inferior,superior);//imprime mensaje
			//inferior,superior lee los valores insertados en teclado (%d-%d)
		}
	}while(valor<inferior || valor>superior);//do-while termina con la misma condicon que if
	return valor;
}

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include "arbol.h"
#include "funciones.h"
#define MAX 100

int main()
{
	Arbol a[MAX];
	int lineas = 0;
	
	for (int i = 0; i<MAX; i++)
	{
		a[i]=nuevoArbol();
	}
	
	inicializarArbol(a);
	
	arbolArchivo(a, "Arboles.txt"); //Abro el archivo original y paso los datos a la estructura.
	lineas = contarLineasStruct(a);
		
	FILE *archNuevo;
	archNuevo = fopen("Arboles_nuevo.txt", "w");	
	for (int i = 0; i<lineas; i++)
	{
		agregarArrayArbol(a[i]);
	}	
	fclose(archNuevo);	//Crea un nuevo archivo con los datos originales*/
	
		
	agregarArbol("Laurel", 210, 2.55);
	agregarArbol("Secuoya Caucho", 150, 1.99);
	agregarArbol("Gikgo biloba", 90, 1.88); //Agrego por parametro los arboles pedidos
	
	arbolArchivo(a, "Arboles_nuevo.txt");
	
	lineas = contarLineasStruct(a);	
	
	for(int i = 0; i<lineas; i++)
	{
		mostrarArbol(a[i]);	
	}		
	//---------------------------------------
	printf("\nPara seguir, presione cualquier tecla.");
	getchar();
	
	modificarArbol("Laurel", a, lineas);
	getchar();
	
	system("CLS");
	
	eliminarArbol("Cocotero", a, lineas);
	lineas = contarLineasStruct(a);
	
	eliminarArbol("Falsa Acacia", a, lineas);
	lineas = contarLineasStruct(a);	
	
	ArbolToTxt(a, lineas);
	
	for(int i = 0; i<lineas; i++)
	{
		mostrarArbol(a[i]);	
	}				
}

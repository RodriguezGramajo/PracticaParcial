#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include "arbol.h"
#include "funciones.h"
#define MAX 100

struct Arboles
{
    char especie[MAX];
    int edad;
    float altura;
};

void ejecucionPrograma()
{
	Arbol a[MAX];
	int lineas = 0;
	
	for (int i = 0; i<MAX; i++)
	{
		a[i]=nuevoArbol();
	}
	
	arbolArchivo(a, "Arboles.txt"); //Abro el archivo original y paso los datos a la estructura.
	
	lineas = contarLineas("Arboles.txt");	
	FILE *archNuevo;
	archNuevo = fopen("Arboles_nuevo.txt", "w");	
	for (int i = 0; i<lineas; i++)
	{
		agregarArrayArbol(a[i]);
	}	
	fclose(archNuevo);	//Crea un nuevo archivo con los datos originales
		
	agregarArbol("Laurel", 210, 2.55);
	agregarArbol("Secuoya Caucho", 150, 1.99);
	agregarArbol("Gikgo biloba", 90, 1.88); //Agrego por parametro los arboles pedidos
		
	arbolArchivo(a, "Arboles_nuevo.txt");	
	lineas = contarLineas("Arboles_nuevo.txt");
	
	for (int i = 0; i<lineas-1; i++)
	{
		mostrarArbol(a[i]);
	}
	
	
	for (int i = 0; i<MAX; i++)
	{
		destruirArbol(a[i]);
	}	
}

void arbolArchivo(Arbol a[], char *nombreArchivo)
{
	FILE *arch;
	arch = fopen(nombreArchivo, "r");	
	char buff[MAX] = " ";
	int i = 0;
	
	if(arch == NULL)
	{
		printf("Error al abrir archivo");
	}
	else
	{
		while (!feof(arch))
		{
			fgets(buff, MAX, arch);
			a[i] = 	archToArbol(buff, MAX);
			i++;										
		}
	}
	fclose(arch);		
}

void agregarArbol(char especie[], int edad, float altura)
{
	FILE *arch;
	arch = fopen("Arboles_nuevo.txt", "a");
	fprintf(arch, "%s+%d+%f\n", especie, edad, altura);
	fclose(arch);
}

void agregarArrayArbol(Arbol a)
{
	FILE *arch;
	arch = fopen("Arboles_nuevo.txt", "a");
	fprintf(arch, "%s+%d+%f\n", a->especie, a->edad, a->altura);
	fclose(arch);
}

Arbol archToArbol(char c[], int t)
{
	Arbol a = nuevoArbol();
	int i, posMas1, posMas2;
	char auxEspecie[100] = " ", auxEdad[1000] = " ", auxAltura[100] = " ";
	
	posMas1 = busquedaSecuencial(0, c,'+', t);
	posMas2 = busquedaSecuencial(posMas1+1, c, '+', t);
	
	 for (i=0;i<posMas1;i++)
    {
       auxEspecie[i] = c[i];
    }
    
    for (i=posMas1+1;i<posMas2;i++)
    {
        auxEdad[i-posMas1-1] = c[i];
    }
    
    for(i=posMas2+1; i<t;i++)
	{
        if(c[i]=='\n')
		{
            break;
        }
		else
		{
            auxAltura[i-posMas2-1] = c[i];
        }
    }
    
    strcpy(a->especie, auxEspecie);
    a->edad = atoi(auxEdad);
    a->altura = atof(auxAltura);
    
    return a;
}

void mostrarArbol(Arbol a)
{
	printf("\nEspecie: %s, Edad: %d, Altura: %.2f\n", a->especie, a->edad, a->altura);
}


Arbol nuevoArbol(){
        Arbol a = malloc(sizeof(struct Arboles));
        return a;
}

void destruirArbol(Arbol a)
{
	free(a);
}

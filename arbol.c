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

int contarLineasStruct(Arbol a[])
{
	int flag, i = 0;
	while(flag != 1)
	{	
		i++;
		if (a[i]->edad == -1)
		{
			flag = 1;
		}
				
	}
	return i;	
}
void inicializarArbol(Arbol a[])
{
	for(int i = 0; i<MAX; i++)
	{
		strcpy(a[i]->especie,"-1");
		setEdad(a, i, "-1");
		setAltura(a, i, "-1");
	}
}

void arbolArchivo(Arbol a[], char *nombreArchivo)
{
	FILE *arch;
	arch = fopen(nombreArchivo, "r");	
	char buff[MAX];
	int i = 0;
	
	if(arch == NULL)
	{
		printf("Error al abrir archivo");
	}
	else
	{
		while (fgets(buff, MAX, arch))
		{
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

void ArbolToTxt(Arbol a[], int t)
{
	FILE *arch;
	arch = fopen("Arboles_nuevo.txt", "w+");
	
	for (int i = 0; i<t; i++)
	{
		fprintf(arch, "%s+%d+%f\n", a[i]->especie, a[i]->edad, a[i]->altura);
	}
	
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

int posicionBusqueda(char busqueda[], Arbol a[], int t)
{
	int posicionBuscado = -1;
	for(int i = 0; i<t; i++)
	{
		if(strcmp(busqueda, a[i]->especie) == 0)
		{
			posicionBuscado = i;
		}		
	}
	return posicionBuscado;
}

void modificarArbol(char nombreEspecie[], Arbol a[], int t)
{
	system("CLS");
	printf("Modificar %s:", nombreEspecie);
	
	int posicionBuscado = -1;
	int edadOriginal = 0;
	float alturaOriginal = 0;
	char nuevaEdad[MAX], nuevaAltura[MAX];
	
	posicionBuscado = posicionBusqueda(nombreEspecie, a, t);

	edadOriginal = getEdad(a, posicionBuscado);
	alturaOriginal = getAltura(a, posicionBuscado);
	printf("Datos originales: EDAD %d ALTURA %.2f\n", edadOriginal, alturaOriginal);
	
	printf("Nueva Edad: ");
	fflush(stdin);
	gets(nuevaEdad);
	setEdad(a, posicionBuscado, nuevaEdad);	
	
	printf("Nueva Altura: ");
	fflush(stdin);
	gets(nuevaAltura);
	setAltura(a, posicionBuscado, nuevaAltura);
	
	mostrarArbol(a[posicionBuscado]);
		
}

void eliminarArbol(char nombreEspecie[], Arbol a[], int t)
{	
	int posicionBuscado = -1;
	posicionBuscado = posicionBusqueda(nombreEspecie, a, t);
	
	for(int i = posicionBuscado; i<=t; i++)
	{
		a[i] = a[i+1];
	}			
}

float getAltura(Arbol a[], int pos)
{
	return a[pos]->altura;
}
int getEdad(Arbol a[], int pos)
{
	return a[pos]->edad;
}
void setAltura(Arbol a[], int pos, char nuevaAlt[])
{
	float altura = 0;
	altura = atof(nuevaAlt);	
	a[pos]->altura = altura;
}
void setEdad(Arbol a[], int pos, char nuevaEdad[])
{
	int edad = 0;
	edad = atoi(nuevaEdad);	
	a[pos]->edad = edad;
}

void mostrarArbol(Arbol a)
{
	printf("Especie: %s, Edad: %d, Altura: %.2f\n", a->especie, a->edad, a->altura);	
}



Arbol nuevoArbol(){
        Arbol a = malloc(sizeof(struct Arboles));
        return a;
}

void destruirArbol(Arbol a)
{
	free(a);
}

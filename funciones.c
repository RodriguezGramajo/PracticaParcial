#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include "arbol.h"
#include "funciones.h"

int busquedaSecuencial (int o,char v[], char c, int t){
    for(int i=o; i<t; i++){
        if(v[i]==c){
            return i;
        }
    }
    return -1;
}

int contarLineas(char *nombreArchivo)
{
	FILE *arch;
	arch = fopen(nombreArchivo, "r");
	int i, c = 0;
	
	if(arch == NULL)
	{
		printf("Error al abrir archivo");
	}
	else
	{
		while (!feof(arch))
		{
			c = fgetc(arch);		
			if(c == '\n')
  			{
    			i++;
  			}										
		}
	}
	fclose(arch);
	return i+1;
}

#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

struct Arboles;

typedef struct Arboles *Arbol;

void ejecucionPrograma();

void arbolArchivo(Arbol a[], char *nombreArchivo);



void agregarArbol(char especie[], int edad, float altura);

void agregarArrayArbol(Arbol a);

Arbol archToArbol(char c[], int t);

void mostrarArbol(Arbol a);

//void modificarArbol("Laurel"); //Modifica los datos por teclado, el nombre no se modifica

Arbol nuevoArbol();

void destruirArbol(Arbol a);
#endif

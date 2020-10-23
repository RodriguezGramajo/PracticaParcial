#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

struct Arboles;

typedef struct Arboles *Arbol;

int contarLineasStruct(Arbol a[]);

void inicializarArbol(Arbol a[]);

void arbolArchivo(Arbol a[], char *nombreArchivo);

void agregarArbol(char especie[], int edad, float altura);

void agregarArrayArbol(Arbol a);

void ArbolToTxt(Arbol a[], int t);

Arbol archToArbol(char c[], int t);

void mostrarArbol(Arbol a);

int posicionBusqueda(char busqueda[], Arbol a[], int t);

void modificarArbol(char nombreEspecie[], Arbol a[], int t);

void eliminarArbol(char nombreEspecie[], Arbol a[], int t);

float getAltura(Arbol a[], int pos);

int getEdad(Arbol a[], int pos);

void setAltura(Arbol a[], int pos, char nuevaAlt[]);

void setEdad(Arbol a[], int pos, char nuevaEdad[]); 

Arbol nuevoArbol();

void destruirArbol(Arbol a);
#endif

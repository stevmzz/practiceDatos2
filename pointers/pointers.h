#ifndef POINTERS_H
#define POINTERS_H
#include <string>



struct Estudiante {
    std::string nombre;
    std::string id;
    float calificacion;
};



struct Nodo {
    int dato;
    Nodo* next;
};



struct NodoArbol {
    int valor;
    NodoArbol* izquierdo;
    NodoArbol* derecho;
};



class Pointers {
public:
    Pointers();
    void intercambiar(int* a, int* b); // ejercicio1
    int* buscar(int* arr, int tamaño, int valor); // ejercicio2
    int* crearArrayDinamico(int tamaño); // ejercicio3
    void liberarMemoria(int* array);
    int** crearMatriz(int filas, int columnas); // ejercicio4
    void llenarMatriz(int** matriz, int filas, int columnas);
    void mostrarMatriz(int** matriz, int filas, int columnas);
    void liberarMatriz(int** matriz, int filas);

    Estudiante* crearEstudiantes(int n); // ejercicio 5
    void ingresarDatos(Estudiante* estudiantes, int n);
    void mostrarEstudiantes(Estudiante* estudiantes, int n);
    Estudiante* mejorEstudiante(Estudiante* estudiantes, int n);

    void insertarAlInicio(Nodo** cabeza, int valor); // ejercicio 6
    void insertarAlFinal(Nodo** cabeza, int valor);
    void eliminarNodo(Nodo** cabeza, int valor);
    void mostrarLista(Nodo* cabeza);
    void liberarLista(Nodo** cabeza);

    void push(Nodo** tope, int valor); // ejercicio 7
    int pop(Nodo** tope);
    int peek(Nodo* tope);
    bool estaVacia(Nodo* tope);

    void encolar(Nodo** frente, Nodo** final, int valor); // ejercicio 8
    int desencolar(Nodo** frente, Nodo** final);
    int consultarFrente(Nodo* frente);
    bool estaVaciaCola(Nodo* frente);

    NodoArbol* crearNodo(int valor); // ejercicio 9
    NodoArbol* insertarNodo(NodoArbol* raiz, int valor);
    NodoArbol* buscarNodo(NodoArbol* raiz, int valor);
    void inOrden(NodoArbol* raiz);
    void liberarArbol(NodoArbol* raiz);

    int duplicar(int n); // ejercicio 10
    int triplicar(int n);
    int alCuadrado(int n);
    void aplicarOperacion(int* arr, int tamano, int (Pointers::*operacion)(int));
    void mostrarArray(int* arr, int tamano);
};

#endif

#include <iostream>
#include "../pointers//pointers.h"
#include <cstdlib>
#include <ctime>

Pointers::Pointers() {}

// ejercicio 1
void Pointers::intercambiar(int* a, int* b) {
    int temporal = *a;
    *a = *b;
    *b = temporal;
}



// ejercicio 2
int* Pointers::buscar(int* arr, int tamaño, int valor) {
    for (int i = 0; i < tamaño; i++) {
        if (*(arr + i) == valor) {
            return arr + i;
        }
    }
    return nullptr;
}



// ejercicio 3
int* Pointers::crearArrayDinamico(int tamaño) {
    int* array = new int[tamaño];
    srand(time(NULL));
    for (int i = 0; i < tamaño; i++) {
        array[i] = rand() % 100 + 1;
    }
    return array;
}
void Pointers::liberarMemoria(int* array) {
    delete[] array;
}



// ejercicio 4
int** Pointers::crearMatriz(int filas, int columnas) {
    int** matriz = new int*[filas];
    for (int i = 0; i < filas; i++) {
        matriz[i] = new int[columnas];
    }
    return matriz;
}
void Pointers::llenarMatriz(int** matriz, int filas, int columnas) {
    srand(time(NULL));
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            matriz[i][j] = rand() % 100 + 1;
        }
    }
}
void Pointers::mostrarMatriz(int** matriz, int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            std::cout << matriz[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}
void Pointers::liberarMatriz(int **matriz, int filas) {
    for (int i = 0; i < filas; i++) {
        delete[] matriz[i];
    }
    delete[] matriz;
}



// ejercicio 5
Estudiante* Pointers::crearEstudiantes(int n) {
    return new Estudiante[n];
}
void Pointers::ingresarDatos(Estudiante* estudiantes, int n) {
    std::cin.ignore();
    for (int i = 0; i < n; i++) {
        std::cout << "\nIngrese datos del estudiante " << (i + 1) << ":\n";
        std::cout << "Nombre: ";
        std::getline(std::cin, estudiantes[i].nombre);
        std::cout << "ID: ";
        std::getline(std::cin, estudiantes[i].id);
        std::cout << "Calificacion: ";
        std::cin >> estudiantes[i].calificacion;
        std::cin.ignore();
    }
}
void Pointers::mostrarEstudiantes(Estudiante* estudiantes, int n) {
    for (int i = 0; i < n; i++) {
        std::cout << "Estudiante " << (i + 1) << ":" << std::endl;
        std::cout << "Nombre: " << estudiantes[i].nombre << std::endl;
        std::cout << "ID: " << estudiantes[i].id << std::endl;
        std::cout << "Calificacion: " << estudiantes[i].calificacion << std::endl;
        std::cout << "===============" << std::endl;
    }
}
Estudiante* Pointers::mejorEstudiante(Estudiante* estudiantes, int n) {
    float mejorCalificacion = estudiantes[0].calificacion;
    int indiceMejor = 0;
    for (int i = 0; i < n; i++) {
        if (estudiantes[i].calificacion > mejorCalificacion) {
            mejorCalificacion = estudiantes[i].calificacion;
            indiceMejor = i;
        }
    }
    return &estudiantes[indiceMejor];
}



// ejercicio 6
void Pointers::insertarAlInicio(Nodo** cabeza, int valor) {
    Nodo* nuevoNodito = new Nodo;
    nuevoNodito -> dato = valor;
    nuevoNodito -> next = *cabeza;
    *cabeza = nuevoNodito;
}
void Pointers::insertarAlFinal(Nodo** cabeza, int valor) {
    Nodo* nuevoNodito = new Nodo;
    nuevoNodito -> dato = valor;
    nuevoNodito -> next = nullptr;
    if (*cabeza == nullptr) {
        *cabeza = nuevoNodito;
        return;
    }
    Nodo* aux = *cabeza;
    while (aux -> next != nullptr) {
        aux = aux -> next;
    }
    aux -> next = nuevoNodito;
}
void Pointers::eliminarNodo(Nodo** cabeza, int valor) {
    if (*cabeza == nullptr) {
        return;
    }
    if ((*cabeza) -> dato == valor) {
        Nodo* aux = *cabeza;
        *cabeza = (*cabeza) -> next;
        delete aux;
        return;
    }
    Nodo* actual = *cabeza;
    Nodo* anterior = nullptr;
    while (actual != nullptr && actual -> dato != valor) {
        anterior = actual;
        actual = actual -> next;
    }
    if (actual == nullptr) {
        return;
    }
    anterior -> next = actual -> next;
    delete actual;
}
void Pointers::mostrarLista(Nodo* cabeza) {
    Nodo* aux = cabeza;
    while (aux != nullptr) {
        std::cout << aux -> dato;
        aux = aux -> next;
        if (aux != nullptr) {
            std::cout << " -> ";
        }
    }
    std::cout << " -> NULL" << std::endl;
}
void Pointers::liberarLista(Nodo** cabeza) {
    Nodo* actual = *cabeza;
    Nodo* siguiente = nullptr;
    while (actual != nullptr) {
        siguiente = actual -> next;
        delete actual;
        actual = siguiente;
    }
    *cabeza = nullptr;
}



// ejercicio 7
void Pointers::push(Nodo** tope, int valor) {
    Nodo* nuevoNodito = new Nodo;
    nuevoNodito -> dato = valor;
    nuevoNodito -> next = *tope;
    *tope = nuevoNodito;
}
int Pointers::pop(Nodo** tope) {
    if (*tope == nullptr) {
        std::cout << "Error: La pila esta vacia" << std::endl;
        return -1;
    }
    Nodo* temp = *tope;
    int valor = temp -> dato;
    *tope = (*tope) -> next;
    delete temp;
    return valor;
}
int Pointers::peek(Nodo* tope) {
    if (tope == nullptr) {
        std::cout << "Error: La pila esta vacia" << std::endl;
        return -1;
    }
    return tope -> dato;
}
bool Pointers::estaVacia(Nodo* tope) {
    return tope == nullptr;
}



// ejercicio 8
void Pointers::encolar(Nodo** frente, Nodo** final, int valor) {
    Nodo* nuevoNodito = new Nodo;
    nuevoNodito -> dato = valor;
    nuevoNodito -> next = nullptr;
    if (*frente == nullptr) {
        *frente = nuevoNodito;
        *final = nuevoNodito;
        return;
    }
    (*final) -> next = nuevoNodito;
    *final = nuevoNodito;
}
int Pointers::desencolar(Nodo** frente, Nodo** final) {
    if (*frente == nullptr) {
        std::cout << "Error: La cola esta vacia" << std::endl;
        return -1;
    }
    Nodo* temp = *frente;
    int valor = temp -> dato;
    *frente = (*frente) -> next;
    if (*frente == nullptr) {
        *final = nullptr;
    }
    delete temp;
    return valor;
}
int Pointers::consultarFrente(Nodo* frente) {
    if (frente == nullptr) {
        std::cout << "Error: La cola esta vacia" << std::endl;
        return -1;
    }
    return frente -> dato;
}
bool Pointers::estaVaciaCola(Nodo *frente) {
    return frente == nullptr;
}



// ejercicio 9
NodoArbol* Pointers::crearNodo(int valor) {
    NodoArbol* nuevoNodin = new NodoArbol;
    nuevoNodin -> valor = valor;
    nuevoNodin -> izquierdo = nullptr;
    nuevoNodin -> derecho = nullptr;
    return nuevoNodin;
}
NodoArbol* Pointers::insertarNodo(NodoArbol* raiz, int valor) {
    if (raiz == nullptr) {
        return crearNodo(valor);
    }
    if (valor < raiz -> valor) {
        raiz -> izquierdo = insertarNodo(raiz -> izquierdo, valor);
    }
    if (valor > raiz -> valor) {
        raiz -> derecho = insertarNodo(raiz -> derecho, valor);
    }
    return raiz;
}
NodoArbol* Pointers::buscarNodo(NodoArbol* raiz, int valor) {
    if (raiz == nullptr || raiz->valor == valor) {
        return raiz;
    }
    if (valor < raiz -> valor) {
        return buscarNodo(raiz -> izquierdo, valor);
    }
    if (valor > raiz -> valor) {
        return buscarNodo(raiz -> derecho, valor);
    }
}
void Pointers::inOrden(NodoArbol* raiz) {
    if (raiz != nullptr) {
        inOrden(raiz -> izquierdo);
        std::cout << raiz -> valor << " ";
        inOrden(raiz -> derecho);
    }
}
void Pointers::liberarArbol(NodoArbol* raiz) {
    if (raiz != nullptr) {
        liberarArbol(raiz -> izquierdo);
        liberarArbol(raiz -> derecho);
        delete raiz;
    }
}



// ejercicio 10
int Pointers::duplicar(int n) {
    return n * 2;
}
int Pointers::triplicar(int n) {
    return n * 3;
}
int Pointers::alCuadrado(int n) {
    return n * n;
}
void Pointers::aplicarOperacion(int* arr, int tamano, int (Pointers::*operacion)(int)) {
    for (int i = 0; i < tamano; i++) {
        arr[i] = (this ->*operacion)(arr[i]);
    }
}
void Pointers::mostrarArray(int* arr, int tamano) {
    std::cout << "[";
    for (int i = 0; i < tamano; i++) {
        std::cout << arr[i];
        if (i < tamano - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
}
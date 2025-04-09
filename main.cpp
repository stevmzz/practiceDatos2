#include <iostream>
#include <limits>
#include <iomanip>
#include "pointers//pointers.h"

void pausar() {
    std::cout << "\nPresione Enter para continuar...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

int main() {
    int tipo, numero;
    Pointers pointers;
    bool salir = false;

    while (!salir) {

        // encabezado principal
        std::cout << "+--------------------------------------------------+" << std::endl;
        std::cout << "|             PRACTICA DE DATOS II                 |" << std::endl;
        std::cout << "+--------------------------------------------------+" << std::endl;
        // menu principal
        std::cout << "\n[ Menu Principal ]" << std::endl;
        std::cout << "------------------" << std::endl;
        std::cout << "1. Ejercicios de punteros" << std::endl;
        std::cout << "0. Salir" << std::endl;
        std::cout << "\nIngrese su opcion: ";
        std::cin >> tipo;

        switch (tipo) {
            case 0:
                salir = true;
                break;

            case 1:
                std::cout << "+--------------------------------------------------+" << std::endl;
                std::cout << "|               EJERCICIOS DE PUNTEROS             |" << std::endl;
                std::cout << "+--------------------------------------------------+" << std::endl;

                std::cout << "\n[ Seleccione un ejercicio ]" << std::endl;
                std::cout << "-------------------------" << std::endl;
                std::cout << "1. Intercambio de variables" << std::endl;
                std::cout << "2. Busqueda en array" << std::endl;
                std::cout << "3. Array dinamico" << std::endl;
                std::cout << "4. Matriz dinamica" << std::endl;
                std::cout << "5. Estructura con punteros" << std::endl;
                std::cout << "6. Lista enlazada simple" << std::endl;
                std::cout << "0. Volver al menu principal" << std::endl;
                std::cout << "\nIngrese su opcion: ";
                std::cin >> numero;

                switch (numero) {
                    case 1: {
                        std::cout << "+--------------------------------------------------+" << std::endl;
                        std::cout << "|              INTERCAMBIO DE VARIABLES            |" << std::endl;
                        std::cout << "+--------------------------------------------------+" << std::endl;
                        int numA, numB;
                        std::cout << "\nEste ejercicio intercambia el valor de dos variables usando punteros.\n" << std::endl;
                        std::cout << "Digite el valor para a: ";
                        std::cin >> numA;
                        std::cout << "Digite el valor para b: ";
                        std::cin >> numB;
                        std::cout << "\nValores antes del intercambio:" << std::endl;
                        std::cout << "   a = " << numA << ", b = " << numB << std::endl;
                        pointers.intercambiar(&numA, &numB);
                        std::cout << "\nValores despues del intercambio:" << std::endl;
                        std::cout << "   a = " << numA << ", b = " << numB << std::endl;
                        pausar();
                        break;
                    }

                    case 2: {
                        std::cout << "+--------------------------------------------------+" << std::endl;
                        std::cout << "|                 BUSQUEDA EN ARRAY                |" << std::endl;
                        std::cout << "+--------------------------------------------------+" << std::endl;
                        int numeros[] = {10, 25, 30, 15, 40};
                        int valorBuscado;
                        std::cout << "\nEste ejercicio busca un valor en un array y retorna un puntero al elemento.\n" << std::endl;
                        std::cout << "Array disponible: [";
                        for (int i = 0; i < 5; i++) {
                            std::cout << numeros[i];
                            if (i < 4) std::cout << ", ";
                        }
                        std::cout << "]" << std::endl;
                        std::cout << "\nDigite el valor a buscar: ";
                        std::cin >> valorBuscado;
                        int* resultado = pointers.buscar(numeros, 5, valorBuscado);
                        std::cout << "\nResultado de la busqueda:" << std::endl;
                        if (resultado != NULL) {
                            std::cout << "[OK] Valor " << valorBuscado << " encontrado en la posicion " << (resultado - numeros) << std::endl;
                        } else {
                            std::cout << "[X] El valor " << valorBuscado << " no se encontro en el array" << std::endl;
                        }
                        pausar();
                        break;
                    }

                    case 3: {
                        std::cout << "+--------------------------------------------------+" << std::endl;
                        std::cout << "|                  ARRAY DINAMICO                  |" << std::endl;
                        std::cout << "+--------------------------------------------------+" << std::endl;
                        int tamano;
                        std::cout << "\nEste ejercicio crea un array dinamico con valores aleatorios entre 1 y 100.\n" << std::endl;
                        std::cout << "Ingrese el tamano del array: ";
                        std::cin >> tamano;
                        int* array = pointers.crearArrayDinamico(tamano);
                        std::cout << "\nElementos del array generado:" << std::endl;
                        std::cout << "[";
                        for (int i = 0; i < tamano; i++) {
                            std::cout << array[i];
                            if (i < tamano - 1) std::cout << ", ";
                        }
                        std::cout << "]" << std::endl;
                        pointers.liberarMemoria(array);
                        std::cout << "\n[OK] Memoria liberada correctamente." << std::endl;
                        pausar();
                        break;
                    }

                    case 4: {
                        std::cout << "+--------------------------------------------------+" << std::endl;
                        std::cout << "|                 MATRIZ DINAMICA                  |" << std::endl;
                        std::cout << "+--------------------------------------------------+" << std::endl;
                        int filas, columnas;
                        std::cout << "\nEste ejercicio crea una matriz dinamica bidimensional con valores aleatorios.\n" << std::endl;
                        std::cout << "Ingrese el numero de filas: ";
                        std::cin >> filas;
                        std::cout << "Ingrese el numero de columnas: ";
                        std::cin >> columnas;
                        int** matriz = pointers.crearMatriz(filas, columnas);
                        pointers.llenarMatriz(matriz, filas, columnas);
                        std::cout << "\nMatriz generada:" << std::endl;
                        std::cout << "---------------" << std::endl;
                        pointers.mostrarMatriz(matriz, filas, columnas);
                        pointers.liberarMatriz(matriz, filas);
                        std::cout << "\n[OK] Memoria de la matriz liberada correctamente." << std::endl;
                        pausar();
                        break;
                    }

                    case 5: {
                        std::cout << "+--------------------------------------------------+" << std::endl;
                        std::cout << "|              ESTRUCTURA CON PUNTEROS             |" << std::endl;
                        std::cout << "+--------------------------------------------------+" << std::endl;
                        int numEstudiantes;
                        std::cout << "\nEste ejercicio maneja un array dinamico de estructuras Estudiante.\n" << std::endl;
                        std::cout << "Ingrese el numero de estudiantes: ";
                        std::cin >> numEstudiantes;
                        Estudiante* estudiantes = pointers.crearEstudiantes(numEstudiantes);
                        std::cout << "\nIngreso de datos:" << std::endl;
                        std::cout << "----------------" << std::endl;
                        pointers.ingresarDatos(estudiantes, numEstudiantes);
                        std::cout << "\nLista de estudiantes:" << std::endl;
                        std::cout << "--------------------" << std::endl;
                        pointers.mostrarEstudiantes(estudiantes, numEstudiantes);
                        Estudiante* mejor = pointers.mejorEstudiante(estudiantes, numEstudiantes);
                        std::cout << "\nEstudiante con mejor calificacion:" << std::endl;
                        std::cout << "---------------------------------" << std::endl;
                        std::cout << "  Nombre: " << mejor->nombre << std::endl;
                        std::cout << "  ID: " << mejor->id << std::endl;
                        std::cout << "  Calificacion: " << mejor->calificacion << std::endl;
                        delete[] estudiantes;
                        std::cout << "\n[OK] Memoria liberada correctamente." << std::endl;
                        pausar();
                        break;
                    }

                    case 6: {
                        std::cout << "+--------------------------------------------------+" << std::endl;
                        std::cout << "|              LISTA ENLAZADA SIMPLE               |" << std::endl;
                        std::cout << "+--------------------------------------------------+" << std::endl;

                        std::cout << "\nEste ejercicio implementa una lista enlazada simple usando punteros.\n" << std::endl;

                        Nodo* miLista = NULL;
                        int opcion = 0;
                        int valor = 0;

                        do {
                            std::cout << "\n[ Operaciones con Lista Enlazada ]" << std::endl;
                            std::cout << "---------------------------------" << std::endl;
                            std::cout << "1. Insertar al inicio" << std::endl;
                            std::cout << "2. Insertar al final" << std::endl;
                            std::cout << "3. Eliminar nodo" << std::endl;
                            std::cout << "4. Mostrar lista" << std::endl;
                            std::cout << "0. Volver al menu anterior" << std::endl;

                            std::cout << "\nSeleccione una operacion: ";
                            std::cin >> opcion;

                            switch (opcion) {
                                case 1:
                                    std::cout << "Ingrese valor a insertar al inicio: ";
                                    std::cin >> valor;
                                    pointers.insertarAlInicio(&miLista, valor);
                                    std::cout << "[OK] Valor " << valor << " insertado al inicio de la lista." << std::endl;
                                    break;

                                case 2:
                                    std::cout << "Ingrese valor a insertar al final: ";
                                    std::cin >> valor;
                                    pointers.insertarAlFinal(&miLista, valor);
                                    std::cout << "[OK] Valor " << valor << " insertado al final de la lista." << std::endl;
                                    break;

                                case 3:
                                    std::cout << "Ingrese valor a eliminar: ";
                                    std::cin >> valor;
                                    pointers.eliminarNodo(&miLista, valor);
                                    std::cout << "[OK] Operación de eliminación completada." << std::endl;
                                    break;

                                case 4:
                                    std::cout << "\nContenido actual de la lista:" << std::endl;
                                    if (miLista == NULL) {
                                        std::cout << "La lista está vacía" << std::endl;
                                    } else {
                                        pointers.mostrarLista(miLista);
                                    }
                                    break;

                                case 0:
                                    std::cout << "\nLiberando memoria de la lista..." << std::endl;
                                    pointers.liberarLista(&miLista);
                                    std::cout << "[OK] Memoria liberada correctamente." << std::endl;
                                    break;

                                default:
                                    std::cout << "\n! Opción no válida. Por favor intente de nuevo." << std::endl;
                                    break;
                            }

                        } while (opcion != 0);

                        pausar();
                        break;
                    }

                    case 7: {
                        std::cout << "+--------------------------------------------------+" << std::endl;
                        std::cout << "|                 PILA CON PUNTEROS                |" << std::endl;
                        std::cout << "+--------------------------------------------------+" << std::endl;

                        std::cout << "\nEste ejercicio implementa una pila (stack) usando punteros.\n" << std::endl;

                        Nodo* pila = NULL;
                        int opcion = 0;
                        int valor = 0;

                        do {
                            std::cout << "\n[ Operaciones con Pila ]" << std::endl;
                            std::cout << "-----------------------" << std::endl;
                            std::cout << "1. Push (insertar)" << std::endl;
                            std::cout << "2. Pop (extraer)" << std::endl;
                            std::cout << "3. Peek (consultar tope)" << std::endl;
                            std::cout << "4. Verificar si esta vacia" << std::endl;
                            std::cout << "0. Volver al menu anterior" << std::endl;

                            std::cout << "\nSeleccione una operacion: ";
                            std::cin >> opcion;

                            switch (opcion) {
                                case 1:
                                    std::cout << "Ingrese valor a insertar: ";
                                    std::cin >> valor;
                                    pointers.push(&pila, valor);
                                    std::cout << "[OK] Valor " << valor << " insertado en la pila." << std::endl;
                                    break;

                                case 2:
                                    if (!pointers.estaVacia(pila)) {
                                        valor = pointers.pop(&pila);
                                        std::cout << "[OK] Valor extraido: " << valor << std::endl;
                                    } else {
                                        std::cout << "[X] No se puede extraer: la pila esta vacia." << std::endl;
                                    }
                                    break;

                                case 3:
                                    if (!pointers.estaVacia(pila)) {
                                        valor = pointers.peek(pila);
                                        std::cout << "[OK] Valor en el tope: " << valor << std::endl;
                                    } else {
                                        std::cout << "[X] No hay elementos: la pila esta vacia." << std::endl;
                                    }
                                    break;

                                case 4:
                                    if (pointers.estaVacia(pila)) {
                                        std::cout << "[OK] La pila esta vacia." << std::endl;
                                    } else {
                                        std::cout << "[OK] La pila contiene elementos." << std::endl;
                                    }
                                    break;

                                case 0:
                                    std::cout << "\nLiberando memoria de la pila..." << std::endl;
                                    while (!pointers.estaVacia(pila)) {
                                        pointers.pop(&pila);
                                    }
                                    std::cout << "[OK] Memoria liberada correctamente." << std::endl;
                                    break;

                                default:
                                    std::cout << "\n! Opcion no valida. Por favor intente de nuevo." << std::endl;
                                    break;
                            }

                        } while (opcion != 0);

                        pausar();
                        break;
                    }

                    case 8: {
                        std::cout << "+--------------------------------------------------+" << std::endl;
                        std::cout << "|                 COLA CON PUNTEROS                |" << std::endl;
                        std::cout << "+--------------------------------------------------+" << std::endl;

                        std::cout << "\nEste ejercicio implementa una cola (queue) usando punteros.\n" << std::endl;

                        Nodo* frente = NULL;
                        Nodo* final = NULL;
                        int opcion = 0;
                        int valor = 0;

                        do {
                            std::cout << "\n[ Operaciones con Cola ]" << std::endl;
                            std::cout << "-----------------------" << std::endl;
                            std::cout << "1. Encolar (insertar)" << std::endl;
                            std::cout << "2. Desencolar (extraer)" << std::endl;
                            std::cout << "3. Consultar frente" << std::endl;
                            std::cout << "4. Verificar si esta vacia" << std::endl;
                            std::cout << "0. Volver al menu anterior" << std::endl;

                            std::cout << "\nSeleccione una operacion: ";
                            std::cin >> opcion;

                            switch (opcion) {
                                case 1:
                                    std::cout << "Ingrese valor a encolar: ";
                                    std::cin >> valor;
                                    pointers.encolar(&frente, &final, valor);
                                    std::cout << "[OK] Valor " << valor << " encolado correctamente." << std::endl;
                                    break;

                                case 2:
                                    if (!pointers.estaVaciaCola(frente)) {
                                        valor = pointers.desencolar(&frente, &final);
                                        std::cout << "[OK] Valor desencolado: " << valor << std::endl;
                                    } else {
                                        std::cout << "[X] No se puede desencolar: la cola esta vacia." << std::endl;
                                    }
                                    break;

                                case 3:
                                    if (!pointers.estaVaciaCola(frente)) {
                                        valor = pointers.consultarFrente(frente);
                                        std::cout << "[OK] Valor en el frente: " << valor << std::endl;
                                    } else {
                                        std::cout << "[X] No hay elementos: la cola esta vacia." << std::endl;
                                    }
                                    break;

                                case 4:
                                    if (pointers.estaVaciaCola(frente)) {
                                        std::cout << "[OK] La cola esta vacia." << std::endl;
                                    } else {
                                        std::cout << "[OK] La cola contiene elementos." << std::endl;
                                    }
                                    break;

                                case 0:
                                    std::cout << "\nLiberando memoria de la cola..." << std::endl;
                                    while (!pointers.estaVaciaCola(frente)) {
                                        pointers.desencolar(&frente, &final);
                                    }
                                    std::cout << "[OK] Memoria liberada correctamente." << std::endl;
                                    break;

                                default:
                                    std::cout << "\n! Opcion no valida. Por favor intente de nuevo." << std::endl;
                                    break;
                            }

                        } while (opcion != 0);

                        pausar();
                        break;
                    }

                    case 9: {
                        std::cout << "+--------------------------------------------------+" << std::endl;
                        std::cout << "|            ARBOL BINARIO DE BUSQUEDA             |" << std::endl;
                        std::cout << "+--------------------------------------------------+" << std::endl;

                        std::cout << "\nEste ejercicio implementa un Arbol Binario de Busqueda usando punteros.\n" << std::endl;

                        NodoArbol* arbol = NULL;
                        int opcion = 0;
                        int valor = 0;

                        do {
                            std::cout << "\n[ Operaciones con ABB ]" << std::endl;
                            std::cout << "---------------------" << std::endl;
                            std::cout << "1. Insertar valor" << std::endl;
                            std::cout << "2. Buscar valor" << std::endl;
                            std::cout << "3. Mostrar recorrido en orden" << std::endl;
                            std::cout << "0. Volver al menu anterior" << std::endl;

                            std::cout << "\nSeleccione una operacion: ";
                            std::cin >> opcion;

                            switch (opcion) {
                                case 1:
                                    std::cout << "Ingrese valor a insertar: ";
                                    std::cin >> valor;
                                    arbol = pointers.insertarNodo(arbol, valor);
                                    std::cout << "[OK] Valor " << valor << " insertado en el arbol." << std::endl;
                                    break;

                                case 2:
                                    std::cout << "Ingrese valor a buscar: ";
                                    std::cin >> valor;
                                    if (pointers.buscarNodo(arbol, valor) != NULL) {
                                        std::cout << "[OK] Valor " << valor << " encontrado en el arbol." << std::endl;
                                    } else {
                                        std::cout << "[X] Valor " << valor << " no encontrado en el arbol." << std::endl;
                                    }
                                    break;

                                case 3:
                                    std::cout << "\nRecorrido en orden: ";
                                    if (arbol == NULL) {
                                        std::cout << "El arbol esta vacio";
                                    } else {
                                        pointers.inOrden(arbol);
                                    }
                                    std::cout << std::endl;
                                    break;

                                case 0:
                                    std::cout << "\nLiberando memoria del arbol..." << std::endl;
                                    pointers.liberarArbol(arbol);
                                    arbol = NULL;
                                    std::cout << "[OK] Memoria liberada correctamente." << std::endl;
                                    break;

                                default:
                                    std::cout << "\n! Opcion no valida. Por favor intente de nuevo." << std::endl;
                                    break;
                            }

                        } while (opcion != 0);

                        pausar();
                        break;
                    }

                    case 10: {
                        std::cout << "+--------------------------------------------------+" << std::endl;
                        std::cout << "|              PUNTEROS A FUNCIONES                |" << std::endl;
                        std::cout << "+--------------------------------------------------+" << std::endl;

                        std::cout << "\nEste ejercicio demuestra el uso de punteros a funciones.\n" << std::endl;

                        int opcion = 0;
                        int tamano = 0;
                        int* array = nullptr;

                        std::cout << "Ingrese el tamano del array: ";
                        std::cin >> tamano;

                        if (tamano <= 0) {
                            std::cout << "[X] Tamano invalido. Debe ser mayor a cero." << std::endl;
                            pausar();
                            break;
                        }

                        // Crear y llenar el array
                        array = new int[tamano];
                        std::cout << "Ingrese " << tamano << " valores enteros:" << std::endl;
                        for (int i = 0; i < tamano; i++) {
                            std::cout << "Valor " << (i + 1) << ": ";
                            std::cin >> array[i];
                        }

                        std::cout << "\nArray original: ";
                        pointers.mostrarArray(array, tamano);

                        do {
                            std::cout << "\n[ Operaciones disponibles ]" << std::endl;
                            std::cout << "--------------------------" << std::endl;
                            std::cout << "1. Duplicar valores" << std::endl;
                            std::cout << "2. Triplicar valores" << std::endl;
                            std::cout << "3. Elevar al cuadrado" << std::endl;
                            std::cout << "0. Volver al menu anterior" << std::endl;

                            std::cout << "\nSeleccione una operacion: ";
                            std::cin >> opcion;

                            switch (opcion) {
                                case 1:
                                    pointers.aplicarOperacion(array, tamano, &Pointers::duplicar);
                                    std::cout << "Despues de duplicar: ";
                                    pointers.mostrarArray(array, tamano);
                                    break;

                                case 2:
                                    pointers.aplicarOperacion(array, tamano, &Pointers::triplicar);
                                    std::cout << "Despues de triplicar: ";
                                    pointers.mostrarArray(array, tamano);
                                    break;

                                case 3:
                                    pointers.aplicarOperacion(array, tamano, &Pointers::alCuadrado);
                                    std::cout << "Despues de elevar al cuadrado: ";
                                    pointers.mostrarArray(array, tamano);
                                    break;

                                case 0:
                                    std::cout << "\nLiberando memoria del array..." << std::endl;
                                    delete[] array;
                                    std::cout << "[OK] Memoria liberada correctamente." << std::endl;
                                    break;

                                default:
                                    std::cout << "\n! Opcion no valida. Por favor intente de nuevo." << std::endl;
                                    break;
                            }

                        } while (opcion != 0);

                        pausar();
                        break;
                    }

                    default:
                        std::cout << "\n!  Opcion no valida. Por favor intente de nuevo." << std::endl;
                        break;
                }
                break;

            case 2:
                std::cout << "proximamente otro tipo de ejercicios" << std::endl;
                pausar();
                break;

            default:
                std::cout << "\n!  Opcion no valida. Por favor intente de nuevo." << std::endl;
                break;
        }
    }
    return 0;
}
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Ejercicio 1: Encuentra el Elemento Mayor
Descripción: Escribe una función que tome un arreglo de enteros
y su tamaño, y devuelva el valor más grande del arreglo.
*/
int findMax(int arr[], int size) {
  int max = 0;
  for (int i = 0; i < size; i++) {
    if (arr[i] > max) {
      max = arr[i];
    }
  }
  return max;
}

/*
Ejercicio 2: Invertir un Arreglo
Descripción: Escribe una función que tome un arreglo y su tamaño, y luego
invierta el orden de sus elementos.
*/
void reverseArray(int arr[], int size) {
  int left = 0;
  int right = size - 1;

  while (left < right) {
    int temp = arr[left];
    arr[left] = arr[right];
    arr[right] = temp;

    left++;
    right--;
  }
}

/*
Ejercicio 3: Filtrar Números Pares
Descripción: Escribe una función que tome un arreglo de enteros
y su tamaño, y luego devuelva un nuevo arreglo que contenga solo
los números pares del arreglo original.
*/
int *filterEvenNumbers(int arr[], int size, int *newSize) {
  int evenCount = 0;
  for (int i = 0; i < size; i++) {
    if (arr[i] % 2 == 0) {
      evenCount++;
    }
  }
  int *evenArr = (int *)malloc(evenCount * sizeof(int));
  if (evenArr == NULL) {
    printf("Error: No se pudo asignar memoria.\n");
    exit(1);
  }
  int evenIndex = 0;
  for (int i = 0; i < size; i++) {
    if (arr[i] % 2 == 0) {
      evenArr[evenIndex] = arr[i];
      evenIndex++;
    }
  }

  *newSize = evenCount;
  return evenArr;
}

/*
Ejercicio 4: Fusión de dos Arreglos Ordenados
Descripción: Escribe una función que tome dos arreglos
ordenados y sus tamaños, y luego fusione estos dos
arreglos en un tercer arreglo también ordenado.
*/
void mergeSortedArrays(int arr1[], int size1, int arr2[], int size2,
                       int result[]) {
  int index1 = 0, index2 = 0, indexMerged = 0;

  while (index1 < size1 && index2 < size2) {
    if (arr1[index1] <= arr2[index2]) {
      result[indexMerged] = arr1[index1];
      index1++;
    } else {
      result[indexMerged] = arr2[index2];
      index2++;
    }
    indexMerged++;
  }

  while (index1 < size1) {
    result[indexMerged] = arr1[index1];
    index1++;
    indexMerged++;
  }

  while (index2 < size2) {
    result[indexMerged] = arr2[index2];
    index2++;
    indexMerged++;
  }
}

/*
Ejercicio 5: Comprobación de Ordenación
Descripción: Escribe una función que tome un arreglo y su tamaño,
y luego devuelva 1 si el arreglo está ordenado en orden ascendente,
  0 si no está ordenado, y -1 si está ordenado en orden descendente.
*/
int checkSorted(int arr[], int size) {
  int ascending = 1;
  int descending = 1;

  for (int i = 1; i < size; i++) {
    if (arr[i] < arr[i - 1]) {
      ascending = 0;
    }
    if (arr[i] > arr[i - 1]) {
      descending = 0;
    }
  }

  if (ascending) {
    return 1;
  } else if (descending) {
    return -1;
  } else {
    return 0;
  }
}
/*
Ejercicio 6: Información de una Biblioteca
Descripción: Vamos a representar la información de una biblioteca. En la
biblioteca, hay libros, y cada libro tiene un autor. Queremos organizar esta
información utilizando estructuras anidadas en C. Escribe la función para
inicializar la información de un libro.
*/

typedef struct {
  char nombre[50];
  int anioNacimiento;
} Autor;

typedef struct {
  char titulo[100];
  Autor autor;
  int anioPublicacion;
} Libro;

void inicializarLibro(Libro *libro, const char *titulo, const char *nombreAutor,
                      int anioNacimiento, int anioPublicacion) {
  strcpy(libro->titulo, titulo);
  strcpy(libro->autor.nombre, nombreAutor);
  libro->autor.anioNacimiento = anioNacimiento;
  libro->anioPublicacion = anioPublicacion;
}

/*
Ejercicio 7: Lista enlazada de números
Descripción: Escribe una función que tome un arreglo de enteros y su tamaño, y
luego cree una lista enlazada usando la estructura Nodo. Cada nodo de la lista
debe contener un número del arreglo, y los nodos deben estar enlazados en el
mismo orden que los números aparecen en el arreglo. El último nodo de la lista
debe apuntar a NULL. La función debe devolver un puntero al primer nodo de la
lista enlazada.
Recuerda reservar memoria dinámica para cada nodo usando malloc.
  */

typedef struct nodo {
  int numero;
  struct nodo *siguiente; // puntero al siguiente nodo
} Nodo;

Nodo *crearListaEnlazada(int arr[], int size) {
  if (tamaño <= 0) {
    return NULL;
  }

  Nodo* primerNodo = NULL;
  Nodo* nodoActual = NULL;

  for (int i = 0; i < size; i++) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    if (nuevoNodo == NULL) {
      while (primerNodo != NULL) {
        Nodo* temp = primerNodo;
        primerNodo = primerNodo->siguiente;
        free(temp);
        }
      return NULL;
    }
    nuevoNodo->numero = arr[i];
    nuevoNodo->siguiente = NULL;

    if (nodoActual == NULL) {
      primerNodo = nuevoNodo;
      nodoActual = nuevoNodo;
    } else {
      nodoActual->siguiente = nuevoNodo;
      nodoActual = nuevoNodo;
    }
  }

  return primerNodo;
}

#include "bstree.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Casos de prueba para arboles de busqueda binaria generales
 */

#define N_PALABRAS 16

static void *copiar_cadena(void *dato) {
  char *str = malloc(sizeof(char) * (strlen(dato) + 1));
  assert(str != NULL);
  strcpy(str, dato);
  return str;
}
static int comparar_cadena(void *dato1, void *dato2) {
  return strcmp(dato1, dato2);
}
static void destruir_cadena(void *dato) { free(dato); }
static void imprimir_cadena(void *dato, __attribute__((unused)) void *extra) {
  /* __attribute__((unused)) le dice al compilador que esta variable puede no
   * ser usada, de esta forma las banderas no tiran warnings.*/
  printf("\"%s\" ", (char *)dato);
}

int main() {

  char *palabras[N_PALABRAS] = {"gato",      "perro",    "casa",     "persona",
                                "parque",    "arbol",    "edificio", "calle",
                                "argentina", "santa fe", "rosario",  "unr",
                                "edya",      "farmacia", "tiempo",   "celular"};

  // Creamos un arbol vacio y le insertamos las palabras
  BSTree arbol = bstee_crear();
  for (int i = 0; i < N_PALABRAS; i++)
    arbol = bstree_insertar(arbol, palabras[i], copiar_cadena, comparar_cadena);

  // Imprimir el arbol inorden (alfabetico)
  printf("Recorrido inorden: ");
  //bstree_recorrer(arbol, BTREE_RECORRIDO_IN, imprimir_cadena, NULL);
  puts("");


  int contador = 0;
  printf("KK");
  BSTree dato_nodo = bstee_crear();
  dato_nodo = bstree_k_esimo_menor(arbol, &contador, 3);
  printf("KK");
  char * datito = dato_nodo->dato;
  printf("K esimo elemento: %s",datito);

  // Destruir arbol
  bstree_destruir(arbol, destruir_cadena);

  return 0;
}



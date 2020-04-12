#include "assert.h"
#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"

#define ARRAY_SIZE 10

struct max_min_result {
    int max_value;
    int min_value;
    unsigned int max_position;
    unsigned int min_position;
};

struct max_min_result compute_max_min(int array[], unsigned int length){
    assert(length > 0);
    array = array;
    struct max_min_result result = { 0, 0, 0, 0 };
    for (unsigned int indice = 0; indice < length; indice++){
        if (result.min_value>=array[indice]){
           result.min_value = array[indice];
           result.min_position=indice;
        }
        
       if (result.max_value<=array[indice]){
           result.max_value = array[indice];
           result.max_position=indice;
       }
    }

   return result;
}

int main(void){
    int array[ARRAY_SIZE] = { 4, -1, 5, 8, 9, 0, 3, 6, 0, 0 };
    printf("Por favor, ingrese los 10 valores del arreglo\n");

    for (unsigned int indice=0; indice < 10; indice++){
       scanf("%i",&array[indice]);
    }
    
    compute_max_min(array, ARRAY_SIZE);
    
    struct max_min_result result = compute_max_min(array, ARRAY_SIZE);
    printf("Maximo: %d\n", result.max_value);
    printf("Posicion del maximo: %u\n", result.max_position);
    printf("Minimo: %d\n", result.min_value);
    printf("Posicion del minimo: %u\n", result.min_position);
    
    return 0;
}

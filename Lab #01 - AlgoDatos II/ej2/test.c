#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

void swap(int a[], int x, int y){
    int temp = a[x]; 
    a[x] = a[y]; 
    a[y] = temp;
}

int partition (int a[], int izq, int der){ 
    int pivot = a[der]; 
    int i = (izq - 1);  
  
    for (int j = izq; j <= der-1; j++) 
    { 
        if (a[j] < pivot) 
        { 
            i++; 
            swap(a, i, j); 
        } 
    } 
    swap(a, i+1, der); 
    return (i + 1); 
} 
  
void quickSort(int a[], int izq, int der) 
{ 
    if (izq < der){ 

        int piv = partition(a, izq, der); 
        quickSort(a, piv + 1, der); 

    } 
}

//Salida por pantalla
void imprimeArreglo(int a[],int n_max){
 int i=0;
 while (i<n_max){
       printf("%i ",a[i]);
       i++;
    }
}

int main(void){
    int len;
    printf("Ingresar longitud del arreglo: ");
    scanf("%i",&len);
    assert(len >= 0);
    int a[len];
    printf("Ingresar arreglo: ");
    for (int i = 0; i < len; i++){
        scanf("%i",&a[i]);
    }
   quickSort(a, 0u, (len == 0u) ? 0 : len - 1u); 
   imprimeArreglo(a, len);  
}
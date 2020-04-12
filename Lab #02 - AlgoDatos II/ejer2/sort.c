#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "helpers.h"
#include "sort.h"

static bool goes_before(player_t x, player_t y){
    x = x; y = y;    
    if(x.rank <= y.rank){
        return true;       
    }
    return false;
}

bool array_is_sorted(player_t atp[], unsigned int length){
    unsigned int i = 1;
    while (i < length && goes_before(atp[i - 1], atp[i])){
        i++;
    }
    return (i == length);
}

// Funciones Nesesarias:
void swap(player_t a[], int i, int j){
  player_t tmp = a[i];
  a[i] = a[j];
  a[j] = tmp;
}

int partition(player_t a[], int izq, int der) {
    int ppiv = izq;
    int i = izq + 1;
    int j = der;
    while (i <= j){
        if (goes_before(a[i], a[ppiv])){
            i++;
        }
        else if (goes_before(a[ppiv], a[j])){
            j--;
        }
        else{
            swap(a,i,j);
            i++;
            j--;
        }
    }
    swap(a, ppiv, j);
    ppiv = j; 
    return ppiv;
}

void quick_sort_rec(player_t a[], int izq, int der){
    int ppiv = 0;
    if (izq < der){
        ppiv = partition(a,izq,der);
        if (ppiv == 0){
            quick_sort_rec(a,izq,ppiv);
        }
        else{
            quick_sort_rec(a,izq,ppiv-1);
        }
        quick_sort_rec(a,ppiv+1,der);             
    }  
}

void sort(player_t a[], int length){
    quick_sort_rec(a, 0, (length == 0) ? 0 : length - 1);    
}
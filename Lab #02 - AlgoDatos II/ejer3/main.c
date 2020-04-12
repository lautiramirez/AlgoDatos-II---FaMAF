#include<stdio.h>
#include<stdlib.h>


int main()
{
    int x = 5;
    int y = -4;
    int *p = &x; 
    int *q = &y;
    int *r = p;

    int temp = x;
    *p = y;
    *q = temp;
  
    printf("El valor de *p=%d, *q=%d y *r=%d\n", *p, *q, *r);

    x = 5;
    y = -4;
    p = &x;
    q = &y;
    r = p;

    p = q;
    q = r;  

    printf("El valor de *p=%d, *q=%d y *r=%d\n", *p, *q, *r);
    
    return (EXIT_SUCCESS);
}

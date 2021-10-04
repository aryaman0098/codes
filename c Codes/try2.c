#include<stdio.h>
#define M(x, y) (x < y)? x : y;

void main(){
    int *ptr, list[100], i;
    for(i = 0; i < 100; i++){
        list[i] = i + 10;
    }
    ptr = list + 27;
    printf("%d\n", list[27]);
    printf("%d\n", *ptr);
}
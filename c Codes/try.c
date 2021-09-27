#include<stdlib.h>
#include<stdio.h>

int main(){

    int n = 1;
    for(int i=0; i<100000000; i++){n++;}
    printf("%d\n", n);

    return 0;
} 
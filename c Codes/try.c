#include<stdlib.h>
#include<stdio.h>
#include<string.h>

char *vow = "aeiou",c,ch;

int main(){
    int i  = 0, n;
    for(scanf("%i", &n), getchar(); i < n;){
        putc(ch = getchar(), stdout);i++;
        if(strchr(vow, ch)){
            while(++i&&strchr(vow, c = getchar()));
            putc(c, stdout);
        }
    }
} 
#include<stdlib.h>
#include<stdio.h>

int MyFunction(int a, int b){
	int k = 0;
	while(a - k * b >= b) ++k;
	return a - k * b;
}

int main(){
	unsigned char ch = 0;
	int count = 0;
	while(++ch <= 255)
		printf("%d", 1);
		count++;
	printf("%d", count);
}

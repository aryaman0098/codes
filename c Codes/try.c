#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>

int count = 0;

void* temp () {
  for(int i = 0; i < 10000; i++) {
    count++;
  }
}

int main() {
  pthread_t p1, p2;
  if(pthread_create(&p1, NULL, &temp, NULL) == 0) {
    printf("%d\n", 1);
  }
  if(pthread_create(&p2, NULL, &temp, NULL) == 0) {
    printf("%d\n", 2);
  }
  if(pthread_join(p2, NULL) == 0) {
    printf("%d\n", 4);
  }
  if(pthread_join(p1, NULL) == 0) {
    printf("%d\n", 3);
  }
  printf("%d", count);
  return 0;
}
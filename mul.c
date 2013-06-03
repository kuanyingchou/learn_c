#include<stdio.h>
#include<stdlib.h>

int * multiply(int *a, int *b) {}

void print(int x, int y, int *a) {
   for(int i=0; i<x; i++) {
      for(int j=0; j<y; j++) {
         printf("%d ", a[i][j]);
      }
      printf("\n");
   }
}
void input_matrix(int x, int y, int *a) {
   for(int i=0; i<x; i++) {
      for(int j=0; j<y; j++) {
         scanf("%d", &a[i][j]);
      }
   }
}
int main() {
   printf("hello, moon!\n");
   int d[4];
   scanf("%d %d %d %d", &d[0], &d[1], &d[2], &d[3]);
   printf("%d %d %d %d", d[0], d[1], d[2], d[3]);
   int *a = (int*)malloc(sizeof(int) * d[0] * d[1]);
   int *b = (int*)malloc(sizeof(int) * d[0] * d[1]);
   input_matrix(d[0], d[1], a);
   input_matrix(d[1], d[2], b);
   int *r = multiply(a , b);
   print(d[0], d[2], r);

}


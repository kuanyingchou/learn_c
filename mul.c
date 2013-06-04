#include<stdio.h>
#include<stdlib.h>

void input_matrix(int x, int y, int **a) {
   int i;
   int j;
   for(i=0; i<x; i++) {
      for(j=0; j<y; j++) {
         scanf("%d", &a[i][j]);
      }
   }
}
int **alloc_matrix(int x, int y) {
   int **r= (int **) malloc(sizeof(int *) * x);
   int i;
   for(i=0; i<x; i++) {
      r[i] = (int *) malloc(sizeof(int) * y);
   }
   return r;
}

int **multiply(int **a, int ax, int ay, int **b, int bx, int by) {
   //printf("r = %d x %d \n", ax, by);
   int **r = (int**)alloc_matrix(ax, by);
   int ar;
   int bc;
   int ac;
   for(ar=0; ar<ax; ar++) {
      for(bc=0; bc<by; bc++) {
          int sum = 0;
          for(ac=0; ac<ay; ac++) {
             sum += a[ar][ac] * b[ac][bc];
          }
          r[ar][bc] = sum;
      }
   }
   return r;
}

void print(int x, int y, int **a) {
   int i;
   int j;
   for(i=0; i<x; i++) {
      for(j=0; j<y; j++) {
         printf("%d ", a[i][j]);
      }
      printf("\n");
   }
}
int main() {
   printf("hello, moon!\n");
   printf("input dimensions of matrix A and matrix B: ");
   int d[4];
   scanf("%d %d %d %d", &d[0], &d[1], &d[2], &d[3]);
   printf("got dimensions: A = %d by %d, B = %d by %d\n", 
       d[0], d[1], d[2], d[3]);
   int **a = alloc_matrix(d[0], d[1]);
   int **b = alloc_matrix(d[2], d[3]);
   printf("enter matrix A (%d by %d)...\n", d[0], d[1]);
   input_matrix(d[0], d[1], a);
   printf("matrix A = \n");
   print(d[0], d[1], a);
   printf("enter matrix B (%d by %d)...\n", d[2], d[3]);
   input_matrix(d[2], d[3], b);
   printf("matrix B = \n");
   print(d[2], d[3], b);

   int **r = multiply(a , d[0], d[1], b, d[2], d[3]);
   printf("A * B = \n");
   print(d[0], d[3], r);

   free(a);
   free(b);
   free(r);
}


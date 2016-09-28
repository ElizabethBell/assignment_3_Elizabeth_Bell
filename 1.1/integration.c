#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <stdlib.h>
#include <math.h>

double f (double n, int x) {
  double y;
  int i;
  for (i=0; i<x; i++) {
    y = pow(n, 2.0);
    y = sqrt(y);
  }
  return y;
}

double integrate (int a, int b, int n, int x) {
  int i;
  double sol;
  
  for (i=1; i<n; i++) {
    double num = a+(i+0.5)*((b-a)/n);
    sol = f(num, x)*((b-a)/n);
  }
  return sol;
}

int main(int argc, char *argv[]) {
  struct timeval start, end;
  if(argc != 5) {
    printf("Incorrect number of arguments.\n");
  }
  else {
    int arg1, arg2, arg3, arg4;
    arg1 = atoi(argv[1]);
    arg2 = atoi(argv[2]);
    arg3 = atoi(argv[3]);
    arg4 = atoi(argv[4]);
    gettimeofday(&start, NULL);
    integrate(arg1, arg2, arg3, arg4);
    gettimeofday(&end, NULL); 
  }
  printf("Time: %ld\n", ((end.tv_sec * 1000000 + end.tv_usec)-(start.tv_sec * 1000000 + start.tv_usec)));
  
  return 0;
}
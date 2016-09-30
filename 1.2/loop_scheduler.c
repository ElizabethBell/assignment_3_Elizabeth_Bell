#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>

pthread_mutex_t mut;

int sol = 0;

void *i() {
  
  return NULL;
}

/*double f (double n, int x) {
  double y=n;
  int i;
  for (i=0; i<x; i++) {
    y += pow(n, 2.0);
    //y = sqrt(y);
  }
  return y;
}

double integrate (int a, int b, int n, int x) {
  int i;
  double sol;
  struct timeval start, end;
  
  gettimeofday(&start, NULL);
  for (i=0; i<n; i++) {
    double num = a+(i+0.5)*((b-a)/n);
    sol += f(num, x)*((b-a)/n);
  }
  gettimeofday(&end, NULL);
  printf("Time: %ld\n", ((end.tv_sec * 1000000 + end.tv_usec)-(start.tv_sec * 1000000 + start.tv_usec)));
  return sol;
}

int main(int argc, char *argv[]) {
  if(argc != 5) {
    printf("Incorrect number of arguments.\n");
  }
  else {
    int arg1, arg2, arg3, arg4;
    arg1 = atoi(argv[1]);
    arg2 = atoi(argv[2]);
    arg3 = atoi(argv[3]);
    arg4 = atoi(argv[4]);
    integrate(arg1, arg2, arg3, arg4);
  }
  return 0;
}*/
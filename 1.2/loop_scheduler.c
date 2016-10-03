#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>

pthread_mutex_t* mut;

double sol = 0;
int a, b;

double f (double n, int x) {
  double y=n;
  int i;
  for (i=0; i<x; i++) {
    y = pow(1, 2.0);
    y = sqrt(1);
  }
  return y;
}

double integrate (int a, int b, int x) {
  int i;
  double solu;
  struct timeval start, end;
  
  gettimeofday(&start, NULL);
  for (i=0; i<100; i++) {
    double num = a+(i+0.5)*((b-a)/100);
    solu += f(num, x)*((b-a)/100);
  }
  gettimeofday(&end, NULL);
  printf("Time: %ld\n", ((end.tv_sec * 1000000 + end.tv_usec)-(start.tv_sec * 1000000 + start.tv_usec)));
  return (double)solu;
}

void* j(int n[]) {
  int nums[4];
  int i;
  for(i=0; i<4; i++) {
    nums[i]=n[i];
  }
  while (b < nums[2]) {
   pthread_mutex_lock(mut);
   sol += integrate(a, b, nums[3]);
   a = b+1;
   b += nums[3];
   pthread_mutex_unlock(mut);
  }
  pthread_exit(NULL);
  return NULL;
}

int main(int argc, char *argv[]) {
  if(argc != 4) {
    printf("Incorrect number of arguments.\n");
  }
  else {
    int numthreads, granularity, intensity, num, i;
    numthreads = atoi(argv[1]);
    granularity = atoi(argv[2]);
    intensity = atoi(argv[3]);
    num = granularity/numthreads;
    int nums[4] = {numthreads, granularity, intensity, num};
    a = 1;
    b = num;
    pthread_t th[numthreads];
    
    for (i=0; i<numthreads; i++) {
      pthread_create(&th[i], NULL, j, nums);
    }
    for (i=0; i<numthreads; i++) {
      pthread_join(th[i], NULL);
    }
  }
  pthread_exit(NULL);
  return 0;
}
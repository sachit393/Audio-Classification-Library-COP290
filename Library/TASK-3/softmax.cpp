#include <iostream>
#include <cmath>

using namespace std;

void softmax(float *A, int size){
  float denominator = 0;
  for(int i=0;i<size;i++){
    denominator += exp(A[i]);       // denominator will be some of exponentials of each value
  }
  for(int i=0;i<size;i++){
    A[i] = exp(A[i])/denominator;   // replacing each value with its corresponding probability
  }
}

#include <stdio.h>
#include <time.h>
#include <fstream>
#include <iostream>
#include <cstring>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <iomanip>
#include <chrono>
//#include </opt/homebrew/opt/openblas/include/cblas.h>
// #include </home/eshan/OpenBLAS/cblas.h>
// #include "openblasmult.h"
#include <cblas.h>




using namespace std;

namespace OPENBLAS{
  float* openblasmult(float*A, float*B, float*D, int m, int k, int n){    // A will be inputmatrix, B will be weightmatrix, D will be bias matrix
      float*C =  (float *) malloc( sizeof(float) * m* n );

      cblas_sgemm (CblasRowMajor, CblasNoTrans, CblasNoTrans , m , n , k , 1.0 , A , k , B , n , 0.0 , C , n);    // computing product of matrix A,B (stored in rowMajor form) and adding bias to it

      for(int i=0;i<m*n;i++){
        C[i]+=D[i];             // add to the product bias
      }
      return C;
    }
}
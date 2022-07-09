#include <iostream>
#include <fstream>
#include <map>
#include "libaudio.h"

#include "classifier.h"
using namespace std;





pred_t* classify(float* probabilities, int size, pred_t*ans){


    map <int, float> prob ;
    for(int i=0;i<size;i++){
        prob[i]=probabilities[i] ;
    }
    float maxi = probabilities[0] ;
    int curri=0 ;
    int ansind[3], j=0 ;
                            // Iterating thrice to find the top three probabilities
    for(int k=0;k<3;k++){
    curri=0, maxi=prob[0] ;
                            // Iterating over the probabilities array to find the max probability
    for(int i=0;i<size;i++){
        if(prob[i]>maxi){
            maxi=prob[i] ;
            curri=i ;
        }
    }
    ansind[j]=curri ;       // saving the index of max probability
    j++ ;
    prob[curri]=0 ;         // dumping the max probability , so that the next maximum can be calculated in the next iteration
    }
    for(int i=0;i<3;i++){   // storing the labels and values for the 3 highest probabiliets
      ans[i].label = ansind[i];
      ans[i].prob = probabilities[ansind[i]];
    }
    return ans;             // returning the answer
}
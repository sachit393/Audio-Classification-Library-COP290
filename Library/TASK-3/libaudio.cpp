#include <iostream>
#include <string>
#include "libaudio.h"
#include "DNN.h"
#include "classifier.h"
using namespace std;
pred_t* libaudioAPI(const char* audiofeatures, pred_t* pred){
    float* probabilities = DNN(audiofeatures);          // calling DNN to get probabilities for each of the 12 labels
    pred_t* ans = classify(probabilities, 12, pred);    // getting the top  probabilities from the 12 probabilties
    return ans ;                                        // returning the answer
}
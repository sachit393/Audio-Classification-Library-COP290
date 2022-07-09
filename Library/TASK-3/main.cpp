#include <iostream>
#include <fstream>
#include <iomanip>
#include "libaudio.h"
#include "helper.h"
using namespace std;

int main(int argc, char const *argv[]) {
  string keywords[12] =  {"silence", "unknown", "yes", "no", "up", "down", "left", "right", "on", "off", "stop", "go"};   // sounds corresponding to each numeric label 
  if(argc < 3){
    insufficientArguments();      // if number of arguments passed through command line is less than 3
    return 0;
  }
  try{
    pred_t* placeholder = new pred_t[3];              // placeholder for storing the resultant probabilities
    placeholder = libaudioAPI(argv[1], placeholder);  // getting the resultant probabilities in placeholder
    ofstream outputStream;                
    outputStream.open(argv[2],ios_base::app);         // open the output file (append all the outputs to previous content)
    outputStream<<"=> "<<setprecision(9)<<argv[1]<<" "<<keywords[placeholder[0].label]<<" "<<keywords[placeholder[1].label]<<" "<<keywords[placeholder[2].label]<<" "<<placeholder[0].prob<<" "<<placeholder[1].prob<<" "<<placeholder[2].prob<<"\n";
                                                      // printing the result
  }
  catch(string s){
    cout<<s;
  }

  return 0;
}

#FILE DETAILS 

libaudio.cpp 
- It contains pred_t structure (defined as per the instructions given on piazza) 
- This contains a function libaudioAPI to which given a path to input matrix, it will pass the matrix through DNN layers which will perform classification and store the 3 most probable values in placeholder of type pred_t*.

DNN.cpp
- It takes the path to the inputVectorFile (which will contain the contents of 1x250 vector)
- The float array inputMatrix will store the 250 values
- All the bias and weight matrices defined by macros in dnn_weights.h are used to initialize respective float array
- First we pass the input through 3 layers. Each layers multiplies the result of previous layer with corresponding weights , adds corresponding bias and applies relu.
- The final result is passed through a softmax layer to convert it into a vector of probabilities.

classfier.cpp

- It takes a probabilities array, along with its size and a pred_t array which is supposed to store the three maximum probabilities of type pred_t
- The probabilities arrays iterated over thrice and in each iteration the maximum value (and its corresponding index) is saved and then dumped (so that we can find the next maximum in the next iteration)
- Finally the extracted values and indices are stored in the placeholder array of type pred_t and is returned


relu.cpp
- It takes a matrix (which is stored as an array of floats in row or column major format), and the applies activation function to the matrix

softmax.cpp
- It takes a vector (which is stored as an array of floats ), and the applies softmax function to the matrix

inputoutput.cpp
- It is used to take input the 1x250 matrix/vector of features from a given file. 

helper.cpp 
- It contains helper functions for error handling.

#Error handling

- If the number of arguments in command line are less than 3, then "More number of arguments are required" is printed on the console and the program terminates gracefully

- If the input matrix filename does not exists then "Please check name of your file; unable to find <filename>" is printed on the console and the program terminates gracefully

- If the input file contains some values which cannot be converted to float (34.s21ds1232 for example) , then "Check the input matrix in file <filename>, 34.s21ds1232 cannot be converted to float"


-- test.sh is a bash script to automatically test for all files present in mfcc_features
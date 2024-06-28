//simple program that compares the magnitude of two vectors
//pracice of struct and methods
#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

struct vec{
    vector<float> scalars;
};

float mag(vec v){
    float scalarSquareSum = 0;
    for (float scalar : v.scalars){
        scalarSquareSum += pow(scalar,2);
    }
    return sqrtf(scalarSquareSum);
}

int main(){
   vec v1; 
   v1.scalars = vector<float>({1,2,3,4,5});
   vec v2;
   v2.scalars = vector<float>({1,2,3,4,5});
   cout << "The magnitude of the two vectors is " 
   << ((mag(v1) == mag(v2))? "equal." : "not equal.") << endl;
}
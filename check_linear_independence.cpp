//program to check linear independence between two vectors using the cauchy schwartz inequality

#include <stdio.h>
#include <iostream>
#include <math.h>
#include <tuple>
#include <vector>

using namespace std;

float magnitude(const vector<float>& vec){
    float sum = 0;
    for (float component:vec){
        sum += component*component;
    };
    return pow(sum,0.5);
}

float dotproduct(const vector<float>& v1, const vector<float>& v2){
    if(v1.size()!=v2.size()){
        return NULL;
    }
    else{
        float sum = 0;
        for (int i = 0; i < v1.size(); i++){
            sum += v1[i]*v2[i];
        }
        return sum;
    }
}

bool independent(const vector<float>& v1,const vector<float>& v2){
    //flanck constant, float comparison tolerance
    const float flanck = 1e-6;
    // if either vector is zero then dependant with any vector
    if (magnitude(v1) < flanck || magnitude(v2) < flanck){
        return false;
    }
    return ((abs(magnitude(v1)*magnitude(v2))-(dotproduct(v1,v2))) > flanck);
    }


int main(){
    vector<float> vec1 = {1.0,2.5,3.0};
    vector<float> vec2 = {1.0,2.0,4.0};      
    vector<float> vec3 = {2.0,5.0,6.0}; 
    cout << "vec1 and vec2 are " << (independent(vec1, vec2)? "independent" : "dependent") << endl;
    cout << "vec1 and vec3 are " << (independent(vec1, vec3)? "independent" : "dependent") << endl;
    return 0;
}
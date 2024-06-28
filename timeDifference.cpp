#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
using namespace std;

string stringDiff(int difference){
    string ans = "";
    vector<string> unitNames ({"second", "minute", "hour", "day", "month", "year"});
    vector<int> deflatorUnits ({12,30,24,60,60,60});
    vector<int> deflator({60});
    for (int c = 0; c < deflatorUnits.size(); c++){
        int x = deflatorUnits.at(c);
        deflator.push_back(x);
        for (int c1 = c ; c1 < deflatorUnits.size(); c1++){
            x*=deflatorUnits.at(c1);
        }
    }
    cout << "testing deflator values: " << endl;
    for (int dx : deflator){
        cout << dx << endl;
    }
    vector<int> unitValues (5);
    for (int d : deflator){
        unitValues.push_back(difference/d);
        //cout << difference << " " << d << " " << difference/d <<  " " << difference%d << endl;
        difference = difference % d;
        //cout << "new diff af mod : " << difference << endl;
        //if (difference == 0){
         //   continue;
        //}
    }
    for (int v = 0; v < unitValues.size(); v++){
       //ans.append(unitValues.at(v) + " " + unitNames.at(v) + (unitValues.at(v)>1?"s":"") + " ");
    }
    return ans;
}
int main(){
    //vector<int> testVals ({60,61,3601,(24*3600),(20*24*3600),(2*30*24*3600),(3*12*30*24*3600)});
    vector<int>testVals ({3601});
    for (int v : testVals){
        cout << v << " in words: " << stringDiff(v) << endl;
    }
    return 0;
}

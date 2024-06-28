#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
using namespace std;

string stringDiff(int difference){
    string ans = "";
    vector<string> unitNames ({"year", "month", "day", "hour", "minute", 
        "second"
    });
    vector<int> deflatorUnits ({12,30,24,60,60});
    vector<int> deflator({});
    for (int c = 0; c < deflatorUnits.size(); c++){
        int x = 1;
        for (int c1 = c ; c1 < deflatorUnits.size(); c1++){
            x*=deflatorUnits.at(c1);
        }
        deflator.push_back(x);
    }

    vector<int> unitValues ({}); //answers go here
    for (int dc = 0; dc < deflator.size(); dc++){
        int d = deflator.at(dc);
        if (difference >= d){ 
            unitValues.push_back(difference/d);
            difference %= d;
        }
        else{
            unitValues.push_back(0);
        }
    }
    //remaining seconds added
    unitValues.push_back(difference);
    
    for (int asd : unitValues){
    }
    for (int v = 0; v < unitValues.size(); v++){
       ans.append(to_string(unitValues.at(v)) + " " + unitNames.at(v) + ((unitValues.at(v)>1||unitValues.at(v)==0)?"s":"") + " ");
    }
    return ans;
}
int main(){
    vector<int> testVals ({60,61,3601,(24*3600),(20*24*3600),(2*30*24*3600),(3*12*30*24*3600 + 7200 + 3)});
    for (int v : testVals){
        cout << stringDiff(v) << endl;
    }
    return 0;
}

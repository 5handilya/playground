//simple program that turns int seconds into years, months, days, hours, minutes, seconds
//wrote this chilling/watching the US presidential debate 2024 (trump-biden)
//theyre saying they might change the democratic candidate
//28-6-24

#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
using namespace std;

string stringDiff(int inputSeconds){
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
        if (inputSeconds >= d){ 
            unitValues.push_back(inputSeconds/d);
            inputSeconds %= d;
        }
        else{
            unitValues.push_back(0);
        }
    }
    //remaining seconds added
    unitValues.push_back(inputSeconds);
    
    for (int v = 0; v < unitValues.size(); v++){
       ans.append((unitValues.at(v)==0)?"":(to_string(unitValues.at(v)) 
       + " " + unitNames.at(v) + (unitValues.at(v)>1?"s":"") + " "));
    }
    return ans;
}
int main(){
        int inp;
        cout << "Enter a number of seconds to convert into other units: (max 69 years)" << endl;
        cin >> inp;
        cout << stringDiff(inp) << endl;
    return 0;
}

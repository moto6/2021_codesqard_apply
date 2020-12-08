#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstdio>
#include "cube.hpp"
using namespace std;

const string PROMPT = "CUBE> ";
const bool DEBUG = 1; // 1:debug // 0:deploy
const int TESTMODULE = 5;
// 1 : init, print
// 2 : string to task
// 3 : Random shuffle function ->c_rsfl
// 4 : CMD_isValid -> bool CMD_isValid(char c) {
// 5 : Cube action 
Cube Chandler;




///////////////
int main(void) {
    c_init(&Chandler);
    string buf,testbuffer;
    queue<string> tasks;
    while (1) {
        
        cout << PROMPT;
        cin >> buf;

        if (buf == "Q" || buf == "q") {
            cout << "Bye~";
            break;
        }
        else {}


        vector<string> ins_v = c_s2task(buf);
        for (auto i : ins_v) {
            tasks.push(i);
        }

        
        //cube adjust && result print
        while (!tasks.empty()) {
            c_act(&Chandler, tasks.front());
            tasks.pop();
        }

    }
    return 0;
}





////FRR'U2R
// "F'","R'","U'","B'","L'","D'",
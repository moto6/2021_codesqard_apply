#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstdio>
#include <ctime>
#include "cube.hpp"
using namespace std;

const string PROMPT = "CUBE> ";
Cube Chandler;

int main(void) {
    
    time_t curTime, startTime;
    startTime = time(NULL);

    c_init(&Chandler);
    string buf,testbuffer;
    queue<string> tasks;
    int iter = 0;
    
    while (1) {
        
        cout << PROMPT;
        cin >> buf;

        if (buf == "Q" || buf == "q") {
            curTime = time(NULL);
		    cout << "Elapsed time : "<< to_string(curTime-startTime)<<endl; 
            cout << "Add implementation : " << endl;
            cout << "Number of operations : " << iter << endl;
            cout << "\nBye~";
            break;
        }
        else if (buf[0] =='T'){
            testapp((int)(buf[1]-'0'));
        }
        else {
            vector<string> ins_v = c_s2task(buf);
            for (auto i : ins_v) {
                tasks.push(i);
            }
            
            //cube adjust && result print
            while (!tasks.empty()) {
                string action_item = tasks.front();
                c_act(&Chandler, action_item);
                cout << "\n\n" << action_item<<endl;
                tasks.pop();
                c_print(&Chandler);
                iter++;
            }
            iter--;
        }
        iter++;
    }
    return 0;
}





////FRR'U2R
// "F'","R'","U'","B'","L'","D'",
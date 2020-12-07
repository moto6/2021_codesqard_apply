#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include "cube.hpp"
#include "cube.cpp"
using namespace std;

const string PROMPT = "CUBE> ";

int main(int argc, char* argv[]) {
    string buf;
    queue<string> tasks;
    while (1) {
        cout << PROMPT;
        cin >> buf;
        
        if (buf == "Q" || buf == "q") {
            cout << "Bye~";
            break;
        }
        else {}

        //string to task
        // UUR -> U,U,R
        //task
        vector<string> ins_v = c_s2task(buf);
        for(auto i:ins_v) {
            tasks.push(i);
        }

        //cube adjust && result print
        while (!tasks.empty()) {
            c_act(tasks.front());
            tasks.pop();
        }
    }
    return 0;
}


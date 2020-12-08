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
    vector<string> ins_v
    int iter = 0;
    
    while (1) {
        
        cout << PROMPT;
        cin >> buf;

        if (buf == "Q" || buf == "q") {
            curTime = time(NULL);
		    cout << "Elapsed time : "<< to_string(curTime-startTime)<<endl; 
            cout << "Additional implemented functions : " << endl;
            cout << "\tRandom Shuffle //  Time Display // Fit all sides"<<endl;
            cout << "Number of operations : " << iter << endl;
            cout << "\nBye~";
            break;
        }
        else if (buf[0] =='T'){// 테스트 케이스 돌리기
            testapp((int)(buf[1]-'0'));
        }
        else {

            //입력 처리
            if (buf =="@"){//큐브의 무작위 섞기 기능
                ins_v = c_rsfl();
                for (auto i : ins_v) {
                    cout << i <<endl;
                    tasks.push(i);
                }
            }
            else {
                ins_v = c_s2task(buf);
                for (auto i : ins_v) {
                    tasks.push(i);
                }
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
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
Cube Chandler;

int main(void) {
    
    time_t startTime = time(NULL);
    string buf,testbuffer;
    queue<string> tasks;
    vector<string> ins_v;
    
    cout << "\n\n=====  Rubik's Cube Simulation  =====\n";
    cout << "H : help  // Q : Exit \n"<<endl;
    c_init(&Chandler);
    int iter = 0;
    
    while (1) {
        
        cout << PROMPT;
        cin >> buf;

        if (buf == "Q" || buf == "q") {         // Q : 종료기능
            c_finalize(&startTime, iter);
            break;
        }
        else if (buf[0] =='T'){                 // T# : 테스트 케이스
            testapp((int)(buf[1]-'0'));
            iter = 0;//테스트시 iter 0초기화
            //T1명령어 사용으로 큐브를 초기화하는경우, 프로그램이 의도치않게 종료됨
        }
        else if (buf =="@"){                    // @ : 무작위 섞기 기능
            ins_v = c_rsfl();
            cout << "Random Shuffle :";
            for (auto i : ins_v) {
                cout << i <<' ';
                tasks.push(i);
            }
        }
        else if(buf == "help" || buf == "H") {  // H : 도움말
            c_helper();
        }
        else {                                  // 이외 : 입력받은 문자로 큐브동작
            ins_v = c_s2task(buf);
            for (auto i : ins_v) {
                tasks.push(i);
            }
        }


        //입력받은 명령어를 처리하여 큐브를 변경
        while (!tasks.empty()) {
            string action_item = tasks.front();
            c_act(&Chandler, action_item);
            cout << "\n\n" << action_item<<endl;
            tasks.pop();
            c_print(&Chandler);
            iter++;
        }

        if(is_Fitallsides(&Chandler) && iter>=1) {
            cout << "\n\n ====== Congratulations! =====\n";
            cout << "You have hit all faces!\n";
            cout << "this program will close automatically.\n\n\n";
            c_finalize(&startTime, iter);
            break;
        }
    }
    return 0;
}
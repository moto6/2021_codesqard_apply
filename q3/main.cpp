#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstdio>
using namespace std;


/*
typedef char cSide[3][3];

struct mcube {
    cSide top;
    cSide m1;
    cSide m2;
    cSide m3;
    cSide m4;
    cSide bot;
}typedef Cube;
*/

struct _mycube {
    char top[3][3];
    char si1[3][3];
    char si2[3][3];
    char si3[3][3];
    char si4[3][3];
    char bot[3][3];
}typedef Cube;
typedef char cSide[3][3];




bool CMD_isValid(char c);
int c_act(string s);
vector<string> c_s2task(string s);
int c_rsfl();
void c_print(Cube* handler);
void c_init(Cube* handler);

/////////////////////////////////////





//
const string PROMPT = "CUBE> ";
Cube Chandler;




///////////////
int main(void) {
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


        //test
        c_init(&Chandler);
        c_print(&Chandler);
        /*

        //string to task : UUR -> U,U,R
        vector<string> ins_v = c_s2task(buf);
        for(auto i:ins_v) {
            tasks.push(i);
        }

        //cube adjust && result print
        while (!tasks.empty()) {
            c_act(tasks.front());
            tasks.pop();
        }
        */
    }
    return 0;
}



void c_init(Cube* handler) {
    cSide* ptr = &(handler->top);
    const char initdata[] = "BWOGYR";
    for (int k = 0; k < 6; k++) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                ptr[k][i][j] = initdata[k];
            }
        }
    }

}


void c_print(Cube* handler) {
    //cube print
    //cube_handler
    cSide* csp = &(handler->top);
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                cout << csp[i][j][k] << ' ';
            }
            cout << endl;
        }
        if (i == 0 || i == 4) {
            cout << "\n\n" << endl;
        }
        
    }

    return;
}

int c_rsfl() {
    //cube random shuffle
    return 0;
}

vector<string> c_s2task(string s) {

    int len = s.length();
    vector<string> ret;

    for (int i = 0; i < len; i++) {
        if (s[i + 1] == '\'') {
            //prime case
            if (CMD_isValid(s[i])) {
                ret.push_back(s.substr(i, 2));
                i++;
            }

        }
        else if ('0' <= s[i + 1] && s[i + 1] <= '9') {
            //주의 : 한자리 숫자 반복만 지원함.
            if (CMD_isValid(s[i])) {
                int rep = 0;
                rep = (int)(s[i + 1] - '0');
                for (int i = 0; i < rep; i++) {
                    ret.push_back(s.substr(i, 2));
                }
                i++;

            }

        }
        else {
            //nomal case
            string stmp = s.substr(i, 1);
            ret.push_back(stmp);
        }

    }
    return ret;

}

int c_act(string s) {
    //명령에 따라서 큐브를 실제로 동작시킴
    return s.length();

}


bool CMD_isValid(char c) {
    const static char CMD_LIST[] = "FRUBLD";//len = 6
    for (int i = 0; i < 6; i++) {
        if (c == CMD_LIST[i]) {
            return true;
        }
    }
    return false;
}


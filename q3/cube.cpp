#include <vector>
#include <string>
#include <iostream>
using namespace std;
#ifndef _cube_h_
#define _cube_h_

struct _mycube {
    char top[3][3];
    char si1[3][3];
    char si2[3][3];
    char si3[3][3];
    char si4[3][3];
    char bot[3][3];
}typedef Cube;


int c_print (Cube * _mycube) {
    //cube print
    return 0;
}

int c_rsfl() {
    //cube random shuffle
    return 0;
}

vector<string> c_s2task(string s) {
    s.length();
	int len = s.length();
	vector<string> ret;

	for (int i = 0; i < len; i++) {
		if (s[i + 1] == '\'') {
            //prime case
            if(CMD_isValid(s[i])) {
                ret.push_back(s.substr(i,2));
                i++;
            }
            
		}
        else if('0'<= s[i+1] && s[i+1] <='9') {
            //주의 : 한자리 숫자 반복만 지원함.
            if(CMD_isValid(s[i])) {
                int rep=0;
                rep = (int)(s[i+1]-'0');
                for(int i=0 ; i<rep ; i++) {
                    ret.push_back(s.substr(i,2));
                }
                i++;
                
            }

        }
		else {
			//nomal case
			string stmp = s.substr(i,1);
			ret.push_back(stmp);
		}
		
	}
	return ret;

}

int c_act (string s) {
    //명령에 따라서 큐브를 실제로 동작시킴
    
}


bool CMD_isValid(char c) {
    const static char CMD_LIST[] = "FRUBLD";//len = 6
    for(int i=0 ; i<6 ; i++) {
        if(c == CMD_LIST[i]) {
            return true;
        }
    }
    return false;
}



#endif //_cube_h
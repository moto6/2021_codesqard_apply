#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <cstdlib>//for atoi
#include <algorithm>

using namespace std;


//Structs
struct wordpushpull {
	string word;
	int dist;
	char cmd;
}typedef WP;


//Functions
WP tok_parser(string s);
string pusher(WP ins);


//consts
const string PROMPT = "> ";

int main() {
	string buf;
	
	while (1) {
		cout << PROMPT;
		getline(cin, buf);
		if (buf == "-1" || buf == "q" || buf == "0") {
			cout << "ByeBye!";
			break;
		}
		else {
			//continue
		}

		WP input = tok_parser(buf);
		string ans = pusher(input);

		cout << ans << endl;
		
	}
		
}

WP tok_parser(string s) {
	//in : string 
	//out : WP struct
	//tokenizer
	
	vector<int> bp;//blank point , location of blank
	WP ret;
	int len = s.length();
	int ord = 0;
	
	for (int i = 0; i < len; i++) {
		if (s[i] == ' ') {
			bp.push_back(i);
		}
	}
	if(bp.size() != 2) {
		ret.cmd = 'e';
	}

	//0 ~ pt1 : 
	ret.word = s.substr(0, bp.at(0));


	//pt1 ~ pt2 : 
	string temp = (s.substr(bp.at(0), bp.at(1)));
	ret.dist = atoi(temp.c_str());
	
	
	//pt2 ~ end
	ret.cmd = s[bp.at(1) + 1];

	return ret;
}

string pusher(WP ins) {
	//in : wp struct
	//out : result of 
	string ret,tmp;
	string ori = ins.word;
	stack<char> s;
	int len = ori.length();//문자열 길이
	
						   
	//입력값 간소화
	if (ins.dist < 0) {
		ins.dist = ins.dist * -1;
		if (ins.cmd == 'r' || ins.cmd == 'R') {
			ins.cmd = 'L';
		}
		else if (ins.cmd == 'l' || ins.cmd == 'L') {
			ins.cmd = 'R';
		}
		else if (ins.cmd == 'e') {
			ret = "unknowon command inserted";
			return ret;
		}
	}
	if(ins.dist >= len) {
		ins.dist = ins.dist % len;
	}
	int num = ins.dist;//밀어내는 거리
	if (num == 0) {
		return ori;
	}

	
	if (ins.cmd == 'r' || ins.cmd == 'R') {
		tmp = ori.substr(0, len - num);
		ori = ori.substr(len-num, num);

		ret =ori+ tmp;

	}
	else if (ins.cmd == 'l' || ins.cmd == 'L') {
		tmp = ori.substr(num, len - num);
		ori = ori.substr(0, num);

		ret = tmp + ori;
	}
	else {
		ret = "unknowon command inserted :";
		ret += ins.cmd;
		
	}
	return ret;
}

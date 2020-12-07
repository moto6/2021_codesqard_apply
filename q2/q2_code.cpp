#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;


char map[3][3] = { 0,};

//consts
const string PROMPT = "CUBE> ";

//functions
void do_cube(string cmd);
queue<string> str2task(string s);

int main() {
	
	string buf,cmd;
	queue<string> task;
	//input
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> map[i][j];
		}
	}


	while (1) {
		cout << PROMPT;
		//getline(cin, buf);
		cin >> buf;
		if (buf == "Q" || buf == "q") {
			cout << "Bye~";
			break;
		}
		else {}

		//string to task
		// UUR -> U,U,R
		task = str2task(buf);

		//cube adjust && result print
		while (!task.empty()) {
			cmd = task.front();
			do_cube(cmd);
			task.pop();
		}
	}
}

void do_cube(string cmd) {
	//확장성이 영 별로입니다 ㅠㅠ..
	//리팩토링을 한다면 deque를 사용
	cout << cmd << endl;
	char swap;
	//map[yi][xj];
	//커맨드에 맞게 큐브를 움직임
	if (cmd.length() == 2 && cmd[1] == '\'') {
		
		//U'
		if (cmd == "U'") {
			swap = map[0][0];
			map[0][0] = map[0][1];
			map[0][1] = map[0][2];
			map[0][2] = swap;
		}

		//R'
		if (cmd == "R'") {
			swap = map[2][2];
			map[2][2] = map[1][2];
			map[1][2] = map[0][2];
			map[0][2] = swap;
		}

		//L'
		if (cmd == "L'") {
			swap = map[2][0];
			map[2][0] = map[1][0];
			map[1][0] = map[0][0];
			map[0][0] = swap;
		}

		//B'
		if (cmd == "B'") {
			swap = map[2][2];
			map[2][2] = map[2][1];
			map[2][1] = map[2][0];
			map[2][0] = swap;
		}
	}
	else if(cmd.length() == 1) {
		//U
		if (cmd == "U") {
			swap = map[0][2];
			map[0][2] = map[0][1];
			map[0][1] = map[0][0];
			map[0][0] = swap;
		}

		//R
		if (cmd == "R") {
			swap = map[0][2];
			map[0][2] = map[1][2];
			map[1][2] = map[2][2];
			map[2][2] = swap;
		}

		//L
		if (cmd == "L") {
			
			swap = map[0][0];
			map[0][0] = map[1][0];
			map[1][0] = map[2][0];
			map[2][0] = swap;
		}


		//B
		if (cmd == "B") {
			swap = map[2][0];
			map[2][0] = map[2][1];
			map[2][1] = map[2][2];
			map[2][2] = swap;
		}
		
	}
	else {
		cout << "unknowun command : ";
		cout << cmd <<", re-enter!" <<endl;

	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << endl;
}


queue<string> str2task(string s) {
	s.length();
	int len = s.length();
	queue<string>ret;

	for (int i = 0; i < len; i++) {
		if (s[i + 1] != '\'') {
			if (s[i] == 'U' || s[i] == 'R' || s[i] == 'L' || s[i] == 'B') {
				//char tmp = s[i];
				ret.push(s.substr(i,1));
			}
			else {
				//drop
			}
		}
		else {
			//prime case
			string stmp = s.substr(i, 2);
			ret.push(stmp);
			i++;
		}
		
	}
	return ret;
}

//TC
/*

U'L'LLBB'BU


*/
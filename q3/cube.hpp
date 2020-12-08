#ifndef __CUBE_H__
#define __CUBE_H__

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstdio>
#include <ctime>
using namespace std;

struct _mycube {
    char top[3][3];
    char m1[3][3];
    char m2[3][3];
    char m3[3][3];
    char m4[3][3];
    char bot[3][3];
}typedef Cube;
typedef char cSide[3][3];

void testapp(int mod);
bool CMD_isValid(string cin);
int c_act(Cube* c,string s);
void c_print(Cube* handler);
void c_init(Cube* handler);
void c_finalize(time_t *startTime, int iter);
vector<string> c_s2task(string s);
vector<string> c_rsfl();
void c_helper(void);
bool is_Fitallsides(Cube* handler);

#endif // __CUBE_H__
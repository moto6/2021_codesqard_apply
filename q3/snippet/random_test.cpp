#include <random>
#include <iostream>
#include <vector>
#include <string>


//
#include <cstdlib>
#include <ctime>

//
using namespace std;

int main() {
	

	//random_device rd;
    //minstd_rand gen(rd());
    //mt19937 gen(rd());
    
    //uniform_int_distribution<int> dis(0, 99);
    
    vector<string> add_task;//cube random shuffle
    //char sub[] = "FRUBLD";
    string cmdlist[10]= {"R","U","L","B","F'","R'","U'","B'","L'","D'"};  
    
	srand((unsigned int)time(NULL));

	int count = rand();
    count = count%17;

    for (int i = 0; i < 5+count; i++) {
        add_task.push_back(cmdlist[rand()%10]);
    }
    
    
    ///answer
    //return add_tast;
    
    for(auto i :add_task) {
    	cout << i << "  ";
	}
    while(1) {
    	getchar();
    	cout << rand() << endl;
	}
    return 0;
    
}

// Collatz.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <vector>

using namespace std;

int globalCounter = 0;

inline void print(vector<int> l){
	for(int i = 1; i < l.size(); i++){
		cout << i << " escapes in " << l[i] << " iteration" << (l[i] == 1?"":"s") << endl;
	}
}

//writes the variable into the global variable.  When this exits, retrieve the value from the global variable
//as the correct answer to all the function calls needed for this iteration of Collatz.
void Collatz(int i){
	if(i == 1){
		return;
	}
	if(i % 2 == 0){
		Collatz(i / 2);
	}else{
		Collatz( 3 * i + 1);
	}
	++globalCounter;
}

int main(int argc, char* argv[])
{
	int n;
	cout << "How many Collatz numbers do you want to compute? ";
	cin >> n;

	//add 1 for the ignored 0 index
	n++;

	//the index in the vector will be the number being tested, the value at that index is the collatz number
	vector<int> list(n, 0);

	for(int i = 1; i < list.size(); i++){
		globalCounter = 0;
		Collatz(i);
		list[i] = globalCounter;
	}
	print(list);
	//await dummy input so the prompt doesn't close
	int junk;
	cin >> junk;
}


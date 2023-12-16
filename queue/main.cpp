#include <iostream>
#include <string>
#include <thread>
#include "queue.h"

using namespace std;

int main()
{
	
	TQueue<int> testst(5);
	int n = 10000000;
	auto start = chrono::high_resolution_clock::now();
	
	for (int i = 0; i < n; i++) {
		testst.Push(i);
		testst.Pop();
	}

	auto end = chrono::high_resolution_clock::now();
	chrono::duration<float> d = end - start;
	cout << d.count();
	 return 0;
}

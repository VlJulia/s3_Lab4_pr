#include <iostream>
#include <string>
#include "queue.h"

using namespace std;

int main()
{
	TQueue<int> testst(5);
	testst.Push(2);
	testst.Push(4);
	testst.Push(6);
	testst.Push(8);
	cout << testst<<endl;
	cout << "\nfirst " << testst.Get() << endl;
	

	cout << "test 1" << endl;

	int a = testst.Pop();
	cout << testst <<endl;
	cout << "\nPop was " << a << endl;
	cout << "\nfirst " << testst.Get() << " empty " << testst.IsEmpty() << endl;

	cout << "\ntest 2" << endl;
	testst.Pop();
	testst.Pop();
	testst.Pop();
	cout << testst << endl;
	cout << "\n empty " << testst.IsEmpty() << endl;
	
	 return 0;
}

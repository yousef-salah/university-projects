#include <iostream>
using namespace std;


int sumArray(int* X) {
	int* xptr;
	int sum = 0;
	for (xptr = &X[0]; xptr <= &X[99]; xptr++) sum += *xptr;
	return sum;
}


int main()
{
	int x[100];
	for (int i = 0; i < 100; i++)
	{
		x[i] = 1;
	}
	cout << sumArray(x);

	return 0;
}


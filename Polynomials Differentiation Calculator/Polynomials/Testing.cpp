
#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;



int sumArray(int* X) {
	int* xptr;
	int sum = 0;
	for (xptr = &X[0]; xptr <= &X[99]; xptr++) sum += *xptr;
	return sum;
}


int amain()
{
	int x[100];
	int j = 0;
	int ja = 0;
	for (int i = 0; i < 100; i++)
	{
		x[i] = 1;
	}
	//cout << sumArray(x);

	cout << x << endl;
	cout << x + 1 << endl;
	cout << &j << endl;
	cout << &ja << endl;


	return 0;
}

int main()
{
	char B[] = "Yousef";
	char* BPtr = B;
	int x[10];
	int * xPtr = x;

	cout << x << endl;
	cout << *B + 1 << endl;

	cout << *BPtr << endl;
	cout << &BPtr << endl;



	cout << "++++++++++++++++++++++++++++++++++++" << endl;
	cout << x <<endl;
	cout << &x << endl;
	cout << &x[0] << endl;
	
	
	
	
	
	return 0;
}


void printX(int x[])
{
	cout << sizeof(x);
}

void testing(int a[]);

int _main()
{
	/*
	const int Abed = 18;

	const int*  AbedPtr = &Abed;
	AbedPtr = NULL;
	cout << PI << endl;
	#undef PI
	#define PI 2.2
	cout << PI << endl;


	int y = 5;
	int* yPtr = &y;

	printf("%p", yPtr);
	cout << endl;
	printf("%p", &yPtr);
	cout << endl << "L " << yPtr << endl;
	*/

	/*
	int x = 5;
	int* xPtr = &x;

	cout << (*xPtr)++ << endl; 
	cout << *xPtr<< endl;
	*xPtr++;
	cout << *xPtr;

	xPtr = NULL;
	cout << *xPtr << endl; // RTE
	const int z = 5;
	int a[(int)PI];

	cout << *&x << endl;

	int p = PI;
	p = PI;
	cout << p;

	*/

	/*int x = 5;
	const int* xPtr = &x;
	(* xPtr++);
	cout << *xPtr;*/

	/*int a[] = { 1,5,7 };
	const int * aPtr = a;
	
	(aPtr)++;
	cout << *aPtr;
	cout << ++*a;
	*/

	/*int x = 5;
	int z, g, w, t;
	double y = 10;
	int* xPtr = &x;
	double* yPtr = &y;

	cout << yPtr << endl;
	cout << (yPtr - (double *)xPtr);*/

	//double x = 5;
	//double y = 3.3;

	//double* xPtr = &x;
	//double* yPtr = &y;

	

	//cout << sizeof(xPtr) << endl;
	//cout << sizeof(yPtr) << endl;

	//cout << &xPtr << endl;
	//cout << ((int * )&*xPtr)<< endl;
	//cout << &x << endl;


	//int x = 5;
	//cout << *&x;

	 
	//typedef int * intPointer;
	//intPointer xPtr;
	//cout << typeid(xPtr).name();
	
	//	int& y = x;
	//y++;

	//int a{ 5 };
	//cout << a;

	//int x[5] = { 1, 22, 3, 4, 5 };
	//int * xptr = x;
	//testing(x);

	//cout << *(++xptr) << endl;
	//xptr--;
	//cout << *(xptr + 1);
	//cout << *xptr << endl;

	//printf("%p", x);
	
	
	//(x == &x[0]) ? cout << "Equal" : cout<<"Not Equal";

	/*
	cout << x << endl;
	cout << &x << endl;
	cout << &x[0] << endl;
	cout << sizeof(x) << endl;
	printX(x);
	char* ch;
	cout <<endl<< sizeof(ch);
	*/

	//void* ptr = &x;
	//cout << typeid(ptr).name() << endl;
	//cout << static_cast<int *>(ptr) << endl;
	//cout << *(int * )ptr;

	
	double y = 5;
	int x = 5;


	int* xPtr = &x;
	double * yPtr = &y;

	if (xPtr < (int *)yPtr) cout << "YES" << endl;
	else cout << "NO" << endl;

	cout << xPtr << endl;
	cout << yPtr << endl;
	
	
	//system("pause");
	return 0;
}


void testing(int a[])
{
	//int x = 5;

	//cout << x << endl;
	//cout << *&x << endl;
	cout << *a++ << endl;
	a--;
	cout << *(a++) << endl;
	cout << *((--a)++) << endl;
	//a--;
	cout << *a++ << endl;
	cout << *a << endl;


	//cout << *a + 2;
	
	
	//cout << *(++a) << endl;
	//cout << typeid(a).name();

	/*for (int i = 0; i < 5; i++)
	{
		cout << a[i];
		cout << *(a + i);
		cout << endl;
	}*/
}



/*
print the values above diagonal


int a[4][4] = {
		{1,2,3,4},
		{5,6,7,8},
		{9,10,11,12},
		{13,14,15,16},
	};

	for (int i = 0; i <= 3; i++)
	{
		for (int j = 0; j <= 3; j++)
		{
			if (i < j) cout << a[i][j] << endl;
		}
	}


*/

/*

Array multiblication.

int C[2][3] = {
		{1,2,3},
		{4,5,6}
	};

	int B[3][2] = {
		{10,11},
		{20,21},
		{30,31}
	};
	int A[2][2];


	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			int sum = 0;
			for (int k = 0; k < 3; k++)
			{
				sum += B[k][j] * C[i][k];
			}
			A[i][j] = sum;
			cout << A[i][j] << endl;
		}
	}


*/
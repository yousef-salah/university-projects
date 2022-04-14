#include <iostream>

using namespace std;


void passArrayOfChar(char*  name)
{
	cout << "The second char is: " << *( name + 1) << endl;
	cout << "The name  is: " << name[2] << endl;
}

int main()
{

	char name[] = { "yousef" };
	passArrayOfChar(name);
}

////
////	Question => 1
////

/*
#include <iostream>

using namespace std;

bool isContains(int[], int, int);

int main()
{
	int arr[5];
	int x;

	cout << "Enter 5 integers: " ;

	for (int i = 0; i < 5; i++) {
		cin >> arr[i];
	}

	cout << "Enter an integer to search for: ", cin >> x;

	if (isContains(arr, 5, x)) {
		cout << x <<  " is in The array of numbers";
	}
	else cout << x << " is not in the array";
	
}


bool isContains(int arr[], int size, int number)
{
	for (int i = 0; i < size; i++){
		if (arr[i] == number) return true;
	}
	return false;
}



*/

////
////	Question => 2
//// 

/*

#include <iostream>

using namespace std;

bool magicSquareMatrix(int[][3], int);
int horizontalSummation(int[], int);
int verticalSummation(int[][3], int, int);

//int diagonalSummation(int[][3], int);

int rightDiagonal(int[][3], int);
int leftDiagonal(int[][3], int);

int sum = 0;

int main()
{
	int arr[3][3];

	cout << "Enter a 3x3 matrix of integers: ";

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >>  arr[i][j];
		}
	}

	if(magicSquareMatrix(arr, 3)){
		cout << "The matrix is a magic matrix with a magic constant " << horizontalSummation(arr[0],3);
	}
	else cout << "No";

	return 0;
}

// check if a matrix is a magic matrix. 
bool magicSquareMatrix(int arr[3][3], int size) 
{
	for (int i = 0; i < size; i++) {
		if (horizontalSummation(arr[i], 3) != verticalSummation(arr, size, i)) {
			return false;
		}
	}
	
	if (rightDiagonal(arr, size) !=  leftDiagonal(arr, size)) {
		return false;
	}

	if (rightDiagonal(arr, size) != horizontalSummation(arr[0], 3)) {
		return false;
	}
	
	return true;
}

int horizontalSummation(int arr[], int size)
{
	sum = 0;
	for (int i = 0; i < size; i++) {
		sum += arr[i];
	}
	return sum;
}


int verticalSummation(int arr[][3], int size, int column)
{
	sum = 0;
	for (int i = 0; i < size; i++) {
		sum += arr[i][column];
	}
	return sum;
}


// "/"
int rightDiagonal(int arr[][3], int size)  
{
	sum = 0;
	for (int i = 0, j = size -1 ; i < size and j >=0 ; i++,j--) {
			sum += arr[i][j];
	}
	return sum;
}
 // "\"
int leftDiagonal(int arr[][3], int size)
{
	sum =0;
	for (int i = 0; i < size; i++) {
		sum += arr[i][i];
	}
	return sum;
}

// i   j 
// 0   2
// 1   1
// 2   0


*/
/**
* Derivative Calculator.
* 
* @file PolynomialsDerivatives.cpp
* @author Yousef Salah Khodroj
* @version 1.1
*/

#include <iostream>
#include <math.h>     // ** just for pow() method

using namespace std;

int cofficient(char exp[]);
int casting(char character);
int exponent(char exp[]);
int arraySize(char exp[]);
int findIndex(char exp[], char character);
int arrOfCharToInt(char exp[], int start, int finish);
int numberOfDigits(int number); 

bool isConstant(char exp[]);
bool isConains(char character, char arr[]);

void polyTerms(char expression[][15]);
void split(char input[], char exp[][15], char options[]);
void derivative(char exp[][15]);
void Delete(char exp[]);
void setValueAfterDerivative(char exp[], int coff, int expo);
void secondDerivative(char expression[][15]);
void printMenue();
void swapArray(char exp[][15], int & index);
void printTwoDimensionalArray(char expression[][15]);

int _1main()
{   
    char option = 'o';
    char input[150];
    char expression[10][15] = { NULL };  // 10 polynomials with 15 Characters length for everyone.
    char operators[] = { '+' , '-', '\0' };

 
    printMenue();

    while (option != '9') {
        cout << endl;
        cout << "  Enter the operation : ";
        cin >> option; 
        cout << endl;

        switch (option) 
        {
            case '1':
                for (int counter = 0; expression[counter][0]; counter++) Delete(expression[counter]);
                cout << "  Please Insert the polynomial in its proper format  : " , cin >> input;
                cout << endl;
                split(input, expression, operators);
                break;

            case '2':  // return all the terms of a polynomial as a single line string
                cout << "    Polynomial = " ;
                printTwoDimensionalArray(expression);
                break;

            case '3':
                derivative(expression);
                cout << "    first Derivative = ";                 // for indentation
                printTwoDimensionalArray(expression);
                break;

            case '4':
                secondDerivative(expression);
                cout << "    Second Derivative = ";                 // for indentation
                printTwoDimensionalArray(expression);
                break;

            case '5':
                polyTerms(expression);
                break;

            case '6':
                printMenue();
                break;

            case '9':
                cout << "    Thanks for using our program :)" << endl;
                cout << "    have a nice day  :)" << endl;
                return 0;

            default:
                    cout << "    Invalid input!!!";
                    break;
        }

        cout << endl;
    }
    
    return 0;
}

/**
* Return The Cofficient value of Expression.
* 
* @param Array of Characters Represents part of Polynomail.
* 
* @return Intger Represent the Value of Cofficient.
*/
int cofficient(char exp[])
{
    int index = findIndex(exp, 'x');
    
    return arrOfCharToInt(exp, 0, index);
}

/**
* Return The Exponent Value of Expression.
* 
* @param Array of Characters Represents part of Polynomail.
* 
* @return Intger Represent the Value of Exponent.
*/
int exponent(char exp[]) 
{
    int sum = 0;
    int index = findIndex(exp, 'x');

    if (isConstant(exp)) return 0;

    if (!exp[index + 1]) { // '^'
        return 1;
    }
    index += 2;  //  'x^1'
    
    return arrOfCharToInt(exp, index, arraySize(exp));
}

/**
* Convert number fron character form 
* to Integer form.
* 
* @param Character Represent Number.
* 
* @return value of this number.
*/
int casting(char character)
{
    return ((int)character - 48);
    // return  ?? - '0'
}

/**
* Return Size of passed Array 
* depands in its sequential of non-null values.
* 
* @param Array of Character.
* 
* @return Integer Represent the Size of Passed Array.
*/
int arraySize(char exp[]) 
{
    int counter = 0;
    for (counter = 0; exp[counter]; counter++);
    return counter;
}

/**
* Function split one Dimensional Array to Two Dimensional Array
* by depands on Operator Array.
* 
* @param Array of Characters.
* @param Array of Arrays of Characters.
* 
* @return void.
*/
void split(char input[], char exp[][15], char operators[]) // insert values in array 
{
    int polyCount = 0;                                     // polyCount =>  polynomials Counter
    int splittedArrayIndex = 0;                            // splittedArrayIndex point to index in 2d array 

    for (int inputIndex = 0; input[inputIndex]; inputIndex++)
    {
        if (isConains(input[inputIndex], operators) and inputIndex) {
                
            exp[polyCount][splittedArrayIndex] = '\0';
            
            //get the sign and put it at first index in the next term
            polyCount += 1;
            exp[polyCount][0] = input[inputIndex];
            splittedArrayIndex = 1;                // start insert after sign ( + , -)
                
        } else {
            exp[polyCount][splittedArrayIndex] = input[inputIndex];
            splittedArrayIndex++;
        }   
    }

    //exp[polyCount][splittedArrayIndex] = '\0';
}

/**
* Return true when Expression is Constant i.e. whet x have zero Exponent.
* 
* @param Array of Characters.
* 
* @return boolean True if is constant, else that false.
*/
bool isConstant(char exp[]) 
{
    for (int index = 0; exp[index]; index++) {
        if (exp[index] == 'x') return false;
    }

    return true;
}

/**
* Return index of 'x' or size of array if Expression is Constant.
* 
* @param Array of Characters.
* 
* @return Integer index of passed character or size of passed array.
*/
int findIndex(char exp[], char character)
{   
    int index = 0;
    for (; exp[index]; index++) {
        if (exp[index] == character) return index;
    }
    return index;
}

/**
* print the cofficient and exponent of expression as (cofficient , exponent) notation.
* 
* @param Array of Arrays of Characters.
* 
* @return void.
*/
void polyTerms(char expression[][15])
{
    for (int counter = 0; expression[counter][0]; counter++) 
    {
        cout  << "    " << expression[counter] << "  =>      " << "( " << cofficient(expression[counter]) << " , ";
        cout << exponent(expression[counter]) << " )" << endl;
    }
}

/**
* Find Derivative of Given Expression and Save it in the same Array.
* 
* @param Array of Arrays of Characters.
*
* @return void.
*/
void derivative(char expression[][15])
{
    for (int poly = 0; expression[poly][0]; poly++) {

        if (isConstant(expression[poly])) {

            Delete(expression[poly]);
            swapArray(expression, poly);
        }
        else {
            int coff = cofficient(expression[poly]);
            int expo = exponent(expression[poly]);

            coff = coff * expo;
            expo--;

            setValueAfterDerivative(expression[poly], coff, expo);
        }
    }
}

/**
* Set value of Term after Derivative in one Dimensional Array.
* 
* @param Array of Characters.
* @param Integer Cofficient.
* @param Integer Exponent.
* 
* @return void.
*/
void setValueAfterDerivative(char exp[], int coff, int expo)
{
    Delete(exp);  // delete current term to build it again after derivative.

    int index = 0;

    if (coff > 0) {
        exp[index] = '+';

    } else {
        exp[index] = '-';
        coff = coff *  -1;
    }

    index++;

    int coffDigits = numberOfDigits(coff);                  // number of digits in specific number.

    for (int cell = coffDigits; cell >= index; cell--) {
        int numInAsci = (coff % 10) + 48;
        exp[cell] = (char)numInAsci;                        // explicit casting (int => char)
        coff /= 10;
    }

    index += coffDigits;                                    // last index in array.

    if (expo > 0) {
        int expoDigits = numberOfDigits(expo);
        exp[index] = 'x';
        if (expo > 1) { 
            exp[++index] = '^';

            for (int cell = expoDigits + index; cell > index; cell--) {
                exp[cell] = (char)((expo % 10) + 48);
                expo /= 10;
            }
        }
    }
}

/**
* Return the Number of Digits of Given Number.
* 
* @param Integer Number.
* 
* @return Integer Number of Digits.
*/
int numberOfDigits(int number)
{
    int digitsCounter = 0;
    for (; number; digitsCounter++) {
        number /= 10;
    }
    return digitsCounter;
}

/**
* Delete All Character in passed Array depands in its sequential of non-null values.
* 
* @param Array of Characters.
* 
* @return void.
*/
void Delete(char exp[])
{
    for (int cell = 0; exp[cell]; cell++) {
        exp[cell] = NULL;
    }
}

/**
* Return the integer value of part of  passed Array form start to finish.
* 
* @param Array of Characters.
* @param Integer start from.
* @param Integer finish.
* 
* @return Integer.
*/
int arrOfCharToInt(char exp[], int start, int finish)
{
    double sum = 0;
    int  isNegative = 1;

    if (exp[start] == '-') { // check if the value is negative value.
        isNegative = -1;
        start++;
    }
    if (exp[start] == '+') start++; // '+'

    if ((start == finish) and !isConstant(exp)) { // 'x' '-x' '+x'
        return (1 * isNegative);
    }
    
    for (; start < finish ; start++) {
        sum += pow(10, ((finish - start) -1 )) * casting(exp[start]);
    }

    return ((int)sum * isNegative);
}

/**
* Find the Second Dervative of Given Term.
* 
* @param Array of Arrays of Characters.
* 
* @return void.
*/
void secondDerivative(char expression[][15])
{
    // check #######################
    derivative(expression);
}

/**
* Back shift Array in Two Dimensional Array
* One Step Back starts form index.
* 
* @param Array of Arrays of Characters.
* @param Integer & index.
* 
* @return void.
*/
void swapArray(char expression[][15], int & index) 
{
    int row = index;

    for (; expression[row + 1][0] && row < 9; row++) {
        int col = 0;
        for (; expression[row + 1][col]; col++) {
            expression[row][col] = expression[row + 1][col];
        }
    }

    Delete(expression[row]);
    index--;               // go back one step.
}

/**
* Print simple User Interface That represents the options which user can choose one from it.
* 
* @return void.
*/
void printMenue() 
{
    cout << "  Welcome to our Program Please Enter the number of What Option you Chose : " << endl << endl;
    cout << "     (1) Insert a new polynomial in its proper format. { x^2 }" << endl;
    cout << "     (2) Print the Polynomial as a single line Text." << endl;
    cout << "     (3) Calculate and Return the First Derivative of Polynomial." << endl;
    cout << "     (4) Calculate and Return the Second Derivative of Polynomial." << endl;
    cout << "     (5) Return the Terms of polynomial." << endl;
    cout << "     (6) Options List." << endl;
    cout << "     (9) Exit." << endl << endl;
}

/**
* Print Two Dimensional Array in single line sequentially.
* 
* @param Array of Arrays of Characters.
*/
void printTwoDimensionalArray(char expression[][15])
{
    for (int row = 0; expression[row][0]; row++)
    {
        cout << expression[row];
    }

    if (!expression[0][0]) {
        cout << "0";
    }
}

/**
* Return True if Array contains the Given character.
* 
* @param Char you want to find.
* @param Array of Characters. 
* 
* @return Boolean True if Character is in the Array.
*/
bool isConains(char character, char arr[])
{
    for (int cell = 0; arr[cell]; cell++)
    {
        if (arr[cell] == character) return true;
    }

    return false;
}
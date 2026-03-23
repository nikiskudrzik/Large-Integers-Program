#include <iostream>
#include "largeIntegers.h"
using namespace std;

int main()
{
    largeIntegers num1("123456789987654321");
    largeIntegers num2("987654321123456789");

    largeIntegers sum = num1.add(num2);
    largeIntegers difference = num2.subtract(num1);
    largeIntegers product = num1.multiply(num2);

    cout << "First number: ";
    num1.printNumber();

    cout << "Second number: ";
    num2.printNumber();

    cout << endl;

    cout << "Addition:" << endl;
    sum.printNumber();

    cout << endl;

    cout << "Subtraction (second - first):" << endl;
    difference.printNumber();

    cout << endl;

    cout << "Multiplication:" << endl;
    product.printNumber();

    cout << endl;

    cout << "Comparison:" << endl;
    if (num1.compare(num2) == 0)
    {
        cout << "The two numbers are equal." << endl;
    }
    else if (num1.compare(num2) == -1)
    {
        cout << "The first number is smaller than the second number." << endl;
    }
    else
    {
        cout << "The first number is greater than the second number." << endl;
    }

    return 0;
}
#include <iostream>
#include <vector>
#include "largeIntegers.h"
using namespace std;

// starts with 0
largeIntegers::largeIntegers()
{
    number = "0";
}

// starts with the given number
largeIntegers::largeIntegers(string num)
{
    number = removeLeadingZeros(num);
}

// sets the number
void largeIntegers::setNumber(string num)
{
    number = removeLeadingZeros(num);
}

// returns the number
string largeIntegers::getNumber() const
{
    return number;
}

// prints the number
void largeIntegers::printNumber() const
{
    cout << number << endl;
}

// removes extra zeros at the front
string largeIntegers::removeLeadingZeros(string str) const
{
    int i = 0;

    while (i < str.length() - 1 && str[i] == '0')
    {
        i++;
    }

    return str.substr(i);
}

// checks if first number is smaller than second
bool largeIntegers::isSmaller(string a, string b) const
{
    a = removeLeadingZeros(a);
    b = removeLeadingZeros(b);

    if (a.length() < b.length())
    {
        return true;
    }
    else if (a.length() > b.length())
    {
        return false;
    }

    return a < b;
}

// adds two string numbers
string largeIntegers::addStrings(string a, string b) const
{
    string answer = "";
    int carry = 0;
    int i = a.length() - 1;
    int j = b.length() - 1;

    while (i >= 0 || j >= 0 || carry > 0)
    {
        int digit1 = 0;
        int digit2 = 0;

        if (i >= 0)
        {
            digit1 = a[i] - '0';
            i--;
        }

        if (j >= 0)
        {
            digit2 = b[j] - '0';
            j--;
        }

        int sum = digit1 + digit2 + carry;
        answer = char((sum % 10) + '0') + answer;
        carry = sum / 10;
    }

    return removeLeadingZeros(answer);
}

// subtracts second string number from first
string largeIntegers::subtractStrings(string a, string b) const
{
    string answer = "";
    int borrow = 0;
    int i = a.length() - 1;
    int j = b.length() - 1;

    while (i >= 0)
    {
        int digit1 = (a[i] - '0') - borrow;
        int digit2 = 0;

        if (j >= 0)
        {
            digit2 = b[j] - '0';
        }

        if (digit1 < digit2)
        {
            digit1 += 10;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }

        int diff = digit1 - digit2;
        answer = char(diff + '0') + answer;

        i--;
        j--;
    }

    return removeLeadingZeros(answer);
}

// multiplies two string numbers
string largeIntegers::multiplyStrings(string a, string b) const
{
    int size1 = a.length();
    int size2 = b.length();
    vector<int> result(size1 + size2, 0);

    for (int i = size1 - 1; i >= 0; i--)
    {
        for (int j = size2 - 1; j >= 0; j--)
        {
            int digit1 = a[i] - '0';
            int digit2 = b[j] - '0';

            int product = digit1 * digit2;
            int sum = product + result[i + j + 1];

            result[i + j + 1] = sum % 10;
            result[i + j] += sum / 10;
        }
    }

    string answer = "";

    for (int i = 0; i < result.size(); i++)
    {
        answer += char(result[i] + '0');
    }

    return removeLeadingZeros(answer);
}

// adds two largeIntegers objects
largeIntegers largeIntegers::add(const largeIntegers& other) const
{
    return largeIntegers(addStrings(number, other.number));
}

// subtracts two largeIntegers objects
largeIntegers largeIntegers::subtract(const largeIntegers& other) const
{
    if (isSmaller(number, other.number))
    {
        return largeIntegers("0");
    }

    return largeIntegers(subtractStrings(number, other.number));
}

// multiplies two largeIntegers objects
largeIntegers largeIntegers::multiply(const largeIntegers& other) const
{
    return largeIntegers(multiplyStrings(number, other.number));
}

// compares two largeIntegers objects
int largeIntegers::compare(const largeIntegers& other) const
{
    if (number == other.number)
    {
        return 0;
    }
    else if (isSmaller(number, other.number))
    {
        return -1;
    }
    else
    {
        return 1;
    }
}
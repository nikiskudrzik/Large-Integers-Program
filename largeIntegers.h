#ifndef LARGEINTEGERS_H
#define LARGEINTEGERS_H

#include <string>
using namespace std;

class largeIntegers
{
private:
    string number;

    string addStrings(string a, string b) const;
    string subtractStrings(string a, string b) const;
    string multiplyStrings(string a, string b) const;
    bool isSmaller(string a, string b) const;
    string removeLeadingZeros(string str) const;

public:
    largeIntegers();
    largeIntegers(string num);

    void setNumber(string num);
    string getNumber() const;
    void printNumber() const;

    largeIntegers add(const largeIntegers& other) const;
    largeIntegers subtract(const largeIntegers& other) const;
    largeIntegers multiply(const largeIntegers& other) const;

    int compare(const largeIntegers& other) const;
};

#endif
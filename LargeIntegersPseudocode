# Design Documentation

## Detailed Pseudocode

Class largeIntegers

Private:
- number as string

Helper Functions:

removeLeadingZeros(str)
- remove zeros at the front of the number
- return cleaned string

isSmaller(a, b)
- if a has fewer digits than b, return true
- if a has more digits than b, return false
- if same length, compare values
- return whether a is smaller

addStrings(a, b)
- start from the last digit of both numbers
- add digits one by one
- keep track of carry
- build the result string
- return the result

subtractStrings(a, b)
- assume a is greater than or equal to b
- start from the last digit
- subtract digits one by one
- use borrow when needed
- build the result string
- return the result

multiplyStrings(a, b)
- create a result list of zeros
- multiply each digit in a with each digit in b
- add results in correct positions
- convert result list to string
- return the result

Public Functions:

Constructor()
- set number to "0"

Constructor(num)
- set number to cleaned num

setNumber(num)
- store the number

getNumber()
- return the number

printNumber()
- display the number

add(other)
- add this number and the other number
- return result

subtract(other)
- if this number is smaller, return 0
- otherwise subtract and return result

multiply(other)
- multiply this number and the other number
- return result

compare(other)
- if numbers are equal, return 0
- if this number is smaller, return -1
- otherwise return 1

## Use Case

1. Create two largeIntegers objects
2. Store large numbers in them
3. Add the numbers
4. Subtract the numbers
5. Multiply the numbers
6. Compare the numbers
7. Print the results

/**
 * Implement the myAtoi(string s) function, which converts a string to a 32-bit 
 * signed integer.
 * 
 * The algorithm for myAtoi(string s) is as follows:
 * 
 * Whitespace: Ignore any leading whitespace (" ").
 * Signedness: Determine the sign by checking if the next character is '-' or '+', 
 * assuming positivity if neither present.
 * Conversion: Read the integer by skipping leading zeros until a non-digit character
 * is encountered or the end of the string is reached. If no digits were read, then 
 * the result is 0.
 * Rounding: If the integer is out of the 32-bit signed integer range [-2^31, 2^31 - 1]
 * then round the integer to remain in the range. Specifically, integers less than 
 * -2^31 should be rounded to -2^31, and integers greater than 2^31 - 1 should be 
 * rounded to 2^31 - 1.
 * Return the integer as the final result.
 */

#include <bits/stdc++.h>
using namespace std;

int myAtoi(string s) {
    long long res = 0; //to store the result
    int sign = 1; //to store the sign (default -> positive)
    int i = 0; //pointer to the given string
    
    //Checking for whitespace
    while(i < s.length() && s[i]==' ') i++;

    //Checking for signedness
    if(s[i] == '-') {
        sign = -1;
        i++;
    } else if(s[i] == '+') {
        i++;
    }

    //Conversion
    while(i < s.length() && isdigit(s[i])) {
        res = res * 10 + (s[i] - '0');
        if(sign == 1 && res > INT_MAX) return INT_MAX;
        if(sign == -1 && -res < INT_MIN) return INT_MIN;
        i++;
    }

    return (int)(sign * res);
}

int main() {
    string s;
    cout << "Enter the string: ";
    cin >> s;

    int result = myAtoi(s);

    cout << result << endl;

    return 0;
}
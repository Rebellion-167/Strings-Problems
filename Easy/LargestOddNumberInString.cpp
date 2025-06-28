/**
 * You are given a string num, representing a large integer. Return the largest-valued 
 * odd integer (as a string) that is a non-empty substring of num, or an empty string 
 * "" if no odd integer exists.
 * 
 * A substring is a contiguous sequence of characters within a string.
 * 
 * Example 1:
 * Input: num = "52"
 * Output: "5"
 * Explanation: The only non-empty substrings are "5", "2", and "52". "5" is the only 
 * odd number.
 * 
 * Example 2:
 * Input: num = "4206"
 * Output: ""
 * Explanation: There are no odd numbers in "4206".
 * 
 * Example 3:
 * Input: num = "35427"
 * Output: "35427"
 * Explanation: "35427" is already an odd number.
 */

#include <bits/stdc++.h>
using namespace std;

string findOddNumber(string s) {
    for(int i=s.length() - 1; i>=0; i--) {
        if(((int)s[i]) % 2 == 1) 
            return s.substr(0, i+1);
    }
    return "";
}

int main() {
    string s;
    cout << "Enter the string : ";
    cin >> s;

    string result = findOddNumber(s);

    cout << "The largest odd number from the string is : " << result << endl;

    return 0;
}

/**
 * Time Complexity : O(N) where N = size of the string
 * Reason : We are iteration over the entire string
 * 
 * Space Complexity: O(N) since we are returning a string
 */
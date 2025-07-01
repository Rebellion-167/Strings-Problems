/**
 * Given a valid parentheses string s, return the nesting depth of s. The nesting 
 * depth is the maximum number of nested parentheses.
 * 
 * Example 1:
 * Input: s = "(1+(2*3)+((8)/4))+1"
 * Output: 3
 * Explanation:
 * Digit 8 is inside of 3 nested parentheses in the string.
 * 
 * Example 2:
 * Input: s = "(1)+((2))+(((3)))"
 * Output: 3
 * Explanation:
 * Digit 3 is inside of 3 nested parentheses in the string.
 * 
 * Example 3:
 * Input: s = "()(())((()()))"
 * Output: 3
 */

#include <bits/stdc++.h>
using namespace std;

int findMaxDepth(string s) {
    int ans = 0; //to store the maximum depth
    int openBrackets = 0; //to store the current open bracket count

    for(int i=0;i<s.size();i++) {
        char c = s[i];
        if(c == '(') openBrackets++;
        if(c == ')') openBrackets--;
        ans = max(ans, openBrackets);
    }
    return ans;
}

int main() {
    string s;
    cout << "Enter the string : ";
    cin >> s;
    
    int res = findMaxDepth(s);

    cout << res << endl;

    return 0;
}

/**
 * Time Complexity : O(n) where n is the size of the string
 * Reason : We are iterating over the entire string
 * 
 * Space Complexity : O(1) as no extra space is used
 */
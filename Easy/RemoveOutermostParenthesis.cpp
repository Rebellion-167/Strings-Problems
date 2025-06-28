/**
 * A valid parentheses string is either empty "", "(" + A + ")", or A + B, where A and 
 * B are valid parentheses strings, and + represents string concatenation.
 * 
 * For example, "", "()", "(())()", and "(()(()))" are all valid parentheses strings.
 * A valid parentheses string s is primitive if it is nonempty, and there does not exist 
 * a way to split it into s = A + B, with A and B nonempty valid parentheses strings.
 * 
 * Given a valid parentheses string s, consider its primitive decomposition: s = P1 + 
 * P2 + ... + Pk, where Pi are primitive valid parentheses strings.
 * 
 * Return s after removing the outermost parentheses of every primitive string in 
 * the primitive decomposition of s.
 */

#include <bits/stdc++.h>
using namespace std;

string removeOuterParenthesis(string s) {
    int count = 0;
    string ans = "";
    for(int i=0;i<s.length();i++) {
        if(s[i] == ')') count--;
        if(count != 0) ans.push_back(s[i]);
        if(s[i] == '(') count++;
    }
    return ans;
}

int main() {
    string s;
    cout << "Enter the parenthesis string : ";
    cin >> s;

    string result = removeOuterParenthesis(s);

    cout << "After removing outermost parenthesis : " << result << endl;

    return 0;
}

/**
 * Time Complexity : O(len(s)) since we are traversing the entire string
 * Space Complexity : O(1) as no extra space is used
 */
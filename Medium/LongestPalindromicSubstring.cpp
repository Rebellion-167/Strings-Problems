/**
 * Given a string s, return the longest palindromic substring in s.
 * 
 * Example 1:
 * Input: s = "babad"
 * Output: "bab"
 * Explanation: "aba" is also a valid answer.
 * 
 * Example 2:
 * Input: s = "cbbd"
 * Output: "bb"
 */

#include <bits/stdc++.h>
using namespace std;

string longestPalin(string s) {
    string res = ""; //to store the longest palindrome
    int resLen = 0; //to store the length of longest palindrome
    int l, r;
    for(int i=0;i<s.length();i++) {
        //For odd length
        l = i, r = i;
        while(l >= 0 && r < s.length() && s[l] == s[r]) {
            if((r - l + 1) > resLen) {
                res = s.substr(l, r - l + 1);
                resLen = r - l + 1;
            }
            l--;
            r++;
        }

        //For even length
        l = i, r = i+1;
        while(l >= 0 && r < s.length() && s[l] == s[r]) {
            if((r - l + 1) > resLen) {
                res = s.substr(l, r - l + 1);
                resLen = r - l + 1;
            }
            l--;
            r++;
        }
    }
    return res;
}

int main() {
    string s;
    cout << "Enter the string : ";
    cin >> s;

    string result = longestPalin(s);

    cout << "The longest palindromic substring is : " << result << endl;

    return 0;
}

/**
 * Time Complexity - O(n^2) since we are iterating over the entire string
 * Space Complexity - O(1)
 */
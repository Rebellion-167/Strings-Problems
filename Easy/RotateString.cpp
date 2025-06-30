/**
 * Given two strings s and goal, return true if and only if s can become goal after 
 * some number of shifts on s.
 * 
 * A shift on s consists of moving the leftmost character of s to the rightmost 
 * position.
 * 
 * Example 1:
 * Input: s = "abcde", goal = "cdeab"
 * Output: true
 * 
 * Example 2:
 * Input: s = "abcde", goal = "abced"
 * Output: false
 */

#include <bits/stdc++.h>
using namespace std;

bool rotatedString(string s, string goal) {
    //Checking if the lengths are different
    if(s.length() != goal.length()) return false;

    //Concatenating s with itself
    string doubleString = s + s;

    //Using find to search for 'goal' in 'doubleString'
    //If find returns an index that is less than the
    //length of the doubleString, 'goal' is a rotated string
    return doubleString.find(goal) < doubleString.length();
}

int main() {
    string s, goal;
    cout << "Enter the two strings : ";
    cin >> s >> goal;

    bool result = rotatedString(s, goal);

    cout << boolalpha << result << endl;

    return 0;
}

/**
 * Time Complexity : O(n) where n is the length of the string
 * Reason : The substring find function is typically implemented using an algorithm
 * that runs in O(n). This involves scanning the doubledString of length 2n for 
 * the substring goal of length n. Since the search occurs in a string of size 2n, 
 * the overall complexity for this operation remains O(n).
 * 
 * Space Complexity : O(n) due to the concatenated string
 */
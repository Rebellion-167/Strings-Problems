/**
 * Given two strings, check if two strings are anagrams of each other or not.
 * 
 * Examples:
 * 
 * Example 1:
 * Input: CAT, ACT
 * Output: true
 * Explanation: Since the count of every letter of both strings are equal.
 * 
 * Example 2:
 * Input: RULES, LESRT 
 * Output: false
 * Explanation: Since the count of U and T  is not equal in both strings.
 */

#include <bits/stdc++.h>
using namespace std;

bool checkAnagrams(string s1, string s2) {
    //Checking if lengths of two strings are different
    if(s1.length() != s2.length()) return false;
    //Using Hashing
    int freq[26] = {0};

    //First we are incrementing for every character
    //we find in s1, then decrementing for every 
    //character we find in s2. Ideally, for two strings
    //to be anagrams of each other, the resultant frequecy
    //should be zero in our case
    for(int i=0;i<s1.length();i++) {
        freq[s1[i] - 'A']++;
    }
    for(int i=0;i<s2.length();i++) {
        freq[s2[i] - 'A']--;
    }
    for(int i=0;i<26;i++) {
        if(freq[i] != 0)
            return false;
    }
    return true;
}

int main() {
    string s1, s2;
    cout << "Enter the two strings : ";
    cin >> s1 >> s2;

    bool result = checkAnagrams(s1, s2);

    cout << boolalpha << result;
}

/**
 * Time Complexity : O(n) where n is the length of the string
 * Space Complexity : O(1)
 */
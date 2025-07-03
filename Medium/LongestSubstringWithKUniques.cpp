/**
 * You are given a string s consisting only lowercase alphabets and an integer k. 
 * Your task is to find the length of the longest substring that contains exactly 
 * k distinct characters.
 * 
 * Note : If no such substring exists, return -1. 
 * 
 * Examples:
 * Input: s = "aabacbebebe", k = 3
 * Output: 7
 * Explanation: The longest substring with exactly 3 distinct characters is 
 * "cbebebe", which includes 'c', 'b', and 'e'.
 * 
 * Input: s = "aaaa", k = 2
 * Output: -1
 * Explanation: There's no substring with 2 distinct characters.
 * 
 * Input: s = "aabaaab", k = 2
 * Output: 7
 * Explanation: The entire string "aabaaab" has exactly 2 unique characters 'a' and 
 * 'b', making it the longest valid substring.
 */

#include <bits/stdc++.h>
using namespace std;

int longestSubstring(string s, int k) {
    int n = s.length();
    int left = 0, right = 0, maxLen = -1;
    unordered_map<char, int> mpp;

    while(right < n) {
        mpp[s[right]]++;

        //Shrinking the window if unique chars > k
        while(mpp.size() > k) {
            mpp[s[left]]--;
            if(mpp[s[left]] == 0)
                mpp.erase(s[left]);
            left++;
        }

        //Checking for exactly k uniques
        if(mpp.size() == k) {
            maxLen = max(maxLen, right - left + 1);
        }
        right++;
    }
    return maxLen;
}

int main() {
    string s;
    cout << "Enter the string : ";
    cin >> s;

    int k;
    cout << "Enter the value of k : ";
    cin >> k;

    int length = longestSubstring(s, k);

    cout << length << endl;

    return 0;
}
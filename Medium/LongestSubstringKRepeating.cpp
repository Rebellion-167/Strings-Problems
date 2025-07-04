/**
 * Given a string s and an integer k, return the length of the longest substring of 
 * s such that the frequency of each character in this substring is greater than or 
 * equal to k.
 * 
 * if no such substring exists, return 0.
 * 
 * Example 1:
 * Input: s = "aaabb", k = 3
 * Output: 3
 * Explanation: The longest substring is "aaa", as 'a' is repeated 3 times.
 * 
 * Example 2:
 * Input: s = "ababbc", k = 2
 * Output: 5
 * Explanation: The longest substring is "ababb", as 'a' is repeated 2 times and 
 * 'b' is repeated 3 times.
 */

#include <bits/stdc++.h>
using namespace std;

//Brute force approach
int longestSubstring(string s, int k) {
    //Creating a map to store frequencies
    unordered_map<char, int> mpp;
    
    int maxLen = 0;
    int n = s.length();
    int count = 0;

    for(int i=0;i<n;i++) {
        mpp[s[i]]++;
        if(mpp[s[i]] == k) count++;
    }

    if(mpp.size() == count) maxLen = s.length();

    return maxLen;
}

//Optimizing
int longestSubK(string s, int k) {
    int n = s.length();
    int maxLen = 0;
    for(int i=0;i<n;i++) {
        int count = 0;
        unordered_map<char, int> mpp;
        for(int j=i;j<n;j++) {
            mpp[s[j]]++;
            if(mpp[s[j]] == k) count++;
            if(mpp.size() == count) maxLen = max(maxLen, j - i + 1);
        }
    }
    return maxLen;
}

//Optimal
int longestSubSplit(string s, int k) {
    int n = s.size();
    if(n == 0) return 0;

    unordered_map<char, int> mpp;
    for(char c : s) mpp[c]++;

    for(int i=0;i<n;i++) {
        if(mpp[s[i]] < k) {
            //Splitting and solving for each part
            int left = longestSubSplit(s.substr(0, i), k);
            int right = longestSubSplit(s.substr(i+1), k);
            return max(left, right);
        }
    }
    return n;
}
int main() {
    string s;
    cout << "Enter the string : ";
    cin >> s;

    int k;
    cout << "Enter the value of k : ";
    cin >> k;

    int maxi = longestSubSplit(s, k);
    // int n = s.length();
    // int maxi = 0;
    // //Generating substrings
    // for(int i=0;i<n;i++) {
    //     for(int j=i;j<n;j++) {
    //         string sub = s.substr(i, (j - i + 1));
    //         int l = longestSubstring(sub, k);
    //         maxi = max(maxi, l);
    //     }
    // }
    cout << maxi << endl;

    return 0;
}

/**
 * Time Complexity : O(n^2)
 * Space Complexity : O(n)
 */
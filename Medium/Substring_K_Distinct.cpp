/**
 * Given a string consisting of lowercase characters and an integer k, the task is to 
 * count all possible substrings (not necessarily distinct) that have exactly k distinct 
 * characters. 
 * 
 * Examples :
 * Input: s = "abc", k = 2
 * Output: 2
 * Explanation: Possible substrings are ["ab", "bc"]
 * 
 * Input: s = "aba", k = 2
 * Output: 3
 * Explanation: Possible substrings are ["ab", "ba", "aba"]
 * 
 * Input: s = "aa", k = 1
 * Output: 3
 * Explanation: Possible substrings are ["a", "a", "aa"]
 */

#include <bits/stdc++.h>
using namespace std;

int substringDistinct(string s, int k) {
    int n = s.length();
    int count = 0;
    unordered_map<char, int> mpp;
    int left = 0, right = 0;

    while(right < n) {
        mpp[s[right]]++;

        while(mpp.size() > k) {
            mpp[s[left]]--;
            if(mpp[s[left]] == 0)
                mpp.erase(s[left]);
            left++;
        }
        count += right - left + 1;
        right++;
    }
    return count;
}

int main() {
    string s;
    cout << "Enter the string : ";
    cin >> s;

    int k;
    cout << "Enter the value of k : ";
    cin >> k;

    int res = substringDistinct(s, k) - substringDistinct(s, k-1);

    cout << res << endl;
    return 0;
}


/**
 * The beauty of a string is the difference in frequencies between the most frequent
 * and least frequent characters.
 *
 * For example, the beauty of "abaacc" is 3 - 1 = 2.
 *
 * Given a string s, return the sum of beauty of all of its substrings.
 *
 * Example 1:
 * Input: s = "aabcb"
 * Output: 5
 * Explanation: The substrings with non-zero beauty are ["aab","aabc","aabcb","abcb",
 * "bcb"], each with beauty equal to 1.
 *
 * Example 2:
 * Input: s = "aabcbaa"
 * Output: 17
 */

#include <bits/stdc++.h>
using namespace std;

int findBeauty(string s) {
    int n = s.length();
    int total = 0;
    for(int i=0;i<n;i++) {
        vector<int> freq(26, 0);
        for(int j=i;j<n;j++) {
            freq[s[j] - 'a']++;
            int mostFreq = 0, leastFreq = INT_MAX;
            for(int k=0;k<26;k++) {
                if(freq[k] > 0) {
                    mostFreq = max(mostFreq, freq[k]);
                    leastFreq = min(leastFreq, freq[k]);
                }
            }
            total += (mostFreq - leastFreq);
        }
    }
    return total;
}

int main() {
    string s;
    cout << "Enter the string : ";
    cin >> s;

    int count = findBeauty(s);
    cout << count << endl;
}

/**
 * Time Complexity : O(n^2) since we are finding substrings
 * Space Complexity : O(1)
 */
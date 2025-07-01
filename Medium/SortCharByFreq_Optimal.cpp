/**
 * Given a string s, sort it in decreasing order based on the frequency of the 
 * characters. The frequency of a character is the number of times it appears in the 
 * string.
 * 
 * Return the sorted string. If there are multiple answers, return any of them.
 * 
 * Example 1:
 * Input: s = "tree"
 * Output: "eert"
 * Explanation: 'e' appears twice while 'r' and 't' both appear once.
 * So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
 * 
 * Example 2:
 * Input: s = "cccaaa"
 * Output: "aaaccc"
 * Explanation: Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc" 
 * are valid answers.
 * Note that "cacaca" is incorrect, as the same characters must be together.
 * 
 * Example 3:
 * Input: s = "Aabb"
 * Output: "bbAa"
 * Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
 * Note that 'A' and 'a' are treated as two different characters.
 */

#include <bits/stdc++.h>
using namespace std;

string sortCharacters(string s) {
    unordered_map<char, int> mpp;
    for(int i=0;i<s.size();i++) mpp[s[i]]++;

    vector<pair<char, int>> freq (mpp.begin(), mpp.end());
    sort(freq.begin(), freq.end(), [](auto &a, auto &b) {
        return a.second > b.second;
    });

    string res;
    for(auto &p: freq) {
        res.append(p.second, p.first);
    }
    return res;
}

int main() {
    string s;
    cout << "Enter the string : ";
    cin >> s;

    string res = sortCharacters(s);

    cout << res << endl;

    return 0;
}

/**
 * Time Complexity : O(n + nlog n) where n is the size of the map
 * Space Complexity : O(n)
 */
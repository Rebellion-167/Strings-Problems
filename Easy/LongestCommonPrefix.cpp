/**
 * Write a function to find the longest common prefix string amongst an array of 
 * strings.
 * 
 * If there is no common prefix, return an empty string "".
 * 
 * Example 1:
 * Input: strs = ["flower","flow","flight"]
 * Output: "fl"
 * 
 * Example 2:
 * Input: strs = ["dog","racecar","car"]
 * Output: ""
 * Explanation: There is no common prefix among the input strings.
 */

#include <bits/stdc++.h>
using namespace std;

string findPrefix(vector<string>& strs) {
    if(strs.empty()) return "";
    string prefix = strs[0];

    for(int i=1;i<strs.size();i++) {
        int j = 0;
        while (j < prefix.size() && j < strs[i].size() && prefix[j] == strs[i][j]) {
            j++;
        }
        prefix = prefix.substr(0, j);
        if(prefix == "") break;
    }
    return prefix;
}

int main() {
    int n;
    cout << "Enter the number of strings : ";
    cin >> n;

    vector<string> strs;

    cout << "Enter the strings : ";
    for(int i=0;i<n;i++) {
        string temp;
        cin >> temp;
        strs.push_back(temp);
    }

    string prefix = findPrefix(strs);

    cout << "The longest common prefix is : " << prefix << endl;

    return 0;
}

/**
 * Time Complexity - O(n * m) where n is the number of strings and m is the average 
 * string length
 * Space Complexity - O(1) as no extra space is used
 */
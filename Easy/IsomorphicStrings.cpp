/**
 * Given two strings s and t, determine if they are isomorphic.
 * 
 * Two strings s and t are isomorphic if the characters in s can be replaced to get t.
 * 
 * All occurrences of a character must be replaced with another character while 
 * preserving the order of characters. No two characters may map to the same 
 * character, but a character may map to itself.
 * 
 * Example 1:
 * Input: s = "egg", t = "add"
 * Output: true
 * Explanation:
 * The strings s and t can be made identical by:
 * Mapping 'e' to 'a'.
 * Mapping 'g' to 'd'.
 * 
 * Example 2:
 * Input: s = "foo", t = "bar"
 * Output: false
 * Explanation:
 * The strings s and t can not be made identical as 'o' needs to be mapped to both 
 * 'a' and 'r'.
 * 
 * Example 3:
 * Input: s = "paper", t = "title"
 * Output: true
 */

#include <bits/stdc++.h>
using namespace std;

bool findIsomorphic(string s1, string s2) {

    //Edge Case - If strings are of unequal length
    if(s1.length() != s2.length()) 
        return false;

    //Creating a Hashmap
    unordered_map<char, char> mpp1; // s1 -> s2
    unordered_map<char, char> mpp2; // s2 -> s1

    for(int i=0;i<s1.length();i++) {
        char c1 = s1[i];
        char c2 = s2[i];

        //Checking mapping from s1 to s2
        if(mpp1.count(c1)) {
            if(mpp1[c1] != c2) 
                return false;
        } else {
            mpp1[c1] = c2;
        }

        //Checking mapping from s2 to s1
        //To prevent two chars in s1 mapping to same
        //char in s2
        if(mpp2.count(c2)) {
            if(mpp2[c2] != c1) 
                return false;
        } else {
            mpp2[c2] = c1;
        }
    }
    return true;
}

int main() {
    string s1, s2;
    cout << "Enter two strings : ";
    cin >> s1 >> s2;

    if(findIsomorphic(s1, s2))
        cout << "The strings are isomorphic.";
    else
        cout << "The strings are not isomorphic.";

    return 0;
}

/**
 * Time Complexity : O(N) where N is the length of string
 * Space Complexity : O(1)
 */
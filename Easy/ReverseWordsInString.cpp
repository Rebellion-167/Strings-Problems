/**
 * Given a string s, reverse the words of the string.
 * 
 * Examples:
 * 
 * Example 1:
 * Input: s=”this is an amazing program”
 * Output: “program amazing an is this”
 * 
 * Example 2:
 * Input: s=”This is decent”
 * Output: “decent is This”
 */

#include <bits/stdc++.h>
using namespace std;

string reverseWords(string s) {
    int left = 0;
    int right = s.length() - 1;

    string temp = "";
    string ans = "";

    //Skipping leading spaces
    while(left <= right && s[left] == ' ') left++;
    //Skipping trailing spaces
    while(right >= left && s[right] == ' ') right--;

    //Iterating the string and keep on adding to form a word
    //If empty space is encountered then add the current word to the result
    while(left <= right) {
        char ch = s[left];
        if(ch != ' ') 
            temp += ch;
        else if(ch == ' ') {
            if(temp != "") {
                if(ans != "") ans = temp + " " + ans;
                else ans = temp;
                temp = "";
            }
            //Skipping consecutive spaces
            while(left + 1 <= right && s[left + 1] == ' ') left++;
        }
        left++;
    }

    //To add the last word
    if(temp != "") {
        if(ans != "") ans = temp + " " + ans;
        else ans = temp;
    }
    return ans;
}

int main() {
    string s;
    cout << "Enter the string : ";
    getline(cin, s);

    string result = reverseWords(s);

    cout << "The reversed string is : " << result << endl;

    return 0;
}

/**
 * Time Complexity : O(len(s)) since we are traversing the entire string
 * Space Complexity : O(N) as we are using temporary strings
 */
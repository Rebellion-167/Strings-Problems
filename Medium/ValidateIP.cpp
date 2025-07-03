/**
 * You are given a string s in the form of an IPv4 Address. Your task is to validate 
 * an IPv4 Address, if it is valid return true otherwise return false.
 * 
 * IPv4 addresses are canonically represented in dot-decimal notation, which consists 
 * of four decimal numbers, each ranging from 0 to 255, separated by dots, e.g., 
 * "172.16.254.1"
 * 
 * A valid IPv4 Address is of the form x1.x2.x3.x4 where 0 <= (x1, x2, x3, x4) <= 255. 
 * Thus, we can write the generalized form of an IPv4 address as 
 * (0-255).(0-255).(0-255).(0-255)
 * 
 * Note: Here we are considering numbers only from 0 to 255 and any additional leading 
 * zeroes will be considered invalid.
 * 
 * Examples : 
 * Input: s = "222.111.111.111"
 * Output: true
 * Explanation: Here, the IPv4 address is as per the criteria mentioned and also 
 * all four decimal numbers lies in the mentioned range.
 * 
 * Input: s = "5555..555"
 * Output: false
 * Explanation: "5555..555" is not a valid. IPv4 address, as the middle two portions 
 * are missing.
 * Input: s = "0.0.0.255"
 * Output: true
 */

#include <bits/stdc++.h>
using namespace std;

bool validIP(string s) {
    int n = s.length();
    int count = 0; //count of segments
    int i = 0;
    while (i < n) {
        string part = "";
        //Extracting segment until '.' or end of string
        while(i < n && s[i] != '.') {
            part += s[i];
            i++;
        }
        //Checking for empty segment
        if(part.empty()) return false;
        //Checking for non-digit characters
        for(char c : part) {
            if (!isdigit(c)) return false;
        }   
        //Checking for leading zeroes (except "0")
        if(part.size() > 1 && part[0] == '0') return false;
        //Converting to integer and checking range
        int num = stoi(part);
        if (num < 0 || num > 255) return false;
        count++;
        i++; //skipping the dot
    }
    //There must be exactly 4 segments
    return count == 4;
}

int main() {
    string ip;
    cout << "Enter an IP Address : ";
    cin >> ip;

    bool check = validIP(ip);

    cout << boolalpha << check;

    return 0;
}

/**
 * Time Complexity : O(n) where n is the size of the string
 * Space Complexity : O(1)
 */
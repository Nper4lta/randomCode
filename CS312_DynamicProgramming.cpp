#include <iostream>
#include <algorithm>

using namespace std;

// Function to find the longest palindromic subsequence
string longestPalindromeSubseq(string s, int i, int j) {
    // Base case: if the substring has only one character
    if (i == j) {
        return s.substr(i, 1);
    }

    // Base case: if the substring has two characters and they are the same
    if (s[i] == s[j] && i + 1 == j) {
        return s.substr(i, 2);
    }

    // If the first and last characters match
    if (s[i] == s[j]) {
        return s[i] + longestPalindromeSubseq(s, i + 1, j - 1) + s[j];
    }

    // If the first and last characters do not match
    string option1 = longestPalindromeSubseq(s, i, j - 1);
    string option2 = longestPalindromeSubseq(s, i + 1, j);

    return (option1.length() > option2.length()) ? option1 : option2;
}

int main() {
    string str = "character";
    
    cout << "Testing longestPalindromeSubseq without dynamic programming which takes O(2^n)" << endl; 
    cout << "Using character should get carac" << endl;
    cout << "Running the code got: " << longestPalindromeSubseq(str, 0, str.length() - 1) << endl;

    str = "comma";
    cout << "Using comma should get mm" << endl;
    cout << "Running the code got: " << longestPalindromeSubseq(str, 0, str.length() - 1) << endl;

    return 0;
}

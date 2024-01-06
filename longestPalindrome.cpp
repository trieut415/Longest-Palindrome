#include "longestPalindrome.h"

#include <iostream>
#include <fstream>
#include <regex>
#include <unordered_set> 
#include <unordered_map> 

int SplitLeftRight(const string& inStr, int leftHalf, int rightHalf) {
    int length = 0;
    while (inStr[leftHalf] == inStr[rightHalf] && leftHalf >= 0 && rightHalf < inStr.length()) { //check if the left and right are equal in the indices of text
        length = rightHalf - leftHalf + 1; //update the length
        rightHalf++; 
        leftHalf--;
    }
    return length;
}

int longestPalindrome() {

    ifstream file("BigData.txt");  //reading and adding the file to one long string
    string text;
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            text += line;
        }
        file.close();
    }

    int longestPal = 0;
    for (int i = 0; i < text.length() - 1; i++) {
        int evenLength = SplitLeftRight(text, i, i + 1); //recursively call functino to repeatedly split the split/expand the string to go through its element
        int oddLength = SplitLeftRight(text, i, i);

    if (oddLength > longestPal) { longestPal = oddLength; } //set equal to respective value in the case that it is odd/even
    if (evenLength > longestPal) { longestPal = evenLength; }

    }
    return longestPal;
}

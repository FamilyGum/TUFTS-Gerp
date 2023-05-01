
#include <string>
#include <iostream>
#include <vector>

using namespace std;


/* string stripNonAlphaNum
* Purpose: strips all of the outside non alpha-numeric characters off the 
* given input string
* Parameters: string input
* Returns: the modified string
* Effects: none
*/
string stripNonAlphaNum (string input) {
    int length = input.length();
    int start = 0;
    int end = length - 1;

    while(not isalnum(input[start]) and start < length){
        start++;
    }
    while(not isalnum(input[end]) and start < end){
        end--;
    }
    int newlen = end - start + 1;
    return input.substr(start, newlen);
}

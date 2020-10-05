// Write an efficient function that checks whether any permutation ↴ of an input string is a palindrome. ↴

//     You can assume the input string only contains lowercase letters.

//     Examples :

//     "civic" should return true
//     "ivicc" should return true
//     "civil" should return false
//     "livci" should return false

#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

bool hasPalindromePermutation(string &str)
{
    // check if any permutation of the input is a palindrome
    unordered_set<char> letterCount;

    for (char letter : str)
    {
        if (letterCount.find(letter) != letterCount.end())
        {
            letterCount.erase(letter);
        }
        else
        {
            letterCount.insert(letter);
        }
    }

    return letterCount.size() <= 1;
}

int main()
{
    string str = "ivicc";
    cout << hasPalindromePermutation(str);
}
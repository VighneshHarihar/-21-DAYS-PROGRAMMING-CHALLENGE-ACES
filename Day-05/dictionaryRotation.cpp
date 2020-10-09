
// I want to learn some big words so people think I'm smart.

// I opened up a dictionary to a page in the middle and started flipping through, looking for words I didn't know. I put each word I didn't know at increasing indices in a huge vector I created in memory. When I reached the end of the dictionary, I started from the beginning and did the same thing until I reached the page I started at.

// Now I have a vector of words that are mostly alphabetical, except they start somewhere in the middle of the alphabet, reach the end, and then start from the beginning of the alphabet. In other words, this is an alphabetically ordered vector that has been "rotated." For example:

//   const vector<string> words {
//     "ptolemaic",
//     "retrograde",
//     "supplant",
//     "undulate",
//     "xenoepist",
//     "asymptote",  // <-- rotates here!
//     "babka",
//     "banoffee",
//     "engender",
//     "karpatka",
//     "othellolagkage",
// };

// Write a function for finding the index of the "rotation point," which is where I started working from the beginning of the dictionary. This vector is huge (there are lots of words I don't know) so we want to be efficient here.

#include <iostream>
#include <string>
#include <vector>

// C++11 lest unit testing framework
//#include "lest.hpp"

using namespace std;
// size_t getAscii(string getVal)
// {
//     size_t intVal = 0;
//     for (auto ch : getVal)
//     {
//         intVal += int(ch);
//     }

//     return intVal;
// }
// size_t findRotationPoint(const vector<string> &words)
// {
//     // find the rotation point in the array
//     int checker = getAscii(words[0]);
//     for (int i = 1; i < words.size(); i++)
//     {
//         int current = getAscii(words[i]);
//         if (current < checker)
//         {
//             return i;
//         }
//         else
//         {
//             checker = current;
//         }
//     }
//     return 0;
// }
size_t findRotationPoint(const vector<string> &words)
{
    size_t floorIndex = 0;
    size_t ceilingIndex = words.size() - 1;

    while (floorIndex < ceilingIndex)
    {
        size_t distance = ceilingIndex - floorIndex;
        size_t halfDist = distance / 2;
        size_t guessIndex = floorIndex + halfDist;

        //string current = words[guessIndex];

        if (words[guessIndex] >= words[0])
        {
            // go right
            floorIndex = guessIndex;
        }
        else
        {
            // go left
            ceilingIndex = guessIndex;
        }

        // if floor and ceiling have converged
        if (floorIndex + 1 == ceilingIndex)
        {

            // between floor and ceiling is where we flipped to the beginning
            // so ceiling is alphabetically first
            break;
        }
    }

    return ceilingIndex;
}

int main()
{
    vector<string> words{"ptolemaic", "retrograde", "supplant", "undulate",
                         "xenoepist", "asymptote", "babka", "banoffee", "engender", "karpatka",
                         "othellolagkage"};
    size_t actual = findRotationPoint(words);
    cout << actual;
}
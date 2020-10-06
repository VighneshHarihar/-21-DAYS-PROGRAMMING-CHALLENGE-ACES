
// You created a game that is more popular than Angry Birds.

// Each round, players receive a score between 0 and 100, which you use to rank them from highest to lowest. So far you're using an algorithm that sorts in O(n\lg{n})O(nlgn) time, but players are complaining that their rankings aren't updated fast enough. You need a faster sorting algorithm.

// Write a function that takes:

// a vector of unsortedScores
// the highestPossibleScore in the game
// and returns a sorted vector of scores in less than O(n\lg{n})O(nlgn) time.

// I/P: {37, 89, 41, 65, 91, 53}
// O/P: {91, 89, 65, 53, 41, 37}
#include <iostream>
#include <vector>
#include <unordered_map>
// C++11 lest unit testing framework
//#include "lest.hpp"

using namespace std;

vector<int> sortScores(const vector<int> &unorderedScores, int highestPossibleScore)
{
    // sort the scores in O(n) time
    unordered_map<int, int> lookup;
    for (auto it : unorderedScores)
    {
        lookup[it]++;
    }
    vector<int> sortedVector;
    //int curretIndex = 0;

    for (int i = highestPossibleScore; i > 0; i--)
    {
        int count = lookup[i];

        for (int j = 0; j < count; j++)
            sortedVector.push_back(i);
    }
    return sortedVector;
}
int main()
{
    vector<int> scores{37, 89, 41, 65, 91, 53};

    auto ans = sortScores(scores, 100);
    for (auto it : ans)
    {
        cout << it << " ";
    }
}
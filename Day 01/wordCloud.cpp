#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;
vector<string> splits(string &str)
{
    vector<string> words;
    int wordIndex = 0, wordLength = 0;

    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        if (isalpha(ch))
        {
            if (wordLength == 0)
                wordIndex = i;
            wordLength++;
        }
        else
        {
            string current_word = str.substr(wordIndex, wordLength);
            words.push_back(move(current_word));
            wordLength = 0;
        }
    }
    return words;
}
unordered_map<string, int> populateWordsToCounts(string &str)
{
    vector<string> words = splits(str);

    unordered_map<string, int> wordCloud;
    for (int i = 0; i < words.size(); i++)
    {
        auto it = wordCloud.find(words[i]);
        if (it != wordCloud.end())
        {
            ++it->second;
        }
        else
        {
            wordCloud.insert(make_pair(words[i], 1));
        }
    }
    return wordCloud;
}
//7/7/2020 --- EDD:15/4/2021

int main()
{
    string str = "I like Like";
    //populateWordsToCounts(str);
    unordered_map<string, int> ans = populateWordsToCounts(str);
    for (auto it : ans)
    {
        cout << it.first << ": " << it.second << endl;
    }
}
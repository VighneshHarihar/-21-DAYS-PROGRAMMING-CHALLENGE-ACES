// Writing programming interview questions hasn't made me rich yet ... so I might give up and start trading Apple stocks all day instead.

// First,
// I wanna know how much money I could have made yesterday if I'd been trading Apple stocks all day.

//So I grabbed Apple's stock prices from yesterday and put them in a vector called stockPrices, where:

//The indices are the
//time(in minutes) past trade opening time,
//which was 9 : 30am local time.The values are the price(in US dollars) of one share of Apple stock at that time.So if the stock cost $500 at 10 : 30am, that means stockPrices[60] = 500.

//Write an efficient function that takes stockPrices
//and returns the best profit I could have made from one purchase and one sale of one share of Apple stock yesterday.

// No "shorting"—you need to buy before you can sell.Also,
// you can't buy and sell in the same time step—at least 1 minute has to pass.

#include <iostream>
#include <vector>
#include <algorithm>
// C++11 lest unit testing framework
//#include "lest.hpp"

using namespace std;
int getMaxProfit(const vector<int> &stockPrices)
{
    if (stockPrices.size() < 2)
    {
        throw invalid_argument("Getting a profit requires at least 2 prices");
    }

    // MyInitalSolution O(n^2)
    int maxProfit = 0;
    for (int i = 0; i < stockPrices.size(); i++)
    {
        for (int j = i + 1; j < stockPrices.size(); j++)
        {
            if (maxProfit == 0 && i == 0 && j == 1)
            {
                maxProfit = stockPrices[j] - stockPrices[i];
            }
            else if (maxProfit < stockPrices[j] - stockPrices[i])
            {
                maxProfit = stockPrices[j] - stockPrices[i];
            }
        }
    }

    // Optimised Solution O(n)
    //  int maxProfit = stockPrices[1] - stockPrices[0], minPrice = stockPrices[0];
    // for (int currentPrice : stockPrices)
    // {

    //     if (currentPrice > minPrice)
    //     {
    //         maxProfit = max(maxProfit, currentPrice - minPrice);
    //     }
    //     minPrice = min(minPrice, currentPrice);
    // }

    return maxProfit;
}
int main()
{
    int actual = getMaxProfit({7, 2, 8, 9});
    cout << actual; //Output should be 7
}
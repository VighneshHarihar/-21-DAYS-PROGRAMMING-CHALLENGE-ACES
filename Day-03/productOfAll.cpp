#include <iostream>
#include <vector>

using namespace std;
// vector<int> getProductofAllIntsBeforeIndex(vector<int> &intVector)
// {
//     int preCal = 1;
//     vector<int> beforeIndex;
//     for (int i = 0; i < intVector.size(); i++)
//     {
//         if (i == 0)
//         {

//             beforeIndex.push_back(preCal);
//         }
//         else
//         {
//             preCal *= intVector[i - 1];
//             beforeIndex.push_back(preCal);
//         }
//     }
//     return beforeIndex;
// }

// vector<int> getProductofAllIntsAfterIndex(vector<int> intVector)
// {
//     int preCal = 1;
//     vector<int> AfterIndex;
//     for (int i = intVector.size(); i >= 0; i--)
//     {
//         if (i == intVector.size())
//         {

//             AfterIndex[i] = preCal;
//         }
//         else
//         {
//             preCal *= intVector[i + 1];
//             AfterIndex[i] = preCal;
//         }
//     }
//     return AfterIndex;
// }

vector<int> getProductsOfAllIntsExceptAtIndex(const vector<int> &intVector)
{
    // make a vector with the products
    if (intVector.size() < 2)
    {
        throw invalid_argument("Getting a product required atleast 2 values");
    }
    vector<int> product;

    //MySolution O(n^2)
    int productCal = 1;
    for (int i = 0; i < intVector.size(); i++)
    {
        for (int j = 0; j < intVector.size(); j++)
        {
            if (j != i)
            {
                productCal *= intVector[j];
            }
        }
        product.push_back(productCal);
        productCal = 1;
    }

    //optimized solution

    return product;
}
int main()
{
    vector<int> actual = getProductsOfAllIntsExceptAtIndex({3, 1, 2, 5, 6, 4});
    for (auto it : actual)
    {
        cout << it << " ";
    }
}
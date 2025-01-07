#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int totalFruit(vector<int>& fruits)
    {
        unordered_map<int, int> fruitCount;
        int left = 0, maxFruits = 0;

        for (int right = 0; right < fruits.size(); ++right) 
        {
            fruitCount[fruits[right]]++;
            while (fruitCount.size() > 2)
            {
                fruitCount[fruits[left]]--;
                if (fruitCount[fruits[left]] == 0)
                {
                    fruitCount.erase(fruits[left]);
                }
                left++;
            }
            maxFruits = max(maxFruits, right - left + 1);
        }
        return maxFruits;
    }
};

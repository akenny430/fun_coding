#include <vector> 
#include <limits> 

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int price_low = std::numeric_limits<int>::max(); 
        int profit = 0; 
        for (const int& price : prices)
        {
            price_low = std::min(price, price_low); 
            profit = std::max(profit, price - price_low); 
        }
        return profit; 
    }
};
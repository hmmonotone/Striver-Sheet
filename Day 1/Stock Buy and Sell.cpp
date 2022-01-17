//Link to the problem
//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0,buy=prices[0],sell=prices[0];
        for(int i=0;i<prices.size();i++)
        {
            buy=min(buy,prices[i]);
            profit=max(profit,prices[i]-buy);
        }
        return profit;
    }
};

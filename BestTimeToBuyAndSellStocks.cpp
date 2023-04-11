class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxp=INT_MIN;
        int minp=INT_MAX;
        for(int i=0;i<prices.size();i++){
            minp=min(minp,prices[i]);//MINIMUM PRICE TILL THE ITH INDEX WE R TRYING TO BUY THE STOCKS AT THE EARLIEST 
            int currp=prices[i]-minp;//current profit if we sell at the ith day 
            maxp=max(maxp,currp);//maximise the profit 
        }
        return maxp;
    }
};

https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

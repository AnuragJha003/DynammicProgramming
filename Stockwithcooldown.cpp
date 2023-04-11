class Solution {
    private:
    int f(int ind,int buy,vector<int>& prices, vector<vector<int>>& dp){
        if(ind>=prices.size()){
            return 0;
        }
        if(dp[ind][buy]!=-1){
            return dp[ind][buy];
        }
        if(buy==1){
            return dp[ind][buy]=max(-prices[ind]+f(ind+1,0,prices,dp),0+f(ind+1,1,prices,dp));
        }
        return dp[ind][buy]=max(prices[ind]+f(ind+2,1,prices,dp),0+f(ind+1,0,prices,dp));
    }
    
    //cool down is once u sell a stock u cannot buy on the next day 
    
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size()+2,vector<int>(2,0));
        //return f(0,1,prices,dp);
        for(int ind=prices.size()-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                 if(buy==1){
                     dp[ind][buy]=max(-prices[ind]+dp[ind+1][0],0+dp[ind+1][1]);
        }
                else{
                    dp[ind][buy]=max(prices[ind]+dp[ind+2][1],0+dp[ind+1][0]);
            }
            }
        }
            
            return dp[0][1];
        }
};

https://www.codingninjas.com/codestudio/problems/highway-billboards_3125969?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

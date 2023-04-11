#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices, int n, int k)
{
    
     vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));//INITILASED WITH 0 SO  INITIALLY BASE COND KO LIKHNA 
    for(int ind=n-1;ind>=0;ind--){
        for(int buy=0;buy<=1;buy++){
        for(int cap=1;cap<=k;cap++){
             if(buy==1){
                 dp[ind][buy][cap]=max(-prices[ind]+dp[ind+1][0][cap],0+dp[ind+1][1][cap]);
    }
            else{
    dp[ind][buy][cap]=max(prices[ind]+dp[ind+1][1][cap-1],0+dp[ind+1][0][cap]);
            }
        }
    }
    }
    return dp[0][1][k];
    
    
    // Write your code here.
}

https://www.codingninjas.com/codestudio/problems/best-time-to-buy-and-sell-stock_1080698?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

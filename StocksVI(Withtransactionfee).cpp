#include <bits/stdc++.h> 
int maximumProfit(int n, int fee, vector<int> &prices) {
    // Write your code here.
     vector<vector<long>>dp(n+1,vector<long>(2,0));
    //return f(0,1,values,n,dp);
    dp[n][0]=dp[n][1]=0;//BASE CASE 
    for(int ind=n-1;ind>=0;ind--){//FLOW OF TABULATION ASSIGNMENT IS OPP TO THAT OF RECURSSION 
        for(int buy=0;buy<=1;buy++){
             long profit=0;
    if(buy){
        profit=max(-prices[ind]+dp[ind+1][0]-fee,dp[ind+1][1]);
    }
    else{
        profit=max(prices[ind]+dp[ind+1][1] , dp[ind+1][0]);
    }
     dp[ind][buy]=profit;
        }
    }
    
    return dp[0][1];
}
//SAME CODEE AS STOCKII JUST THE FEE IS SUBTRACTED AFTER A PURCHASE IS DONE 

https://www.codingninjas.com/codestudio/problems/rahul-and-his-chocolates_3118974?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

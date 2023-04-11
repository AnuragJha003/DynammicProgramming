#include<bits/stdc++.h>
long  f(int ind,int buy,long *values, int n,vector<vector<long>> &dp){
    if(ind==n){
        return 0;//EVEN IF WE R UNABLE TO SELL A STOCK AFTER BUYIGN IT ONCE WE REACH THE END WE WILL BE UNABLE TO CONTRIBUTE TO ITS PROFIT AS IT WILL NOT BE CONSIDERED 
    }//no more money u can get from this even if u r holding a stock 
    if(dp[ind][buy]!=-1)  return dp[ind][buy];
    long profit=0;
    if(buy){
        profit=max(-values[ind]+f(ind+1,0,values,n,dp),0+f(ind+1,1,values,n,dp));
    }//if u r allowed to buy u can buy and move ahead else dont buy and move ahead
    else{
        profit=max(values[ind]+f(ind+1,1,values,n,dp) , 0+f(ind+1,0,values,n,dp));
    }//if u r allowed to sell sell and move aheadn else dont sell and move ahead 
    return dp[ind][buy]=profit;
}
//PLAIN RECURSSION WILL GIVE TLE 
//MEMOIZATION



long getMaximumProfit(long *values, int n)
{
    vector<vector<long>>dp(n+1,vector<long>(2,0));
    //2 for the flag buy 0 and 1
    //return f(0,1,values,n,dp); buy flag 1 means can buy and 0 means cannot buy 
    dp[n][0]=dp[n][1]=0;//BASE CASE 
    for(int ind=n-1;ind>=0;ind--){//FLOW OF TABULATION ASSIGNMENT IS OPP TO THAT OF RECURSSION 
        for(int buy=0;buy<=1;buy++){
             long profit=0;
    if(buy){
        profit=max(-values[ind]+dp[ind+1][0],dp[ind+1][1]);
    }
    else{
        profit=max(values[ind]+dp[ind+1][1] , dp[ind+1][0]);
    }
     dp[ind][buy]=profit;
        }
    }
    
    return dp[0][1];//RETURNING ELMNT IS OPPOSITE OF TABULATION IN HERE SO WE RETURN THIS FLOW OF TABULATION WHEN COMPARED TO RECURSSION AND MEMEOIZATION IS COMPLETELY OPPOSITE
    
    
    
    
    //Write your code here
}

https://www.codingninjas.com/codestudio/problems/selling-stock_630282?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

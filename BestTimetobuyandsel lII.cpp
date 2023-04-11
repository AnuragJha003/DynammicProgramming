int f(int ind,int buy,int cap,vector<int> &prices,int n,vector<vector<vector<int>>> &dp){
    if(ind==n || cap==0){
        return 0;
    }//BASE CASE'
    if(dp[ind][buy][cap]!=-1){
        return dp[ind][buy][cap];
    }
    if(buy==1){
        return dp[ind][buy][cap]=max(-prices[ind]+f(ind+1,0,cap,prices,n,dp),0+f(ind+1,1,cap,prices,n,dp));
    }
    return dp[ind][buy][cap]=max(prices[ind]+f(ind+1,1,cap-1,prices,n,dp),0+f(ind+1,0,cap,prices,n,dp));
}

//ONLY RECURSSION WILL GIVE TLE 

int maxProfit(vector<int>& prices, int n)
{
    vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));//INITILASED WITH 0 SO  INITIALLY BASE COND KO LIKHNA 
    for(int ind=n-1;ind>=0;ind--){//3 nested loops in direction opp to recurrance
        for(int buy=0;buy<=1;buy++){
        for(int cap=1;cap<=2;cap++){
             if(buy==1){
                 dp[ind][buy][cap]=max(-prices[ind]+dp[ind+1][0][cap],0+dp[ind+1][1][cap]);
    }
            else{
    dp[ind][buy][cap]=max(prices[ind]+dp[ind+1][1][cap-1],0+dp[ind+1][0][cap]);
            }
        }
    }
    }
    return dp[0][1][2];
    
    
    
    //return f(0,1,2,prices,n,dp);
    // Write your code here.
}

https://www.codingninjas.com/codestudio/problems/buy-and-sell-stock_1071012?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

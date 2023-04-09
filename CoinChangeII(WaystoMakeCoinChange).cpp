#include<bits/stdc++.h>

long f(int ind,int t,int *a, vector<vector<long>> &dp){
    if(ind==0){
        return(t%a[0]==0);//infinte time toh 
    }//just like minimum coins problem 
    if(dp[ind][t]!=-1) return dp[ind][t];
    long nt=f(ind-1,t,a,dp);
    long take=0;
    if(a[ind]<=t) take=f(ind,t-a[ind],a,dp);
    //can take infinite times toh 
    return dp[ind][t]=nt+take;
}


//ONLY REC WILL GIVE TLE 

long countWaysToMakeChange(int *denominations, int n, int value)
{
    //vector<vector<int>> dp(n,vector<int>(value+1,-1));
    //return f(n-1,value,denominations,dp);
    vector<vector<long>> dp(n,vector<long>(value+1,0));
    for(int t=0;t<=value;t++){
        dp[0][t]=(t%denominations[0]==0);
    }//BASE CASE WLAA
    for(int ind=1;ind<n;ind++){
        for(int t=0;t<=value;t++){//nested loops for tab in opp sense of recursion this is 
            long  nt=dp[ind-1][t];
            long  take=0;
            if(denominations[ind]<=t) take=dp[ind][t-denominations[ind]];
            dp[ind][t]=nt+take;
        }
    }
    return dp[n-1][value];
    //Write your code here
}

https://www.codingninjas.com/codestudio/problems/ways-to-make-coin-change_630471?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
https://leetcode.com/problems/coin-change-ii/

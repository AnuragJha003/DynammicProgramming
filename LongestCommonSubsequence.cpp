#include<bits/stdc++.h>

int f(int i,int j,string &s, string &t,vector<vector<int>> &dp){
    if(i<0 || j<0){
        return 0;
    }//if negative index for any one of them then gg ho rkha h 
    if(dp[i][j]!=-1) return dp[i][j];
    if(s[i]==t[j]){
        return dp[i][j]= 1+f(i-1,j-1,s,t,dp);// 1 added as it is the length of the longest common subsequence of the two strings gg 
    }//equal h then i-1 j-1 
    return dp[i][j]= 0+max(f(i-1,j,s,t,dp),f(i,j-1,s,t,dp));
}//max length of lcs so max of i-1 j and i j-1 

//ONLY RECURSSION GIVES TLE 
//MEMOIZATION 
//TABULATION 1 SHIFTED INDEX USED AND SO RECURSSION INDEX MODIFIED BY DOING -1 TO IT ELSE SHD BE ADDED IN THE NESTED FOR LOOP OR ELSE IT GOES BACK FROM THERE

int lcs(string s, string t){
    int n=s.size();int m=t.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    //return f(n-1,m-1,s,t,dp);//i and j for the two trings traversal 
    //TABULATION CODE 
   //THESE 2 FOR LOOPS MAYBE OMITTED IF INITILASED WITH 0 
    for(int j=0;j<m;j++)  dp[0][j]=0;
    for(int i=0;i<n;i++)  dp[i][0]=0;//BASE CASE YA INITILASIE WITH 0 
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1]==t[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
        }
    }
    return dp[n][m];    
}
//recurssion for generating all subsequences u will get tle take a particular char or not take type
//vector string types 

https://www.codingninjas.com/codestudio/problems/longest-common-subsequence_624879?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
https://leetcode.com/problems/longest-common-subsequence/

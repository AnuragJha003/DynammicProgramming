#include<bits/stdc++.h>
int f(int i,int j,string str1,string str2,  vector<vector<int>> &dp){
    if(i<0){
        return j+1;
    }//string1 gets exhausted 
    //negative index means empty string toh so no of operations is j+1
    if(j<0){
        return i+1;
    }//if string2 gets exhausted 
        //negative index means empty string toh so no of operations is i+1

    if(dp[i][j]!=-1) return dp[i][j];
    if(str1[i]==str2[j]) return dp[i][j]=f(i-1,j-1,str1,str2,dp);//if they r mathcing we keep the common part in tact
    return dp[i][j]=1+min({f(i,j-1,str1,str2,dp),f(i-1,j,str1,str2,dp),f(i-1,j-1,str1,str2,dp)});
                         //insert it(I WILL STAY WHERE IT IS AS INSERTION DONE AHEAD AND J-1)       //deletee this ith char(I-1 AND J WILL BE AS IT IS ANS I IS DELETED )         //replace the chars(BOTH I AND J--) 
}

int editDistance(string str1, string str2)
{
    int n=str1.size();int m=str2.size();
    //DP N AND M FOR COMPLEXITY 
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    //return f(n-1,m-1,str1,str2,dp);
    //1 added to the index and shifted in here for performance 
    for(int i=0;i<=n;i++){
        dp[i][0]=i;
    }
    for(int j=0;j<=m;j++){
        dp[0][j]=j;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
              if(str1[i-1]==str2[j-1]) dp[i][j]=dp[i-1][j-1];
              else dp[i][j]=1+min({dp[i][j-1],dp[i-1][j],dp[i-1][j-1]});
        }
    }
    return dp[n][m];
    //write you code here
}

https://www.codingninjas.com/codestudio/problems/edit-distance_630420?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
https://leetcode.com/problems/edit-distance/

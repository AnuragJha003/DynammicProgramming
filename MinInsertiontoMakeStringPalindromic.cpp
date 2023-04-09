#include<bits/stdc++.h>

int lcs(string s, string t)
{
    int n=s.size();int m=t.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    //return f(n-1,m-1,s,t,dp);
    //TABULATION CODE 
    for(int j=0;j<m;j++) dp[0][j]=0;
    for(int i=0;i<n;i++) dp[i][0]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1]==t[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
        }
    }
    return dp[n][m];
    
    //Write your code here
}

//max will be the lenght of the strings as abc not palindrom 
//abc + rev(abc)=abccba palindrome:)
//for minimum we need to keep the longest palindromic subsequence intact in here 
//no of insertions will be the n-lps 

int longestPalindromeSubsequence(string s)
{
    // Write your code here.
    string t=s;
    reverse(t.begin(),t.end());
    return lcs(s,t);
    
    
    
    
    
}
int minInsertion(string &str)
{
    // Write your code here.
    return str.size()-longestPalindromeSubsequence(str); 
}

https://www.codingninjas.com/codestudio/problems/minimum-insertions-to-make-palindrome_985293?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0
https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/

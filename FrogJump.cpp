#include<bits/stdc++.h>

//int f(int ind, vector<int> &heights,vector<int> &dp){
//    //if(ind==0) return 0;
//    if(ind==0)  return dp[ind]=0;
//if(dp[ind]!=-1) return dp[ind];
//int right=INT_MAX;
//int left=f(ind-1,heights,dp)+abs(heights[ind]-heights[ind-1]);
//if(ind>1) right=f(ind-2,heights,dp)+abs(heights[ind]-heights[ind-2]);
//return dp[ind]=min(left,right);

//}
//PLAIN RECURSSION LIKE THIS GIVES TLE 



int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    vector<int> dp(n+1,-1);//MEMOIZATION STEP TO STORE VALUES OF RECURRENCE 
    //return f(n-1,heights,dp);
  //TABULARIZATION METHOD GIVEN DOWN
    //dp[0]=0;//BASE TYPE 
    /*for(int i=1;i<n;i++){
        int fs=dp[i-1]+abs(heights[i]-heights[i-1]);
        int ss=INT_MAX;
        if(i>1){
            ss=dp[i-2]+abs(heights[i]-heights[i-2]);
        }
        dp[i]=min(fs,ss);
    }*/
    //return dp[n-1];//ANSWER WILL BE STORED AT LAST INDEX AND SINCE THERE R N SO LAST INDEX OF DP ARRAY WILL BE N-1 
}
https://www.codingninjas.com/codestudio/problems/frog-jump_3621012?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

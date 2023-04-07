class Solution {
public:
//int memo[46] = {0};
    int f(int n,vector<int>& dp){
        if(n<=2){
            return n;
        }
        if(dp[n]!=-1)return dp[n];
        return dp[n]=f(n-1,dp)+f(n-2,dp);
    }
int climbStairs(int n) {
/*memo[0] = 0;
memo[1] = 1;
memo[2] = 2;
for(int i =3;i < 46;i++)
memo[i] = memo[i-1] + memo[i-2];
return memo[n];*/
    vector<int> dp(n+1,-1);
    int ans=f(n,dp);
    return ans;
}
};


https://leetcode.com/problems/climbing-stairs/


#include<bits/stdc++.h>

int solve(long long n,vector<int>&t){
if(n==0||n==1){
return 1;//BASE CONDITION 
}//0 m aagye toh possible h and if 1 pe ho u can only use thhe 1 step jump process gg issliye 1 aa rha 
if(t[n]!=-1){
return t[n];
}//IF DP HAS MARKED VALUE MEANS KUCH VALUE INITILASED H OTHER THAN DEFAULT VALUE SO return it 
int left=solve(n-1,t)%1000000007;//ONE STEP JUMP 
int right=0;
if(n>=2){
   right=solve(n-2,t)%1000000007;//2 STEP JUMP JUST CHECKED KI JYADA NHI HO JAYE ISSLIYE IF COND GIVEN 
}
return t[n]=(left+right)%1000000007;//T[N] INITILSED HERE WITH THE SUM OF BOTH POSSIBLE WAYS 
}

int countDistinctWays(long long nStairs)
{
vector<int>t(nStairs+1,-1);//DP VECTOR IN WHICH WE WILL BE STORING THESE 
return solve(nStairs,t)%1000000007;//RECURSSIVE FNC BEING CALLED 
   //  Write your code here.
}

https://www.codingninjas.com/codestudio/problems/count-ways-to-reach-nth-stairs_798650?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

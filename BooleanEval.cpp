#include <bits/stdc++.h>
const int mod=1000000007;
long long f(int i,int j,int isTrue,string & exp,vector<vector<vector<long long>>> &dp){
    if(i>j) return 0;
    if(i==j){
        if(isTrue){
            return exp[i]=='T';//if looking for true 
        }
        else{
            return exp[i]=='F';//if looking for false
        }
    }
    //the final result shpuld be true and at single partition the above base case holds 
    if(dp[i][j][isTrue]!=-1) return dp[i][j][isTrue];
    long long ways=0;//no of ways initially 
    for(int ind=i+1;ind<=j-1;ind+=2){
        long long lt=f(i,ind-1,1,exp,dp);
        long long lf=f(i,ind-1,0,exp,dp);
        long long rt=f(ind+1,j,1,exp,dp);
        long long rf=f(ind+1,j,0,exp,dp);
        //left partiiton required true/false then and right partition required false/true then 
        
        if(exp[ind]=='&'){
            if(isTrue) ways=(ways+(rt*lt)%mod)%mod;//if u need true so both has to be true
            else ways=(ways+(rt*lf)%mod+(rf*lt)%mod+(lf*rf)%mod)%mod;//else if u need false any one of them has to be false
        }
        else if(exp[ind]=='|'){//if it is or 
            if(isTrue) ways=(ways+(rt*lt)%mod +(rf*lt)%mod+(lf*rt)%mod)%mod;//any one can be true and it will be true
            else ways=(ways+(lf*rf)%mod)%mod;//for false both has to be false
        }
        else{//if index of partitioning is xor 
            if(isTrue) ways=(ways+(lt*rf)%mod+(lf*rt)%mod)%mod;//if it is true then both have to be diff
            else ways=(ways+(lf*rf)%mod+(lt*rt)%mod)%mod;//else for false then both have to be same 
        }
    }
    return dp[i][j][isTrue]=ways;
    
}
//RECURSSION CODE WRITTEN WAY TOO BIG BUT OKK LOGICAL TLE FOR LARGE TEST CASES




int evaluateExp(string & exp) {
    // Write your code here.
    int n=exp.size();
    vector<vector<vector<long long>>>dp(n,vector<vector<long long>>(n,vector<long long>(2,-1)));
    return f(0,n-1,1,exp,dp);
    //0 the left partion index and n-1 is the final partition index finally and 1 is istrue flag and exp is passed as the statement 
}
https://www.codingninjas.com/codestudio/problems/problem-name-boolean-evaluation_1214650?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

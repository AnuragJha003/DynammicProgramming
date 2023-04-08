class Solution {
public:
    bool f(int ind,int target,vector<int> &arr, vector<vector<int>> &dp){
    if(target==0) return true;
    if(ind==0) return (arr[ind]==target);
    if(dp[ind][target]!=-1) return dp[ind][target];
    bool nottake=f(ind-1,target,arr,dp);
    bool take=false;
    if(target>=arr[ind]){
        take=f(ind-1,target-arr[ind],arr,dp);
    }
    return dp[ind][target]=take|nottake;
}

    
    bool canPartition(vector<int>& arr) {
        	// Write your code here.
    int s=0;
    for(auto x:arr){
        s=s+x;
    }
    //even hona hoga toh for partition 
    if(s%2!=0){
        return false;
    }
    else{
    int k=s/2;
        int n=arr.size();
    //target as k in the array 
    vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
    return f(n-1,k,arr,dp);
    }
    
    
    
    }
};

https://leetcode.com/problems/partition-equal-subset-sum/

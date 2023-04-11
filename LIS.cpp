
class Solution {
public:
    int lnds(vector<int>& nums, int i,int prev, vector<vector<int>>&dp){
        if(nums.size()==i)return 0;
        
        if(dp[i][prev+1]!=-1)return dp[i][prev+1];                //prev+1 in dp because of grid have no -1 index to handle  this we use coordinate shift by +1
         int maxi=-1e9, not_take=0, take=0;
        
         not_take=0+lnds(nums, i+1, prev,dp);//not take index i moved ahead just 
         if(prev==-1 || nums[i]>nums[prev]){
            take= 1+lnds(nums, i+1, i,dp);  
        }//u can take only if prev is the very first u can for the first case as no prev and 
        //u can take if the current elmnt is greater than prev and it is a increasing subsequence 
         maxi=max(take, not_take);//take the maximum 
        return dp[i][prev+1]=maxi;
    }
    //f(3,0) length of LIS starting from 3rd index whose prev index is 0 
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>>dp(nums.size(), vector<int>(nums.size()+1, -1));
        return lnds(nums, 0, -1, dp);
        //ind is the traversal for index on the nums array and prev is for checking if increasing sequence or not 
    }
};//DP WITH MEMOIZATION  

https://leetcode.com/problems/longest-increasing-subsequence/

class Solution {
public:
    int findNumberOfLIS(vector<int>& arr) {
        int n=arr.size();
    vector<int> dp1(n,1);
    vector<int> count(n,1);
    int maxi=1;
    for(int i=0;i<n;i++){
        for(int prev=0;prev<i;prev++){
            if(arr[prev]<arr[i] && 1+dp1[prev]>dp1[i]){
                dp1[i]=dp1[prev]+1;
                count[i]=count[prev];//COPY THE COUNT NO PROBLEM 
                //THE SAME LIS IS BEING CONTINUED IN HERE
            }
            else if(arr[prev]<arr[i] && 1+dp1[prev]==dp1[i]){//IF LENGTH EQUAL 
                count[i]+=count[prev];//LENGTH OF LIS IS EQUAL 
            }//SO THIS ELSE IF INCREASE THE COUNT OF THE EQUAL SIZED  LIS OCCURING 
        }maxi=max(maxi,dp1[i]);//STORE THE MAXIMUM OF THE LIS STARTING FROM THE FRONT INDEX
    }
    int ans=0;
    for(int i=0;i<n;i++){
        if(dp1[i]==maxi){//IF LENGTH OF LIS ENDING AT INDEX I IS MAXI IS SAME
            ans=ans+count[i];//ADD THE COUNT / NO OF LIS AT THAT INDEX TO THE ANSWER 
        }
    }//ANS IS SUMMING UP THE TOTAL COUNTS OF LIS POSSIBLE IN THE ARRAY 
    return ans;
    // Write your code here.
    }
};

https://www.codingninjas.com/codestudio/problems/number-of-longest-increasing-subsequence_3751627?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
https://leetcode.com/problems/number-of-longest-increasing-subsequence/

#include <bits/stdc++.h> 
int longestBitonicSequence(vector<int>& arr, int n) {
    vector<int> dp1(n,1);
    vector<int> dp2(n,1);
    for(int i=0;i<n;i++){
        for(int prev=0;prev<i;prev++){
            if(arr[prev]<arr[i] && 1+dp1[prev]>dp1[i]){
                dp1[i]=dp1[prev]+1;
            }
        }
    }
    for(int i=n-1;i>=0;i--){
        for(int prev=n-1;prev>i;prev--){
            if(arr[prev]< arr[i] && dp2[prev]+1>dp2[i]){
                dp2[i]=dp2[prev]+1;
            }
            
        }
    }
    //longest increasing and longest decreasing are both bitonic inceeasing /decreasing portion
    int maxi=0;
    for(int i=0;i<n;i++){
        maxi=max(maxi,dp1[i]+dp2[i]-1);
    }
    return maxi;
} 
//LIS FROM THE FRONT AND LIS FROM THE BACK INCREASING FROM FRONT .... INCREASING FROM BACK ...////\\\\INCREASING DECREASING 
//DP1 LIS FROM FRONT INDEX AND DP2 STORED THE LIS FROM THE BACK INDEX 
//LENGTH OF BITONIC FOR A GIVEN INDEX I DP1[I]+DP2[I]-1;MAX 

https://www.codingninjas.com/codestudio/problems/longest-bitonic-sequence_1062688?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos



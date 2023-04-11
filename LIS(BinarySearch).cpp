#include<bits/stdc++.h>
int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int>temp;
    temp.push_back(arr[0]);//TEMP IS ALREADY STORING 1ST ELMNT 
    for(int i=1;i<n;i++){
        if(arr[i]>temp.back()){
            temp.push_back(arr[i]);//LARGER ELMNT 
        }//IF LARGER ELMNT SIMPLY PUSH BACK 
        else{
             int ind=lower_bound(temp.begin(),temp.end(),arr[i])-temp.begin();//POINTS TO THE INDEX HAVING FIRST ELMNT GREATER THAN  ARR[I]
            temp[ind]=arr[i];//BINARY SEARCH DONE AND LARGER ELMNT REPLACED STORING IT IN TEMP
        }
    }//WILL NOT GIVE CORRECT LIS BUT LENGHT WILL BE CORRECT
    return temp.size();//LIS WILL NOT BE CORRECT BUT THE LENGTH WILL BE 
}
//THIS IS A NLOGN APPROACH AS THIS WILL WORK FOR LARGE TEST CASES TOO 

https://www.codingninjas.com/codestudio/problems/longest-increasing-subsequence_630459?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

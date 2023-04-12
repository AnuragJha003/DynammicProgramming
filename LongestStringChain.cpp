#include <bits/stdc++.h> 
bool compare(string& s1, string& s2){
    if(s1.size() != s2.size() + 1) return false;
    //IF DIFFERENCE BETWEEN SIZE IS >1 THEN FLASE
    
    int first = 0;
    int second = 0;//POINTERS TO THE  STRING S1 AND S2 
    //S1 SIZE WILL BE MORE THAN EQUAL TO S2 
    while(first < s1.size()){//POINTER TAKEN ON S1
        if(second < s2.size() && s1[first] == s2[second]){
            first ++;
            second ++;
        }//EQUAL WE MOVE BOTH THE POINTERS AHEAD 
        else first ++;//WE MOVE THE FIRST POINTER TO S1 AHEAD 
    }
    if(first == s1.size() && second == s2.size()) return true;//IF BOTH REACH TILL THE END SIMULTANEOULY THEN TRUE
    //BDC BDCA B D C MATCH SECOND DOES NOT REACH END SO NO 
    else return false; 
}

bool comp(string& s1, string& s2){
    return s1.size() < s2.size();
}//SORTED ACCORDINGH TO THE LENGHT MAKE IT  A SUBSEQUENCE FOR CONVERTING SUBSET INTO SUBSEQUENCE 

int longestStrChain(vector<string> &arr)
{
    // Write your code here.
        int n = arr.size();
    
    //sort the array TO CONVERT THE SUBSET PROBLEM INTO A SUBSEQUENCE PROBLEM FOR OUR PROBLEM 
    sort(arr.begin(), arr.end(),comp);//NLOGN 

    vector<int> dp(n,1);
    
    int maxi = 1;
    
    for(int i=0; i<=n-1; i++){
        
        for(int prev_index = 0; prev_index <=i-1; prev_index ++){
            //TC IS O(N2* CHECK (ITERATING OVER THE STRING LENGTH IN HERE))
            if( compare(arr[i], arr[prev_index]) && 1 + dp[prev_index] > dp[i]){
                dp[i] = 1 + dp[prev_index];
            }
        }
        
        if(dp[i] > maxi)
            maxi = dp[i];
    }
    return maxi;
}

https://leetcode.com/problems/longest-string-chain/
https://www.codingninjas.com/codestudio/problems/longest-string-chain_3752111?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

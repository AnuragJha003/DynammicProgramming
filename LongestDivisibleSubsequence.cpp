#include <bits/stdc++.h> 
vector<int> divisibleSet(vector<int> &arr){
    int n=arr.size();
    sort(arr.begin(),arr.end());//SORTED TO ENSURE ARR[I]>=AR[J]
    //AFTER SORTING IT WILL BE MUCH LIKE LIS IT WILL BECOME 
    //LIKE A LONGEST DIVISIBLE SUBSEQENCE (JUST CHANGE IN THE IF CONDITION )
    vector<int> dp(n,1),hash(n);
    int maxi=1;int li=0;
    for(int i=0;i<n;i++){//TRAVERSING ALL INDEX 
        hash[i]=i;//HASH TO STORE PREVIOUS INDEX IN THE LONGEST DIVISIBLE SUBSEQUNCE
        for(int prev=0;prev<i;prev++){//CHECLING TH EPREVIOUS 
            if(arr[i]%arr[prev]==0 && dp[i]<dp[prev]+1){
                //IF DIVISIBLE AND LENGHT MORE 
                dp[i]=dp[prev]+1;//STORE THE LENGHT OF THE LONGEST DIVISIBLE SUB TILL ITH INDEX
                hash[i]=prev;//STORE THE PRVIOUS ELMNT INDEX TO THE CURRENT ELMNT IN THE LONGEST DIVISIVLE SUBSET
            }
        }
        if(dp[i]>maxi){
            maxi=dp[i];
            li=i;//STORE THE MAX LENGHT AND POSSIBLE LAST INDEX OF THE LONGES TDIVISILE SUBSEWQUENCE 
        }
    }
    vector<int> temp;
    temp.push_back(arr[li]);//STORE THE TEMP
    while(hash[li]!=li){
        li=hash[li];
        temp.push_back(arr[li]);
    }//PUSH ALL ELMNT OF THE LONGEST DIVISIBLE SUBSEQUQENCE BY TRACING BACK THE ELMNTS USING THE HASH VECTOR
    reverse(temp.begin(),temp.end());//REVERSE AS TAKEN FROM THE END 
    //for(auto it:temp) cout<<it<<" ";
    //cout<<endl;
    return temp;
    
    
    // Write your code here.
    }
    
    https://www.codingninjas.com/codestudio/problems/divisible-set_3754960?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
    https://leetcode.com/problems/largest-divisible-subset/

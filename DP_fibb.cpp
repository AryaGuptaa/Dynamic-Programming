#include<iostream>
#include<vector>
using namespace std; 

// using reccursion

int usingRecc(int n){
    //base case
    if(n== 0 || n==1){
        return n;
    }
    //recc
    int ans = usingRecc(n-1) + usingRecc(n-2);
    return ans;
}

// using memoization

int usingMemo(int n, vector<int> &dp){
    //base case
    if(n==0 || n==1){
        return n;
    }
    // return if already exist
    if(dp[n] != -1){
        return dp[n];
    }
    //store and return using recc
    dp[n] = usingMemo(n-1, dp) + usingMemo(n-2,dp);
    return dp[n];
}

// using tabulation

int usingTabu(int n){
    vector<int>dp(n+1,-1); // create dp array

    dp[0]=0; //analyse base case
    if(n==0){
        return 0;
    }
    dp[1]=1;

    for(int i =2; i<=n;i++){ //fill the remaining array
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

//using space optimized

int usingSpaceOpt(int n){
    int prev = 0;
    if(n==0){
        return 0;
    }
    int curr =1;
    if(n==1){
        return 1;
    }
    int ans;
    for(int i =2 ;i<=n;i++){
        ans = curr+prev;
        prev= curr;
        curr = ans;
    }
    return ans;
}


int main(){

    // int num = usingRecc(6);
    // cout<<num<<endl;
    
    // int n =6;
    // vector<int> dp(n+1, -1);
    // int num = usingMemo(n,dp);
    // cout<<num<<endl;

    // int num = usingTabu(7);
    // cout<<num<<endl;

    cout<<usingSpaceOpt(6)<<endl;

    return 0;
}
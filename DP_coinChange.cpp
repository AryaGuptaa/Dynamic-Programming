#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

// using reccursion

int usingRecc(vector<int> & coins, int amount){
    if(amount ==0){
        return 0;
    }

    int mini = INT_MAX;

    for(int i =0; i<=coins.size();i++){
        if(amount-coins[i] >= 0){
            int reccAns = usingRecc(coins, amount- coins[i]);
            if(reccAns!= INT_MAX){ 
                int ans = 1 + reccAns;
                mini = min(mini, ans);
            }
        }
    }
    return mini;
}

//using memoization

int usingMemo(vector<int> & coins, int amount, vector<int> & dp){
    if(amount == 0){
        return 0;
    }

    int mini = INT_MAX;

    if(dp[amount] != -1){
        return dp[amount];
    }

    for(int i =0; i<=coins.size();i++){
        if(amount-coins[i] >= 0){
            int reccAns = usingMemo(coins, amount- coins[i],dp);
            if(reccAns!= INT_MAX){ 
                int ans = 1 + reccAns;
                mini = min(mini, ans);
            }
        }
    }
    dp[amount]= mini;
    return dp[amount];
}

// using tabulation

int usingTabu(vector<int> & coins, int amount){
    int n = amount;
    vector<int> dp(n +1,INT_MAX);

    dp[0]= 0;

    for(int value =1; value <= amount; value++){
        int mini = INT_MAX;
        for(int i =0; i< coins.size(); i++){
            if(value - coins[i] >= 0){
                int reccAns = dp[value-coins[i]];
                if(reccAns!= INT_MAX){ 
                    int ans = 1 + reccAns;
                    mini = min(mini, ans);
                }
            }
        }
        dp[value] = mini;
    }
    return dp[amount];
}

int coinChange(vector<int> & coins, int amount){

    // int ans =usingRecc(coins,amount);

    // int n = amount;
    // vector<int> dp(n +1,-1);
    // int ans = usingMemo(coins,amount,dp);

    int ans = usingTabu(coins, amount);

    if(ans != INT_MAX){
        return ans;
    }
    else{
        return -1;
    }

}

int main(){

    vector<int> coins;
    coins= {1,2,5};
    int amount = 11;
    cout<<coinChange(coins,amount)<<endl;

    return 0;
}

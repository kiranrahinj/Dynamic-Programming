//In this problem there is big Twist.
//Initialization of base cond. is little bit tricky.Means think as per input
//Then initialize the 1 row with their value
//Here Twist is the minor changes as per old code.

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int coinChange(vector<int>& coins, int sum ) {
    int n=coins.size();
    ll amount=sum;
    ll t[n+1][amount+1];

// Twist 1
    for(int i=0;i<=n;i++)t[i][0]=0;
    for(int i=0;i<=amount;i++)t[0][i]=INT_MAX;

// Twist 2
    for(int j=1;j<=amount;j++){
        if(j%coins[0]==0)t[1][j]=j/coins[0];
        else
         t[1][j]=INT_MAX;
    }
    for(int i = 2; i <= n; i++) {
        for(int j = 1; j <= amount; j++) {
            if(coins[i - 1] <= j) {
// Twist 3
                if(t[i][j - coins[i - 1]] != INT_MAX)
                    t[i][j] = min(1 + t[i][j - coins[i - 1]], t[i - 1][j]);
                else
                    t[i][j] = t[i - 1][j];
            } else {
                t[i][j] = t[i - 1][j];
            }
        }
    }
    return t[n][amount]==INT_MAX ? -1:t[n][amount];
}


int main(){
    vector<int>coins{1,2,5};
    int amount=11;
    
    cout<<coinChange(coins,11);
    return 0;
}


///our solution:

//Here that above condition is satiesfy our sol.
//INT_MAX-1 -> we are adding one in it INT_MAX-1+1 ==> INT_MAX
int coinChange(vector<int>& coins, int sum ) {
    int n=coins.size();
    ll amount=sum;
    ll t[n+1][amount+1];

    for(int i=0;i<=n;i++)t[i][0]=0;
    for(int i=0;i<=amount;i++)t[0][i]=INT_MAX-1; // 1

    for(int j=1;j<=amount;j++){
        if(j%coins[0]==0)t[1][j]=j/coins[0];
        else
         t[1][j]=INT_MAX-1;                      // 2
    }
    for(int i = 2; i <= n; i++) {
        for(int j = 1; j <= amount; j++) {
            if(coins[i - 1] <= j) {
                t[i][j] = min(1 + t[i][j - coins[i - 1]], t[i - 1][j]); //3
            } else {
                t[i][j] = t[i - 1][j];
            }
        }
    }
    return t[n][amount]==INT_MAX-1? -1:t[n][amount];
}
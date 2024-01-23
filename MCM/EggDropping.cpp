#include <bits/stdc++.h>
using namespace std;

//this is the memoization code.
int t[201][201];
int solve1(int e,int f){
    if(e==1)return f;
    if(f==0 || f==1)return f;
    
    if(t[e][f]!=-1)return t[e][f];
    int temp=INT_MAX;
    
    for(int k=1;k<=f;k++){
        
        int mn=1+max(solve(e,f-k),solve(e-1,k-1));
        temp=min(temp,mn);
    }
    return t[e][f]=temp;
}

//little bit optimised code.
int t[201][201];
    int solve(int e,int f){
        if(e==1)return f;
        if(f==0 || f==1)return f;
        
        if(t[e][f]!=-1)return t[e][f];
        int temp=INT_MAX;
        
        for(int k=1;k<=f;k++){
        	int low,high;
            if(t[e-1][k-1]!=-1){
            	low=t[e-1][k-1];
            }
            else{
            	low=solve(e-1,k-1);
            	t[e-1][k-1]=low; 
            }
    
            if(t[e][f-k]!=-1){
            	high=t[e][f-k];
            }
            else{
                high=solve(e,f-k);
            	t[e][f-k]=high; 
            }
    
            int mn=1+max(low,high);
            temp=min(temp,mn);
        }
        return t[e][f]=temp;
    }

int eggDrop(int n, int k) 
{
    memset(t,-1,sizeof(t));
    return solve(n,k);
}

int main(){
	cout<<eggDrop(1,3);
	return 0;
}


// ========================================================================================
// More optimised using BS
class Solution {
public:
    //Time: O(n*k*logn), Space: O(n*k)
    int helper(int k, int n, vector<vector<int>>& memo){
        if(n == 0 || n == 1) return n;
        if(k == 1) return n;
        
        if(memo[k][n] != -1) return memo[k][n];
        
        int mn = INT_MAX, low = 0, high = n, temp = 0;
        
        while(low<=high){
            
            int mid = (low + high)/2;
            
            /*representing both the choices with memo
            First one, if the egg will break, no. of eggs will decreased and we have to
            down from that floor.
            Second one, if the egg will not break, no. of eggs will not decreased and we
            have to go above form that floor.*/
            
            int left = helper(k-1, mid-1, memo);
            int right = helper(k, n-mid, memo);
            
            temp = 1 + max(left, right);
            
            //since we need more temp value in worst case, so need to go above
            if(left < right) 
                low = mid+1;
            else 
                high = mid-1;     //move to the downward
    
            mn = min(mn, temp); //minimum number of attempts
        }
        return memo[k][n] = mn;
    }
    
    int superEggDrop(int k, int n) {
        //k means number of eggs, n means number of floors
        vector<vector<int>> memo(k+1, vector<int>(n+1, -1));
        return helper(k, n, memo);
    }
};


//top down
class Solution {
public:
    
    int superEggDrop(int K, int N) {
        if(N==0||N==1) return N;     //Think for base case
        if(K==1) return N;
        
        vector<vector<int>> dp(K+1,vector<int> (N+1,0));
      for(int i=0;i<=K;i++)
        dp[i][0]=0,dp[i][1]=1;   //Filling from base case as if N==0 ans=0 , N==1 ans=1
      for(int i=0;i<=N;i++)
        dp[0][i]=0,dp[1][i]=i;   //Filling from base case as if K==0 ans=0 , K==1 ans=N, number of current floor (i)
        
        for(int i=2;i<K+1;i++)
        {
            for(int j=2;j<N+1;j++)
            {    int l=1,h=j,temp=0,ans=100000;
                 while(l<=h)
                 {
                    int mid=(l+h)/2;
                    int left= dp[i-1][mid-1]; //egg broken check for down floors of mid
                    int right= dp[i][j-mid];  // not broken check for up floors of mid
                    temp=1+max(left,right);          //store max of both 
                    if(left<right){                  //since right is more than left and we need more in worst case 
                      l=mid+1;                       // so l=mid+1 to gain more temp for worst case : upward
                    }
                    else                             //left > right so we will go downward 
                    {    
                        h=mid-1;
                    }
                    ans=min(ans,temp);               //store minimum attempts
                 }
                 dp[i][j]=ans;
            }
        }
        return dp[K][N];
         
    }
};
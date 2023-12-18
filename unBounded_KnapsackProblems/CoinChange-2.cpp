//this problem contains how many times u can get sum
//same step of 0-1 knapsack count subset problem just minor change 

#include <bits/stdc++.h>
using namespace std;

int main(){
	vector<int>coins{1,2,3,4,5};
	int sum=5,n=coins.size();

	int t[n+1][sum+1];

	for(int i=0;i<=n;i++)t[i][0]=1;
	for(int i=0;i<=sum;i++)t[0][i]=0;
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=sum;j++){
			if(coins[i-1]<=j){
				t[i][j]=t[i][j-coins[i-1]]+t[i-1][j];
			}
			else
				t[i][j]=t[i-1][j];
		}
	}	
	cout<<t[n][sum];
	return 0;
}
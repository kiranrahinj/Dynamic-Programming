//We have to find subsets having given diff.
//We are clueless for that two subsets having given diff
// s1-s2=diff. but we know s1+s2=sum; //here sum is total array sum;
// Simple maths: We are adding those eqn= s1-s2+s1+s2=diff+sum
//op: 2s1=sum+diff . s1=(sum+diff)/2 / (sum-diff)/2 Now here we can find s1 count.
//same problem is target sum

#include<bits/stdc++.h>
using namespace std;

int countOfSubset(int a[],int sum,int n,int target){
	int t[n+1][sum+1];
	
	for(int i=0;i<n+1;i++){
		for(int j=0;j<sum+1;j++){
			if(i==0)t[i][j]=0;
			if(j==0)t[i][j]=1;
		}
	}

	for(int i=1;i<n+1;i++){
		for(int j=0;j<sum+1;j++){
			if(a[i-1]<=j){
				t[i][j]=t[i-1][j-a[i-1]] + t[i-1][j];
			}
			else
				t[i][j]=t[i-1][j];
		}
	}
	return t[n][target]; //in last row all for all subset sum is calculated.
}


int main(){
	int a[]={1,2,3,4,7}; int diff=1;
	int n=sizeof(a)/sizeof(a[0]);
	
	int sum=0;
	for(int k:a)sum+=k;

	int s1=(sum-diff)/2; //by formula we have to find s1
	
	cout<<countOfSubset(a,sum,n,s1);

	return 0;
}
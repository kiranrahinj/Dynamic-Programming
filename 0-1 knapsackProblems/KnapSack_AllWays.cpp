#include<bits/stdc++.h>
using namespace std;

1. //This is the recursive solution
int knapsack(int wt[],int val[],int w,int n){
	//base condition
	if(n==0 || w==0)return 0; 

	//Code from the choice diagram
	if(wt[n-1]<=w){
		return max(val[n-1]+knapsack(wt,val,w-wt[n-1],n-1) , knapsack(wt,val,w,n-1));
	}
	else id(wt[n-1]>w){
		return knapsack(wt,val,w,n-1);
	}
}

2. //Memoization of above code, We are adding only 3 lines in it.
int t[n+1][w+1];
memset(t,-1,sizeOf(t));

int knapsack(int wt[],int val[],int w,int n){
	//base condition
	if(n==0 || w==0)return 0;

	//check it is alredy calculted or not      
	if(t[n][w]!=-1)return t[n][w]; 

	//Code from the choice diagram
	if(wt[n-1]<=w){
		return t[n][w]= max(val[n-1]+knapsack(wt,val,w-wt[n-1],n-1) , knapsack(wt,val,w,n-1));
	}
	else id(wt[n-1]>w){
		return t[n][w]= knapsack(wt,val,w,n-1);
	}
}

int main(){
	
3. //Top Down approach, Most .In this are removing recursion.
	int t[n+1][w+1];
	int val[],wt[];

	//filling base condition
	for(int i=0;i<n+1;i++){
		for(int j=0;j<w+1;j++){
			if(i==0)t[i][j]=0;
			if(j==0)t[i][j]=1;
		}
	}
	//choice diagram
	for(int i=1;i<n+1;i++){
		for(int j=1;j<w+1;j++){
			if(wt[i-1]<=j){
				t[i][j]=max( val[i-1]+ t[i-1][j-wt[i-1]] , t[i-1][j]);
			}
			else{
				t[i][j]=t[i-1][j];
			}
		}
	}
	cout<<t[n][w]; //here will be the last answer
	
}
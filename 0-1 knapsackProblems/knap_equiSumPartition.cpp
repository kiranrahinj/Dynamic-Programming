#include<bits/stdc++.h>
using namespace std;

bool rec(vector<int>&v,int target,int n){
	if(n==0){
	    if(target==0)return true;
	    return false;
	}

	if(v[n-1]<=target){
		return rec(v,target-v[n-1],n-1) || rec(v,target,n-1);
	}
	else
		return rec(v,target,n-1);
}

vector<vector<bool>>t;
bool memoization(vector<int>&v,int target,int n){
	if(n==0){
	    if(target==0)return true;
	    return false;
	}

	if(t[n][target]!=false)return t[n][target];

	if(v[n-1]<=target){
		return t[n][target]= memoization(v,target-v[n-1],n-1) || memoization(v,target,n-1);
	}
	else
		return t[n][target]= memoization(v,target,n-1);
}

int main(){
	vector<int>v{1,2,3,4};

	int sum=0,n=v.size();
	for(int i:v)sum+=i;

	t.resize(v.size()+1,vector<bool>(sum+1,false));
	//now we have to check sum/2 array is there or not!
	if(sum%2!=0)cout<<0;
	else 
		cout<<rec(v,sum/2,n);	

	return 0;
}
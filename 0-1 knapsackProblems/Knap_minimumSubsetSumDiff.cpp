// This problem is same as equal sum partition of subset. But here we want minimum diff
// but we dont know actual range so we are calculating like  0-> sum of array.We get the range
// Just think u got one specific range then do some mathematics
// s1+s2=sum s1=sum-s2;
// So we are checking like we have s1-s2=0 suppose 0 is min;
// We are doing like  sum-2*s1 at time we will get ans.


#include<bits/stdc++.h>
using namespace std;

int main(){
	int a[]={1,2,4,0};
	
	int sum=0;
	for(int k:a)sum+=k;  //calculating range

	bool t[5][sum+1];
	
	for(int i=0;i<5;i++){
		for(int j=0;j<sum+1;j++){
			if(i==0)t[i][j]=false;
			if(j==0)t[i][j]=true;
		}
	}
	
	for(int i=1;i<5;i++){
		for(int j=1;j<sum+1;j++){
			if(a[i-1]<=j){
				t[i][j]=t[i-1][j-a[i-1]] || t[i-1][j];
			}
			else
				t[i][j]=t[i-1][j];

			// cout<<t[i][j]<<" ";
		}
		// cout<<endl;
	}
	vector<int>v;
					
	for(int i=0;i<=(sum+1)/2;i++)
		if(t[4][i])v.push_back(i);	//checking how many subsets are there

	int mn=INT_MAX;
	for(int i=0;i<v.size();i++){
		mn=min(mn,sum-2*v[i]);        //last formula
	}
	cout<<abs(mn);

	return 0;
}

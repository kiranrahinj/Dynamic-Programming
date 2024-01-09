//this is the MCM question in that we are finding the min multiplication.

#include<bits/stdc++.h>
using namespace std;

int t[101][101];

int solve(int a[],int i,int j){
    if(i>=j)return 0;
    
    if(t[i][j]!=-1)return t[i][j];
    
    int mn=INT_MAX;
    
    for(int k=i;k<j;k++){
        int temp=solve(a,i,k) + solve(a,k+1,j)+ (a[i-1]*a[k]*a[j]);
        
        mn=min(mn,temp);
    }
    return t[i][j]=mn;
}

int main(){
    int arr[] = { 1, 2, 3, 4, 3 };
    memset(t,-1,sizeof(t));
    cout<<solve(arr,1,5-1);
      
	return 0;
}
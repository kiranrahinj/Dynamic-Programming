#include<bits/stdc++.h>
using namespace std;


int rec(int a[],int n,int target){
	if(n==0){
		if(target==0)return 1;
		return 0;
	}

	if(a[n-1]<=target){
		return rec(a,n-1,target-a[n-1]) + rec(a,n-1,target);
	}
	else{
		return rec(a,n-1,target);
	}
}

int main(){
	int arr[] = { 1, 2, 3, 4, 5 };
    int sum = 10;
    int n = sizeof(arr) / sizeof(arr[0]);
 
    cout << rec(arr, n, sum);

	return 0;
}
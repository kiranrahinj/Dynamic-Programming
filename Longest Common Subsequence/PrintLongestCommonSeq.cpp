//Printing is based on that calculated t[]. we are just itertating base on the 
//a[i]==b[j] then we are going back like i--; j--;
//if not equal then checking t[i-1][j]>t[i][j-1] then we are going to max side.

#include<bits/stdc++.h>
using namespace std;

int main(){
	string a="abcefg"; int n=a.size();
	string b="adcefbcefg"; int m=b.size();

	int t[n+1][m+1];

	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			if(i==0)t[i][j]=0;
			if(j==0)t[i][j]=0;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i-1]==b[j-1]){
				t[i][j]=1+t[i-1][j-1];
			}
			else
				t[i][j]=max(t[i-1][j],t[i][j-1]);
		}
	}
	// cout<<t[n][m];

	string ans="";

	while(n>0 && m>0){
		if(a[n-1]==b[m-1]){
			ans+=a[n-1];
			n--;
			m--;
		}
		else{
			if(t[n][m-1]>t[n-1][m]){
				m--;
			}
			else{
				n--;
			}
		}
	}
	reverse(ans.begin(),ans.end());
	cout<<ans;
	return 0;
}
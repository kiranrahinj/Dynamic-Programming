#include <bits/stdc++.h>
using namespace std;

int main(){
	string S1="abcdf";
	string S2="abceg";
	int n=S1.size(),m=S2.size();
	int t[n+1][m+1],mx=0;
        
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0 || j==0)t[i][j]=0;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(S1[i-1]==S2[j-1]){
                t[i][j]=1+t[i-1][j-1];
                mx=max(t[i][j],mx);
            }
            else t[i][j]=0;
        }
    }
    cout<<mx;

	return 0;
}	
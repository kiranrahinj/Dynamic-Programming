//In this Que. we have return min insertion and deletion to make string equal.
// we have 2 string we can find that LCS.
//Using this LCS we can say in first string we can do deletion. 
//But we have LCS then we can minus it and same for insertion after minus from second 
// string we will get min insertion
//Look pattern and find Approach.

#include<bits/stdc++.h>
using namespace std;

int main(){

	string s1="heap",s2="pea";
	int n=s1.size(),m=s2.size();
	  
	int t[n+1][m+1];

	for(int i=0;i<=n;i++){
	  for(int j=0;j<=m;j++){
	      if(i==0 || j==0){
	          t[i][j]=0;
	      }
	  }
	}

	for(int i=1;i<=n;i++){
	  for(int j=1;j<=m;j++){
	      if(s1[i-1]==s2[j-1]){
	          t[i][j]=1+ t[i-1][j-1];
	      }
	      else
	          t[i][j]=max(t[i-1][j],t[i][j-1]);
	  }
	}
	//untill this is lcs code....
	int lcs=t[n][m];

	int deletion=n-lcs;
	int insertion=m-lcs;

	cout<<"Min_Deletion => "<<deletion <<" & "<<"Min_Insertion => "<<insertion<<endl;

	cout<<"Total Minimum insertion & deletion => "<<deletion+insertion;

	return 0;
}
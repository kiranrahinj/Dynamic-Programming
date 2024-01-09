<<<<<<< HEAD
//try to do simple choice diagram from that write recursive code
#include <bits/stdc++.h>
using namespace std;

//this is recursive code
int rec(string s1,string s2,int n,int m){
	if(n==0 || m==0)return 0;

	if(s1[n-1]==s2[m-1]){
		return 1+ rec(s1,s2,n-1,m-1);
	}
	else
		return max(rec(s1,s2,n-1,m), rec(s1,s2,n,m-1));
}

int main(){
	string s1="abcefg";
	string s2="adcefhbcefg";
	int n=s1.size(),m=s2.size();		
	cout<<rec(s1,s2,n,m)<<endl;

	//Top Down Approach
    int t[n+1][m+1];
    
    //base condition
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0 || j==0)t[i][j]=0;
        }
    }

    //choice diagram code
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]){
                t[i][j]=1+t[i-1][j-1];
            }
            else{
                t[i][j]=max(t[i-1][j],t[i][j-1]);
            }
        }
    }

    cout<<t[n][m];
   return 0;
=======
//try to do simple choice diagram from that write recursive code
#include <bits/stdc++.h>
using namespace std;

//this is recursive code
int rec(string s1,string s2,int n,int m){
	if(n==0 || m==0)return 0;

	if(s1[n-1]==s2[m-1]){
		return 1+ rec(s1,s2,n-1,n-1);
	}
	else
		return max(rec(s1,s2,n-1,m), rec(s1,s2,n,m-1));
}

int main(){
	string s1="abcdf";
	string s2="abceg";
	int n=s1.size(),m=s2.size();		
	cout<<rec(s1,s2,n,m)<<endl;

	//Top Down Approach
    int t[n+1][m+1];
    
    //base condition
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0 || j==0)t[i][j]=0;
        }
    }

    //choice diagram code
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]){
                t[i][j]=1+t[i-1][j-1];
            }
            else{
                t[i][j]=max(t[i-1][j],t[i][j-1]);
            }
        }
    }

    cout<<t[n][m];
   return 0;
>>>>>>> fdd9bdab766b80be91993a8dadaa4fa9372ce260
}
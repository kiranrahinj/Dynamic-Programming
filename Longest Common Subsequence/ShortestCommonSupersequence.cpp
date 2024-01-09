//we have givern two string S and A from that we have to return length of SuperSeq.
// S="abac", A= "cab"   outputstring is ="cabac" and its length is 5.

// 1. For printing length use one idea like find LCS from both string
//    then add that both strings then reduce length of LCS bcz it will come 2 time.
// 2. To print it we have to use same idea of Print LCS but here little changes
//    Like we are pushing that not equal idx val.

//LeetCode Hard

#include<bits/stdc++.h>
using namespace std;

int main(){
	string s1="abac",s2="cab";
	int n=s1.size(),m=s2.size();

    int t[n+1][m+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0 || j==0)t[i][j]=0;
        }
    }
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
 // until here all same as LCS of 2 string
 // 1. Size of Shortest Common Supersequence 
    int total=n+m;
    cout<<total-t[n][m]<<endl;

 // 2. Printing of Shortest Common Supersequence 
    int i=n,j=m;
    string ans="";
    while(i>0 && j>0){
        if(s1[i-1]==s2[j-1]){
            ans.push_back(s1[i-1]);
            i--;j--;
        }
        else{
            if(t[i][j-1]>t[i-1][j]){
                ans.push_back(s2[j-1]);
                j--;
            }
            else{
                ans.push_back(s1[i-1]);
                i--;
            }
        }
    }
    //Here superSeq so we have to add remaining chars
    while(i>0){
        ans.push_back(s1[i-1]);
        i--;
    }
    while(j>0){
        ans.push_back(s2[j-1]);
        j--;
    }

    reverse(ans.begin(),ans.end());
    cout<<ans;

	return 0;
}
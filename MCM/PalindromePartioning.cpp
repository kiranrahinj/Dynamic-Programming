#include<bits/stdc++.h>
using namespace std;


int t[2001][2001];
bool isPalindrome(string s,int i,int j){
    if(i>j)return 0;

    while(i<j){
        if(s[i]!=s[j])return false;
        i++;
        j--;
    }
    return true;
}
//this solution gives TLE. So we are going to optimise it...
int solve(string s,int i,int j){
    if(i>j)return 0;

    if(isPalindrome(s,i,j))return 0;

    if(t[i][j]!=-1)return t[i][j];

    int mn=INT_MAX;

    for(int k=i;k<j;k++){
        int temp=solve(s,i,k) + solve(s,k+1,j)+1;
        mn=min(mn,temp);
    }
    return t[i][j]=mn;
}

//optimised but some TC gives TLE...
 int solve(string s,int i,int j){
        if(i>j)return 0;

        if(isPalindrome(s,i,j))return 0;
        
        if(t[i][j]!=-1)return t[i][j];

        int mn=INT_MAX;

        for(int k=i;k<j;k++){
            int left,right;
           //here we are checking that val is alredy calculated or not
            if(t[i][k]!=-1){
                right=t[i][k];
            }
            else{
           //if not then we are calculating
                right=solve(s,i,k);
                t[i][k]=right;
            }

            if(t[k+1][j]!=-1){
                left=t[k+1][j];
            }
            else{
                left=solve(s,k+1,j);
                t[k+1][j]=left;
            }

            int temp=left+right+1;

            mn=min(mn,temp);
        }
        return t[i][j]=mn;
    }


int main(){
	string s="aab";
	memset(t,-1,sizeof(t));
	cout<<solve(s,0,2);

	return 0;
}
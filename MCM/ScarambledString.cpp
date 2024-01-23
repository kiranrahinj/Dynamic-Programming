#include<bits/stdc++.h>
using namespace std;


// this is the basic recursion
bool solve(string s1,string s2){
    if(s1.compare(s2)==0)return true;
    
    if(s1.size()<=1 || s2.size()<=1)return false;
    
    bool flag=false;
    int n=s1.size();
    for(int i=1;i<n;i++){
        bool c1=solve(s1.substr(0,i),s2.substr(n-i,n))&& solve(s1.substr(i,n),s2.substr(0,n-i));
        bool c2=solve(s1.substr(0,i),s2.substr(0,i))&& solve(s1.substr(i,n),s2.substr(i,n));
        
        if(c1 || c2){
            return true;
        }
    }
    return false;
}

bool isScramble(string S1, string S2){
    if(S1.length()!=S2.length())return false;
    if(S1.compare(S2)==0)return true;
    return solve(S1,S2);
}  


int main(){

    cout<<isScramble("abcde","caebd");

    return 0;
}

//Memoization
class Solution {
public:
    unordered_map<string,bool>m;
    bool solve(string s1,string s2){
        if(s1.compare(s2)==0)return true;
        
        if(s1.size()<=1 || s2.size()<=1)return false;
        
        string key=s1;
        key.push_back(' ');
        key.append(s2);
        
        if(m.find(key)!=m.end())return m[key];
        
        bool flag=false;
        int n=s1.size();
        for(int i=1;i<n;i++){
            bool c1=solve(s1.substr(0,i),s2.substr(n-i,n))&& solve(s1.substr(i,n),s2.substr(0,n-i));
            bool c2=solve(s1.substr(0,i),s2.substr(0,i))&& solve(s1.substr(i,n),s2.substr(i,n));
            
            if(c1 || c2){
                return m[key]=true;
            }
        }
        return m[key]=false;
    }
    bool isScramble(string S1, string S2) {
        if(S1.length()!=S2.length())return false;
        if(S1.compare(S2)==0)return true;
        return solve(S1,S2);
    }
};
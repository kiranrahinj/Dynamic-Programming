//This is little bit tricky
/*
You are given an expression 'exp' in the form of a string where operands will be : (TRUE or FALSE), and operators will be : (AND, OR or XOR).
Now you have to find the number of ways we can parenthesize the expression such that it will evaluate to TRUE.
As the answer can be very large, return the output modulo 1000000007.
Note :

‘T’ will represent the operand TRUE.
‘F’ will represent the operand FALSE.
‘|’ will represent the operator OR.
‘&’ will represent the operator AND.
‘^’ will represent the operator XOR.
Example :

Input: 'exp’ = "T|T & F".

Output: 1
*/


//this is the recursive code.
#include<bits/stdc++.h>
using namespace std;

int helper(string s,int i,int j, bool isTrue){
    if(i>j)return false;

    if(i==j){
        if(isTrue==true){
            return s[i]=='T';
        }
        else
            return s[i]=='F';
    }


    int ans=0;

    for(int k=i+1;k<j;k+=2){
        int LT=helper(s,i,k-1,true);
        int LF=helper(s,i,k-1,false);
        int RT=helper(s,k+1,j,true);
        int RF=helper(s,k+1,j,false);

        if(s[k]=='&'){
            if(isTrue==true){
                ans+=LT*RT;
            }
            else
                ans+=LF*RF +LF*RT +RF*LT;
        }
        else if(s[k]=='|'){
            if(isTrue==true){
                ans+=LT*RT+LF*RT +RF*LT;
            }
            else
                ans+=LF*RF;
        }
        else if(s[k]=='^'){
            if(isTrue==true){
                ans+=LT*RF +LF*RT;
            }
            else
                ans+=LT*RT+RF*LF;
        }

    }

    return ans;
}

///memoization code
// in the code we can do 3D matrix but we can do one thing we can use map.
//In map we can store key as i,j,isTrue and that min val will be its value.

unordered_map<string,int>mp;
int helper2(string s,int i,int j, bool isTrue){
    if(i>j)return false;

    if(i==j){
        if(isTrue==true){
            return s[i]=='T';
        }
        else
            return s[i]=='F';
    }
    string temp=to_string(i);
    temp.push_back(' ');
    temp.append(to_string(j));
    temp.push_back(' ');
    temp.append(to_string(isTrue));

    if(mp.find(temp)!=mp.end())return mp[temp];

    int ans=0;

    for(int k=i+1;k<j;k+=2){
        int LT=helper2(s,i,k-1,true);
        int LF=helper2(s,i,k-1,false);
        int RT=helper2(s,k+1,j,true);
        int RF=helper2(s,k+1,j,false);

        if(s[k]=='&'){
            if(isTrue==true){
                ans+=LT*RT;
            }
            else
                ans+=LF*RF +LF*RT +RF*LT;
        }
        else if(s[k]=='|'){
            if(isTrue==true){
                ans+=LT*RT+LF*RT +RF*LT;
            }
            else
                ans+=LF*RF;
        }
        else if(s[k]=='^'){
            if(isTrue==true){
                ans+=LT*RF +LF*RT;
            }
            else
                ans+=LT*RT+RF*LF;
        }

    }

    return mp[temp]=ans;
}

int evaluateExp(string exp) {
    return helper2(exp,0,exp.size()-1,true);
}

int main(){

    cout<<evaluateExp("F|T^F");
    return 0;
}
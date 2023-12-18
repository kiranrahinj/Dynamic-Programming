//in this we are checking is there subset is present with given sum

class Solution{   
public:
    //rec solution
    bool rec(vector<int>&arr,int level,int sum,int target){
        if(level>=arr.size()){
            if(sum==target)return true;
            return false;
        }
        return rec(arr,level+1,sum+arr[level],target) || rec(arr,level+1,sum,target);
    }

    //TopDown approach
    bool isSubsetSum(vector<int>arr, int sum){
    //   return rec(arr,0,0,sum);
        int n=arr.size(); 
        bool t[n+1][sum+1];
        
        for(int i=0;i<n+1;i++){
            for(int j=0;j<sum+1;j++){
                if(i==0)t[i][j]=false;
                if(j==0)t[i][j]=true;
            }
        }
        
        for(int i=1;i<n+1;i++){
            for(int j=1;j<sum+1;j++){
                if(arr[i-1]<=j){
                    t[i][j]=t[i-1][j-arr[i-1]] || t[i-1][j]; 
                }
                else
                    t[i][j]=t[i-1][j];
            }
        }
        return t[n][sum];
    }
};

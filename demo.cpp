// //this is the MCM question in that we are finding the min multiplication.

// #include<bits/stdc++.h>
// using namespace std;

// // int t[101][101];

// // int solve(int a[],int i,int j){
// //     if(i>=j)return 0;
    
// //     if(t[i][j]!=-1)return t[i][j];
    
// //     int mn=INT_MAX;
    
// //     for(int k=i;k<j;k++){
// //         int temp=solve(a,i,k) + solve(a,k+1,j)+ (a[i-1]*a[k]*a[j]);
        
// //         mn=min(mn,temp);
// //     }
// //     return t[i][j]=mn;
// // }

// bool cmp(pair<int,int>a,pair<int,int>b){
//     return a.first<b.first;
// }

// int main(){
//         int n=6;
//         int gallery[] = {-1, 2, 2, -1, 0, 0};
//         vector<pair<int,int>>v(n);
//         for(int i=0;i<n;i++){
//             int l = (i-gallery[i]<0)?0:i-gallery[i];
//             int r = (i+gallery[i]>=n)?n-1:i+gallery[i];
            
//             if(gallery[i]==-1){l=-1,r=-1;}
//             v[i] = {l,r};
//         }
//         sort(v.begin(),v.end(),cmp);
//         for(auto val:v){
//             cout<<"("<<val.first<<","<<val.second<<") ";
//         }cout<<endl;
//         int ans=0;
//         int endpoint = n;
//         for(int i=0;i<n;i++){
//             cout<<i<<endl;
//             if(v[i].first==-1)continue;
//             cout<<v[i].second<<endl;
//             // if(v[i].second<endpoint-1 and endpoint>0){
//             //     return -1;
//             // }
//             // else{
//                 cout<<"else"<<endl;
//                 if(endpoint==0)return ans;
//                 ans++;
//                 int nextEndpoint = endpoint;
//                 while(i<n and v[i].second>=endpoint-1){
//                     cout<<"while "<<i<<endl;
//                     nextEndpoint = min(nextEndpoint,v[i].first);
//                     i++;
//                 // }
//                 endpoint = nextEndpoint;
//                 i--;
//             }
//             cout<<"end"<<endl;
//         }

// 	return 0;
// }
#include <iostream>
#include <queue>
#include <unordered_map>

struct Compare {
    bool operator()(const std::unordered_map<int, int>& a, const std::unordered_map<int, int>& b) const {
        int freqA = a.count(1) ? a.at(1) : 0;
        int freqB = b.count(1) ? b.at(1) : 0;

        // Compare based on frequency (higher frequency comes first)
        if (freqA != freqB) {
            return freqA < freqB;  // Sort by frequency first
        } else {
            // If frequencies are equal, compare based on the number itself (key 1)
            return a.at(1) > b.at(1);
        }
    }
};

int main() {
    // Creating a priority queue of unordered_maps with a custom comparator
    std::priority_queue<std::unordered_map<int, int>, std::vector<std::unordered_map<int, int>>, Compare> pq;

    // Example: Adding unordered_maps to the priority queue
    std::unordered_map<int, int> map1 = {{1, 10}, {2, 20}};
    std::unordered_map<int, int> map2 = {{1, 15}, {2, 25}};
    std::unordered_map<int, int> map3 = {{1, 10}, {2, 15}};

    // Adding maps to the priority queue
    pq.push(map1);
    pq.push(map2);
    pq.push(map3);

    // Accessing and processing the elements in priority order
    while (!pq.empty()) {
        std::unordered_map<int, int> topElement = pq.top();
        pq.pop();
        std::cout << "Element: {1=" << topElement[1] << ", 2=" << topElement[2] << "}, Frequency: " << topElement[1] << std::endl;
    }

    return 0;
}

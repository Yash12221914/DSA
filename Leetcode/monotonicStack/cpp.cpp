#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int main(){
    int n = 3;
    int m = 3;

    vector<vector<int>> arr(n,vector<int> (m));
    arr = {{1,2,3},{4,5,6},{7,8,9}};

    for(int i = 0;i<arr.size();i++){
        for(int j = i;j<arr[0].size();j++){
            swap(arr[i][j],arr[j][i]);
        }
    }
    for(int i = 0;i<arr.size();i++){
        reverse(arr[i].begin(),arr[i].end());
    }
    for(int i = 0;i<arr.size();i++){
        for(int j = 0;j<arr[0].size();j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    // vector<vector<int>> arr(n,vector<int> (m,0));
    // for(int i = 0;i<n;i++){
    //     for(int j =0;j<m;j++){
    //         cin>>arr[i][j];
    //     }
    // }
    
    // for(int i = 0;i<n;i++){
    //     for(int j = 0;j<arr[i].size();j++){
    //         swap(arr[i][j],arr[j][i]);
    //     }
    // }
    
    // for(int i  = 0;i<n;i++){
    //     reverse(arr[i].begin(),arr[i].end());
    // }
    
    // for(int i = 0;i<n;i++){
    //     for(int j = 0;j<m;j++){
    //         cout<<arr[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    return 0;
}
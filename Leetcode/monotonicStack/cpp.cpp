// #include<bits/stdc++.h>
// #include<algorithm>
// using namespace std;
// int main(){
//     int n = 3;
//     int m = 3;

//     vector<vector<int>> arr(n,vector<int> (m));
//     arr = {{1,2,3} ,
//             {4,5,6},
//             {7,8,9}
//         };

//     for(int i = 0;i<arr.size();i++){
//         for(int j = i;j<arr[0].size();j++){
//             swap(arr[i][j],arr[j][i]);
//         }
//     }
//     for(int i = 0;i<arr.size();i++){
//         reverse(arr[i].begin(),arr[i].end());
//     }
//     for(int i = 0;i<arr.size();i++){
//         for(int j = 0;j<arr[0].size();j++){
//             cout<<arr[i][j]<<" ";
//         }
//         cout<<endl;
//     }

//     // vector<vector<int>> arr(n,vector<int> (m,0));
//     // for(int i = 0;i<n;i++){
//     //     for(int j =0;j<m;j++){
//     //         cin>>arr[i][j];
//     //     }
//     // }
    
//     // for(int i = 0;i<n;i++){
//     //     for(int j = 0;j<arr[i].size();j++){
//     //         swap(arr[i][j],arr[j][i]);
//     //     }
//     // }
    
//     // for(int i  = 0;i<n;i++){
//     //     reverse(arr[i].begin(),arr[i].end());
//     // }
    
//     // for(int i = 0;i<n;i++){
//     //     for(int j = 0;j<m;j++){
//     //         cout<<arr[i][j]<<" ";
//     //     }
//     //     cout<<endl;
//     // }
//     return 0;
// }


#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'lights' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts INTEGER n as parameter.
 */

 const int MOD = 100000;

 // Function to compute (2^n - 1) % MOD
 long lights(int n) {
     long result = 1;
     for (int i = 0; i < n; ++i) {
         result = (result * 2) % MOD;
     }
     result = (result - 1 + MOD) % MOD; // Ensure it's not negative
     return result;
 }
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        long result = lights(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

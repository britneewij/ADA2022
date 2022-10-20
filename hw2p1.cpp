// resources used :
// http://www8.cs.umu.se/kurser/TDBA77/VT06/algorithms/BOOK/BOOK2/NODE45.HTM

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cassert>
#include <random>
#include <chrono>
#include <cmath>
#include <string>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define int long long 
using namespace std;

int count_worst_val(int arr[], int left, int right){
    int max_sum = arr[left];
    int temp_sum = 0;

    for (int i=left; i<=right; i++){
        if (temp_sum > 0){
            temp_sum = temp_sum + arr[i];
        }
        else temp_sum = arr[i];

        if (temp_sum > max_sum){
            max_sum = temp_sum;
        }
    }
    return max_sum;
}

int find_min(vector < vector<int> >& dp, vector < vector<int> >& val, int i, int j){
    int res = 1e18;

    // Consider the i-th stage, it will end at j, assume it starts at k
    // Pick the minimum value out of all possible k
    for (int k=i; k<=j; k++){
        res = min(res, dp[i-1][k-1] + val[k][j]);
    }
    return res;
}

void partition(vector < vector<int> >& dp, vector < vector<int> >& val, int N, int K){
    // initialize
    dp[0][0] = 0;
    
    for (int i=1; i<=K; i++){
        for (int j=i; j<=N; j++){
            if (i==1) dp[i][j] = val[i][j];

            dp[i][j] = find_min(dp, val, i, j);
            //cout<<dp[i][j]<<"\n";
        }
    }
    return;
}

signed main(){
    int N, K;
    cin>>N>>K;

    auto a = new int[N+1];
    for (int i=1; i<=N; i++){
        cin>>a[i];
    }

    // N*N to store worst case discomfort values
    vector<vector<int>> val(N+1, vector<int> (N+1));
    for (int i=1; i<=N; i++){
        for (int j=i; j<=N; j++){
            val[i][j] = (j-i+1) * count_worst_val(a, i, j);
        }
    }
    
    // dp[K][N]
    vector<vector<int>> dp((K+1), vector<int> (N+1, 1e18));
    partition(dp, val, N, K);
    cout<<dp[K][N]<<"\n";

    return 0;
}

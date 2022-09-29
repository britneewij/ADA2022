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
#include <bits/stdc++.h>

#define int long long 
using namespace std;

int *dp;

int littlez(int W, int N, int wt[]){
    int money = W;
    int total = 0;
    int temp = money;

    for (int j=N-1; j>=0; j--){
        money = money % wt[j];
    }
    return temp - money;
}

void optimal(int W, int N, int wt[]){
    memset(dp, 0, sizeof dp);
 
    for (int i=0; i<=W; i++){
        for (int j=0; j<N; j++){
            if (wt[j]<=i){
                dp[i] = max(dp[i], dp[i-wt[j]] + wt[j]);
            }
        }
    }
}
 
signed main(){
    int N, W;
    cin>>N>>W;

    dp = (int *)malloc(sizeof(int) * W);

    int *wt = (int *)malloc(sizeof(int) * N);
    for(int i=0; i<N; i++){
        scanf("%lld", &wt[i]);
    }

    sort(wt, wt+N);

    int *little = (int *)malloc(sizeof(int) * W);
    for (int i=1; i<=W; i++){
        little[i] = littlez(i, N, wt);
    }
    
    optimal(W, N, wt);

    for (int i=1; i<=W; i++){
        if (little[i] >= dp[i]){
            cout << little[i] - dp[i] << "\n";
        }
        else{
            cout << dp[i] - little[i]<< "\n";
        }
    }

    return 0;
}

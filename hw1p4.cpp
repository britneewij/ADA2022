// 40 points

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

int count(int N, int *val){
    int cnt = 0;
    int min;
    for(int i=0; i<N-1; i++){
        min=100000;
        for(int j=i+1; j<N; j++){
            for (int k=i; k<j+1; k++){
                if (val[k] < min){
                    min = val[k];
                }
            }
    
            if ((abs(val[j] -val[i])) == min){
                cnt++;
            }
        }
    }

    return cnt;
}

signed main(){
    int N;
    cin>>N;

    int *val = (int *)malloc(sizeof(int) * N);
    for(int i=0; i<N; i++){
        cin>>val[i];
    }

    cout<<count(N, val)<<"\n";

    return 0;
}

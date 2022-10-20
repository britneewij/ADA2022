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

int EditDistance(string word1, string word2){
    if (word1.length()>word2.length()){
        swap(word1,word2);
    }

    int size1 = word1.length();
    int size2 = word2.length();
    int dp[size1+1][size2+1];

    for (int i=1; i<=size1; i++){
        dp[i][0] = i;
    }

    for (int i=1; i<=size2; i++){
        dp[0][i] = i;
    }
        
    for (int i=1; i<=size1; i++){
        for (int j=1; j<=size2; j++){
            if (word1[i-1] == word2[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                dp[i][j] = min(dp[i][j-1], min(dp[i-1][j-1], dp[i-1][j])) + 1;
            }
        }
    }
        
    return dp[size1][size2];
}

signed main(){
    string word1, word2;
    cin>>word1>>word2;

    cout<<EditDistance(word1, word2)<<"\n";

    return 0;
}

// References :
// Huifeng Guan Youtube LeetCode 1505 Discussion https://www.youtube.com/watch?v=qE5M1sz6j9U

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
#include <unordered_map>
#include <list>

#define int long long 
using namespace std;

const int N = 5e5+5;
const int A = 128;
int n, k;
string s, ans;

bool used[N];
int nxt[A], offset[A];

signed main(){
    cin >> s >> k;
    n = s.size();
    ans = s;

    // first occurance of each char
    for(int c=0; c<A; c++){
        nxt[c] = -1;
    }

    for(int i=0; i<n; i++){
        if(nxt[s[i]]==-1){
            nxt[s[i]] = i;
        }
    }

    for(int i=0; i<n; i++){
        // find best character in range
        int c;
        for(c=0; c<A; c++){
            if(nxt[c]==-1){
                continue;
            }

            int idx = nxt[c] + offset[c] - i;
            if(idx <= k){
                k -= idx;
                break;
            }
        }
        
        ans[i] = s[nxt[c]];
        used[nxt[c]] = true;
        for(int d=0; d<A; d++){
            if(nxt[d] < nxt[c]){
                offset[d]++;
            }
        }
    
        int start = nxt[c];
        nxt[c] = -1;
        for(int j=start+1; j<n; j++){
            if(used[j]==true){
                offset[c]--;
            }
            else if(s[j]==c){
                nxt[c] = j;
                break;
            }
        }     
    }

    cout << ans << "\n";
}

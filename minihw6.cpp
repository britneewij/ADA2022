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
#include <cstring>

using namespace std;
#define int long long 

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;

    int *a = new int[m+1];
    int *b = new int[m+1];
    int *c = new int[m+1];
    for (int i=0; i<m; i++){
        cin >> a[i] >> b[i] >> c[i];
    }

    int *v = new int[n+1];
    for (int i=0; i<n+1; i++){
        v[i] = rand()%2;
    }

    for(int i=0; i<m; i++){
        int va = v[abs(a[i])];
        if (a[i]<0){
            va = 1 - va;
        } 
        int vb = v[abs(b[i])];
        if (b[i]<0){
            vb = 1 - vb;
        } 
        int vc = v[abs(c[i])];
        if (c[i]<0){
            vc = 1 - vc;
        } 

        while((va or vb or vc) == 0){
            if(((1 - va) or vb or vc) == 1){
                v[abs(a[i])] = 1 - v[abs(a[i])];
                break;
            }
            else if((va or (1 - vb) or vb) == 1){
                v[abs(b[i])] = 1 - v[abs(b[i])];
                break;
            }
            else if ((va or vb or (1 - vc)) == 1){
                v[abs(c[i])] = 1 - v[abs(c[i])];
                break;
            }
        }  
    }

    for (int i=1; i<n+1; i++){
        if (v[i]==0){
            cout << "-1";
        }
        else cout << "1";

        if (i!=n){
            cout << " ";
        }
        else{
            cout << "\n";
        }
    }

    return 0;
}

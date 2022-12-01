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
int n, m;

struct Edge{
    int end, len, toll;
};
vector<vector<Edge>> adj;

struct Path{
    int idx;
    int l, c;
    int longest_l;
};

struct cmp_weight{
    bool operator()(Path a, Path b){
        if (a.l == b.l){
            return a.c > b.c;
        }
        return a.l > b.l;
    }
};

int dijkstra(){
    priority_queue<Path, vector<Path>, cmp_weight> pq;

    int* inST = new int[n];
    memset(inST, 0, sizeof(int)*n);

    int* total = new int[n];
    int* longest =  new int[n];
    pq.push({0, 0, 0, 0});
    Path tmp;
    for (int i=0; i<n; i++){
        while (!pq.empty()){
            tmp = pq.top();
            pq.pop();

            if (inST[tmp.idx] == 0 || tmp.idx == -1)break;
        }
        
        inST[tmp.idx] = 1;

        Edge temp_edge;
        total[tmp.idx] = tmp.c;
        longest[tmp.idx] = tmp.longest_l;
        int temp_toll, temp_longest;
        for (int j=0; j<adj[tmp.idx].size(); j++){
            temp_edge = adj[tmp.idx][j];

            if (inST[temp_edge.end] == 0){
                if (temp_edge.len < longest[tmp.idx]){
                    temp_longest = longest[tmp.idx];
                    temp_toll = total[tmp.idx];
                }
                else if (temp_edge.len >= longest[tmp.idx]){
                    temp_longest = temp_edge.len;

                    if (temp_edge.len > longest[tmp.idx]){
                        temp_toll = temp_edge.toll;
                    }
                    else {
                        temp_toll = total[tmp.idx] + temp_edge.toll; 
                    }
                }
                pq.push({temp_edge.end, temp_edge.len, temp_toll, temp_longest});
            }
        }
    }

    int ans = 0;
    for (int i=0; i<n; i++){
        ans += total[i];
    }
    return ans;
}

void init(){
    for (int i=0; i<n; i++){
        vector<Edge> temp;
        adj.push_back(temp);
    }
}

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;

    init();
    for (int i=0; i<m; i++){
        int node1, node2, l, c;
        cin >> node1 >> node2 >> l >> c;

        adj[node1].push_back({node2, l, c});
        adj[node2].push_back({node1, l, c});
    }

    cout << dijkstra() << "\n";

    return 0;
}

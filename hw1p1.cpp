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

using namespace std;
typedef long long int LL;
vector<pair<int,int>> ans;
LL N;

void push(int x){
    ans.push_back({1,x});
}

void pop(){
    ans.push_back({2,0});
}

void photo(){
    ans.push_back({3,0});
}

void dc(LL start, LL end){
    LL mid = (start+end-1)/2;

    // base case
    if (start == end){
        push(start);
        photo();
        return;
    }

    for (LL i = mid+1; i <= end; i++){
        push(i);
    }
    dc(start, mid);
    
    for (LL i = mid; i <= end; i++){
        pop();
    }
    
    for (LL i = start; i <= mid; i++){
        push(i);
    }
    dc(mid+1, end);
    
    for (LL i = start; i <= mid; i++){
        if (ans.size() != N){
            pop();
        }
    }
}

int main(){
    cin>>N;

    dc(1, N);

    cout<<ans.size()<<"\n";
    for(auto[p,q] : ans){
        if(p==1) cout << "PLACE " << q << "\n";
        if(p==2) cout << "POP" << "\n";
        if(p==3) cout << "PHOTO" << "\n";
    }
    
    return 0;
}

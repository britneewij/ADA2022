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
#include <bits/stdc++.h>

#define int long long 
using namespace std;

signed main(){
  int M;
  cin >> M;

  char temp[32];
  vector<int> dangos; 
  vector<int> weight;
  for (int i=0; i<M; i++){
    cin >> temp;

    if (temp[0]=='P'){
      // puts a dango with weight w to the rod
      int w;
      cin >> w;
      dangos.push_back(w);

      int size = weight.size();
      if (size==0){
        weight.push_back(w);
      }
      else{
        int prev_w = weight[size-1];
        weight.push_back(w + prev_w);
      }
    }
    else if (temp[0]=='T'){
      // takes a dango off and eats it
      int size = dangos.size();
      cout << dangos[size-1] << "\n";
      dangos.pop_back();
      weight.pop_back();
    }
    else if (temp[0]=='C'){
      // takes x dangos off
      // eat the x/k heaviest dangos
      int x, k;
      cin >> x >> k;

      int eat = ceil(double((float)x/(float)k)); // amount to be eaten
      //cout << "eat " << eat << "\n";

      int* off_dangos = new int[x]; // dangos taken off
      int* temp_dangos = new int[x]; // temp to store order
      int size = dangos.size();
      for (int i=0; i<x; i++){
        //int size = dangos.size();
        //cout << "haha" << dangos[size-1] << "\n";
        off_dangos[i] = dangos[size-1];
        temp_dangos[i] = dangos[size-1];
        //cout << "off " << off_dangos[i] << " temp " << temp_dangos[i] << "\n";
        dangos.pop_back();
        weight.pop_back();
      }
      sort(off_dangos, off_dangos+x);
      /*
      for (int i=0; i<x; i++){
        cout << "off sorted " << off_dangos[i] << "\n";
      }
      */

      int last;
      int sum = 0;
      int temp_idx = x-1;
      for (int i=0; i<eat; i++){
        if (i==eat-1){
          last = off_dangos[temp_idx];
        }
        sum += off_dangos[temp_idx];
        temp_idx--;
      }
      cout << sum << "\n";

      for (int i=x-1; i>=0; i--){
        if (temp_dangos[i] < last){
          int val = temp_dangos[i];
          dangos.push_back(val);

          int size = weight.size();
          if (size==0){
            weight.push_back(val);
          }
          else{
            int prev_val = weight[size-1];
            weight.push_back(val + prev_val);
          }
        }
      }
    }
    else{
      // takes x dangos off
      // calculate the sum of weight of those dangos
      int x;
      cin >> x;

      int ans;
      int idx = weight.size();
      if (x == dangos.size()){
        ans = weight[idx-1];
      }
      else{
        ans = weight[idx-1] - weight[idx-1-x];
      }
      cout << ans << "\n";
    }
    /*
    // check
    for (int i=0; i<(dangos.size()); i++){
      cout << "dango " << dangos[i] << "\n";
    }
    cout << "MEOOWWWW\n";
    */
  }
  return 0;
}

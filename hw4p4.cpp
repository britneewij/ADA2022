#include "choose.h"
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int x;
int endtime[3];
vector<int> task;

void schedule(int N){
    x = N;

    for(int i=1; i<=x; i++){
        task.push_back(i);
    }
  
    sort(task.begin(), task.end(), [&](int i,int j){
        return compare_task(i,j)==1;
    });

    for(int i : task){
        int m = (endtime[1] < endtime[2]) ? 1:2;

        endtime[m] = assign_task(m, i);
    }
}

// Hint from discord group message 2022/10/11 sent by 兔子冬眠中💤#6675, 2022/10/18 sent by rrruby#0112.
// Discussion with a friend who has passed ADA last year, B09902085.

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
int total_m = 0;
int total_time = 0;

typedef struct Group{
	int m; // size
	int finish, remaining;
}group;

typedef struct Customer{
	// a = prepare
	// b = finish
	int a, b;
}customer;

int compare_b(customer x, customer y){
	if (x.b > y.b){
		return 1;
	}
	else return 0;
}

int compare_m(group x, group y){
	if ((x.m * y.finish) > (y.m * x.finish)){
		//((total_time - x.finish * total_m) > (y.m * total_time - y.finish * total_m)){
		return 1;
	}
	else return 0;
}

//a is preparing, b is enjoying the dish
void timeline(group *time, customer *cust, int id){
    int remain = 0, finish = 0;

    for (int i=0; i<time[id].m; i++){
    	if (cust[i].a + cust[i].b <= remain){
    		remain -= cust[i].a;
    	}
        else remain = cust[i].b;

        finish += cust[i].a;
    }
    time[id].finish = finish;
    time[id].remaining = remain;

    total_time += time[id].finish;
}

int ans(group *time, int N){
	int res = 0;
    int temp_val = 0;

	for (int i=0; i<N; i++){
	    temp_val += time[i].finish;
	    res += time[i].m * (time[i].remaining + temp_val);
	}
	return res;
}

signed main(){
	int N;
	cin >> N;

	group *time = new group[N];
	for (int i=0; i<N; i++){
		int m;
		cin >> m;

        total_m += m;
		time[i].m = m;

		customer *cust = new customer[m];
		for (int j=0; j<m; j++){
			cin >> cust[j].a >> cust[j].b;
		}

		sort(cust, cust+time[i].m, compare_b);
	    timeline(time, cust, i);
	}
	sort(time, time+N, compare_m);

	cout << ans(time, N) << "\n";
}

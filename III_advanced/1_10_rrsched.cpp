#include <bits/stdc++.h>
typedef long long ll;
 
const int MAXN = 5e4+5;

ll n;
ll res[MAXN];
ll BIT[MAXN];

void update(int idx, ll val){
	while(idx <= 50000){
		BIT[idx] += val;
		idx += idx & -idx;
	}
}

ll query(int idx){
	ll sum = 0;
	while(idx > 0){
		sum += BIT[idx];
		idx -= idx & -idx;
	}
	return sum;
}

int main(){
  std::cin >> n;
  std::pair<int, int> table[n];
	for(int i = 1;i <= n; i++){
		int t;
    std::cin >> t;
		table[i] = {t, i};
	}
	sort(table+1, table+n+1);
	for(int i = 1;i <= n; i++)
		update(i, 1);
	ll delta, tot = 0;
	for(int i = 1;i <= n; i++){
		delta = table[i].first - ((i > 1) ? table[i-1].first : 0);
		tot += (n-(i-1))*delta;
		res[table[i].second] = tot - (n-(i-1)) + query(table[i].second);
		update(table[i].second, -1);
	}
	for(int i = 1; i <= n; i++)
		std::cout << res[i] << std::endl;
	return 0;
}

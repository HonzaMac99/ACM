#include <bits/stdc++.h>

int cases;
int maxm, ans, mid, cows, temp ;
int N, C;
std::vector<int> x;

// check whether the cows can fit using minimal gap of len k 
bool check(int k) {
  cows = 1;
  temp = x[0];
  for (int i = 1; i < N; i++) {
    if (x[i] - temp >= k) {
      cows++;
      temp = x[i];
    }
  }
  if (cows >= C) 
    return true;
  return false;
}

void bin_search(int l, int u) {
  ans = -1;
  while (l<=u) {
    mid=(l+u)/2;
    if (check(mid)) {
      if (mid>ans)
        ans=mid;
      l=mid+1;
    } 
    else
      u=mid-1;
  }
}

int main() {
  std::cin >> cases;

  while (cases > 0) {
    std::cin >> N >> C;

    x.clear();
    x.resize(N);

    for (int i = 0; i < N; i++)
      std::cin >> x[i];

    std::sort(x.begin(), x.end());
    bin_search(0, x[N-1]);
    std::cout << ans << std::endl;

    cases--;
  }
}

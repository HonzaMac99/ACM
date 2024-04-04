#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define MOD 100000007

typedef long long int llong;

bool in_vec(std::vector<int> vec, int var) {
  return (std::find(vec.begin(), vec.end(), var) != vec.end());
}

int get_comb_coeff(int n) {
  if (n <= 2) 
    return n;

  llong* comb_arr = new llong[n];

  std::fill(comb_arr, comb_arr+n, 1);

  
  llong new_result, old_result;
  for (int i = 3; i < n+1; i++) { 
    for (int j = 1; j < i; j++) {
      old_result = new_result;
      new_result = comb_arr[j-1] + comb_arr[j]; 
      if (j > 1)
        comb_arr[j-1] = old_result % MOD;
    }
    // for (int j = 0; j < i; j++) 
    //   std::cout << comb_arr[j] << " ";
    // std::cout << std::endl;
  }
  
  int comb_coeff = 0;
  for (int i = 0; i < n; i++) {
    comb_coeff += comb_arr[i];
    comb_coeff = comb_coeff % MOD;
  }

  delete[] comb_arr;
  return comb_coeff;
}

int main() {
  int n_cases, set_len, case_id = 1;
  std::cin >> n_cases;
  for (int i = 0; i < n_cases; i++) {
    std::cin >> set_len;
    llong set_sum = 0;
    for (int j = 0; j < set_len; j++) {
      llong set_el;
      std::cin >> set_el;
      set_sum += set_el; 
      set_sum = set_sum % MOD;  // modulo 100000007
    }
    llong coeff = get_comb_coeff(set_len);
    set_sum *= coeff;
    set_sum = set_sum % MOD;  // modulo 100000007
    std::cout << "Case " << case_id << ": " << set_sum << std::endl;
    case_id += 1;
  }

  return 0;
}

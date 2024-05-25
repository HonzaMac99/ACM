#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

typedef std::vector<int> Vec1D;
typedef std::vector<std::vector<int>> Vec2D;
typedef long long int llong;
typedef unsigned long long int ull;

int main() {
  int n_cases = 0;
  std::cin >> n_cases;

  int* input = new int[n_cases];

  int max_element = 0;
  for(int i = 0; i < n_cases; i++) {
    std::cin >> input[i];
    max_element = std::max(max_element, input[i]);
  }

  ull* combs = new ull[max_element+1];
  ull* supp = new ull[max_element+1];
  ull* uniq = new ull[max_element+1];

  std::memset(combs, 0, max_element+1);
  std::memset(uniq, 0, max_element+1);
  combs[0] = 1;

  for(int i = 0; i <= max_element; i++) {
    uniq[i] = (i < 3) ? 1 : 2; 

    for(int j = 0; j < i; j++) {
      combs[i] += combs[j]*uniq[i-j];
    }
  }
  
  combs[0] = 0;
  for(int i = 0; i < n_cases; i++) {
    std::cout << combs[input[i]] % 10000 << std::endl;
  }
  // std::cout << combs[input[n_cases-1]] % 10000;

  delete[] input;
  delete[] combs;
  delete[] uniq;

  return 0;
}

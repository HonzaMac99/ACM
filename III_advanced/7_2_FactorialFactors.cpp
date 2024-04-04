#include <iostream>
#include <math.h>
#include <sstream>
#include <vector>
#include <queue>
#include <cstring>
#include <tuple>
#include <algorithm>

bool in_vec(std::vector<int> vec, int var) {
  return (std::find(vec.begin(), vec.end(), var) != vec.end());
}

// get all primes that are not larger than D (max_num) 
int* get_n_factors(int max_num)
{
  int* numbers = new int[max_num+1];

  std::fill(numbers, numbers+max_num+1, 1);

  int sq = ceil(sqrt(max_num));

  // eratosthenes
  for(int i = 2; i <= sq; i++) {
    if(numbers[i] == 1) {
      // for(int j = int(pow(i, 2)); j <= max_num; j+=i) {
      for(int j = i*2; j <= max_num; j+=i) {
        numbers[j] = std::max(numbers[j], (1 + numbers[j/i]));
      }
    }
  }
  return numbers;
}


int main() {

  std::vector<int> ns;
  int n, max_n = 0;
  

  while(std::cin >> n) { 
    if (n > max_n) 
      max_n = n;
    ns.push_back(n);
  }

  // max_n = 1000000;
  int* fact_counts = get_n_factors(max_n);
  int* fact_counts2 = new int[max_n+1];
  fact_counts2[0] = 1; 
  fact_counts2[1] = 1; 

  int f_count = 0;
  for (int i = 2; i < max_n+1; i++) {
    f_count += fact_counts[i];
    fact_counts2[i] = f_count; 
  }

  for (int i = 0; i < (int)ns.size(); i++) {
    std::cout << fact_counts2[ns[i]] << std::endl;
  }

  delete[] fact_counts;
  return 0;
}

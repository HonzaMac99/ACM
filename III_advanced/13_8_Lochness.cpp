#include <iostream>
#include <cmath>

int main() {
  int n_cases = 0;
  std::cin >> n_cases;

  // note!! When rows, cols are int, 
  // there will be rounding with operator /
  long rows, cols;  
  for(int i = 0; i < n_cases; i++) {
    std::cin >> rows >> cols;
    long sonars_r = rows/3; 
    long sonars_c = cols/3; 
    long n_sonars = sonars_r*sonars_c; 
    std::cout << n_sonars << std::endl;
  }

  return 0;
}

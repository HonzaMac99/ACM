#include <iostream>     
#include <cmath>
#include <cstring>
#include <vector>


int main () {

  int n_cases, result; 
  double n_rows, n_cols; 
  char ch_piece;
  std::cin >> n_cases;
  for(int i = 0; i < n_cases; i++) {
    std::cin >> ch_piece >> n_rows >> n_cols;
    if ((ch_piece == 'r') or (ch_piece == 'Q'))
      result = std::min(n_rows, n_cols);
    else if (ch_piece == 'k') 
      result = std::ceil(n_rows * n_cols / 2);
    else if (ch_piece == 'K') 
      result = std::ceil(n_rows/2) * std::ceil(n_cols/2);
    else
      std::cout << "Bad char on input: " << ch_piece << std::endl;

    std::cout << result << std::endl;
  }
  return 0;
}

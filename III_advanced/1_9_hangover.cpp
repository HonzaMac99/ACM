#include<bits/stdc++.h>

int main() {
  double c, overhang;
  std::cin >> c;
  while (c != 0.0) { 

    overhang = 0.0;
    int n_cards = 0;
    while (overhang <= c) {
      n_cards++;
      overhang += 1.0 / (n_cards + 1.0);
    }
    std::cout << n_cards << " card(s)" << std::endl;
    std::cin >> c;
  }
}

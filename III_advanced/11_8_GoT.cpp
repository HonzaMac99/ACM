#include <iostream>     
#include <cstring>
#include <vector>


double compute_sum(const double probs[], bool used[], int p_len, int r_lvl, int r_max) {
  double sum = 0.0;
  if (r_lvl == r_max) {
    sum = 1.0;
    for (int i = 0; i < p_len; i++) {
      sum *= (used[i]) ? probs[i] : 1 - probs[i];  // padne6 : nepadne6
    }
    return sum;
  }

  for(int i = r_lvl; i < p_len; i++) {
    if (!used[i] and r_lvl+i < p_len) {
      used[i] = 1;
      sum += compute_sum(probs, used, p_len, r_lvl+1, r_max);
      used[i] = 0;
    }
  }
  return sum;
}


int main () {

  int n_cases, n_dices, K_min;
  std::cin >> n_cases;
  for(int i = 0; i < n_cases; i++) {
    std::cin >> n_dices >> K_min;

    bool finished = false;
    double res_prob = 0.0;
    double probs[n_dices];
    int n_probs = 0;
    for(int j = 0; j < n_dices; j++) {
      double a, b, c, d, e, f;
      std::cin >> a >> b >> c >> d >> e >> f;
      if (f == 1.0) {
        K_min--;
        if (K_min <= 0) {
          res_prob = 1.0;
          finished = true;
          break;
        }
      }
      else if (f == 0.0)
        continue;
      else
        probs[n_probs++] = f;
    }
    if (K_min > n_probs) {
      res_prob = 0.0;
      finished = true;
    }

    if (!finished) {
      // exponential complexity?
      bool used[n_probs];
      std::memset(used, 0, n_probs*sizeof(used[0]));
      int r_max = K_min;
      while (r_max <= n_probs) {
        res_prob += compute_sum(probs, used, n_probs, 0, r_max);
        r_max++;
      }
    }
    std::cout << res_prob << std::endl;
  }
  return 0;
}

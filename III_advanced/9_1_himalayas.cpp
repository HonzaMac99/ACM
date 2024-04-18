#include <iostream>     
#include <cmath>     /* atan2 */
#include <vector>
#include <tuple>
#include <queue>
#include <iomanip>

#define PI 3.14159265
typedef std::tuple<int, int> t2int;
// typedef std::priority_queue<t2int, std::vector<t2int>, std::greater<t2int>> min_prior_q;
typedef std::priority_queue<t2int, std::vector<t2int>> min_prior_q;


void print_point(t2int p1) {
  double p1_x = std::get<0>(p1);
  double p1_y = std::get<1>(p1);
  std::cout << p1_x << "  " <<  p1_y << std::endl;
}


double get_light_len(t2int p1, t2int p2, double y_level) {
  double p1_x = std::get<0>(p1);
  double p1_y = std::get<1>(p1);
  double p2_x = std::get<0>(p2);
  double p2_y = std::get<1>(p2);

  double line_len = sqrt(pow(p1_x-p2_x,2) + pow(p1_y-p2_y,2));
  double y_ratio =  (p1_y - y_level) / (p1_y - p2_y);
  return line_len * y_ratio;
}


int main ()
{
  int n_cases, n_points;
  int x, y;

  std::cin >> n_cases;
  for(int i = 0; i < n_cases; i++) {
    std::cin >> n_points;
    min_prior_q q;
    for(int j = 0; j < n_points; j++){ 
      std::cin >> x >> y;
      t2int point(x, y);
      q.push(point);
    }
    double total_len = 0;
    int y_level = 0;

    // while (!q.empty()) {
    //   print_point(q.top());
    //   q.pop();
    // }
    // std::cout << "\n";
    // continue;

    t2int cur_point, last_point;
    cur_point = q.top();
    q.pop();
    for(int j = 1; j < n_points; j++) { 
      last_point = cur_point;
      cur_point = q.top();
      q.pop();
      int cur_p_y = std::get<1>(cur_point);
      if (cur_p_y > y_level) {
        // std::cout << y_level << std::endl;
        total_len += get_light_len(cur_point, last_point, y_level);
        y_level = cur_p_y;
      }
    }
    std::cout << std::fixed << std::setprecision(2) << total_len << std::endl;
  }
  return 0;
}

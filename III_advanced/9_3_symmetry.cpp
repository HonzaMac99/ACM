#include <iostream>     
#include <cmath>     /* atan2 */
#include <vector>
#include <tuple>
#include <queue>
#include <iomanip>
#include <algorithm>

#define PI 3.14159265
typedef std::tuple<int, int> t2int;
// typedef std::priority_queue<t2int, std::vector<t2int>, std::greater<t2int>> min_prior_q;
typedef std::priority_queue<t2int, std::vector<t2int>> min_prior_q;


void print_point(t2int p1) {
  double p1_x = std::get<0>(p1);
  double p1_y = std::get<1>(p1);
  std::cout << p1_x << "  " <<  p1_y << std::endl;
}


bool is_centre(t2int p, t2int s) {
  bool result = false;
  int p_x = std::get<0>(p);
  int p_y = std::get<1>(p);
  int s_x = std::get<0>(s);
  int s_y = std::get<1>(s);

  if (p_x == s_x and p_y == s_y) {
    result = true;
  }
  return result;
}


bool is_centre(t2int p1, t2int p2, t2int s) {
  bool result = false;
  int p1_x = std::get<0>(p1);
  int p1_y = std::get<1>(p1);
  int p2_x = std::get<0>(p2);
  int p2_y = std::get<1>(p2);
  int s_x = std::get<0>(s);
  int s_y = std::get<1>(s);
  double x_s = std::max(p1_x-p2_x, p2_x-p1_x) / 2 + std::min(p1_x, p2_x);
  double y_s = std::max(p1_y-p2_y, p2_y-p1_y) / 2 + std::min(p1_y, p2_y);
  if (x_s == s_x and y_s == s_y) {
    result = true;
  }
  else {
    std::cout << "Not centre: " << x_s << " " << y_s << std::endl;
    print_point(p1);
    print_point(p2);
    print_point(s);
  }
  return result;
}


int main ()
{
  int n_cases, n_points;
  int x, y;
  std::cin >> n_cases;
  for(int i = 0; i < n_cases; i++) {
    long long x_sum = 0, y_sum = 0; 
    std::cin >> n_points;
    min_prior_q q;
    for(int j = 0; j < n_points; j++) {
      std::cin >> x >> y;
      t2int point(x, y);
      q.push(point);
      x_sum += x;
      y_sum += y;
    }
    if (i != 22) continue;

    t2int* pts_sorted = new t2int[n_points];
    for(int j = 0; j < n_points; j++) {
      pts_sorted[j] = q.top();
      print_point(pts_sorted[j]);
      q.pop();
    }

    t2int ps(x_sum/n_points, y_sum/n_points);
    // std::cout << "centre " <<  x_sum/n_points << " " << y_sum/n_points << "\n\n";

    bool is_symmetric = true;
    if (n_points % 2 != 0 and !is_centre(pts_sorted[n_points-1/2], ps)) {
      is_symmetric = false;
    }
    
    int j = 0;
    while(j < n_points/2 + 1) {
      t2int p1 = pts_sorted[j];
      t2int p2 = pts_sorted[n_points-1-j];
      if(!is_centre(p1, p2, ps)) {
        is_symmetric = false;
        break;
      }
      j++;
    }
    if (is_symmetric) {
      std::cout << "yes" << std::endl;
    } 
    else {
      std::cout << "no" << std::endl;
    }
    delete [] pts_sorted;
  }
  return 0;
}

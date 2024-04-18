/* atan2 example */
#include <iostream>     
#include <cmath>     /* atan2 */
#include <vector>

#define PI 3.14159265


int main ()
{
  std::vector<double> radii;
  int n;

  while(std::cin >> n) { 
    double new_rad = n - 0.5;
    radii.push_back(new_rad);
  }

  for(int i = 0; i < radii.size(); i++) {
    double radius = radii[i];
    std::cout << radius << std::endl;

    int n_bound = 0;
    int n_in = 0;

    // todo: make table ceil(radius) by ceil(radius) to mark
    //       corners of the grid that are in or out
    

    int x = ceil(radius);
    int y = 1;
    while (y <= ceil(radius))  {
      double xy_dist = sqrt(pow(x,2)+pow(y,2));
      while (xy_dist > radius) {
        xy_dist = sqrt(pow(--x,2)+pow(y,2));
        n_bound++;
      }
      n_in += x;
      x++;
      y++;
    }
  }



  
  return 0;
}

/* atan2 example */
#include <iostream>     
#include <cmath>     /* atan2 */

#define PI 3.14159265


// angle of a vector to the x axis
double compute_atan(double x, double y) {
  return atan2(y, x) * 180 / PI;
}

int main ()
{
  // double x = -10.0;
  // double y = 10.0;
  // double result = compute_atan(x, y);
  // std::cout << "The arctan for (x=" << x << ", y=" << y << ") is " << result << " deg\n";
  
  return 0;
}

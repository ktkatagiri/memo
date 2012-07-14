#include <iostream>
#include <vector>
#include <cmath>

double solve( double a, int n);

int main(int argc, char *argv[])
{
  double a;

  while (std::cin >> a) {
    //    std::cout << solve(a, 10) << std::endl;
    printf("%.9f\n", solve(a, 10));

  }
  return 0;
}

double solve( double a, int n) {
   double tmp;
  std::vector< double> vec;
  
   double multi = 1.0;
   double dev = 1.0;

  vec.push_back(a);
  for (int i = 1; i < n; ++i) {
    if (i%2 == 1) {
      multi *= 2.0;
    } else {
      dev *= 3.0;
    }
    vec.push_back(a * multi / dev);
  }
  
  double result = 0;
  for (int i = 0; i < vec.size(); ++i) {
    // std::cout << vec[i] << ",";
    result += vec[i];
  }
  // std::cout << std::endl;
  return result;
}

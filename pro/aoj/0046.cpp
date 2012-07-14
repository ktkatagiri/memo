#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>

double solve(const std::vector<double>& vec);

int main(int argc, char *argv[])
{
  std::vector<double> vec;
  double temp;

  // input
  while(std::cin >> temp) {
    vec.push_back(temp);
  }
  
  std::cout << solve(vec) << std::endl;
  return 0;
}

double solve(const std::vector<double>& vec) {
  double result;
  if (vec.size() == 0) { throw "illegal input"; }

  double max = vec[0];
  double min = vec[0];
  for (int i = 0; i < vec.size(); ++i) {
    if (vec[i] > max) { max = vec[i]; }
    else if (vec[i] < min) { min = vec[i]; }
  }
  result = max - min;
  return result;
}

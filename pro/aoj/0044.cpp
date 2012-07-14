#include <iostream>
#include <vector>
#include <cmath>

std::vector<int> solve(int max);

int main(int argc, char *argv[])
{
  int max;

  while(std::cin >> max) {
    std::vector<int> result;

    result = solve(max);
    std::cout << result[0] << " " << result[1] << std::endl;
  }
  return 0;
}


std::vector<int> solve(int max)
{
  int n = 55000;
  std::vector<int> result(2);

  std::vector<bool> vec(n+1);
  for (int i = 0; i <= n; ++i) { vec[i] = true; }
  vec[0] = false;
  vec[1] = false; // not 1 is sosuu
  
  int n_sqrt = (int)(sqrt(n));
  
  // from 2
  for (int i = 2; i < n_sqrt+1; ++i) {
      // if number is false then
      if (!vec[i]) { continue; }
      
      // i * 2 : to self number avoid
      for (int j = i * 2; j <= n; j += i) {
	if (vec[j]) {
	  vec[j] = false;
	}
      }
  }
  
  for (int i = 0; i <= n; ++i) {
    if (vec[i]) // if sosuu
      {
	if (i > max) {
	  result[1] = i;
	  break;
	}
	if (i != max) {
	  result[0] = i;
	}
      }
  }

  // std::cout << result[0] << " " << result[1] << std::endl;
  return result;
}

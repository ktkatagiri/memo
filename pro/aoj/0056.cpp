#include <iostream>
#include <vector>
#include <cmath>

std::vector<bool> makePrimeTable(int n);
int solve(int x, const std::vector<bool>& vec);

int main(int argc, char *argv[])
{
  int x;
  const std::vector<bool> table = makePrimeTable(50005);
  while (std::cin >> x, x) {
    std::cout << solve(x, table) << std::endl;
  }
  return 0;
}

int solve(int x, const std::vector<bool>& vec) {
  int count = 0;
  for(int i=2; i <= x / 2; i++){
    if (vec[i] && vec[x - i]) {
      ++count;
    }
  }

  return count;
}

std::vector<bool> makePrimeTable(int n) {
  std::vector<bool> vec(n+1);

  for (int i = 0; i <= vec.size(); ++i) { vec[i] = true; }
  vec[0] = false;
  vec[1] = false;

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

  return vec;
}

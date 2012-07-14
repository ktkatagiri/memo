#include <iostream>
#include <vector>
#include <cmath>

std::vector<int> makePrimes(int n);
int solve(int x);

int main(int argc, char *argv[])
{
  double x;
  while (std::cin >> x) {
    if (x==0) { break; }
    std::cout << solve(x) << std::endl;
  }
  return 0;
}

int solve(int x) {
  int count = 0;
  std::vector<int> vec = makePrimes(51000);
  for (int i = 0; vec[i] < x && i < vec.size(); ++i) {
    for (int j = 0; vec[j] <= x/2 && j < vec.size(); ++j) {
      if (vec[i]+vec[j]==x) {
	++count;
      }
    }
  }

  return count;
}

// under 50000
std::vector<int> makePrimes(int n) { // param n 以下の素数列を生成し，vector<int>で返す
  std::vector<bool> vec(n+1);
  std::vector<int> result;

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
  
  for (int i = 0;
	 i < n;
       ++i) {
    if (vec[i])
      {
	result.push_back(i);
      }
  }

  return result;
}

#include <iostream>
#include <vector>
#include <cmath>

int solve(int a, int b, int n);

int main(int argc, char *argv[])
{
  int a,b,n;

  while (std::cin >> a >> b >> n) {
    std::cout << solve(a, b, n) << std::endl;
  }
  return 0;
}

int solve(int a, int b, int n) {
  int tmp;
  std::vector<int> vec;

  for (int i = 0; i <= n; ++i) {
    tmp = a / b;
    // std::cout << tmp << " ";
    vec.push_back(tmp);
    a = (a % b) * 10;
  }
  
  int result = 0;
  for (int i = 1; i < vec.size(); ++i) {
    result += vec[i];
  }

  return result;
}

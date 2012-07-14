#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>

#include <sstream>

int solve(int n);

int main(int argc, char *argv[])
{
  int n;

  while(std::cin >> n, n != 0) {
    std::cout << solve(n) << std::endl;
  }

  return 0;
}

// int fact(int n) {
//   if (n <= 1) { return n; }
//   else {
//     return n * fact(n-1);
//   }
// }

int solve(int n) {
  int count = 0;
  while(n /= 5) { count += n; }
  return count;
}


#include <iostream>

int solve(int n);
int main(int argc, char *argv[])
{
  int x;

  while (std::cin >> x && !(std::cin.eof())) {
    std::cout << solve(x) << std::endl;
  }
  return 0;
}
int solve(int n) {
  return (n * n + n + 2) / 2;
}


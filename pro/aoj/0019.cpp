#include <iostream>
// #include <string>
// #include <algorithm>
// #include <vector>
// #include <sstream>

long fact(long n) {
  return (n <= 1) ? 1 : fact(n-1) * n;
}

int main(int argc, char *argv[])
{
  long n; std::cin >> n; std::cout << fact(n) << std::endl;
  return 0;
}
